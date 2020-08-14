/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * Arduino Mega with RAMPS v1.4 (or v1.3) pin assignments
 *
 * Applies to the following boards:
 *
 *  ZRIB_V1 (X-MOT, Y-MOT, Z-MOT, E0-MOT, E1-MOT, Hotend0, Hotend1, Fan, Bed)
 *  ZRIB_V2 (X-MOT, Y-MOT, Z-MOT, E0-MOT, E1-MOT, Hotend0, Hotend1, Fan, Fan2, Bed)
 *  ZRIB_V3 (X-MOT, Y-MOT, Z-MOT, E0-MOT, E1-MOT, Hotend0, Hotend1, Fan, Fan2, Bed)
 *  ZRIB_V5 (X-MOT, Y-MOT, Z-MOT, E0-MOT, E1-MOT, E2-MOT, Hotend0, Hotend1, Fan, Fan2, Bed)
 *  ZRIB_V6 (X-MOT, Y-MOT, Z-MOT, E0-MOT, E1-MOT, E2-MOT, E3-MOT, Hotend0, Hotend1, Fan, Fan2, Bed)
 */
#pragma once

#if HOTENDS > 4 || E_STEPPERS > 4
#error "ZRIB V6 supports up to 4 hotends / E-steppers. Comment out this line to continue."
#endif

#ifndef BOARD_NAME
#define BOARD_NAME "ZONESTAR ZRIB_V6"
#endif

#define BOARD_INFO_NAME "ZONESTAR ZRIB_V6"
#define BOARD_WEBSITE_URL "https://www.aliexpress.com/item/32965406396.html"

