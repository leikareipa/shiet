/*
 * 2020 Tarpeeksi Hyvae Soft
 * 
 * Software: shiet renderer
 * 
 * Creates a DirectDraw 7 surface out of a shiet texture's data.
 * 
 * Note: The Direct3D 7 headers basically force the use of a C++ compiler -
 * hence, the code here might not conform to C89 like the rest of shiet.
 * 
 */

#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <shiet_interface/polygon/texture.h>

#include <windows.h>
#include <d3d.h>

/* Used in conjunction with IDirect3DDevice_EnumTextureFormats(); matches an ARGB
 * 1555 pixel format, and if found, copies it into 'dest'.*/
static HRESULT CALLBACK texture_search_callback_argb_1555(DDPIXELFORMAT* pddpf, VOID* dest)
{
    if ((pddpf->dwRGBAlphaBitMask != 0x8000) ||
        (pddpf->dwRBitMask != 0x7c00) ||
        (pddpf->dwGBitMask != 0x3e0) ||
        (pddpf->dwBBitMask != 0x1f))
    {
        return DDENUMRET_OK;
    }

    memcpy((DDPIXELFORMAT*)dest, pddpf, sizeof(DDPIXELFORMAT));

    return DDENUMRET_CANCEL;
}

LPDIRECTDRAWSURFACE7 shiet_create_directdraw7_surface_from_texture(const struct shiet_polygon_texture_s *const texture,
                                                                   LPDIRECT3DDEVICE7 d3dDevice)
{
    uint32_t m = 0;
    LPDIRECTDRAWSURFACE7 d3dTexture = NULL;
    LPDIRECTDRAWSURFACE7 mipSurface = NULL;

    assert(d3dDevice && "Unknown Direct3D device.");

    /* We require that the Direct3D device is a hardware one, so assert to make sure.*/
    {
        D3DDEVICEDESC7 deviceDescription;
        
        if (FAILED(IDirect3DDevice7_GetCaps(d3dDevice, &deviceDescription)))
        {
            return NULL;
        }

        #ifdef __cplusplus
            assert(((deviceDescription.deviceGUID == IID_IDirect3DHALDevice) ||
                    (deviceDescription.deviceGUID == IID_IDirect3DTnLHalDevice)) &&
        #else
            assert(((deviceDescription.deviceGUID == &IID_IDirect3DHALDevice) ||
                    (deviceDescription.deviceGUID == &IID_IDirect3DTnLHalDevice)) &&
        #endif
                   "Expected a hardware device.");
    }

    /* Create the texture's DirectDraw surface.*/
    {
        LPDIRECTDRAWSURFACE7 renderTarget = NULL;
        LPDIRECTDRAW7 directDrawInterface = NULL;
        DDSURFACEDESC2 surfaceDescription;

        ZeroMemory(&surfaceDescription, sizeof(DDSURFACEDESC2));
        surfaceDescription.dwSize = sizeof(DDSURFACEDESC2);
        surfaceDescription.dwFlags = (DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH | DDSD_PIXELFORMAT| DDSD_TEXTURESTAGE);
        surfaceDescription.ddsCaps.dwCaps = (DDSCAPS_TEXTURE | ((texture->numMipLevels <= 1)? 0 : (DDSCAPS_MIPMAP | DDSCAPS_COMPLEX)));
        surfaceDescription.ddsCaps.dwCaps2 = DDSCAPS2_TEXTUREMANAGE;
        surfaceDescription.dwMipMapCount = 0; /* Shiet textures with mipmapping are expected to have levels down to 1 x 1.*/
        surfaceDescription.dwWidth = texture->width;
        surfaceDescription.dwHeight = texture->height;
        IDirect3DDevice_EnumTextureFormats(d3dDevice, texture_search_callback_argb_1555, &surfaceDescription.ddpfPixelFormat);

        IDirect3DDevice7_GetRenderTarget(d3dDevice, &renderTarget);
        IDirectDrawSurface7_GetDDInterface(renderTarget, (VOID**)&directDrawInterface);
        IDirectDrawSurface7_Release(renderTarget);

        if (FAILED(IDirectDraw7_CreateSurface(directDrawInterface, &surfaceDescription, &d3dTexture, NULL)))
        {
            IDirectDraw7_Release(directDrawInterface);

            return NULL;
        }

        IDirectDraw7_Release(directDrawInterface);
    }

    /* Copy the shiet texture's pixel data into the Direct3D texture.*/
    mipSurface = d3dTexture;
    for (m = 0; m < texture->numMipLevels; m++)
    {
        HDC hdcTexture = 0;

        if (SUCCEEDED(IDirectDrawSurface7_GetDC(mipSurface, &hdcTexture)))
        {
            const unsigned mipLevelSideLength = (texture->width / pow(2, m)); /* Shiet textures are expected to be square.*/
            HDC hdcBitmap = 0;
            HBITMAP map = 0;
            BITMAPINFO bmInfo;
            BITMAPINFOHEADER bmiHead;

            bmiHead.biSize = sizeof(BITMAPINFOHEADER);
            bmiHead.biWidth = mipLevelSideLength;
            bmiHead.biHeight = mipLevelSideLength;
            bmiHead.biPlanes = 1;
            bmiHead.biBitCount = 16;
            bmiHead.biCompression = BI_RGB;
            bmiHead.biSizeImage = 0;
            bmiHead.biXPelsPerMeter = 0;
            bmiHead.biYPelsPerMeter = 0;
            bmiHead.biClrUsed = 0;
            bmiHead.biClrImportant = 0;

            bmInfo.bmiHeader = bmiHead;
            /*TODO bmInfo.bmiColors = 0;*/

            if (!(map = CreateCompatibleBitmap(hdcTexture, mipLevelSideLength, mipLevelSideLength)))
            {
                IDirectDrawSurface7_Release(d3dTexture);
                DeleteObject(map);

                return NULL;
            }

            if (!SetDIBits(NULL, map, 0, mipLevelSideLength, texture->mipLevel[m], &bmInfo, DIB_RGB_COLORS))
            {
                IDirectDrawSurface7_Release(d3dTexture);
                DeleteObject(map);
                
                return NULL;
            }

            if (!(hdcBitmap = CreateCompatibleDC(NULL)))
            {
                IDirectDrawSurface7_Release(d3dTexture);
                DeleteDC(hdcBitmap);
                DeleteObject(map);

                return NULL;
            }

            SelectObject(hdcBitmap, map);
            BitBlt(hdcTexture, 0, 0, mipLevelSideLength, mipLevelSideLength, hdcBitmap, 0, 0, SRCCOPY);

            IDirectDrawSurface7_ReleaseDC(mipSurface, hdcTexture);
            DeleteDC(hdcBitmap);
            DeleteObject(map);
        }
        else
        {
            return NULL;
        }

        /* Move onto the next surface in the mip chain.*/
        if ((texture->numMipLevels > 1) &&
            (m < (texture->numMipLevels - 1)))
        {
            DDSCAPS2 ddsCaps;

            ddsCaps.dwCaps = (DDSCAPS_TEXTURE | DDSCAPS_MIPMAP);
            ddsCaps.dwCaps2 = 0;
            ddsCaps.dwCaps3 = 0;
            ddsCaps.dwCaps4 = 0;

            if (SUCCEEDED(IDirectDrawSurface7_GetAttachedSurface(mipSurface, &ddsCaps, &mipSurface)))
            {
                IDirectDrawSurface7_Release(mipSurface);
            }
            else
            {
                IDirectDrawSurface7_ReleaseDC(d3dTexture, hdcTexture);

                return NULL;
            }
        }
    }

    return d3dTexture;
}