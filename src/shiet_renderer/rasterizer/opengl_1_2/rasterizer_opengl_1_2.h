/*
 * 2020 Tarpeeksi Hyvae Soft
 * 
 * OpenGL 1.2 rasterizer for the shiet renderer.
 * 
 */

#ifndef SHIET_RENDERER_RASTERIZER_OPENGL_H
#define SHIET_RENDERER_RASTERIZER_OPENGL_H

struct shiet_polygon_triangle_s;
struct shiet_polygon_texture_s;

void shiet_rasterizer_opengl_1_2__initialize(void);

void shiet_rasterizer_opengl_1_2__release(void);

void shiet_rasterizer_opengl_1_2__clear_frame(void);

void shiet_rasterizer_opengl_1_2__upload_texture(struct shiet_polygon_texture_s *const texture);

void shiet_rasterizer_opengl_1_2__update_texture(struct shiet_polygon_texture_s *const texture);

void shiet_rasterizer_opengl_1_2__purge_textures(void);

void shiet_rasterizer_opengl_1_2__draw_triangles(struct shiet_polygon_triangle_s *const triangles,
                                                 const unsigned numTriangles);

#endif