/**
                                          +-----------------------+
D0  ( AUX_PIN4   )(    RX0     ) Port: E0 |                       | Port: C2 (            )( EXP1_PIN9 ) D35
D1  ( AUX_PIN3   )(    TX0     ) Port: E1 |                       | Port: C1 (            )(E1_STEP_PIN) D36
D2  ( X_MAX_PIN  )(            ) Port: E4 |                       | Port: C0 (            )(EXP1_PIN10 ) D37
D3  ( X_MIN_PIN  )(            ) Port: E5 |                       | Port: D7 (            )( X_EN_PIN  ) D38
D4  ( XS1_PIN_1  )(            ) Port: G5 |                       | Port: G2 (            )( E2_DIR_PIN) D39
D5  ( XS1_PIN_3  )(            ) Port: E3 |                       | Port: G1 (            )(E2_STEP_PIN) D40
D6  ( FAN2_PIN   )( XS1_PIN_2  ) Port: H3 |                       | Port: G0 (            )( EXP2_PIN3 ) D41
D7  ( HEATER2_PIN)(            ) Port: H4 |                       | Port: L7 (            )( E3_EN_PI  ) D42
D8  (HEAT_BED_PIN)(            ) Port: H5 |                       | Port: L6 (            )(E2_STEP_PIN) D43
D9  (  FAN_PIN   )( LASER_PWM  ) Port: H6 |                       | Port: L5 (            )(E3_DIR_PIN ) D44
D10 ( HEATER1_PIN)(            ) Port: B4 |                       | Port: L4 (            )(           ) D45
D11 ( XS1_PIN_4  )(            ) Port: B5 |                       | Port: L3 (            )(Z_STEP_PIN ) D46
D12 ( PS_ON_PIN  )(            ) Port: B6 |                       | Port: L2 (            )(           ) D47
D13 ( LED_PIN    )(            ) Port: B7 |                       | Port: L1 (            )( Z_DIR_PIN ) D48
D14 ( Y_MIN_PIN  )(            ) Port: J1 |                       | Port: L0 (            )( EXP2_PIN4 ) D49
D15 ( Y_MAX_PIN  )(            ) Port: J0 |                       | Port: B3 (AVR_SPI_MISO)( EXP2_PIN10) D50
D16 ( EXP1_PIN_7 )(    TXD2    ) Port: H1 |                       | Port: B2 (AVR_SPI_MOSI)( EXP2_PIN5 ) D51
D17 ( EXP1_PIN_8 )(    RXD2    ) Port: H0 |                       | Port: B1 (AVR_SPI_SCK )( EXP2_PIN9 ) D52
D18 ( Z_MIN_PIN  )(            ) Port: D3 |                       | Port: B0 ( AVR_SPI_SS )( EXP2_PIN7 ) D53
D19 ( Z_MAX_PIN  )(            ) Port: D2 |       [ZRIB_V6]       | Port: F0 (     A0     )( X_STEP_PIN) D54
D20 ( AUX_PIN1   )(    SDA     ) Port: D1 |     [ATmega2560]      | Port: F1 (     A1     )( X_DIR_PI  ) D55 
D21 ( AUX_PIN2   )(    SCL     ) Port: D0 |                       | Port: F2 (     A2     )( Y_EN_PIN  ) D56 
D22 ( E2_EN_PIN  )(            ) Port: A0 |                       | Port: F3 (     A3     )( E0_SW_PI  ) D57
D23 ( EXP1_PIN6  )(            ) Port: A1 |                       | Port: F4 (     A4     )( E1_SW_PIN ) D58
D24 ( E0_EN_PIN  )(            ) Port: A2 |                       | Port: F5 (     A5     )(           ) D59
D25 ( EXP1_PIN5  )(            ) Port: A3 |                       | Port: F6 (     A6     )( Y_STEP_PIN) D60
D26 ( E0_STEP_PIN)(            ) Port: A4 |                       | Port: F7 (     A7     )( Y_DIR_PIN ) D61
D27 ( EXP1_PIN4  )(            ) Port: A5 |                       | Port: K0 (     A8     )(  Z_EN_PIN ) D62
D28 ( E0_DIR_PIN )(            ) Port: A6 |                       | Port: K1 (     A9     )(           ) D63
D29 ( EXP1_PIN3  )(            ) Port: A7 |                       | Port: K2 (     A10    )( EXP2_PIN1 ) D64  (ADC_KEYPAD_PIN)
D30 ( E1_EN_PIN  )(            ) Port: C7 |                       | Port: K3 (     A11    )(           ) D65
D31 ( EXP2_PIN8  )(            ) Port: C6 |                       | Port: K4 (     A12    )(           ) D66
D32 (            )(            ) Port: C5 |                       | Port: K5 (     A13    )(  E0_TEMP  ) D67
D33 ( EXP2_PIN6  )(            ) Port: C4 |                       | Port: K6 (     A14    )(  BED_TEMP ) D68
D34 ( E1_DIR_PIN )(            ) Port: C1 |                       | Port: K7 (     A15    )(  E1_TEMP  ) D69
                                          +-----------------------+      

                                          /**
//=========================================================================================================//
//	                                         Pins / EXP / ICSP                                             //
//=========================================================================================================//
                _____                               _____               ___
  (BEEPER) D37 | · · | D35 (MOSI_KILL)  (MISO) D50 | · · | D52 ( )     | · | SDA
 (LCD_DAT) D17 | · · | D16 (LCD_CS)        ( ) D31 | · · | D53 ( )     | · | SCL
 (LCD_CLK) D23   · · | D25 (LCD_KEN1)      ( ) D33   · · | D51 (MOSI)  | · | TX
(LCD_KEN2) D27 | · · | D29 (LCD_KENC)      ( ) D49 | · · | D41 (SS)    | · | RX
       ( ) GND | · · | +V5 ( )             ( ) GND | · · | A10 (D64)   | · | GND
                -----                               -----              | · | 5V
                EXP1                                EXP2                ---
                                                                       ICSP1                                   
**/

//=========================================================================================================//
//	                             Hardware serial communication ports.                                   //
//=========================================================================================================//

  #define RXD0                                                      0
  #define TXD0                                                      1

  #define RXD1                                                      16
  #define TXD1                                                      17
  
//=========================================================================================================//
//	                                             Limit Switches                                         //
//=========================================================================================================//

#define X_MIN_PIN                                                    3
#define X_MAX_PIN                                                    2

#define Y_MIN_PIN                                                    14
#define Y_MAX_PIN                                                    15

