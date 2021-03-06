#ifndef KELPO_INTERFACE_POLYGON_VERTEX_H
#define KELPO_INTERFACE_POLYGON_VERTEX_H

#include <kelpo_interface/stdint.h>

struct kelpo_polygon_vertex_s
{
    /* World coordinates.*/
    float x, y, z, w;

    /* Normal.*/
    float nx, ny, nz;

    /* Texture coordinates.*/
    float u, v;

    /* Color.*/
    uint8_t r, g, b, a;
};

#endif
