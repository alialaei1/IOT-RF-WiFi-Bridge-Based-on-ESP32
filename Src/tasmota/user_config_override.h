/*
  user_config_override.h - user configuration overrides my_user_config.h for Tasmota

  Copyright (C) 2021  Theo Arends

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_



#define PROJECT                "nilinet_rft_v1"



#define MODULE                 RFTV1//SONOFF_BASIC      // [Module] Select default module from tasmota_template.h
//#ifdef ESP8266
#define FALLBACK_MODULE        RFTV1//SONOFF_BASIC      // [Module2] Select default module on fast reboot where USER_MODULE is user template
//#define USER_TEMPLATE "{\"NAME\":\"Generic\",\"GPIO\":[1,1,1,1,1,1,1,1,1,1,1,1,1,1],\"FLAG\":0,\"BASE\":18}"  // [Template] Set JSON template
//#endif  // ESP8266



//#define MODULE                 RFTV1
//#define FALLBACK_MODULE        RFTV1

//#define USER_TEMPLATE "{\"NAME\":\"Generic\",\"GPIO\":[1,1,1,1,1,1,1,1,1,1,1,1,1,1],\"FLAG\":0,\"BASE\":18}"  // [Template] Set JSON template

#define STA_SSID1              ""
#define STA_PASS1              ""
#define STA_SSID2              ""
#define STA_PASS2              ""

#define MQTT_HOST              "nilinetdevice.ir"

#define MQTT_USER              "FF100YY414OG"
#define MQTT_PASS              "WT744DJ425OR"


#define MQTT_FULLTOPIC         "nilinet/sensor/security/rft/v1-0/%topic%/%prefix%/"

// %prefix% token options
#define SUB_PREFIX             "cmd"//"cmnd"
#define PUB_PREFIX             "sta"//"stat"
#define PUB_PREFIX2            "tel"//"tele" 


#define MQTT_TOPIC             PROJECT "_%12X"
#define MQTT_GRPTOPIC          "nilinet_rft_v1"
#define MQTT_GROUPTOPIC_FORMAT false
#define MQTT_BUTTON_TOPIC      "0"
#define MQTT_SWITCH_TOPIC      "0"
#define MQTT_CLIENT_ID         PROJECT "_%12X"   //"DVES_%12X"



#define TELE_PERIOD            0 //30
#define TELE_ON_POWER          false  


#define MQTT_RESULT_COMMAND    true //false 
#define MQTT_LWT_MESSAGE       false //false  


#define WEB_PASSWORD           ""
#define FRIENDLY_NAME          "NILINET"


#define NTP_SERVER1            "time-a.nist.gov"
#define NTP_SERVER2            "server3.ir.pool.ntp.org"
#define NTP_SERVER3            "server1.asia.pool.ntp.org"


#define TIME_DST_HEMISPHERE    North
#define TIME_DST_WEEK          Last
#define TIME_DST_DAY           Sun
#define TIME_DST_MONTH         Mar
#define TIME_DST_HOUR          2
#define TIME_DST_OFFSET        +270


#define TIME_STD_HEMISPHERE    North
#define TIME_STD_WEEK          Last
#define TIME_STD_DAY           Sun
#define TIME_STD_MONTH         Oct
#define TIME_STD_HOUR          3
#define TIME_STD_OFFSET        +210


#define LATITUDE               35.689167
#define LONGITUDE              51.388889


#define APP_TIMEZONE           99  


#define KEY_DEBOUNCE_TIME      120
#define KEY_HOLD_TIME          7 


#define SWITCH_DEBOUNCE_TIME   350
#define SWITCH_MODE            FOLLOW


#define MQTT_LWT_OFFLINE       "{\"Event\":\"Offline\"}"         // MQTT LWT offline topic message
#define MQTT_LWT_ONLINE        "{\"Event\":\"Online\"}"     


#define WEB_USERNAME         ""

#define USE_RC_SWITCH

//#define USE_RF_SENSOR

#define USE_RULES
#define USE_EXPRESSION
#define SUPPORT_IF_STATEMENT
//#define USER_RULE1 "<Any rule1 data>"
//#define USER_RULE2 "<Any rule2 data>"
//#define USER_RULE3 "<Any rule3 data>"  




/*****************************************************************************************************\
 * USAGE:
 *   To modify the stock configuration without changing the my_user_config.h file:
 *   (1) copy this file to "user_config_override.h" (It will be ignored by Git)
 *   (2) define your own settings below
 *
 ******************************************************************************************************
 * ATTENTION:
 *   - Changes to SECTION1 PARAMETER defines will only override flash settings if you change define CFG_HOLDER.
 *   - Expect compiler warnings when no ifdef/undef/endif sequence is used.
 *   - You still need to update my_user_config.h for major define USE_MQTT_TLS.
 *   - All parameters can be persistent changed online using commands via MQTT, WebConsole or Serial.
\*****************************************************************************************************/

/*
Examples :

// -- Master parameter control --------------------
#undef  CFG_HOLDER
#define CFG_HOLDER        4617                   // [Reset 1] Change this value to load SECTION1 configuration parameters to flash

// -- Setup your own Wifi settings  ---------------
#undef  STA_SSID1
#define STA_SSID1         "YourSSID"             // [Ssid1] Wifi SSID

#undef  STA_PASS1
#define STA_PASS1         "YourWifiPassword"     // [Password1] Wifi password

// -- Setup your own MQTT settings  ---------------
#undef  MQTT_HOST
#define MQTT_HOST         "your-mqtt-server.com" // [MqttHost]

#undef  MQTT_PORT
#define MQTT_PORT         1883                   // [MqttPort] MQTT port (10123 on CloudMQTT)

#undef  MQTT_USER
#define MQTT_USER         "YourMqttUser"         // [MqttUser] Optional user

#undef  MQTT_PASS
#define MQTT_PASS         "YourMqttPass"         // [MqttPassword] Optional password

// You might even pass some parameters from the command line ----------------------------
// Ie:  export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE -DMY_IP="192.168.1.99" -DMY_GW="192.168.1.1" -DMY_DNS="192.168.1.1"'

#ifdef MY_IP
#undef  WIFI_IP_ADDRESS
#define WIFI_IP_ADDRESS     MY_IP                // Set to 0.0.0.0 for using DHCP or enter a static IP address
#endif

#ifdef MY_GW
#undef  WIFI_GATEWAY
#define WIFI_GATEWAY        MY_GW                // if not using DHCP set Gateway IP address
#endif

#ifdef MY_DNS
#undef  WIFI_DNS
#define WIFI_DNS            MY_DNS               // If not using DHCP set DNS IP address (might be equal to WIFI_GATEWAY)
#endif

// !!! Remember that your changes GOES AT THE BOTTOM OF THIS FILE right before the last #endif !!! 
*/





#endif  // _USER_CONFIG_OVERRIDE_H_
