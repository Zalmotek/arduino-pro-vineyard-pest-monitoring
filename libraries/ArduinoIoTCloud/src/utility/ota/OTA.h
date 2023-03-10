/*
   This file is part of ArduinoIoTCloud.

   Copyright 2020 ARDUINO SA (http://www.arduino.cc/)

   This software is released under the GNU General Public License version 3,
   which covers the main part of arduino-cli.
   The terms of this license can be found at:
   https://www.gnu.org/licenses/gpl-3.0.en.html

   You can be released from the requirements of the above licenses by purchasing
   a commercial license. Buying such a license is mandatory if you want to modify or
   otherwise use the software for commercial activities involving the Arduino
   software without disclosing the source code of your own applications. To purchase
   a commercial license, send an email to license@arduino.cc.
*/

#ifndef ARDUINO_OTA_LOGIC_H_
#define ARDUINO_OTA_LOGIC_H_

/******************************************************************************
 * INCLUDE
 ******************************************************************************/

#include <AIoTC_Config.h>
#include <Arduino.h>

/******************************************************************************
 * DEFINES
 ******************************************************************************/

#define RP2040_OTA_ERROR_BASE (-100)

/******************************************************************************
 * TYPEDEF
 ******************************************************************************/

enum class OTAError : int
{
  None           = 0,
  DownloadFailed = 1,
  RP2040_UrlParseError        = RP2040_OTA_ERROR_BASE - 0,
  RP2040_ServerConnectError   = RP2040_OTA_ERROR_BASE - 1,
  RP2040_HttpHeaderError      = RP2040_OTA_ERROR_BASE - 2,
  RP2040_HttpDataError        = RP2040_OTA_ERROR_BASE - 3,
  RP2040_ErrorOpenUpdateFile  = RP2040_OTA_ERROR_BASE - 4,
  RP2040_ErrorWriteUpdateFile = RP2040_OTA_ERROR_BASE - 5,
  RP2040_ErrorParseHttpHeader = RP2040_OTA_ERROR_BASE - 6,
  RP2040_ErrorFlashInit       = RP2040_OTA_ERROR_BASE - 7,
  RP2040_ErrorReformat        = RP2040_OTA_ERROR_BASE - 8,
  RP2040_ErrorUnmount         = RP2040_OTA_ERROR_BASE - 9,
};

/******************************************************************************
 * FUNCTION DEFINITION
 ******************************************************************************/

#ifdef ARDUINO_ARCH_SAMD
int samd_onOTARequest(char const * ota_url);
String samd_getOTAImageSHA256();
#endif

#ifdef ARDUINO_NANO_RP2040_CONNECT
int rp2040_connect_onOTARequest(char const * ota_url);
String rp2040_connect_getOTAImageSHA256();
#endif

#ifdef BOARD_STM32H7
int portenta_h7_onOTARequest(char const * ota_url, const bool use_ethernet);
String portenta_h7_getOTAImageSHA256();
#endif

#ifdef ARDUINO_ARCH_ESP32
int esp32_onOTARequest(char const * ota_url);
String esp32_getOTAImageSHA256();
#endif

#endif /* ARDUINO_OTA_LOGIC_H_ */
