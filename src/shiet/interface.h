#ifndef SHIET_INTERFACE_H_
#define SHIET_INTERFACE_H_

struct shiet_interface_s
{
    void (*initialize)(const unsigned, const unsigned, const unsigned, const char *const);

    struct
    {
        void (*get_handle)(void**);
        void (*update_window)(void);
        int (*is_window_open)(void);
        /*size*/
    } window;

    struct
    {
        int placeholder;
    } transform;

    struct
    {
        void (*clear_frame)(void);
        /*release*/
        /*framebuffer*/
        /*draw_triangles*/
        /*add_texture*/
        /*update_texture*/
        /*rasterizer_nam*/
        /*rasterizer_version*/
    } rasterize;

    struct
    {
        unsigned shietMajorVersion;
        unsigned shietMinorVersion;
        unsigned shietPatchVersion;
    } metadata;
};

struct shiet_interface_s shiet_create_interface(const char *const rasterizer);

#endif
