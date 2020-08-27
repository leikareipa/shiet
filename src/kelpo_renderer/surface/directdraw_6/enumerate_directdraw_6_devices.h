/*
 * 2020 Tarpeeksi Hyvae Soft
 * 
 * Note: The DirectX 6 headers basically force the use of a C++ compiler -
 * hence, the code here might not conform to C89 like the rest of Kelpo.
 * 
 */

#ifndef KELPO_RENDERER_SURFACE_DIRECTDRAW_6_ENUMERATE_DIRECTDRAW_6_DEVICES_H
#define KELPO_RENDERER_SURFACE_DIRECTDRAW_6_ENUMERATE_DIRECTDRAW_6_DEVICES_H

#include <d3d.h>

#define KELPO_DIRECTDRAW6_DEVICE_LIST_ENTRY_STRING_LENGTH 60

struct kelpo_directdraw6_device_list_entry_s
{
    GUID guid;
    char description[KELPO_DIRECTDRAW6_DEVICE_LIST_ENTRY_STRING_LENGTH + 1]; /* +1 for \0.*/

    struct kelpo_directdraw6_device_list_entry_s *next;
};

/* A linked list of DirectDraw 6 devices.*/
struct kelpo_directdraw6_device_list_s
{
    /* First device in the list.*/
    struct kelpo_directdraw6_device_list_entry_s *root;

    /* Points to a pointer to which the next new device entry should be allocated
     * (the one-past-last entry).*/
    struct kelpo_directdraw6_device_list_entry_s **end;

    /* Total number of devices in this list.*/
    unsigned count;
};

/* Returns a list of all DirectDraw 6 devices on this PC.*/
struct kelpo_directdraw6_device_list_s kelpo_enumerate_directdraw6_devices(void);

/* Returns the GUID of the idx'th DirectDraw 6 device on this PC.*/
GUID kelpo_directdraw6_device_guid(unsigned deviceIdx);

#endif