#define Z_MIN_PIN                                                    18
#define Z_MAX_PIN                                                    19

#define E0_SW_PIN                                                    57
#define E1_SW_PIN                                                    58
//#define Z_SAFE_HOMING
//=========================================================================================================//
//	                                     Z Probe (when not Z_MIN_PIN)                                      //
//=========================================================================================================//

#ifndef Z_MIN_PROBE_PIN
  #define Z_MIN_PROBE_PIN                                            19  //Z_MAX_PIN        
#endif

//=========================================================================================================//
//	                                                Steppers                                               //
//=========================================================================================================//

#if ENABLED(COREXY)
#define X_STEP_PIN                                                   60
#define X_DIR_PIN                                                    61
#define X_ENABLE_PIN                                                 56

#define Y_STEP_PIN                                                   54
#define Y_DIR_PIN                                                    55
#define Y_ENABLE_PIN                                                 38
#else
#define X_STEP_PIN                                                   54
#define X_DIR_PIN                                                    55
#define X_ENABLE_PIN                                                 38

#define Y_STEP_PIN                                                   60
#define Y_DIR_PIN                                                    61
#define Y_ENABLE_PIN                                                 56
#endif

#define Z_STEP_PIN                                                   46
#define Z_DIR_PIN                                                    48
#define Z_ENABLE_PIN                                                 62

#if ENABLED(Z_DUAL_STEPPER_DRIVERS)
#define Z2_STEP_PIN                                                  26
#define Z2_DIR_PIN                                                   28
#define Z2_ENABLE_PIN                                                24
#define Z2_SW_PIN                                                    57

#define E0_STEP_PIN                                                  36
#define E0_DIR_PIN                                                   34
#define E0_ENABLE_PIN                                                30

#define E1_STEP_PIN                                                  40
#define E1_DIR_PIN                                                   39
#define E1_ENABLE_PIN                                                22

#define E2_STEP_PIN                                                  43
#define E2_DIR_PIN                                                   44
#define E2_ENABLE_PIN                                                42
#else
#define E0_STEP_PIN                                                  26
#define E0_DIR_PIN                                                   28
#define E0_ENABLE_PIN                                                24

#define E1_STEP_PIN                                                  36
#define E1_DIR_PIN                                                   34
#define E1_ENABLE_PIN                                                30

#define E2_STEP_PIN                                                  40
#define E2_DIR_PIN                                                   39
#define E2_ENABLE_PIN                                                22

#define E3_STEP_PIN                                                  43
#define E3_DIR_PIN                                                   44
#define E3_ENABLE_PIN                                                42
#endif

//=========================================================================================================//
//	                                        Temperature Sensors                                            //
//=========================================================================================================//

#define TEMP_0_PIN                                                   13  // Analog Input
#define TEMP_BED_PIN                                                 14  // Analog Input
#define TEMP_1_PIN                                                   15  // Analog Input

//=========================================================================================================//
//	                                             Heaters / Fans                                            //
//=========================================================================================================//

#define HEATER_0_PIN                                                 10
#define HEATER_BED_PIN                                               8
#define HEATER_1_PIN                                                 7

#if ENABLED(USE_DUAL_HEATBED_PINS)
#error "HEATER_1_PIN has been repeated distribution for ZRIB V6!!"
#endif
#define FAN_PIN                                                      9  //Laser PWM
#define FAN1_PIN                                                     6

//=========================================================================================================//
//	                                           Misc. Functions                                             //
//=========================================================================================================//

#define SDSS                                                         53
#define LED_PIN                                                      13
#define SD_DETECT_PIN                                                49

//=========================================================================================================//
//	                                   Filament run out detection                                          //
//=========================================================================================================//

#define FILWIDTH_PIN                                                 -1  //Analog Input
#if ENABLED(Z_DUAL_STEPPER_DRIVERS)
#define FIL_RUNOUT_PIN E1_SW_PIN
#define FIL_RUNOUT2_PIN X_MAX_PIN
#else
#define FIL_RUNOUT_PIN E0_SW_PIN
#define FIL_RUNOUT2_PIN E1_SW_PIN
#endif

