/*
 * 2020 Tarpeeksi Hyvae Soft
 * 
 * Software: Kelpo 
 * 
 */

#ifndef KELPO_RENDERER_SURFACE_OPENGL_3_0_GL3_TYPES_H
#define KELPO_RENDERER_SURFACE_OPENGL_3_0_GL3_TYPES_H

#include <gl/gl.h>
#include <gl/glext.h>

#define GLAPIENTRY __stdcall
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED 0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE 0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE 0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE 0x8625
#define GL_CURRENT_VERTEX_ATTRIB 0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE 0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE 0x8643
#define GL_VERTEX_ATTRIB_ARRAY_POINTER 0x8645
#define GL_STENCIL_BACK_FUNC 0x8800
#define GL_STENCIL_BACK_FAIL 0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL 0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS 0x8803
#define GL_MAX_DRAW_BUFFERS 0x8824
#define GL_DRAW_BUFFER0 0x8825
#define GL_DRAW_BUFFER1 0x8826
#define GL_DRAW_BUFFER2 0x8827
#define GL_DRAW_BUFFER3 0x8828
#define GL_DRAW_BUFFER4 0x8829
#define GL_DRAW_BUFFER5 0x882A
#define GL_DRAW_BUFFER6 0x882B
#define GL_DRAW_BUFFER7 0x882C
#define GL_DRAW_BUFFER8 0x882D
#define GL_DRAW_BUFFER9 0x882E
#define GL_DRAW_BUFFER10 0x882F
#define GL_DRAW_BUFFER11 0x8830
#define GL_DRAW_BUFFER12 0x8831
#define GL_DRAW_BUFFER13 0x8832
#define GL_DRAW_BUFFER14 0x8833
#define GL_DRAW_BUFFER15 0x8834
#define GL_BLEND_EQUATION_ALPHA 0x883D
#define GL_POINT_SPRITE 0x8861
#define GL_COORD_REPLACE 0x8862
#define GL_MAX_VERTEX_ATTRIBS 0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_MAX_TEXTURE_COORDS 0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS 0x8872
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_VERTEX_SHADER 0x8B31
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS 0x8B4A
#define GL_MAX_VARYING_FLOATS 0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_SHADER_TYPE 0x8B4F
#define GL_FLOAT_VEC2 0x8B50
#define GL_FLOAT_VEC3 0x8B51
#define GL_FLOAT_VEC4 0x8B52
#define GL_INT_VEC2 0x8B53
#define GL_INT_VEC3 0x8B54
#define GL_INT_VEC4 0x8B55
#define GL_BOOL 0x8B56
#define GL_BOOL_VEC2 0x8B57
#define GL_BOOL_VEC3 0x8B58
#define GL_BOOL_VEC4 0x8B59
#define GL_FLOAT_MAT2 0x8B5A
#define GL_FLOAT_MAT3 0x8B5B
#define GL_FLOAT_MAT4 0x8B5C
#define GL_SAMPLER_1D 0x8B5D
#define GL_SAMPLER_2D 0x8B5E
#define GL_SAMPLER_3D 0x8B5F
#define GL_SAMPLER_CUBE 0x8B60
#define GL_SAMPLER_1D_SHADOW 0x8B61
#define GL_SAMPLER_2D_SHADOW 0x8B62
#define GL_DELETE_STATUS 0x8B80
#define GL_COMPILE_STATUS 0x8B81
#define GL_LINK_STATUS 0x8B82
#define GL_VALIDATE_STATUS 0x8B83
#define GL_INFO_LOG_LENGTH 0x8B84
#define GL_ATTACHED_SHADERS 0x8B85
#define GL_ACTIVE_UNIFORMS 0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH 0x8B87
#define GL_SHADER_SOURCE_LENGTH 0x8B88
#define GL_ACTIVE_ATTRIBUTES 0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH 0x8B8A
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define GL_SHADING_LANGUAGE_VERSION 0x8B8C
#define GL_CURRENT_PROGRAM 0x8B8D
#define GL_POINT_SPRITE_COORD_ORIGIN 0x8CA0
#define GL_LOWER_LEFT 0x8CA1
#define GL_UPPER_LEFT 0x8CA2
#define GL_STENCIL_BACK_REF 0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK 0x8CA4
#define GL_STENCIL_BACK_WRITEMASK 0x8CA5
#define GL_ARRAY_BUFFER 0x8892
#define GL_STATIC_DRAW 0x88E4
#define GL_DYNAMIC_DRAW 0x88E8

