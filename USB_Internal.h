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

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

#include "Platform.h"

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

#ifndef USB_INTERNAL_H_
    #define USB_INTERNAL_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "USB_Port.h"
    #include "driver/STM32L496VGT6P/USB_STM32L496VGT6P.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    #ifndef USB_TIM
        #define USB_TIM PLATFORM_DEFAULT_TIM
    #endif

    #ifndef USB_LOG
        #define USB_LOG PLATFORM_DEFAULT_LOG
    #endif

    #define USB_NAME       "USB"
    #define USB_LOG_PREFIX UTIL_StringConcatenateConstant( USB_NAME, "> " )

    #ifdef DEBUG
        #define USB_Raw( Level, Format, ... ) LOG_Raw( USB_LOG, Level, Format, ##__VA_ARGS__ )
        #define USB_Trace( Format, ... )      LOG_Trace( USB_LOG, UTIL_StringConcatenateConstant( USB_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define USB_Debug( Format, ... )      LOG_Debug( USB_LOG, UTIL_StringConcatenateConstant( USB_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define USB_Info( Format, ... )       LOG_Info( USB_LOG, UTIL_StringConcatenateConstant( USB_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define USB_Warning( Format, ... )    LOG_Warning( USB_LOG, UTIL_StringConcatenateConstant( USB_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define USB_Error( Format, ... )      LOG_Error( USB_LOG, UTIL_StringConcatenateConstant( USB_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define USB_Fatal( Format, ... )      LOG_Fatal( USB_LOG, UTIL_StringConcatenateConstant( USB_LOG_PREFIX, Format ), ##__VA_ARGS__ )
    #else
        #define USB_Raw( Level, Format, ... )
        #define USB_Trace( Format, ... )
        #define USB_Debug( Format, ... )
        #define USB_Info( Format, ... )
        #define USB_Warning( Format, ... )
        #define USB_Error( Format, ... )
        #define USB_Fatal( Format, ... )
    #endif

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    typedef struct USB_Instance_Context_t USB_Instance_Context_t;

    typedef struct USB_Instance
    {
        USB_t USBx;

        union
        {
            USB_Instance_Context_t * Context;
            USB_STM32L496VGT6P_Instance_t * STM32L496VGT6P;
        };
    } USB_Instance_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    // The following APIs MUST be provided by the port
    USB_Status_t USB_IsValid( USB_t USBx );

    USB_Status_t USB_Instance_Initialize( USB_Instance_t * Instance );
    USB_Status_t USB_Instance_Cycle( USB_Instance_t * Instance );
    USB_Status_t USB_Instance_DeInitialize( USB_Instance_t * Instance );

    USB_Status_t USB_Instance_IsReady( USB_Instance_t * Instance );

    USB_Status_t USB_Instance_Write( USB_Instance_t * Instance, USB_Interface_t Interface, USB_Data_t * Data, USB_DataLength_t DataLength );
    USB_Status_t USB_Instance_Read( USB_Instance_t * Instance, USB_Interface_t Interface, USB_Data_t * Data, USB_DataLength_t DataLength );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* USB_INTERNAL_H_ */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