//=========================================================================================================//
//	                                            Power hold pin                                             //
//=========================================================================================================//

#define SUICIDE_PIN                                                  12

//=========================================================================================================//
//	                                                  Servos                                               //
//=========================================================================================================//

#define SERVO0_PIN                                                   4   //XS1(AUX3) Pin1
#define SERVO1_PIN                                                   -1  //XS1(AUX3) Pin3
#define SERVO2_PIN                                                   5   //XS1(AUX3) Pin5
#define SERVO3_PIN                                                   11  //XS1(AUX3) Pin7

//=========================================================================================================//
//	                                           Spindle & Laser contro                                      //
//=========================================================================================================//

#if ENABLED(SPINDLE_LASER_ENABLE)
//#define SPINDLE_LASER_ENABLE_PIN                                     HEATER_0_PIN
#endif

//=========================================================================================================//
//-------------------------------------------[ LCD / Controller ]------------------------------------------//
//=========================================================================================================//
//=========================================================================================================//
//	LCD 128x64                                                                                             //
//=========================================================================================================//

#if ENABLED(ZONESTAR_12864LCD)
#define LCDSCREEN_NAME                                               "ZONESTAR LCD12864"
#define LCD_SDSS                                                     RXD1
#define LCD_PINS_RS                                                  RXD1  //ST7920_CS_PIN	 LCD_PIN_RS     
#define LCD_PINS_ENABLE                                              23    //ST7920_DAT_PIN	 LCD_PIN_ENABLE
#define LCD_PINS_D4                                                  TXD1  //ST7920_CLK_PIN	 LCD_PIN_R/W   
// Alter timing for graphical display
//#define BOARD_ST7920_DELAY_1                                         DELAY_NS(96)
//#define BOARD_ST7920_DELAY_2                                         DELAY_NS(48)
//#define BOARD_ST7920_DELAY_3                                         DELAY_NS(600)
#endif

#if ENABLED(REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER)
#define LCDSCREEN_NAME                                               "Reprap LCD12864"
//USE EXP1 & EXP2 CONNECTOR
#define LCD_PINS_RS                                                  RXD1  //ST7920_CS_PIN	 LCD_PIN_RS
#define LCD_PINS_ENABLE                                              TXD1  //ST7920_DAT_PIN	 LCD_PIN_ENABLE
#define LCD_PINS_D4                                                  23    //ST7920_CLK_PIN	 LCD_PIN_R/W
// Alter timing for graphical display 
//#define BOARD_ST7920_DELAY_1                                         DELAY_NS(96)
//#define BOARD_ST7920_DELAY_2                                         DELAY_NS(48)
//#define BOARD_ST7920_DELAY_3                                         DELAY_NS(600)
#endif
#if ENABLED(CR10_STOCKDISPLAY)
#define LCDSCREEN_NAME                                               "CR10 LCD12864"
#define LCD_PINS_RS                                                  RXD1  //ST7920_CS_PIN	 LCD_PIN_RS      
#define LCD_PINS_ENABLE                                              23    //ST7920_DAT_PIN	 LCD_PIN_ENABLE
#define LCD_PINS_D4                                                  TXD1  //ST7920_CLK_PIN	 LCD_PIN_R/W    
// Alter timing for graphical display
//#define BOARD_ST7920_DELAY_1                                         DELAY_NS(96)
//#define BOARD_ST7920_DELAY_2                                         DELAY_NS(48)
//#define BOARD_ST7920_DELAY_3                                         DELAY_NS(600)
#endif

#if ENABLED(MKS_MINI_12864)
#define LCDSCREEN_NAME                                               "MKS MINI12864"
#define DOGLCD_CS                                                    25
#define DOGLCD_A0                                                    27
#endif
//=========================================================================================================//
//	                                              OLED 128x64                                              //
//=========================================================================================================//

