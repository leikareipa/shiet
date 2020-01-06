#ifndef SHIET_INTERFACE_H
#define SHIET_INTERFACE_H

struct shiet_polygon_triangle_s;
struct shiet_polygon_texture_s;

struct shiet_interface_s
{
    void (*initialize)(const unsigned, const unsigned, const char *const);

    struct
    {
        void (*get_handle)(void**);
        void (*update_window)(void);
        int (*is_window_open)(void);
        /*size*/
    } window;

    struct
    {
        void (*clear_frame)(void);
        void (*upload_texture)(struct shiet_polygon_texture_s *const);
        void (*update_texture)(struct shiet_polygon_texture_s *const);
        void (*draw_triangles)(const struct shiet_polygon_triangle_s *const, const unsigned);
        /*release*/
        /*framebuffer*/
    } rasterizer;

    struct
    {
        unsigned shietMajorVersion;
        unsigned shietMinorVersion;
        unsigned shietPatchVersion;

        const char *rendererName;
        unsigned rendererMajorVersion;
        unsigned rendererMinorVersion;
        unsigned rendererPatchVersion;
    } metadata;
};

struct shiet_interface_s shiet_create_interface(const char *const rasterizerName);

#endif