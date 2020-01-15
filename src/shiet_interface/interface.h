#ifndef SHIET_INTERFACE_INTERFACE_H
#define SHIET_INTERFACE_INTERFACE_H

#include <shiet_interface/common/stdint.h>

#define SHIET_INTERFACE_VERSION_MAJOR 0 /* Starting from version 1, bumped when introducing breaking interface changes.*/
#define SHIET_INTERFACE_VERSION_MINOR 1 /* Bumped (or not) when such new functionality is added that doesn't break compatibility with existing implementations of current major version.*/
#define SHIET_INTERFACE_VERSION_PATCH 0 /* Bumped (or not) on minor bug fixes etc.*/

struct shiet_polygon_triangle_s;
struct shiet_polygon_texture_s;

struct shiet_interface_s
{
    void (*initialize)(const unsigned width,
                       const unsigned height,
                       const unsigned bpp,
                       const int vsyncEnabled,
                       const unsigned deviceID);

    struct shiet_interface_window_s
    {
        uint32_t (*get_handle)(void);

        void (*process_events)(void);

        void (*flip_surface)(void);

        int (*is_window_open)(void);

        /*size*/
    } window;

    struct shiet_interface_rasterizer_s
    {
        void (*clear_frame)(void);

        void (*upload_texture)(struct shiet_polygon_texture_s *const texture);

        void (*update_texture)(struct shiet_polygon_texture_s *const texture);

        void (*draw_triangles)(struct shiet_polygon_triangle_s *const triangles,
                               const unsigned numTriangles);

        /*release*/

        /*framebuffer*/
    } rasterizer;

    struct shiet_interface_metadata_s
    {
        const char *rendererName;
        unsigned rendererVersionMajor;
        unsigned rendererVersionMinor;
        unsigned rendererVersionPatch;
    } metadata;
};

struct shiet_interface_s shiet_create_interface(const char *const rendererName);

#endif
