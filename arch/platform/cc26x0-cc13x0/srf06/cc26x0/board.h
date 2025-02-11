/*
 * Copyright (c) 2014, Texas Instruments Incorporated - http://www.ti.com/
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*---------------------------------------------------------------------------*/
/** \addtogroup cc26xx-srf-tag
 * @{
 *
 * \defgroup cc26x0-cc13x0-peripherals Peripherals for the SmartRF06EB + CC26xxEM
 *
 * Defines related to the SmartRF06 Evaluation Board with a CC26xxEM
 *
 * This file provides connectivity information on LEDs, Buttons, UART and
 * other peripherals
 *
 * This file can be used as the basis to configure other boards using the
 * CC13xx/CC26xx code as their basis.
 *
 * This file is not meant to be modified by the user.
 * @{
 *
 * \file
 * Header file with definitions related to the I/O connections on the TI
 * SmartRF06 Evaluation Board with a CC26xxEM
 *
 * \note   Do not include this file directly. It gets included by contiki-conf
 *         after all relevant directives have been set.
 */
/*---------------------------------------------------------------------------*/
#ifndef BOARD_H_
#define BOARD_H_
/*---------------------------------------------------------------------------*/
#include "ioc.h"
/*---------------------------------------------------------------------------*/
/**
 * \name LED HAL configuration
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define LEDS_CONF_COUNT                 3
#define LEDS_CONF_YELLOW                1
#define LEDS_CONF_VLED1                 2
#define LEDS_CONF_VLED2                 4
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name LED IOID mappings
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_LED_1          IOID_20
#define BOARD_IOID_LED_2          IOID_13
#define BOARD_IOID_LED_3          IOID_14
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name UART IOID mapping
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_UART_RX        IOID_2
#define BOARD_IOID_UART_TX        IOID_3
#define BOARD_IOID_UART_CTS       IOID_9
#define BOARD_IOID_UART_RTS       IOID_8
#define BOARD_UART_RX             (1 << BOARD_IOID_UART_RX)
#define BOARD_UART_TX             (1 << BOARD_IOID_UART_TX)
#define BOARD_UART_CTS            (1 << BOARD_IOID_UART_CTS)
#define BOARD_UART_RTS            (1 << BOARD_IOID_UART_RTS)
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name Button IOID mapping
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_KEY_LEFT       ((int)IOID_UNUSED)
#define BOARD_IOID_KEY_RIGHT      ((int)IOID_UNUSED)
#define BOARD_IOID_KEY_UP         ((int)IOID_UNUSED)
#define BOARD_IOID_KEY_DOWN       ((int)IOID_UNUSED)
#define BOARD_IOID_KEY_SELECT     IOID_11
#define BOARD_KEY_LEFT            (1 << BOARD_IOID_KEY_LEFT)
#define BOARD_KEY_RIGHT           (1 << BOARD_IOID_KEY_RIGHT)
#define BOARD_KEY_UP              (1 << BOARD_IOID_KEY_UP)
#define BOARD_KEY_DOWN            (1 << BOARD_IOID_KEY_DOWN)
#define BOARD_KEY_SELECT          (1 << BOARD_IOID_KEY_SELECT)
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name 3.3V domain IOID mapping
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_3V3_EN         ((int)IOID_UNUSED)
#define BOARD_3V3_EN              (1 << BOARD_IOID_3V3_EN)
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name SPI IOID mapping
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_SPI_SCK        ((int)IOID_UNUSED)
#define BOARD_IOID_SPI_MOSI       ((int)IOID_UNUSED)
#define BOARD_IOID_SPI_MISO       ((int)IOID_UNUSED)
#define BOARD_SPI_SCK             (1 << BOARD_IOID_SPI_SCK)
#define BOARD_SPI_MOSI            (1 << BOARD_IOID_SPI_MOSI)
#define BOARD_SPI_MISO            (1 << BOARD_IOID_SPI_MISO)
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name LCD IOID mapping
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_LCD_MODE       ((int)IOID_UNUSED)
#define BOARD_IOID_LCD_RST        ((int)IOID_UNUSED)
#define BOARD_IOID_LCD_CS         ((int)IOID_UNUSED)
#define BOARD_IOID_LCD_SCK        BOARD_IOID_SPI_SCK
#define BOARD_IOID_LCD_MOSI       BOARD_IOID_SPI_MOSI
#define BOARD_LCD_MODE            (1 << BOARD_IOID_LCD_MODE)
#define BOARD_LCD_RST             (1 << BOARD_IOID_LCD_RST)
#define BOARD_LCD_CS              (1 << BOARD_IOID_LCD_CS)
#define BOARD_LCD_SCK             BOARD_SPI_SCK
#define BOARD_LCD_MOSI            BOARD_SPI_MOSI
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name SD Card IOID mapping
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_SDCARD_CS      ((int)IOID_UNUSED)
#define BOARD_SDCARD_CS           (1 << BOARD_IOID_SDCARD_CS)
#define BOARD_IOID_SDCARD_SCK     BOARD_IOID_SPI_SCK
#define BOARD_SDCARD_SCK          BOARD_SPI_SCK
#define BOARD_IOID_SDCARD_MOSI    BOARD_IOID_SPI_MOSI
#define BOARD_SDCARD_MOSI         BOARD_SPI_MOSI
#define BOARD_IOID_SDCARD_MISO    BOARD_IOID_SPI_MISO
#define BOARD_SDCARD_MISO         BOARD_SPI_MISO
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name ALS IOID mapping
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_ALS_PWR        IOID_26
#define BOARD_IOID_ALS_OUT        IOID_23
#define BOARD_ALS_PWR             (1 << BOARD_IOID_ALS_PWR)
#define BOARD_ALS_OUT             (1 << BOARD_IOID_ALS_OUT)
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name ACC IOID mapping
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_IOID_ACC_PWR        IOID_20
#define BOARD_IOID_ACC_INT        IOID_28
#define BOARD_IOID_ACC_INT1       IOID_28
#define BOARD_IOID_ACC_INT2       IOID_29
#define BOARD_IOID_ACC_CS         IOID_24
#define BOARD_ACC_PWR             (1 << BOARD_IOID_ACC_PWR)
#define BOARD_ACC_INT             (1 << BOARD_IOID_ACC_INT)
#define BOARD_ACC_INT1            (1 << BOARD_IOID_ACC_INT1)
#define BOARD_ACC_INT2            (1 << BOARD_IOID_ACC_INT2)
#define BOARD_ACC_CS              (1 << BOARD_IOID_ACC_CS)
#define BOARD_IOID_ACC_SCK        BOARD_IOID_SPI_SCK
#define BOARD_ACC_SCK             BOARD_SPI_SCK
#define BOARD_IOID_ACC_MOSI       BOARD_IOID_SPI_MOSI
#define BOARD_ACC_MOSI            BOARD_SPI_MOSI
#define BOARD_IOID_ACC_MISO       BOARD_IOID_SPI_MISO
#define BOARD_ACC_MISO            BOARD_SPI_MISO
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \brief ROM bootloader configuration
 *
 * Change CCFG_CONF_BL_PIN_NUMBER to BOARD_IOID_KEY_xyz to select which
 * button triggers the bootloader on reset. Use CCFG_CONF_BL_LEVEL to
 * control the pin level that enables the bootloader (0: low, 1: high). It is
 * also possible to use any other externally-controlled DIO.
 * @{
 */
#define CCFG_CONF_BL_PIN_NUMBER   BOARD_IOID_KEY_SELECT
#define CCFG_CONF_BL_LEVEL        0
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \brief Board indices for the button HAL
 *
 * Those values are not meant to be modified by the user
 * @{
 */
#define BOARD_BUTTON_HAL_INDEX_KEY_LEFT   0x00
#define BOARD_BUTTON_HAL_INDEX_KEY_RIGHT  0x01
#define BOARD_BUTTON_HAL_INDEX_KEY_UP     0x02
#define BOARD_BUTTON_HAL_INDEX_KEY_DOWN   0x03
#define BOARD_BUTTON_HAL_INDEX_KEY_SELECT 0x04
/** @} */
/*---------------------------------------------------------------------------*/
/**
 * \name Device string used on startup
 * @{
 */
#define BOARD_STRING "TI SmartRF06EB + CC26xx EM"
/** @} */
/*---------------------------------------------------------------------------*/
#endif /* BOARD_H_ */
/*---------------------------------------------------------------------------*/
/**
 * @}
 * @}
 */
