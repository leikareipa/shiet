/*
 * 2020 Tarpeeksi Hyvae Soft
 * 
 * OpenGL 3.0 rasterizer for the Kelpo renderer.
 * 
 */

#ifndef KELPO_RENDERER_RASTERIZER_OPENGL_3_0_RASTERIZER_OPENGL_3_0_H
#define KELPO_RENDERER_RASTERIZER_OPENGL_3_0_RASTERIZER_OPENGL_3_0_H

struct kelpo_polygon_triangle_s;
struct kelpo_polygon_texture_s;

int kelpo_rasterizer_opengl_3_0__initialize(void);

int kelpo_rasterizer_opengl_3_0__release(void);

int kelpo_rasterizer_opengl_3_0__clear_frame(void);

int kelpo_rasterizer_opengl_3_0__upload_texture(struct kelpo_polygon_texture_s *const texture);

int kelpo_rasterizer_opengl_3_0__update_texture(struct kelpo_polygon_texture_s *const texture);

int kelpo_rasterizer_opengl_3_0__unload_textures(void);

int kelpo_rasterizer_opengl_3_0__draw_triangles(struct kelpo_polygon_triangle_s *const triangles,
                                                const unsigned numTriangles);

#endif
