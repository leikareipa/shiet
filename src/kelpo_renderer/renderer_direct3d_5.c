#include <stdio.h>
#include <kelpo_renderer/surface/direct3d_5/surface_direct3d_5.h>
#include <kelpo_renderer/rasterizer/direct3d_5/rasterizer_direct3d_5.h>
#include <kelpo_renderer/window/win32/window_win32.h>
#include <kelpo_interface/interface.h>

static const char RENDERER_NAME[] = "Direct3D 5";
static const unsigned RENDERER_VERSION[3] = {KELPO_INTERFACE_VERSION_MAJOR,
                                             0,   /* Minor.*/
                                             1};  /* Patch.*/

static int initialize(const unsigned deviceId,
                      const unsigned screenWidth,
                      const unsigned screenHeight,
                      const unsigned screenBPP)
{
    if (!kelpo_window__create_window(screenWidth, screenHeight, RENDERER_NAME, kelpo_surface_direct3d_5__window_message_handler))
    {
        goto initialization_failed;
    }

    if (!kelpo_surface_direct3d_5__create_surface(screenWidth, screenHeight, screenBPP, 1, deviceId))
    {
        kelpo_surface_direct3d_5__release_surface();
        goto initialization_failed;
    }

    if (!kelpo_rasterizer_direct3d_5__initialize())
    {
        kelpo_rasterizer_direct3d_5__release();
        kelpo_surface_direct3d_5__release_surface();
        goto initialization_failed;
    }

    return 1;

    initialization_failed:
    kelpo_window__release_window();
    return 0;
}

static int release(void)
{
    return (kelpo_surface_direct3d_5__release_surface() &
            kelpo_rasterizer_direct3d_5__release() &
            kelpo_window__release_window());
}

#ifdef __cplusplus
extern "C"
{
#endif

/* Returns 1 on success; 0 on failure.*/
int export_interface(struct kelpo_interface_s *const interface,
                     const unsigned interfaceVersion)
{
    if (interfaceVersion != RENDERER_VERSION[0])
    {
        return 0;
    }

    interface->window.open = initialize;
    interface->window.release = release;
    interface->window.is_open = kelpo_window__is_window_open;
    interface->window.is_closing = kelpo_window__is_window_closing;
    interface->window.process_messages = kelpo_window__process_window_messages;
    interface->window.flip_surface = kelpo_surface_direct3d_5__flip_surface;
    interface->window.get_handle = kelpo_window__get_window_handle;
    interface->window.set_message_handler = kelpo_window__set_external_message_handler;

    interface->rasterizer.clear_frame = kelpo_rasterizer_direct3d_5__clear_frame;
    interface->rasterizer.draw_triangles = kelpo_rasterizer_direct3d_5__draw_triangles;
    interface->rasterizer.upload_texture = kelpo_rasterizer_direct3d_5__upload_texture;
    interface->rasterizer.update_texture = kelpo_rasterizer_direct3d_5__update_texture;
    interface->rasterizer.unload_textures = kelpo_rasterizer_direct3d_5__unload_textures;

    KELPO_COPY_RENDERER_NAME(interface->metadata.rendererName, RENDERER_NAME);
    interface->metadata.rendererVersionMajor = RENDERER_VERSION[0];
    interface->metadata.rendererVersionMinor = RENDERER_VERSION[1];
    interface->metadata.rendererVersionPatch = RENDERER_VERSION[2];

    return 1;
}

#ifdef __cplusplus
}
#endif