#if ENABLED(ZONESTAR_OLED12864)
#define LCDSCREEN_NAME                                               "ZONESTAR OLED12864"
#define LCD_SDSS                                                     RXD1
#define LCD_PINS_RS                                                  23    //RESET Pull low for 1s to init
#define LCD_PINS_DC                                                  TXD1  //
#define DOGLCD_CS                                                    RXD1  //CS
#if ENABLED(OLED_HW_IIC)
//IIC
#error "Oops!  must choose SW SPI for ZRIB board and connect the OLED screen to EXP1 connector"
#elif ENABLED(OLED_HW_SPI)
//HW_SPI
#error "Oops!  must choose SW SPI for ZRIB board and connect the OLED screen to EXP1 connector"
#else
//SW_SPI
#define DOGLCD_A0 LCD_PINS_DC                                            //DC
#define DOGLCD_MOSI                                                  35  //SDA
#define DOGLCD_SCK                                                   37  //SCK
#endif
#endif //OLED 128x64

//=========================================================================================================//
//	                                              LCD 2004                                                 //
//=========================================================================================================/

#if ENABLED(ZONESTAR_LCD2004_ADCKEY) || ENABLED(ZONESTAR_LCD2004_KNOB)
#define LCDSCREEN_NAME                                               "LCD 2004"
#define LCD_PINS_RS                                                  RXD1
#define LCD_PINS_ENABLE                                              TXD1
#define LCD_PINS_D4                                                  23
#define LCD_PINS_D5                                                  25
#define LCD_PINS_D6                                                  27
#define LCD_PINS_D7                                                  29
#endif

//=========================================================================================================//
//	                                              KEYPAD                                                   //
//=========================================================================================================//

#if ENABLED(ZONESTAR_LCD2004_ADCKEY)
#define ADC_KEYPAD_PIN                                               10  //A10 for ADCKEY
#undef LCDSCREEN_NAME
#define LCDSCREEN_NAME                                               "LCD2004 ADCKEY"
#endif

#if ENABLED(REPRAP_DISCOUNT_SMART_CONTROLLER)
#if ENABLED(CR10_STOCKDISPLAY)
#define BTN_EN2                                                      25
#define BTN_EN1                                                      27
#define BTN_ENC                                                      29
#define BEEPER_PIN                                                   37
#define KILL_PIN                                                     35
#elif ENABLED(ZONESTAR_12864LCD)
#define BTN_EN2                                                      25
#define BTN_EN1                                                      27
#define BTN_ENC                                                      29
#define BEEPER_PIN                                                   37
#define KILL_PIN                                                     35
#elif ENABLED(ZONESTAR_12864OLED)
#define BTN_EN2                                                      25
#define BTN_EN1                                                      27
#define BTN_ENC                                                      29
#define BEEPER_PIN                                                   -1
#define KILL_PIN                                                     -1
#elif ENABLED(REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER)
#define BTN_EN2                                                      31
#define BTN_EN1                                                      33
#define BTN_ENC                                                      35
#define BEEPER_PIN                                                   37
#define KILL_PIN                                                     41
#elif ENABLED(ZONESTAR_LCD2004_KNOB)
#define BTN_EN1                                                      31
#define BTN_EN2                                                      33
#define BTN_ENC                                                      35
#define BEEPER_PIN                                                   37
#define KILL_PIN                                                     41
#endif
#endif

//=========================================================================================================//
//	                                      End of LCD / Controller                                          //
//=========================================================================================================//

#if ENABLED(SWAP_E0T_E1T)
#undef TEMP_0_PIN
#undef TEMP_BED_PIN
#undef TEMP_1_PIN
#define TEMP_0_PIN                                                   15  // Analog Input
#define TEMP_BED_PIN                                                 14  // Analog Input
#define TEMP_1_PIN                                                   13  // Analog Input
#elif ENABLED(SWAP_E1T_BEDT)
#undef TEMP_0_PIN
#undef TEMP_BED_PIN
#undef TEMP_1_PIN
#define TEMP_0_PIN                                                   13  // Analog Input
#define TEMP_BED_PIN                                                 15  // Analog Inpu
#define TEMP_1_PIN                                                   14  // Analog Input
#endif
#if ENABLED(SWAP_XP_ZN)
#undef X_MAX_PIN
#undef Z_MIN_PIN
#define Z_MIN_PIN                                                    18
#define X_MAX_PIN                                                    2
#endif
