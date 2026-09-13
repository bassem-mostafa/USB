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

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

USB_Status_t USB_Initialize( USB_t USBx )
{
    USB_Status_t Status = USB_Status_Success;

    do
    {
        USB_Trace( "%s( USBx=%d )", __FUNCTION__, USBx );

        if ( ( Status = USB_Port_Initialize( USBx ) ) != USB_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

USB_Status_t USB_Cycle( USB_t USBx )
{
    USB_Status_t Status = USB_Status_Success;

    do
    {
        USB_Trace( "%s( USBx=%d )", __FUNCTION__, USBx );

        if ( ( Status = USB_Port_Cycle( USBx ) ) != USB_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

USB_Status_t USB_DeInitialize( USB_t USBx )
{
    USB_Status_t Status = USB_Status_Success;

    do
    {
        USB_Trace( "%s( USBx=%d )", __FUNCTION__, USBx );

        if ( ( Status = USB_Port_DeInitialize( USBx ) ) != USB_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

USB_Status_t USB_IsReady( USB_t USBx, USB_Interface_t Interface )
{
    USB_Status_t Status = USB_Status_Success;

    do
    {
        USB_Trace( "%s( USBx=%d )", __FUNCTION__, USBx );

        if ( ( Status = USB_Port_IsReady( USBx, Interface ) ) != USB_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

USB_Status_t USB_Write( USB_t USBx, USB_Interface_t Interface, USB_Data_t * Data, USB_DataLength_t DataLength )
{
    USB_Status_t Status = USB_Status_Success;

    do
    {
        USB_Trace( "%s( USB=%d, Interface=%d, Data=%p, Length=%d )", __FUNCTION__, USBx, Interface, Data, DataLength );

        if ( ( Status = USB_Port_Write( USBx, Interface, Data, DataLength ) ) != USB_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

USB_Status_t USB_Read( USB_t USBx, USB_Interface_t Interface, USB_Data_t * Data, USB_DataLength_t DataLength )
{
    USB_Status_t Status = USB_Status_Success;

    do
    {
        USB_Trace( "%s( USB=%d, Interface=%d, Data=%p, Length=%d )", __FUNCTION__, USBx, Interface, Data, DataLength );

        if ( ( Status = USB_Port_Read( USBx, Interface, Data, DataLength ) ) != USB_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char USB_VERSION[] = "0.0.0.v20260913-1832";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
