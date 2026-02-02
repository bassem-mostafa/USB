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

/**
 *  @file
 *
 *  @brief Platform USB Module
 */

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

/**
 *  @addtogroup Platform_Module
 *
 *  @{
 */

/**
 *  @defgroup Platform_USB USB
 *
 *  @note Default port is STUB if Unspecified
 *
 *  @{
 */

/**
 *  @defgroup Platform_USB_Driver Driver
 *
 *  @{
 *  @}
 */

#ifndef USB_H_
    #define USB_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "USB_Port.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    /**
     *  @brief USB Operation Status
     *
     *  @enum USB_Status_t
     */
    typedef enum USB_Status
    {
        USB_Status_Success = 0,     ///< Success
        USB_Status_ArgumentInvalid, ///< Argument Invalid
        USB_Status_NotSupported,    ///< Not Supported
        USB_Status_Error,           ///< General Error
        USB_Status_Busy,            ///< Busy
        USB_Status_Timeout,         ///< Timeout
    } USB_Status_t;

    /**
     *  @brief USB Data Type
     */
    typedef uint8_t USB_Data_t;

    /**
     *  @brief USB Data Length Type
     */
    typedef uint32_t USB_DataLength_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    /**
     *  @brief Initialize USB peripheral
     *
     *  @note MUST BE called before using any USB API
     *
     *  @param[in] USBx Peripheral
     *
     *  @return USB_Status_t
     */
    USB_Status_t USB_Initialize( USB_t USBx );

    /**
     *  @brief Cycle USB peripheral
     *
     *  @param[in] USBx Peripheral
     *
     *  @return USB_Status_t
     */
    USB_Status_t USB_Cycle( USB_t USBx );

    /**
     *  @brief De-Initialize USB peripheral
     *
     *  @param[in] USBx Peripheral
     *
     *  @return USB_Status_t
     */
    USB_Status_t USB_DeInitialize( USB_t USBx );

    /**
     *  @brief Write data to USB peripheral
     *
     *  @param[in] USBx       Peripheral
     *  @param[in] Data       Data buffer
     *  @param[in] DataLength Length of data buffer
     *
     *  @return USB_Status_t
     */
    USB_Status_t USB_Write( USB_t USBx, USB_Data_t * Data, USB_DataLength_t DataLength );

    /**
     *  @brief Read data from USB peripheral
     *
     *  @param[in] USBx       Peripheral
     *  @param[in] Data       Data buffer
     *  @param[in] DataLength Length of data buffer
     *
     *  @return USB_Status_t
     */
    USB_Status_t USB_Read( USB_t USBx, USB_Data_t * Data, USB_DataLength_t DataLength );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    /**
     *  @brief Version
     */
    extern const char USB_VERSION[];

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* USB_H_ */

/**
 *  @}
 *
 *  @}
 */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
