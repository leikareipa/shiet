/*
 * 2019 Tarpeeksi Hyvae Soft
 * 
 * OpenGL 3.0 render surface for the Kelpo renderer.
 * 
 */

#ifndef KELPO_RENDERER_SURFACE_OPENGL_3_0_SURFACE_OPENGL_3_0_H
#define KELPO_RENDERER_SURFACE_OPENGL_3_0_SURFACE_OPENGL_3_0_H

#include <windef.h>

LRESULT kelpo_surface_opengl_3_0__window_message_handler(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam);

int kelpo_surface_opengl_3_0__release_surface(void);

int kelpo_surface_opengl_3_0__flip_surface(void);

int kelpo_surface_opengl_3_0__create_surface(const unsigned width,
                                             const unsigned height,
                                             const unsigned bpp,
                                             const int vsyncEnabled,
                                             const unsigned deviceIdx);

#endif
