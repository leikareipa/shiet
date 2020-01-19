/*
 * 2020 Tarpeeksi Hyvae Soft
 * 
 * Software: Kelpo
 * 
 * Creates a triangle mesh representing a string of ASCII text, with the character
 * symbols loaded from a texture.
 * 
 * Usage:
 * 
 *   1. Call __create_font() to initialize the font.
 * 
 *   2. Upload the font texture you received in (1) to the renderer.
 * 
 *   3. Call __print().
 * 
 */

#ifndef KELPO_EXAMPLES_COMMON_SRC_TEXT_MESH_H
#define KELPO_EXAMPLES_COMMON_SRC_TEXT_MESH_H

struct kelpo_polygon_texture_s;
struct kelpo_generic_stack_s;

/* Loads the font's character set from a file and converts it into a Kelpo
 * texture, which you should then upload to the renderer.*/
struct kelpo_polygon_texture_s* kelpo_text_mesh__create_font(void);

/* Creates a triangle mesh representing the given ASCII string and positions
 * it at the given XY coordinates. The mesh is appended to the given triangle
 * stack.*/
void kelpo_text_mesh__print(const char *text,
                            unsigned posX,
                            unsigned posY,
                            struct kelpo_generic_stack_s *const dstTriangles);

#endif