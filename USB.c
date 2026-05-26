// #############################################################################
// #### Copyright ##############################################################
// #############################################################################

/*
 * Copyright 2024 BaSSeM
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// #############################################################################
// #### Description ############################################################
// #############################################################################

// @ref https://www.usb.org/
// @ref https://www.usb.org/defined-class-codes

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

#include "Platform.h"

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

#ifndef DEBUG
    #define DEBUG
#endif

#ifdef DEBUG
    #undef DEBUG
#endif

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### Include(s) #############################################################
// #############################################################################

#include "USB.h"
#include "USB_Internal.h"

// #############################################################################
// #### Private Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### Private Type(s) ########################################################
// #############################################################################

typedef struct USB_Context
{
} USB_Context_t;

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

static USB_Status_t USB_Context_Initialize( void );
static USB_Status_t USB_Context_Cycle( void );
static USB_Status_t USB_Context_DeInitialize( void );

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

static USB_Context_t USB_Context;

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

static USB_Status_t USB_Context_Initialize( void )
{
    USB_Status_t Status = USB_Status_Success;

    do
    {
        USB_Trace( "%s( void )", __FUNCTION__ );

        UTIL_UNUSED( USB_Context );
    }
    while ( 0 );

    return Status;
}

static USB_Status_t USB_Context_Cycle( void )
{
    USB_Status_t Status = USB_Status_Success;

    do
    {
        USB_Trace( "%s( void )", __FUNCTION__ );

        UTIL_UNUSED( USB_Context );
    }
    while ( 0 );

    return Status;
}

static USB_Status_t USB_Context_DeInitialize( void )
{
    USB_Status_t Status = USB_Status_Success;

    do
    {
        USB_Trace( "%s( void )", __FUNCTION__ );

        UTIL_UNUSED( USB_Context );
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

USB_Status_t USB_Initialize( USB_t USBx )
{
    USB_Status_t Status = USB_Status_Success;
    USB_Status_t USB_Status = USB_Status_Success;

    do
    {
        USB_Trace( "%s( USBx=%d )", __FUNCTION__, USBx );

        if ( ( Status = USB_Context_Initialize( ) ) != USB_Status_Success )
        {
            break;
        }

        for ( USB_t USB_x = USB_Null; USB_x < USB_Count; ++USB_x )
        {
            if ( USBx != USB_All && USBx != USB_x )
            {
                continue;
            }

            if ( ( USB_Status = USB_Port_Initialize( USB_x ) ) != USB_Status_Success )
            {
                Status = USB_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

USB_Status_t USB_Cycle( USB_t USBx )
{
    USB_Status_t Status = USB_Status_Success;
    USB_Status_t USB_Status = USB_Status_Success;

    do
    {
        USB_Trace( "%s( USBx=%d )", __FUNCTION__, USBx );

        if ( ( Status = USB_Context_Cycle( ) ) != USB_Status_Success )
        {
            break;
        }

        for ( USB_t USB_x = USB_Null; USB_x < USB_Count; ++USB_x )
        {
            if ( USBx != USB_All && USBx != USB_x )
            {
                continue;
            }

            if ( ( USB_Status = USB_Port_Cycle( USB_x ) ) != USB_Status_Success )
            {
                Status = USB_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

USB_Status_t USB_DeInitialize( USB_t USBx )
{
    USB_Status_t Status = USB_Status_Success;
    USB_Status_t USB_Status = USB_Status_Success;

    do
    {
        USB_Trace( "%s( USBx=%d )", __FUNCTION__, USBx );

        for ( USB_t USB_x = USB_Null; USB_x < USB_Count; ++USB_x )
        {
            if ( USBx != USB_All && USBx != USB_x )
            {
                continue;
            }

            if ( ( USB_Status = USB_Port_DeInitialize( USB_x ) ) != USB_Status_Success )
            {
                Status = USB_Status;
            }
        }

        if ( ( USB_Status = USB_Context_DeInitialize( ) ) != USB_Status_Success )
        {
            Status = USB_Status;
        }
    }
    while ( 0 );

    return Status;
}

USB_Status_t USB_IsReady( USB_t USBx, USB_Interface_t Interface )
{
    USB_Status_t Status = USB_Status_Success;
    USB_Status_t USB_Status = USB_Status_Success;

    do
    {
        USB_Trace( "%s( USBx=%d )", __FUNCTION__, USBx );

        for ( USB_t USB_x = USB_Null; USB_x < USB_Count; ++USB_x )
        {
            if ( USBx != USB_All && USBx != USB_x )
            {
                continue;
            }

            for ( USB_Interface_t Interface_x = USB_Interface_Null; Interface_x < USB_Interface_Count; ++Interface_x )
            {
                if ( Interface != USB_Interface_All && Interface != Interface_x )
                {
                    continue;
                }

                if ( ( USB_Status = USB_Port_IsReady( USB_x, Interface_x ) ) != USB_Status_Success )
                {
                    Status = USB_Status;
                }
            }
        }
    }
    while ( 0 );

    return Status;
}

USB_Status_t USB_Write( USB_t USBx, USB_Interface_t Interface, USB_Data_t * Data, USB_DataLength_t DataLength )
{
    USB_Status_t Status = USB_Status_Success;
    USB_Status_t USB_Status = USB_Status_Success;

    do
    {
        USB_Trace( "%s( USB=%d, Interface=%d, Data=%p, Length=%d )", __FUNCTION__, USBx, Interface, Data, DataLength );

        if ( USBx == USB_All )
        {
            // FIXME What should be done while writing to all ?!
            Status = USB_Status_NotSupported;
            break;
        }

        for ( USB_t USB_x = USB_Null; USB_x < USB_Count; ++USB_x )
        {
            if ( USBx != USB_All && USBx != USB_x )
            {
                continue;
            }

            if ( ( USB_Status = USB_Port_Write( USB_x, Interface, Data, DataLength ) ) != USB_Status_Success )
            {
                Status = USB_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

USB_Status_t USB_Read( USB_t USBx, USB_Interface_t Interface, USB_Data_t * Data, USB_DataLength_t DataLength )
{
    USB_Status_t Status = USB_Status_Success;
    USB_Status_t USB_Status = USB_Status_Success;

    do
    {
        USB_Trace( "%s( USB=%d, Interface=%d, Data=%p, Length=%d )", __FUNCTION__, USBx, Interface, Data, DataLength );

        if ( USBx == USB_All )
        {
            // FIXME What should be done while reading from all ?!
            Status = USB_Status_NotSupported;
            break;
        }

        for ( USB_t USB_x = USB_Null; USB_x < USB_Count; ++USB_x )
        {
            if ( USBx != USB_All && USBx != USB_x )
            {
                continue;
            }

            if ( ( USB_Status = USB_Port_Read( USB_x, Interface, Data, DataLength ) ) != USB_Status_Success )
            {
                Status = USB_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char USB_VERSION[] = "0.0.0.v20260526-1252";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