typedef char GLchar;
typedef ptrdiff_t GLsizeiptr;
typedef ptrdiff_t GLintptr;

typedef GLuint (GLAPIENTRY *PFNGLCREATEPROGRAMPROC)(void);
extern PFNGLCREATEPROGRAMPROC glCreateProgram;

typedef GLuint (GLAPIENTRY *PFNGLCREATESHADERPROC)(GLenum type);
extern PFNGLCREATESHADERPROC glCreateShader;

typedef void (GLAPIENTRY *PFNGLSHADERSOURCEPROC)(GLuint shader, GLsizei count, const GLchar *const* string, const GLint* length);
extern PFNGLSHADERSOURCEPROC glShaderSource;

typedef void (GLAPIENTRY *PFNGLCOMPILESHADERPROC)(GLuint shader);
extern PFNGLCOMPILESHADERPROC glCompileShader;

typedef void (GLAPIENTRY *PFNGLGETSHADERIVPROC)(GLuint shader, GLenum pname, GLint* param);
extern PFNGLGETSHADERIVPROC glGetShaderiv;

typedef void (GLAPIENTRY *PFNGLATTACHSHADERPROC)(GLuint program, GLuint shader);
extern PFNGLATTACHSHADERPROC glAttachShader;

typedef void (GLAPIENTRY *PFNGLBINDFRAGDATALOCATIONPROC)(GLuint program, GLuint colorNumber, const GLchar* name);
extern PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocation;

typedef void (GLAPIENTRY *PFNGLLINKPROGRAMPROC)(GLuint program);
extern PFNGLLINKPROGRAMPROC glLinkProgram;

typedef void (GLAPIENTRY *PFNGLUSEPROGRAMPROC)(GLuint program);
extern PFNGLUSEPROGRAMPROC glUseProgram;

typedef void (GLAPIENTRY *PFNGLGENBUFFERSPROC)(GLsizei n, GLuint* buffers);
extern PFNGLGENBUFFERSPROC glGenBuffers;

typedef void (GLAPIENTRY *PFNGLBINDBUFFERPROC)(GLenum target, GLuint buffer);
extern PFNGLBINDBUFFERPROC glBindBuffer;

typedef void (GLAPIENTRY *PFNGLBUFFERDATAPROC)(GLenum target, GLsizeiptr size, const void* data, GLenum usage);
extern PFNGLBUFFERDATAPROC glBufferData;

typedef void (GLAPIENTRY *PFNGLBUFFERSUBDATAPROC)(GLenum target, GLintptr offset, GLsizeiptr size, const void* data);
extern PFNGLBUFFERSUBDATAPROC glBufferSubData;

typedef void (GLAPIENTRY *PFNGLGENVERTEXARRAYSPROC)(GLsizei n, GLuint* arrays);
extern PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;

typedef void (GLAPIENTRY *PFNGLBINDVERTEXARRAYPROC)(GLuint array);
extern PFNGLBINDVERTEXARRAYPROC glBindVertexArray;

typedef GLint (GLAPIENTRY *PFNGLGETATTRIBLOCATIONPROC)(GLuint program, const GLchar* name);
extern PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation;

typedef void (GLAPIENTRY *PFNGLVERTEXATTRIBPOINTERPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);
extern PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;

typedef void (GLAPIENTRY *PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint index);
extern PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;

#undef GLAPIENTRY

#endif
