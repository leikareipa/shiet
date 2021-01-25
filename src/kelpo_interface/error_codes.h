/*
 * 2021 Tarpeeksi Hyvae Soft
 * 
 * Software: Kelpo
 * 
 */

#ifndef KELPO_INTERFACE_ERROR_CODES_H
#define KELPO_INTERFACE_ERROR_CODES_H

enum kelpo_error_code_e
{
    KELPOERR_NO_ERROR = 0, /* This error code must always be 0.*/
    KELPOERR_TOO_MANY_ERRORS,
    KELPOERR_Z_BUFFERING_NOT_SUPPORTED,
    KELPOERR_VSYNC_CONTROL_NOT_SUPPORTED,
    KELPOERR_DISPLAY_MODE_NOT_SUPPORTED,
    KELPOERR_OUT_OF_VIDEO_MEMORY,
    KELPOERR_API_CALL_FAILED
};

#endif
