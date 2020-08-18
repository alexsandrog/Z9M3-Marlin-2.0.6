/**
 * Firmware da impressora Marlin 3D
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Baseado em Sprinter e grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * Este programa é um software livre: você pode redistribuí-lo e / ou modificar
 * sob os termos da GNU General Public License publicada por
 * a Free Software Foundation, seja a versão 3 da Licença, ou
 * (à sua escolha) qualquer versão posterior.
 *
 * Este programa é distribuído na esperança de ser útil,
 * mas SEM QUALQUER GARANTIA; sem mesmo a garantia implícita de
 * COMERCIALIZAÇÃO ou ADEQUAÇÃO A UM DETERMINADO FIM. Veja o
 * GNU General Public License para mais detalhes.
 *
 * Você deve ter recebido uma cópia da GNU General Public License
 * junto com este programa. Caso contrário, consulte <https://www.gnu.org/licenses/>.
 *
 */

// teste 
#pragma once

/**
 * Configuration.h
 *
 * Configurações básicas, como:
 *
 * - Tipo de eletrônica
 * - Tipo de sensor de temperatura
 * - Geometria da impressora
 * - Configuração de parada final
 * - controlador LCD
 * - Recursos extras
 *
 * As configurações avançadas podem ser encontradas em Configuration_adv.h
 *
 */
#define CONFIGURATION_H_VERSION 020006

//===========================================================================
//============================= Getting Started =============================
//===========================================================================

/**
 * Aqui estão alguns links padrão para calibrar sua máquina:
 *
 * https://reprap.org/wiki/Calibration
 * https://youtu.be/wAL9d7FgInk
 * http://calculator.josefprusa.cz
 * https://reprap.org/wiki/Triffid_Hunter%27s_Calibration_Guide
 * https://www.thingiverse.com/thing:5573
 * https://sites.google.com/site/repraplogphase/calibration-of-your-reprap
 * https://www.thingiverse.com/thing:298812
 */

//===========================================================================
//============================= DELTA Printer ===============================
//===========================================================================
// Para uma impressora Delta, comece com um dos arquivos de configuração no
// diretório config / examples / delta e personalizar para sua máquina.
//

//===========================================================================
//============================= SCARA Printer ===============================
//===========================================================================
// Para uma impressora SCARA, comece com os arquivos de configuração em
// config / examples / SCARA e customize para sua máquina.
//

// @section info

// As informações do autor desta construção foram impressas no host durante a inicialização e M115
#define STRING_CONFIG_H_AUTHOR "(Alexsandro , Gonçalves)" // Quem fez as alterações.
//#define CUSTOM_VERSION_FILE Version.h // Caminho do diretório raiz (sem aspas)

/**
 * *** VENDEDORES, LEIA ***
 *
 * Marlin permite adicionar uma imagem de inicialização personalizada para LCDs gráficos.
 * Com esta opção, o Marlin primeiro mostrará sua tela personalizada seguida
 * pelo logotipo padrão da Marlin com número de versão e URL da web.
 *
 * Incentivamos você a aproveitar as vantagens desse novo recurso e também
 * Solicite respeitosamente que você guarde a tela de inicialização do Marlin não modificada.
 */

// Mostra a tela de inicialização do Marlin na inicialização.** ATIVAR PARA PRODUÇÃO **

#define SHOW_BOOTSCREEN

// Mostre o bitmap em Marlin /_Bootscreen.h na inicialização.
//#define SHOW_CUSTOM_BOOTSCREEN

// Mostre o bitmap em Marlin /_Statusscreen.h na tela de status.
//#define CUSTOM_STATUS_SCREEN_IMAGE

// @section machine

/**
 * Selecione a porta serial na placa a ser usada para comunicação com o host.
 * Isso permite a conexão de adaptadores sem fio (por exemplo) a pinos de porta não padrão.
 * A porta serial -1 é a porta serial emulada USB, se disponível.
 * Nota: A primeira porta serial (-1 ou 0) sempre será usada pelo bootloader Arduino.
 *
 * :[-1, 0, 1, 2, 3, 4, 5, 6, 7]
 */
#define SERIAL_PORT 0

/**
 * Selecione uma porta serial secundária na placa para usar para comunicação com o host.
 * :[-1, 0, 1, 2, 3, 4, 5, 6, 7]
 */
//#define SERIAL_PORT_2 1

/**
 * Esta configuração determina a velocidade de comunicação da impressora.
 *
 * 250000 funciona na maioria dos casos, mas você pode tentar uma velocidade menor se
 * você normalmente enfrenta falhas durante a impressão do host.
 * Você pode tentar até 1000000 para acelerar a transferência de arquivos SD.
 *
 * :[2400, 9600, 19200, 38400, 57600, 115200, 250000, 500000, 1000000]
 */
#define BAUDRATE 250000

// Habilite a interface serial Bluetooth em dispositivos AT90USB
//#define BLUETOOTH

// Escolha o nome em boards.h que corresponde à sua configuração
#ifndef MOTHERBOARD
  #define MOTHERBOARD BOARD_ZRIB_V6
#endif

// Nome exibido na mensagem "Pronto" do LCD e no menu Informações
#define CUSTOM_MACHINE_NAME "AG-Z9"

// ID exclusivo da impressora, usado por alguns programas para diferenciar as máquinas.
// Escolha o seu próprio ou use um serviço como https://www.uuidgenerator.net/version4
//#define MACHINE_UUID "f45ad8e5-1ab5-4302-9163-7c2d33d50ca8"

// @section extruder

// Isso define o número de extrusoras
// :[0, 1, 2, 3, 4, 5, 6, 7, 8]
#define EXTRUDERS 1

// Diâmetro do filamento geralmente esperado (1,75, 2,85, 3,0, ...). Usado para sensor volumétrico, de largura de filamento, etc.
#define DEFAULT_NOMINAL_FILAMENT_DIA 1.75

// Para Cyclops ou qualquer "multi-extrusora" que compartilha um único bico.
//#define SINGLENOZZLE

// Salve e restaure a temperatura e a velocidade do ventilador na troca da ferramenta.
// Defina o modo de espera para a ferramenta não selecionada com M104 / 106/109 T ...
#if ENABLED(SINGLENOZZLE)
  //#define SINGLENOZZLE_STANDBY_TEMP
  //#define SINGLENOZZLE_STANDBY_FAN
#endif

/**
 * Průša MK2 Multiplexador multimaterial de bico único e variantes.
 *
 * Este dispositivo permite que um driver de passo em uma placa de controle conduza
 * dois a oito motores de passo, um de cada vez, de maneira adequada
 * para extrusoras.
 *
 * Esta opção permite apenas que o multiplexador ligue a troca de ferramentas.
 * Opções adicionais para configurar movimentos E personalizados estão pendentes.
 */
//#define MK2_MULTIPLEXER
#if ENABLED(MK2_MULTIPLEXER)
  // Override the default DIO selector pins here, if needed.
  // Some pins files may provide defaults for these pins.
  //#define E_MUX0_PIN 40  // Always Required
  //#define E_MUX1_PIN 42  // Needed for 3 to 8 inputs
  //#define E_MUX2_PIN 44  // Needed for 5 to 8 inputs
#endif

/**
 * Unidade Multi-Material Prusa v2
 *
 * Requer NOZZLE_PARK_FEATURE para estacionar a cabeça de impressão em caso de falha da unidade MMU.
 * Requer EXTRUDERS = 5
 *
 * Para configuração adicional, consulte Configuration_adv.h
 */
//#define PRUSA_MMU2

// Uma extrusora dupla que usa um único motor de passo
//#define SWITCHING_EXTRUDER
#if ENABLED(SWITCHING_EXTRUDER)
  #define SWITCHING_EXTRUDER_SERVO_NR 0
  #define SWITCHING_EXTRUDER_SERVO_ANGLES { 0, 90 } // Angles for E0, E1[, E2, E3]
  #if EXTRUDERS > 3
    #define SWITCHING_EXTRUDER_E23_SERVO_NR 1
  #endif
#endif

// Um bico duplo que usa um servo motor para elevar / abaixar um (ou ambos) dos bicos
//#define SWITCHING_NOZZLE
#if ENABLED(SWITCHING_NOZZLE)
  #define SWITCHING_NOZZLE_SERVO_NR 0
  //#define SWITCHING_NOZZLE_E1_SERVO_NR 1          // Se dois servos forem usados, o índice do segundo
  #define SWITCHING_NOZZLE_SERVO_ANGLES { 0, 90 }   // Ângulos para E0, E1 (servo único) ou abaixado / elevado (servo duplo)
#endif

/**
 * Dois carros X separados com extrusoras que se conectam a uma parte móvel
 * por meio de um mecanismo de acoplamento por solenóide. Requer SOL1_PIN e SOL2_PIN.
 */
//#define PARKING_EXTRUDER

/**
 * Dois carros X separados com extrusoras que se conectam a uma parte móvel
 * através de um mecanismo de acoplamento magnético usando movimentos e sem solenóide
 *
 * projeto: https://www.thingiverse.com/thing:3080893
 * movimentos: https://youtu.be/0xCEiG9VS3k
 * https://youtu.be/Bqbcs0CU2FE
 */
//#define MAGNETIC_PARKING_EXTRUDER

#if EITHER(PARKING_EXTRUDER, MAGNETIC_PARKING_EXTRUDER)

  #define PARKING_EXTRUDER_PARKING_X { -78, 184 }     // Posições X para estacionar as extrusoras
  #define PARKING_EXTRUDER_GRAB_DISTANCE 1            // (mm) Distância para mover além do ponto de estacionamento para agarrar a extrusora
  //#define MANUAL_SOLENOID_CONTROL                   // Controle manual de solenóides de encaixe com M380 S / M381

  #if ENABLED(PARKING_EXTRUDER)

    #define PARKING_EXTRUDER_SOLENOIDS_INVERT           // Se habilitado, o solenóide NÃO é magnetizado com a tensão aplicada
    #define PARKING_EXTRUDER_SOLENOIDS_PINS_ACTIVE LOW  // Sinal de pino BAIXO ou ALTO energiza a bobina
    #define PARKING_EXTRUDER_SOLENOIDS_DELAY 250        // (ms) Atraso para campo magnético. Sem atraso se 0 ou não definido.
    //#define MANUAL_SOLENOID_CONTROL                   // Controle manual de solenóides de encaixe com M380 S / M381

  #elif ENABLED(MAGNETIC_PARKING_EXTRUDER)

    #define MPE_FAST_SPEED      9000      // (mm / m) Velocidade para viajar antes do último ponto de distância
    #define MPE_SLOW_SPEED      4500      // (mm / m) Velocidade para a viagem de última distância para estacionar e acoplar
    #define MPE_TRAVEL_DISTANCE   10      // (mm) Último ponto de distância
    #define MPE_COMPENSATION       0      // Compensação de deslocamento -1, 0, 1 (multiplicador) apenas para acoplamento

  #endif

#endif

/**
 * Switching Toolhead
 *
 * Suporte para cabeçotes de ferramentas trocáveis e encaixáveis, como
 * Trocador de ferramentas E3D. Cabeças de ferramentas são travadas com um servo 
 */
//#define SWITCHING_TOOLHEAD

/**
 * Magnetic Switching Toolhead
 *
 * Suporta cabeçotes de ferramentas trocáveis e encaixáveis com um magnético
 * mecanismo de encaixe usando movimento e sem servo.
 */
//#define MAGNETIC_SWITCHING_TOOLHEAD

/**
 * Electromagnetic Switching Toolhead
 *
 * Estacionamento para cinemática CoreXY / HBot.
 * Cabeças de ferramentas são estacionadas em uma borda e seguradas com um eletroímã.
 * Suporta mais de 2 cabeçotes de ferramenta. Veja https://youtu.be/JolbsAKTKf4
 */
//#define ELECTROMAGNETIC_SWITCHING_TOOLHEAD

#if ANY(SWITCHING_TOOLHEAD, MAGNETIC_SWITCHING_TOOLHEAD, ELECTROMAGNETIC_SWITCHING_TOOLHEAD)
  #define SWITCHING_TOOLHEAD_Y_POS          235         // (mm) Y position of the toolhead dock
  #define SWITCHING_TOOLHEAD_Y_SECURITY      10         // (mm) Security distance Y axis
  #define SWITCHING_TOOLHEAD_Y_CLEAR         60         // (mm) Minimum distance from dock for unobstructed X axis
  #define SWITCHING_TOOLHEAD_X_POS          { 215, 0 }  // (mm) X positions for parking the extruders
  #if ENABLED(SWITCHING_TOOLHEAD)
    #define SWITCHING_TOOLHEAD_SERVO_NR       2         // Index of the servo connector
    #define SWITCHING_TOOLHEAD_SERVO_ANGLES { 0, 180 }  // (degrees) Angles for Lock, Unlock
  #elif ENABLED(MAGNETIC_SWITCHING_TOOLHEAD)
    #define SWITCHING_TOOLHEAD_Y_RELEASE      5         // (mm) Security distance Y axis
    #define SWITCHING_TOOLHEAD_X_SECURITY   { 90, 150 } // (mm) Security distance X axis (T0,T1)
    //#define PRIME_BEFORE_REMOVE                       // Prime the nozzle before release from the dock
    #if ENABLED(PRIME_BEFORE_REMOVE)
      #define SWITCHING_TOOLHEAD_PRIME_MM           20  // (mm)   Extruder prime length
      #define SWITCHING_TOOLHEAD_RETRACT_MM         10  // (mm)   Retract after priming length
      #define SWITCHING_TOOLHEAD_PRIME_FEEDRATE    300  // (mm/m) Extruder prime feedrate
      #define SWITCHING_TOOLHEAD_RETRACT_FEEDRATE 2400  // (mm/m) Extruder retract feedrate
    #endif
  #elif ENABLED(ELECTROMAGNETIC_SWITCHING_TOOLHEAD)
    #define SWITCHING_TOOLHEAD_Z_HOP          2         // (mm) Z raise for switching
  #endif
#endif

/**
 * "Mixing Extruder"
 * - Adiciona os códigos G M163 e M164 para definir e "comprometer" os fatores de mixagem atuais.
 * - Estende as rotinas de stepping para mover vários steppers em proporção à mistura.
 * - Suporte opcional para ferramentas virtuais de suporte 'M164 S <index>' do Firmware Repetier.
 * - Esta implementação suporta até duas extrusoras de mistura.
 * - Habilite DIRECT_MIXING_IN_G1 para M165 e mixagem em G1 (da implementação de referência de Pia Taubert).
 */
#define MIXING_EXTRUDER
#if ENABLED(MIXING_EXTRUDER)
  #define MIXING_STEPPERS 3         // Número de steppers em sua extrusora de mistura
  #define MIXING_VIRTUAL_TOOLS 16   // Use o método de ferramenta virtual com M163 e M164
  
  #define USE_PRECENT_MIXDATA		    // Use dados de porcentagem de mistura na configuração de LCD e comando gcode
  #define MIX_STATUS_SCREEN_IMAGE	  // mostra o ÍCONE da taxa de mixagem e os dados no LCD (aplicado apenas no LCD12864)
  #define CUSTOM_STATUS_SCREEN_IMAGE

  //#define DIRECT_MIXING_IN_G1     // Permitir fatores de mistura ABCDHI em comandos de movimento G1
  #define GRADIENT_MIX              // Suporte para mistura de gradiente com M166 e LCD
  #if ENABLED(GRADIENT_MIX)
    //#define GRADIENT_VTOOL        // Adicione M166 T para usar um índice V-tool como um alias de gradiente
  #endif
#endif

// Offset das extrusoras (descomente se estiver usando mais de uma e contando com o firmware para posicionar ao mudar).
// O deslocamento deve ser X = 0, Y = 0 para a extrusora 0 hotend (extrusora padrão).
// Para os outros hotends é a sua distância da extrusora 0 hotend.
//#define HOTEND_OFFSET_X { 0.0, 20.00 } // (mm) relative X-offset for each nozzle
//#define HOTEND_OFFSET_Y { 0.0, 5.00 }  // (mm) relative Y-offset for each nozzle
//#define HOTEND_OFFSET_Z { 0.0, 0.00 }  // (mm) relative Z-offset for each nozzle

// @section machine

/**
 * Controle de fonte de alimentação
 *
 * Habilite e conecte a fonte de alimentação ao PS_ON_PIN.
 * Especifique se a fonte de alimentação está ativa HIGH ou ativa LOW.
 */
//#define PSU_CONTROL
//#define PSU_NAME "Power Supply"

#if ENABLED(PSU_CONTROL)
  #define PSU_ACTIVE_HIGH false     // Defina 'falso' para ATX, 'verdadeiro' para X-Box

  //#define PSU_DEFAULT_OFF         // Mantenha a energia desligada até habilitado diretamente com M80
  //#define PSU_POWERUP_DELAY 250   // (ms) Atraso para a PSU aquecer até a potência máxima

  //#define AUTO_POWER_CONTROL      // Ativar controle automático do pino PS_ON
  #if ENABLED(AUTO_POWER_CONTROL)
    #define AUTO_POWER_FANS         // Ligue a PSU se os ventiladores precisarem de energia
    #define AUTO_POWER_E_FANS
    #define AUTO_POWER_CONTROLLERFAN
    #define AUTO_POWER_CHAMBER_FAN
    //#define AUTO_POWER_E_TEMP        50 // (°C) Ligue PSU acima desta temperatura
    //#define AUTO_POWER_CHAMBER_TEMP  30 // (°C) Ligue PSU acima desta temperatura
    #define POWER_TIMEOUT 30
  #endif
#endif

// @section temperature

//===========================================================================
//============================= Thermal Settings ============================
//===========================================================================

/**
 * --NORMAL IS 4.7kohm PULLUP! - 1kohm pullup pode ser usado no sensor hotend, usando o resistor correto e a tabela
  *
  * Sensores de temperatura disponíveis:
 *
 *    -5 : PT100 / PT1000 with MAX31865 (only for sensors 0-1)
 *    -3 : thermocouple with MAX31855 (only for sensors 0-1)
 *    -2 : thermocouple with MAX6675 (only for sensors 0-1)
 *    -4 : thermocouple with AD8495
 *    -1 : thermocouple with AD595
 *     0 : not used
 *     1 : 100k thermistor - best choice for EPCOS 100k (4.7k pullup)
 *   331 : (3.3V scaled thermistor 1 table for MEGA)
 *   332 : (3.3V scaled thermistor 1 table for DUE)
 *     2 : 200k thermistor - ATC Semitec 204GT-2 (4.7k pullup)
 *   202 : 200k thermistor - Copymaster 3D
 *     3 : Mendel-parts thermistor (4.7k pullup)
 *     4 : 10k thermistor !! do not use it for a hotend. It gives bad resolution at high temp. !!
 *     5 : 100K thermistor - ATC Semitec 104GT-2/104NT-4-R025H42G (Used in ParCan, J-Head, and E3D) (4.7k pullup)
 *   501 : 100K Zonestar (Tronxy X3A) Thermistor
 *   502 : 100K Zonestar Thermistor used by hot bed in Zonestar Prusa P802M
 *   512 : 100k RPW-Ultra hotend thermistor (4.7k pullup)
 *     6 : 100k EPCOS - Not as accurate as table 1 (created using a fluke thermocouple) (4.7k pullup)
 *     7 : 100k Honeywell thermistor 135-104LAG-J01 (4.7k pullup)
 *    71 : 100k Honeywell thermistor 135-104LAF-J01 (4.7k pullup)
 *     8 : 100k 0603 SMD Vishay NTCS0603E3104FXT (4.7k pullup)
 *     9 : 100k GE Sensing AL03006-58.2K-97-G1 (4.7k pullup)
 *    10 : 100k RS thermistor 198-961 (4.7k pullup)
 *    11 : 100k beta 3950 1% thermistor (Used in Keenovo AC silicone mats and most Wanhao i3 machines) (4.7k pullup)
 *    12 : 100k 0603 SMD Vishay NTCS0603E3104FXT (4.7k pullup) (calibrated for Makibox hot bed)
 *    13 : 100k Hisens 3950  1% up to 300°C for hotend "Simple ONE " & "Hotend "All In ONE"
 *    15 : 100k thermistor calibration for JGAurora A5 hotend
 *    18 : ATC Semitec 204GT-2 (4.7k pullup) Dagoma.Fr - MKS_Base_DKU001327
 *    20 : Pt100 with circuit in the Ultimainboard V2.x with 5v excitation (AVR)
 *    21 : Pt100 with circuit in the Ultimainboard V2.x with 3.3v excitation (STM32 \ LPC176x....)
 *    22 : 100k (hotend) with 4.7k pullup to 3.3V and 220R to analog input (as in GTM32 Pro vB)
 *    23 : 100k (bed) with 4.7k pullup to 3.3v and 220R to analog input (as in GTM32 Pro vB)
 *   201 : Pt100 with circuit in Overlord, similar to Ultimainboard V2.x
 *    60 : 100k Maker's Tool Works Kapton Bed Thermistor beta=3950
 *    61 : 100k Formbot / Vivedino 3950 350C thermistor 4.7k pullup
 *    66 : 4.7M High Temperature thermistor from Dyze Design
 *    67 : 450C thermistor from SliceEngineering
 *    70 : the 100K thermistor found in the bq Hephestos 2
 *    75 : 100k Generic Silicon Heat Pad with NTC 100K MGB18-104F39050L32 thermistor
 *    99 : 100k thermistor with a 10K pull-up resistor (found on some Wanhao i3 machines)
 *
 *       1k ohm pullup tables - This is atypical, and requires changing out the 4.7k pullup for 1k.
 *                              (but gives greater accuracy and more stable PID)
 *    51 : 100k thermistor - EPCOS (1k pullup)
 *    52 : 200k thermistor - ATC Semitec 204GT-2 (1k pullup)
 *    55 : 100k thermistor - ATC Semitec 104GT-2 (Used in ParCan & J-Head) (1k pullup)
 *
 *  1047 : Pt1000 with 4k7 pullup (E3D)
 *  1010 : Pt1000 with 1k pullup (non standard)
 *   147 : Pt100 with 4k7 pullup
 *   110 : Pt100 with 1k pullup (non standard)
 *
 *  1000 : Custom - Specify parameters in Configuration_adv.h
 *
 *         Use these for Testing or Development purposes. NEVER for production machine.
 *   998 : Dummy Table that ALWAYS reads 25°C or the temperature defined below.
 *   999 : Dummy Table that ALWAYS reads 100°C or the temperature defined below.
 */
#define TEMP_SENSOR_0 501
#define TEMP_SENSOR_1 0
#define TEMP_SENSOR_2 0
#define TEMP_SENSOR_3 0
#define TEMP_SENSOR_4 0
#define TEMP_SENSOR_5 0
#define TEMP_SENSOR_6 0
#define TEMP_SENSOR_7 0
#define TEMP_SENSOR_BED 501
#define TEMP_SENSOR_PROBE 0
#define TEMP_SENSOR_CHAMBER 0

// Leituras fictícias de temperatura constante do termistor, para uso com 998 e 999
#define DUMMY_THERMISTOR_998_VALUE 60
#define DUMMY_THERMISTOR_999_VALUE 205

// Use o sensor de temperatura 1 como um sensor redundante com o sensor 0. Se as leituras
// os dois sensores diferem muito a impressão será abortada.
//#define TEMP_SENSOR_1_AS_REDUNDANT
#define MAX_REDUNDANT_TEMP_SENSOR_DIFF 10

#define TEMP_RESIDENCY_TIME     10  // (segundos) Tempo de espera para o hotend "liquidar" em M109
#define TEMP_WINDOW              1  // (°C) Proximidade da temperatura para o temporizador de "temperatura alcançada"
#define TEMP_HYSTERESIS          3  // (°C) Temperature proximity considered "close enough" to the target

#define TEMP_BED_RESIDENCY_TIME 10  // (segundos) Tempo de espera para o hotend "liquidar" em M109
#define TEMP_BED_WINDOW          1  // (°C) Proximidade da temperatura para o temporizador de "temperatura alcançada"
#define TEMP_BED_HYSTERESIS      3  // (°C) Temperature proximity considered "close enough" to the target

// Abaixo desta temperatura, o aquecedor será desligado
// porque provavelmente indica um fio do termistor quebrado.
#define HEATER_0_MINTEMP   5
#define HEATER_1_MINTEMP   5
#define HEATER_2_MINTEMP   5
#define HEATER_3_MINTEMP   5
#define HEATER_4_MINTEMP   5
#define HEATER_5_MINTEMP   5
#define HEATER_6_MINTEMP   5
#define HEATER_7_MINTEMP   5
#define BED_MINTEMP        5

// Acima desta temperatura, o aquecedor será desligado.
// Isso pode proteger os componentes de superaquecimento, mas NÃO de curtos-circuitos e falhas.
// (Use MINTEMP para proteção contra curto / falha do termistor.)
#define HEATER_0_MAXTEMP 275
#define HEATER_1_MAXTEMP 275
#define HEATER_2_MAXTEMP 275
#define HEATER_3_MAXTEMP 275
#define HEATER_4_MAXTEMP 275
#define HEATER_5_MAXTEMP 275
#define HEATER_6_MAXTEMP 275
#define HEATER_7_MAXTEMP 275
#define BED_MAXTEMP      150

//===========================================================================
//============================= PID Settings ================================
//===========================================================================
// Guia de ajuste de PID aqui: https://reprap.org/wiki/PID_Tuning

// Comente a seguinte linha para desabilitar o PID e habilitar bang-bang.
#define PIDTEMP
#define BANG_MAX 255     // Limita a corrente ao bocal no modo bang-bang; 255 = corrente total
#define PID_MAX BANG_MAX // Limita a corrente ao bico enquanto o PID está ativo (ver PID_FUNCTIONAL_RANGE abaixo); 255 = corrente total
#define PID_K1 0.95      // Fator de suavização em qualquer circuito PID

#if ENABLED(PIDTEMP)
  #define PID_EDIT_MENU         // Adicione a edição de PID ao menu "Configurações avançadas". (~ 700 bytes de PROGMEM)
  #define PID_AUTOTUNE_MENU     // Adicione o ajuste automático do PID ao menu "Configurações avançadas". (~ 250 bytes de PROGMEM)
  //#define PID_PARAMS_PER_HOTEND // Usa parâmetros PID separados para cada extrusora (útil para extrusoras incompatíveis)
                                  // Definir / obter com gcode: M301 E [número da extrusora, 0-2]

  //Se você estiver usando um hotend pré-configurado, você pode usar um dos conjuntos de valores descomentando-o
  // Ultimaker
  #define DEFAULT_Kp 49.8
  #define DEFAULT_Ki 5.25
  #define DEFAULT_Kd 118.47

  // MakerGear
  //#define DEFAULT_Kp 7.0
  //#define DEFAULT_Ki 0.1
  //#define DEFAULT_Kd 12

  // Mendel Parts V9 on 12V
  //#define DEFAULT_Kp 63.0
  //#define DEFAULT_Ki 2.25
  //#define DEFAULT_Kd 440

#endif // PIDTEMP

//===========================================================================
//====================== PID > Bed Temperature Control ======================
//===========================================================================

/**
 * PID para Aquecimento de cama 
 *
 * Se esta opção estiver habilitada, defina as constantes PID abaixo.
 * Se esta opção for desabilitada, bang-bang será usado e BED_LIMIT_SWITCHING habilitará a histerese.
 *
 * A frequência PID será a mesma da extrusora PWM.
 * Se PID_dT é o padrão, e correto para o hardware / configuração, isso significa 7,689 Hz,
 * o que é bom para conduzir uma onda quadrada em uma carga resistiva e não significativamente
 * aquecimento FET de impacto. Isso também funciona bem em um Relé de estado sólido Fotek SSR-10DA em um 250W
 * aquecedor. Se sua configuração é significativamente diferente desta e você não entende
 * os problemas envolvidos, não use o PID da cama até que alguém verifique se o seu hardware funciona.
 */
#define PIDTEMPBED

//#define BED_LIMIT_SWITCHING

/**
 * Potência máxima da cama
 * Aplica-se a todas as formas de controle de leito (PID, bang-bang e bang-bang com histerese).
 * Quando definido para qualquer valor abaixo de 255, ativa uma forma de PWM para a cama que atua como um divisor
 * portanto, não use-o a menos que você esteja OK com PWM em sua cama. (Veja o comentário sobre a ativação do PIDTEMPBED)
 */
#define MAX_BED_POWER 255 // limita o ciclo de trabalho à cama; 255 = corrente total

#if ENABLED(PIDTEMPBED)
  //#define MIN_BED_POWER 0
  //#define PID_BED_DEBUG // Envia dados de depuração para a porta serial.

  // Aquecedor de silicone 120 V 250 W em borosilicato de 4 mm (MendelMax 1.5+)
  // do modelo FOPDT - kp = 0,39 Tp = 405 Tdead = 66, Tc definido como 79,2, fator agressivo de 0,15 (vs .1, 1, 10)
  #define DEFAULT_bedKp 10.00
  #define DEFAULT_bedKi .023
  #define DEFAULT_bedKd 305.4

  //120V 250W silicone heater into 4mm borosilicate (MendelMax 1.5+)
  //from pidautotune
  //#define DEFAULT_bedKp 97.1
  //#define DEFAULT_bedKi 1.41
  //#define DEFAULT_bedKd 1675.16

  // FIND YOUR OWN: "M303 E-1 C8 S90" to run autotune on the bed at 90 degreesC for 8 cycles.
#endif // PIDTEMPBED

#if EITHER(PIDTEMP, PIDTEMPBED)
  //#define PID_DEBUG             // Envia dados de depuração para a porta serial. Use 'M303 D' para alternar a ativação.
  //#define PID_OPENLOOP          // Coloca o PID em malha aberta. M104 / M140 define a potência de saída de 0 a PID_MAX
  //#define SLOW_PWM_HEATERS      // PWM com frequência muito baixa (cerca de 0,125 Hz = 8s) e tempo mínimo de estado de aproximadamente 1s útil para aquecedores acionados por um relé
  #define PID_FUNCTIONAL_RANGE 10 // Se a diferença de temperatura entre a temperatura alvo e a temperatura real
                                  // for maior que PID_FUNCTIONAL_RANGE, então o PID será desligado e o aquecedor será definido para mín / máx.
#endif

// @section extruder

/**
 * Evite a extrusão se a temperatura estiver abaixo de EXTRUDE_MINTEMP.
 * Adicione M302 para definir a temperatura mínima de extrusão e / ou gire
 * prevenção de extrusão a frio ligada e desligada.
 *
 * *** É ALTAMENTE RECOMENDADO DEIXAR ESTA OPÇÃO ATIVADA! ***
 */
#define PREVENT_COLD_EXTRUSION
#define EXTRUDE_MINTEMP 170

/**
 * Evite uma única extrusão por mais tempo do que EXTRUDE_MAXLENGTH.
 * Observação: para extrusoras Bowden, faça com que seja grande o suficiente para permitir a carga / descarga.
 */
#define PREVENT_LENGTHY_EXTRUDE
#define EXTRUDE_MAXLENGTH 600

//===========================================================================
//======================== Thermal Runaway Protection =======================
//===========================================================================

/**
 * A proteção térmica fornece proteção adicional para sua impressora contra danos
 * e fogo. Marlin sempre inclui faixas de temperatura mínimas e máximas seguras que
 * proteger contra um fio do termistor quebrado ou desconectado.
 *
 * O problema: se um termistor cair, ele irá relatar o muito menor
 * temperatura do ar na sala, e o firmware manterá
 * o aquecedor ligado.
 *
 * Se você receber erros de "Fuga térmica" ou "Falha de aquecimento",
 * detalhes podem ser ajustados em Configuration_adv.h
 */

#define THERMAL_PROTECTION_HOTENDS // Ativar proteção térmica para todas as extrusoras
#define THERMAL_PROTECTION_BED     // Ativar proteção térmica para a cama aquecida
#define THERMAL_PROTECTION_CHAMBER // Ativar proteção térmica para a câmara aquecida

//===========================================================================
//============================= Mechanical Settings =========================
//===========================================================================

// @section machine

// Remova o comentário de uma dessas opções para habilitar a cinemática CoreXY, CoreXZ ou CoreYZ
// na ordem normal ou invertida
#define COREXY
//#define COREXZ
//#define COREYZ
//#define COREYX
//#define COREZX
//#define COREZY

//===========================================================================
//============================== Endstop Settings ===========================
//===========================================================================

// @section homing

// Especifique aqui todos os conectores de fim de curso que estão conectados a qualquer fim de curso ou sonda.
// Quase todas as impressoras usarão uma por eixo. As sondas usarão um ou mais dos
// conectores extras. Deixe indefinido qualquer usado para finalidades sem fim e sem sondagem.
#define USE_XMIN_PLUG
#define USE_YMIN_PLUG
#define USE_ZMIN_PLUG
//#define USE_XMAX_PLUG
//#define USE_YMAX_PLUG
//#define USE_ZMAX_PLUG

// Habilite pullup para todos os endstops para evitar um estado flutuante
#define ENDSTOPPULLUPS
#if DISABLED(ENDSTOPPULLUPS)
  // Desative ENDSTOPPULLUPS para definir pullups individualmente
  //#define ENDSTOPPULLUP_XMAX
  //#define ENDSTOPPULLUP_YMAX
  //#define ENDSTOPPULLUP_ZMAX
  //#define ENDSTOPPULLUP_XMIN
  //#define ENDSTOPPULLUP_YMIN
  //#define ENDSTOPPULLUP_ZMIN
  //#define ENDSTOPPULLUP_ZMIN_PROBE
#endif

// Ative o menu suspenso para todas as paradas finais para evitar um estado flutuante
//#define ENDSTOPPULLDOWNS
#if DISABLED(ENDSTOPPULLDOWNS)
  // Desative ENDSTOPPULLDOWNS para definir suspensos individualmente
  //#define ENDSTOPPULLDOWN_XMAX
  //#define ENDSTOPPULLDOWN_YMAX
  //#define ENDSTOPPULLDOWN_ZMAX
  //#define ENDSTOPPULLDOWN_XMIN
  //#define ENDSTOPPULLDOWN_YMIN
  //#define ENDSTOPPULLDOWN_ZMIN
  //#define ENDSTOPPULLDOWN_ZMIN_PROBE
#endif

// O fim de curso mecânico com COM para aterrar e NC para Sinal usa "false" aqui (configuração mais comum).
#define X_MIN_ENDSTOP_INVERTING true  // Set to true to invert the logic of the endstop.
#define Y_MIN_ENDSTOP_INVERTING true  // Set to true to invert the logic of the endstop.
#define Z_MIN_ENDSTOP_INVERTING true  // Set to true to invert the logic of the endstop.
#define X_MAX_ENDSTOP_INVERTING false  // Set to true to invert the logic of the endstop.
#define Y_MAX_ENDSTOP_INVERTING false  // Set to true to invert the logic of the endstop.
#define Z_MAX_ENDSTOP_INVERTING false // Set to true to invert the logic of the endstop.
#define Z_MIN_PROBE_ENDSTOP_INVERTING true // Set to true to invert the logic of the probe.

/**
 * Stepper Drivers
 *
* Essas configurações permitem que o Marlin ajuste o tempo do driver de passo e habilite opções avançadas para
 * drivers de passo que os suportam. Você também pode substituir as opções de tempo em Configuration_adv.h.
 *
 * A4988 é assumido para drivers não especificados.
 *
 * Options: A4988, A5984, DRV8825, LV8729, L6470, L6474, POWERSTEP01,
 *          TB6560, TB6600, TMC2100,
 *          TMC2130, TMC2130_STANDALONE, TMC2160, TMC2160_STANDALONE,
 *          TMC2208, TMC2208_STANDALONE, TMC2209, TMC2209_STANDALONE,
 *          TMC26X,  TMC26X_STANDALONE,  TMC2660, TMC2660_STANDALONE,
 *          TMC5130, TMC5130_STANDALONE, TMC5160, TMC5160_STANDALONE
 * :['A4988', 'A5984', 'DRV8825', 'LV8729', 'L6470', 'L6474', 'POWERSTEP01', 'TB6560', 'TB6600', 'TMC2100', 'TMC2130', 'TMC2130_STANDALONE', 'TMC2160', 'TMC2160_STANDALONE', 'TMC2208', 'TMC2208_STANDALONE', 'TMC2209', 'TMC2209_STANDALONE', 'TMC26X', 'TMC26X_STANDALONE', 'TMC2660', 'TMC2660_STANDALONE', 'TMC5130', 'TMC5130_STANDALONE', 'TMC5160', 'TMC5160_STANDALONE']
 */
#define X_DRIVER_TYPE  DRV8825
#define Y_DRIVER_TYPE  DRV8825
#define Z_DRIVER_TYPE  DRV8825
//#define X2_DRIVER_TYPE A4988
//#define Y2_DRIVER_TYPE A4988
//#define Z2_DRIVER_TYPE A4988
//#define Z3_DRIVER_TYPE A4988
//#define Z4_DRIVER_TYPE A4988
#define E0_DRIVER_TYPE A4988
#define E1_DRIVER_TYPE A4988
#define E2_DRIVER_TYPE A4988
//#define E3_DRIVER_TYPE A4988
//#define E4_DRIVER_TYPE A4988
//#define E5_DRIVER_TYPE A4988
//#define E6_DRIVER_TYPE A4988
//#define E7_DRIVER_TYPE A4988

// Habilite este recurso se todos os pinos de parada final habilitados forem capazes de interromper.
// Isso removerá a necessidade de pesquisar os pinos de interrupção, economizando muitos ciclos de CPU.
//#define ENDSTOP_INTERRUPTS_FEATURE

/**
 * Limite de ruído final
 *
 * Ative se a sua ponta de prova ou paradas finais dispararem erroneamente devido ao ruído.
 *
 * - Valores mais altos podem afetar a repetibilidade ou a precisão de algumas sondas de leito.
 * - Para corrigir o ruído, instale um capacitor de cerâmica 100nF em paralelo com a chave.
 * - Este recurso não é necessário para microinterruptores comuns montados em PCBs
 * baseado no design do Makerbot, que já possui o capacitor 100nF.
 *
 * :[2,3,4,5,6,7]
 */
//#define ENDSTOP_NOISE_THRESHOLD 2

// Verifique se há endstops presos ou desconectados durante os movimentos de homing.
//#define DETECT_BROKEN_ENDSTOP

//=============================================================================
//============================== Movement Settings ============================
//=============================================================================
// @section motion

/**
 * Configurações padrão
 *
 * Essas configurações podem ser redefinidas por M502
 *
 * Observe que, se EEPROM estiver habilitado, os valores salvos os substituirão.
 */

/**
 * Com esta opção, cada E stepper pode ter seus próprios fatores para o
 * seguintes configurações de movimento. Se menos fatores forem dados do que o
 * número total de extrusoras, o último valor se aplica às demais.
 */
//#define DISTINCT_E_FACTORS

/**
 * Etapas do eixo padrão por unidade (etapas / mm)
 * Substituir com M92
 *                                      X, Y, Z, E0 [, E1[, E2...]]
 */
#define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 600, 88 }

/**
 * Taxa de alimentação máxima padrão (mm / s)
 * Substituir com M203
 *                                      X, Y, Z, E0 [, E1[, E2...]]
 */
#define DEFAULT_MAX_FEEDRATE          { 500, 500, 8, 25 }

//#define LIMITED_MAX_FR_EDITING        // Limite a edição via M203 ou LCD para DEFAULT_MAX_FEEDRATE * 2
#if ENABLED(LIMITED_MAX_FR_EDITING)
  #define MAX_FEEDRATE_EDIT_VALUES    { 600, 600, 10, 50 } // ... ou defina seus próprios limites de edição
#endif

/**
 * Mudança de aceleração máxima padrão (mudança / s) = mm / s
 * (Velocidade máxima de partida para movimentos acelerados)
 * Substituir com M201
 * X, Y, Z, E0 [, E1 [, E2 ...] 
 */
#define DEFAULT_MAX_ACCELERATION      { 2000, 2000, 100, 2000 }

//#define LIMITED_MAX_ACCEL_EDITING     // Limite a edição via M201 ou LCD para DEFAULT_MAX_ACCELERATION * 2
#if ENABLED(LIMITED_MAX_ACCEL_EDITING)
  #define MAX_ACCEL_EDIT_VALUES       { 6000, 6000, 200, 20000 } // ...or, set your own edit limits
#endif

/**
 * Mudança de aceleração padrão (mudança / s) = mm / s
 * Substituir com M204
 *
 * Aceleração M204 P
 * Aceleração de retração M204 R
 * M204 T Travel Acceleration
 */
#define DEFAULT_ACCELERATION          500    // X, Y, Z and E acceleration for printing moves
#define DEFAULT_RETRACT_ACCELERATION  500    // E acceleration for retracts
#define DEFAULT_TRAVEL_ACCELERATION   500
/**
 * Limites de jerk padrão (mm / s)
 * Substituir com M205 X Y Z E
 *
 * "Jerk" especifica a mudança de velocidade mínima que requer aceleração.
 * Ao alterar a velocidade e direção, se a diferença for menor que o
 * valor definido aqui, pode acontecer instantaneamente.
 */
//#define CLASSIC_JERK
#if ENABLED(CLASSIC_JERK)
  #define DEFAULT_XJERK 10.0
  #define DEFAULT_YJERK 10.0
  #define DEFAULT_ZJERK  0.3

  //#define TRAVEL_EXTRA_XYJERK 0.0     // Provisão adicional de empurrão para todos os movimentos de viagem

  //#define LIMITED_JERK_EDITING        // Limite a edição via M205 ou LCD para DEFAULT_aJERK * 2
  #if ENABLED(LIMITED_JERK_EDITING)
    #define MAX_JERK_EDIT_VALUES { 20, 20, 0.6, 10 } // ... ou defina seus próprios limites de edição
  #endif
#endif

#define DEFAULT_EJERK    5.0  // Pode ser usado por Linear Advance

/**
 * Fator de Desvio de Junção
  *
  * Vejo:
  * https://reprap.org/forum/read.php?1,739819
  * https://blog.kyneticcnc.com/2018/10/computing-junction-deviation-for-marlin.html
 */
#if DISABLED(CLASSIC_JERK)
  #define JUNCTION_DEVIATION_MM 0.013 // (mm) Distância da borda da junção real
  #define JD_HANDLE_SMALL_SEGMENTS    // Use estimativa de curvatura em vez de apenas o ângulo de junção
                                      // para segmentos pequenos (<1mm) com grandes ângulos de junção (> 135 °).
#endif

/**
 * S-Curve Acceleration
  *
  * Esta opção elimina a vibração durante a impressão, encaixando um Bézier
  * curva para mover a aceleração, produzindo mudanças de direção muito mais suaves.
  *
  * Veja https://github.com/synthetos/TinyG/wiki/Jerk-Controlled-Motion-Explained
 */
#define S_CURVE_ACCELERATION

//===========================================================================
//============================= Z Probe Options =============================
//===========================================================================
// @section probes

//
// See https://marlinfw.org/docs/configuration/probes.html
//

/**
 * Habilite esta opção para uma sonda conectada ao pino Z-MIN.
  * A sonda substitui o fim de curso Z-MIN e é usada para Z homing.
  * (Ativa automaticamente USE_PROBE_FOR_Z_HOMING.)
 */
//#define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN

// Força o uso da sonda para homing do eixo Z
//#define USE_PROBE_FOR_Z_HOMING

/**
 * Z_MIN_PROBE_PIN
 *
 * Defina este pino se a sonda não estiver conectada a Z_MIN_PIN.
 * Se não for definido o pino padrão para o MOTHERBOARD selecionado
 * será usado. Na maioria das vezes, o padrão é o que você deseja.
 *
 * - A opção mais simples é usar um conector de fim de curso livre.
 * - Use 5 V para sensores energizados (geralmente indutivos).
 *
 * - As placas RAMPS 1.3 / 1.4 podem usar o pino 5V, GND e Aux4-> D32:
 * - Para interruptores simples, conecte ...
 * - interruptores normalmente fechados para GND e D32.
 * - interruptores normalmente abertos para 5V e D32.
 *
 */
//#define Z_MIN_PROBE_PIN // Pin 32 is the RAMPS default

/**
 * Tipo de Sonda
 *
 * Sondas Allen Key, Sondas Servo, Sondas Z-Sled, FIX_MOUNTED_PROBE, etc.
 * Ative um desses para usar o Nivelamento automático da cama abaixo.
 */

/**
 * A "Sonda manual" fornece um meio de fazer o nivelamento "automático" do leito sem uma sonda.
  * Use G29 repetidamente, ajustando a altura Z em cada ponto com comandos de movimento
  * ou (com LCD_BED_LEVELING) o controlador LCD.
 */
//#define PROBE_MANUALLY
//#define MANUAL_PROBE_START_Z 0.2

/**
 * Uma Sonda Fix-Mounted não é implantada ou precisa de uma implantação manual.
 * (por exemplo, uma sonda indutiva ou um interruptor de sonda com base em bocal.)
 */
#define FIX_MOUNTED_PROBE

/**
 * Use o bico como a sonda, como com um condutor
  * sistema de bocal ou um efetor inteligente piezoelétrico.
 */
//#define NOZZLE_AS_PROBE

/**
 * Z Servo Probe, como uma chave de fim de curso em um braço giratório.
 */
//#define Z_PROBE_SERVO_NR 0       // Defaults to SERVO 0 connector.
//#define Z_SERVO_ANGLES { 70, 0 } // Z Servo Deploy and Stow angles

/**
 * A ponta de prova BLTouch usa um sensor de efeito Hall e emula um servo.
 */
//#define BLTOUCH

/**
 * Sensor de pressão com uma interface do tipo BLTouch
 */
//#define CREALITY_TOUCH

/**
 * Touch-MI Probe por hotends.fr
 *
 * Esta sonda é implantada e ativada movendo o eixo X para um ímã na borda da cama.
 * Por padrão, presume-se que o ímã esteja à esquerda e ativado por uma casa. Se o ímã é
 * à direita, ative e defina TOUCH_MI_DEPLOY_XPOS para a posição de implantação.
 *
 * Também requer: BABYSTEPPING, BABYSTEP_ZPROBE_OFFSET, Z_SAFE_HOMING,
 * e um mínimo de Z_HOMING_HEIGHT de 10.
 */
//#define TOUCH_MI_PROBE
#if ENABLED(TOUCH_MI_PROBE)
  #define TOUCH_MI_RETRACT_Z 0.5                  // Altura em que a sonda retrai
  //#define TOUCH_MI_DEPLOY_XPOS (X_MAX_BED + 2)  // Para um ímã no lado direito da cama
  //#define TOUCH_MI_MANUAL_DEPLOY                // Para implantação manual (menu LCD)
#endif

// Uma sonda que é implantada e armazenada com um pino solenóide (SOL1_PIN)
//#define SOLENOID_PROBE

// Uma sonda montada em trenó como as projetadas por Charles Bell.
//#define Z_PROBE_SLED
//#define SLED_DOCKING_OFFSET 5  // A distância extra que o eixo X deve percorrer para pegar o trenó. 0 deve ser suficiente, mas você pode pressioná-lo mais se desejar.

// Uma sonda implantada movendo o eixo x, como a sonda de cremalheira e pinhão do Wilson II projetada por Marty Rice.
//#define RACK_AND_PINION_PROBE
#if ENABLED(RACK_AND_PINION_PROBE)
  #define Z_PROBE_DEPLOY_X  X_MIN_POS
  #define Z_PROBE_RETRACT_X X_MAX_POS
#endif

// Duet Smart Effector (para impressoras delta) - https://bit.ly/2ul5U7J
// Quando o pino é definido, você pode usar M672 para definir / redefinir a sensibilidade da sonda.
//#define DUET_SMART_EFFECTOR
#if ENABLED(DUET_SMART_EFFECTOR)
  #define SMART_EFFECTOR_MOD_PIN  -1  // Connect a GPIO pin to the Smart Effector MOD pin
#endif

/**
 * Use StallGuard2 para sondar o leito com o bocal.
 * Requer drivers de passo Trinamic com capacidade para stallGuard.
 * CUIDADO: Isso pode danificar máquinas com parafusos de avanço Z.
 * Tome muito cuidado ao configurar este recurso.
 */
//#define SENSORLESS_PROBING

//
// For Z_PROBE_ALLEN_KEY see the Delta example configurations.
//

/**
 * Z Sonda para o bocal (X, Y) offset, relativo a (0, 0).
 *
 * No exemplo a seguir, os deslocamentos X e Y são ambos positivos:
 *
 *   #define NOZZLE_TO_PROBE_OFFSET { 10, 10, 0 }
 *
 *     +-- BACK ---+
 *     |           |
 *   L |    (+) P  | R <-- probe (20,20)
 *   E |           | I
 *   F | (-) N (+) | G <-- nozzle (10,10)
 *   T |           | H
 *     |    (-)    | T
 *     |           |
 *     O-- FRONT --+
 *   (0,0)
 *
 * Especifique a posição da sonda como {X, Y, Z}
 */
#define NOZZLE_TO_PROBE_OFFSET { -30, 0, -3 }

// A maioria das sondas deve ficar longe das bordas da cama, mas
// com NOZZLE_AS_PROBE isso pode ser negativo para uma área de sondagem mais ampla.
#define PROBING_MARGIN 40

// Velocidade de deslocamento dos eixos X e Y (mm / m) entre as sondas
#define XY_PROBE_SPEED 12000

// Avanço (mm / m) para a primeira abordagem quando sondagem dupla (MULTIPLE_PROBING == 2)
#define Z_PROBE_SPEED_FAST HOMING_FEEDRATE_Z

// Taxa de avanço (mm / m) para a sonda "precisa" de cada ponto
#define Z_PROBE_SPEED_SLOW (Z_PROBE_SPEED_FAST / 4)

/**
 * Multiple Probing
 *
 * Você pode obter melhores resultados testando 2 ou mais vezes.
 * Com EXTRA_PROBING as leituras mais atípicas serão desconsideradas.
 *
 * Um total de 2 faz sondagens rápidas / lentas com uma média ponderada.
 * Um total de 3 ou mais adiciona mais sondas lentas, calculando a média.
 */
//#define MULTIPLE_PROBING 2
//#define EXTRA_PROBING    1

/**
 * As sondas Z requerem liberação ao implantar, guardar e mover-se entre
 * pontos de sonda para evitar bater na cama e outras ferragens.
 * As sondas montadas em servo requerem espaço extra para o braço girar.
 * As sondas indutivas precisam de espaço para evitar o acionamento precoce.
 *
 * Use essas configurações para especificar a distância (mm) para elevar a sonda (ou
 * abaixe a cama). Os valores definidos aqui se aplicam acima de qualquer (negativo)
 * Sonda Z Offset definido com NOZZLE_TO_PROBE_OFFSET, M851 ou o LCD.
 * Somente valores inteiros> = 1 são válidos aqui.
 *
 * Exemplo: `M851 Z-5` com uma folga de 4 => 9 mm do leito ao bico.
 * Mas: `M851 Z + 1` com uma folga de 2 => 2 mm da base ao bocal.
 */
#define Z_CLEARANCE_DEPLOY_PROBE    2 // Z Liberação para implantação / armazenamento
#define Z_CLEARANCE_BETWEEN_PROBES  2 // Z Folga entre os pontos de sonda
#define Z_CLEARANCE_MULTI_PROBE     2 // Z Folga entre várias sondas
//#define Z_AFTER_PROBING           5 // Posição Z após a realização da sondagem

#define Z_PROBE_LOW_POINT          -3 // Distância mais distante abaixo do ponto-gatilho a percorrer antes de parar

// Para M851 forneça uma faixa para ajustar o deslocamento da sonda Z
#define Z_PROBE_OFFSET_RANGE_MIN -20
#define Z_PROBE_OFFSET_RANGE_MAX 20

// Ative o teste de repetibilidade M48 para testar a precisão da sonda
//#define Z_MIN_PROBE_REPEATABILITY_TEST

// Antes de implantar / guardar pausa para confirmação do usuário
//#define PAUSE_BEFORE_DEPLOY_STOW
#if ENABLED(PAUSE_BEFORE_DEPLOY_STOW)
  //#define PAUSE_PROBE_DEPLOY_WHEN_TRIGGERED // Para implantação manual de teste Allenkey
#endif

/**
 * Ative um ou mais dos seguintes se a sondagem não parecer confiável.
 * Aquecedores e / ou ventiladores podem ser desativados durante a sondagem para minimizar a eletricidade
 * barulho. Um atraso também pode ser adicionado para permitir que o ruído e a vibração se acomodem.
 * Essas opções são mais úteis para a sonda BLTouch, mas também podem melhorar
 * leituras com sondas indutivas e sensores piezoelétricos.
 */
//#define PROBING_HEATERS_OFF       // Desligue os aquecedores ao sondar
#if ENABLED(PROBING_HEATERS_OFF)
  //#define WAIT_FOR_BED_HEATER     // Espere o leito aquecer novamente entre as sondas (para melhorar a precisão)
#endif
#define PROBING_FANS_OFF          // Desligue os ventiladores ao sondar
//#define PROBING_STEPPERS_OFF      // Desligue os steppers (a menos que seja necessário manter a posição) durante a sondagem
//#define DELAY_BEFORE_PROBING 200  // (ms) Para evitar que vibrações acionem sensores piezoelétricos

// Para inversão de passo de ativação de pinos (ativo baixo), use 0, não inversor (ativo alto) use 1
// :{ 0:'Low', 1:'High' }
#define X_ENABLE_ON 0
#define Y_ENABLE_ON 0
#define Z_ENABLE_ON 0
#define E_ENABLE_ON 0 // For all extruders

// Desativa o stepper do eixo imediatamente quando não está sendo usado.
// AVISO: Quando os motores desligam, há uma chance de perder a precisão da posição!
#define DISABLE_X false
#define DISABLE_Y false
#define DISABLE_Z false

// Avisar no visor sobre uma possível precisão reduzida
//#define DISABLE_REDUCED_ACCURACY_WARNING

// @section extruder

#define DISABLE_E false             // Para todas as extrusoras
#define DISABLE_INACTIVE_EXTRUDER   // Mantenha apenas a extrusora ativa habilitada

// @section machine

// Inverta a direção do passo. Altere (ou inverta o conector do motor) se um eixo estiver na direção errada.
#define INVERT_X_DIR true
#define INVERT_Y_DIR true
#define INVERT_Z_DIR false

// @section extruder

// Para extrusora de acionamento direto v9 definido como verdadeiro, para extrusora com engrenagem definida como falso.
#define INVERT_E0_DIR false
#define INVERT_E1_DIR false
#define INVERT_E2_DIR false
#define INVERT_E3_DIR false
#define INVERT_E4_DIR false
#define INVERT_E5_DIR false
#define INVERT_E6_DIR false
#define INVERT_E7_DIR false

// @section homing

//#define NO_MOTION_BEFORE_HOMING // Inibir o movimento até que todos os eixos tenham sido posicionados

//#define UNKNOWN_Z_NO_RAISE      // Não eleve Z (abaixe a cama) se Z for "desconhecido". Para camas que caem quando Z é desligado.

//#define Z_HOMING_HEIGHT  4      // (mm) Altura Z mínima antes do retorno (G28) para folga Z acima da cama, grampos, ...
                                  // Certifique-se de ter tanta folga sobre seu Z_MAX_POS para evitar moagem.

#define Z_AFTER_HOMING  5      // (mm) Altura para a qual mover após o retorno Z

// Direção de paradas finais ao retornar; 1=MAX, -1=MIN
// :[-1,1]
#define X_HOME_DIR -1
#define Y_HOME_DIR -1
#define Z_HOME_DIR -1

// @section machine

// O tamanho da cama de impressão
#define X_BED_SIZE 308
#define Y_BED_SIZE 308

// Travel limits (mm) after homing, corresponding to endstop positions.
#define X_MIN_POS -3
#define Y_MIN_POS -16
#define Z_MIN_POS 0
#define X_MAX_POS X_BED_SIZE
#define Y_MAX_POS Y_BED_SIZE
#define Z_MAX_POS 400

/**
 * Endstops de software
 *
 * - Impedir movimentos fora dos limites definidos da máquina.
 * - Eixos individuais podem ser desabilitados, se desejado.
 * - X e Y aplicam-se apenas a robôs cartesianos.
 * - Use 'M211' para ativar / desativar as paradas finais do software ou relatar o estado atual
 */

// Paradas finais mínimas de software restringem o movimento dentro dos limites mínimos das coordenadas
#define MIN_SOFTWARE_ENDSTOPS
#if ENABLED(MIN_SOFTWARE_ENDSTOPS)
  #define MIN_SOFTWARE_ENDSTOP_X
  #define MIN_SOFTWARE_ENDSTOP_Y
  #define MIN_SOFTWARE_ENDSTOP_Z
#endif

// Paradas máximas de software restringem o movimento dentro dos limites máximos de coordenadas
#define MAX_SOFTWARE_ENDSTOPS
#if ENABLED(MAX_SOFTWARE_ENDSTOPS)
  #define MAX_SOFTWARE_ENDSTOP_X
  #define MAX_SOFTWARE_ENDSTOP_Y
  #define MAX_SOFTWARE_ENDSTOP_Z
#endif

#if EITHER(MIN_SOFTWARE_ENDSTOPS, MAX_SOFTWARE_ENDSTOPS)
  //#define SOFT_ENDSTOPS_MENU_ITEM  // Habilitar / desabilitar paradas finais de software no LCD
#endif

/**
 * Sensores de desgaste de filamento
 * Parâmetros mecânicos ou opto são usados para verificar a presença de filamento.
 *
 * As placas baseadas em RAMPS usam SERVO3_PIN para o primeiro sensor de runout.
 * Para outras placas, você pode precisar definir FIL_RUNOUT_PIN, FIL_RUNOUT2_PIN, etc.
 */
#define FILAMENT_RUNOUT_SENSOR
#if ENABLED(FILAMENT_RUNOUT_SENSOR)
  #define NUM_RUNOUT_SENSORS   1     // Número de sensores, até um por extrusora. Defina um FIL_RUNOUT # _PIN para cada um.
  #define FIL_RUNOUT_STATE     LOW   // Estado do pino indicando que o filamento NÃO está presente.
  #define FIL_RUNOUT_PULLUP          // Use pullup interno para pinos de saída de filamento.
  //#define FIL_RUNOUT_PULLDOWN      // Use o menu suspenso interno para pinos de saída de filamento.

  // Defina um ou mais comandos para executar na saída do filamento.
  // (Depois de 'M412 H', Marlin pedirá ao host para lidar com o processo.)
  #define FILAMENT_RUNOUT_SCRIPT "M600"

  // Depois que um runout for detectado, continue imprimindo este comprimento de filamento
  // antes de executar o script de runout. Útil para um sensor no final de
  // um tubo de alimentação. Requer 4 bytes SRAM por sensor, mais 4 bytes de overhead.
  #define FILAMENT_RUNOUT_DISTANCE_MM 15

  #ifdef FILAMENT_RUNOUT_DISTANCE_MM
    // Ative esta opção para usar um disco codificador que alterna o pino de runout
    // conforme o filamento se move. (Certifique-se de definir FILAMENT_RUNOUT_DISTANCE_MM
    // grande o suficiente para evitar falsos positivos.)
    //#define FILAMENT_MOTION_SENSOR
  #endif
#endif

//===========================================================================
//=============================== Bed Leveling ==============================
//===========================================================================
// @section calibrate

/**
 * Escolha uma das opções abaixo para ativar o Nivelamento da Cama G29. Os parametros
 * e o comportamento do G29 mudará dependendo da sua seleção.
 *
 * Se estiver usando uma Sonda para Z Homing, habilite Z_SAFE_HOMING também!
 *
 * - AUTO_BED_LEVELING_3POINT
 * Sondar 3 pontos arbitrários na cama (que não sejam colineares)
 * Você especifica as coordenadas XY de todos os 3 pontos.
 * O resultado é um único plano inclinado. Melhor para uma cama plana.
 *
 * - AUTO_BED_LEVELING_LINEAR
 * Sondar vários pontos em uma grade.
 * Você especifica o retângulo e a densidade dos pontos de amostra.
 * O resultado é um único plano inclinado. Melhor para uma cama plana.
 *
 * - AUTO_BED_LEVELING_BILINEAR
 * Sondar vários pontos em uma grade.
 * Você especifica o retângulo e a densidade dos pontos de amostra.
 * O resultado é uma malha, melhor para camas grandes ou irregulares.
 *
 * - AUTO_BED_LEVELING_UBL (Nivelamento de leito unificado)
 * Um sistema abrangente de nivelamento da cama combinando os recursos e benefícios
 * de outros sistemas. UBL também inclui geração de malha integrada, malha
 * Sistemas de validação e edição de malha.
 *
 * - MESH_BED_LEVELING
 * Sondar uma grade manualmente
 * O resultado é uma malha adequada para camas grandes ou irregulares. (Veja BILINEAR.)
 * Para máquinas sem uma sonda, o nivelamento da base de malha fornece um método para realizar
 * nivelamento em etapas para que você possa ajustar manualmente a altura Z em cada ponto da grade.
 * Com um controlador LCD, o processo é guiado passo a passo.
 */
//#define AUTO_BED_LEVELING_3POINT
//#define AUTO_BED_LEVELING_LINEAR
#define AUTO_BED_LEVELING_BILINEAR
//#define AUTO_BED_LEVELING_UBL
//#define MESH_BED_LEVELING

/**
 * Normalmente o G28 deixa o nivelamento desabilitado na conclusão. Habilitar
 * esta opção permite que o G28 restaure o estado de nivelamento anterior.
 */
#define RESTORE_LEVELING_AFTER_G28

/**
 * Habilite o registro detalhado de G28, G29, M48, etc.
 * Ligue com o comando 'M111 S32'.
 * NOTA: Requer muito PROGMEM!
 */
//#define DEBUG_LEVELING_FEATURE

#if ANY(MESH_BED_LEVELING, AUTO_BED_LEVELING_BILINEAR, AUTO_BED_LEVELING_UBL)
  // Reduza gradualmente a correção de nivelamento até que uma altura definida seja alcançada,
  // em que ponto o movimento estará nivelado com o plano XY da máquina.
  // A altura pode ser definida com M420 Z <height>
  #define ENABLE_LEVELING_FADE_HEIGHT

  // Para máquinas cartesianas, em vez de dividir os movimentos nos limites da malha,
  // divide os movimentos em segmentos curtos como um Delta. Isso segue o
  // contornos da cama mais próximos do que movimentos retos de ponta a ponta.
  #define SEGMENT_LEVELED_MOVES
  #define LEVELED_SEGMENT_LENGTH 5.0 // (mm) Comprimento de todos os segmentos (exceto o último)

  /**
   * Habilite a ferramenta G26 Mesh Validation Pattern.
   */
  //#define G26_MESH_VALIDATION
  #if ENABLED(G26_MESH_VALIDATION)
    #define MESH_TEST_NOZZLE_SIZE    0.4  // (mm) Diâmetro do bico primário.
    #define MESH_TEST_LAYER_HEIGHT   0.2  // (mm) Altura padrão da camada para a ferramenta de validação de malha G26.
    #define MESH_TEST_HOTEND_TEMP  205    // (°C) Temperatura padrão do bico para a ferramenta de validação de malha G26.
    #define MESH_TEST_BED_TEMP      60    // (°C) Temperatura padrão do leito para a ferramenta de validação de malha G26.
    #define G26_XY_FEEDRATE         20    // (mm/s) Velocidade de avanço para movimentos XY para a ferramenta de validação de malha G26.
    #define G26_RETRACT_MULTIPLIER   1.0  // G26 Q (retração) usado por padrão entre os elementos de teste de malha.
  #endif

#endif

#if EITHER(AUTO_BED_LEVELING_LINEAR, AUTO_BED_LEVELING_BILINEAR)

  // Defina o número de pontos de grade por dimensão.
  #define GRID_MAX_POINTS_X 3
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X
 // #define MIN_PROBE_EDGE_LEFT	20
 // #define MIN_PROBE_EDGE_RIGHT	260
 // #define MIN_PROBE_EDGE_FRONT	20
 // #define MIN_PROBE_EDGE_BACK	260

  // Sondar ao longo do eixo Y, avançando X após cada coluna
  #define PROBE_Y_FIRST

  #if ENABLED(AUTO_BED_LEVELING_BILINEAR)

    // Além da grade testada, continuar a inclinação implícita?
    // O padrão é manter a altura da borda mais próxima.
    //#define EXTRAPOLATE_BEYOND_GRID

    //
    // Subdivisão experimental da grade pelo método Catmull-Rom.
    // Sintetiza pontos intermediários para produzir uma malha mais detalhada.
    //
    //#define ABL_BILINEAR_SUBDIVISION
    #if ENABLED(ABL_BILINEAR_SUBDIVISION)
      // Número de subdivisões entre pontos de sondagem
      #define BILINEAR_SUBDIVISIONS 3
    #endif

  #endif

#elif ENABLED(AUTO_BED_LEVELING_UBL)

  //===========================================================================
  //========================= Unified Bed Leveling ============================
  //===========================================================================

  //#define MESH_EDIT_GFX_OVERLAY   // Exibir uma sobreposição de gráficos ao editar a malha

  #define MESH_INSET 1              // Defina os limites de malha como uma região interna da cama
  #define GRID_MAX_POINTS_X 10      // Não use mais de 15 pontos por eixo, implementação limitada.
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

  #define UBL_MESH_EDIT_MOVES_Z     // Usuários sofisticados preferem nenhum movimento do bico
  #define UBL_SAVE_ACTIVE_ON_M500   // Salve a malha atualmente ativa no slot atual no M500

  //#define UBL_Z_RAISE_WHEN_OFF_MESH 2.5 //Quando o bico está fora da malha, este valor é usado
                                          // como o valor de correção da altura Z.

#elif ENABLED(MESH_BED_LEVELING)

  //===========================================================================
  //=================================== Mesh ==================================
  //===========================================================================

  #define MESH_INSET 10          // Defina os limites de malha como uma região interna da cama
  #define GRID_MAX_POINTS_X 3    // Não use mais de 7 pontos por eixo, implementação limitada.
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

  //#define MESH_G28_REST_ORIGIN // Após o retorno, todos os eixos ('G28' ou 'G28 XYZ') repousam Z em Z_MIN_POS

#endif // BED_LEVELING

/**
 * Adicione um submenu de nivelamento da cama para ABL ou MBL.
 * Inclui um procedimento guiado se a sondagem manual estiver habilitada.
 */
#define LCD_BED_LEVELING

#if ENABLED(LCD_BED_LEVELING)
  #define MESH_EDIT_Z_STEP  0.025 // (mm) Tamanho do passo durante a medição manual do eixo Z.
  #define LCD_PROBE_Z_RANGE 4     // (mm) Faixa Z centrada em Z_MIN_POS para ajuste Z do LCD
  #define MESH_EDIT_MENU        // Adicione um menu para editar pontos de malha
#endif

// Adicione um item de menu para mover entre os cantos da cama para ajuste manual da cama
#define LEVEL_BED_CORNERS

#if ENABLED(LEVEL_BED_CORNERS)
  #define LEVEL_CORNERS_INSET_LFRB { 30, 30, 30, 30 } // (mm) Inserções à esquerda, à frente, à direita, atrás
  #define LEVEL_CORNERS_HEIGHT      0.0   // (mm) Z altura do bico em pontos de nivelamento
  #define LEVEL_CORNERS_Z_HOP       4.0   // (mm) Z altura do bico entre os pontos de nivelamento
  //#define LEVEL_CENTER_TOO              // Mova para o centro após a última curva
#endif

/**
 * Comandos a executar no final da apalpação G29.
 * Útil para retrair ou mover a sonda Z para fora do caminho.
 */
#define Z_PROBE_END_SCRIPT "G1 X154 Y154 Z20 F12000"

// @section homing

// O centro da cama está em (X = 0, Y = 0)
//#define BED_CENTER_AT_0_0

// Defina manualmente a posição inicial. Deixe-os indefinidos para configurações automáticas.
// Para DELTA, este é o centro superior do volume de impressão cartesiana.
//#define MANUAL_X_HOME_POS 0
//#define MANUAL_Y_HOME_POS 0
//#define MANUAL_Z_HOME_POS 0

// Use "Z Safe Homing" para evitar o retorno com uma sonda Z fora da área do leito.
//
// Com este recurso ativado:
//
// - Permitir o retorno Z somente após o retorno X e Y e os drivers de passo ainda habilitados.
// - Se os drivers de passo atingirem o tempo limite, ele precisará do retorno de X e Y novamente antes do retorno de Z.
// - Mova a sonda Z (ou bico) para um ponto XY definido antes do Z Homing.
// - Evita o retorno Z quando a sonda Z está fora da área do leito.
//
//#define Z_SAFE_HOMING

#if ENABLED(Z_SAFE_HOMING)
  #define Z_SAFE_HOMING_X_POINT X_CENTER  // X ponto para Z homing
  #define Z_SAFE_HOMING_Y_POINT Y_CENTER  // Y ponto para Z homing
#endif

// Homing speeds (mm/m)
#define HOMING_FEEDRATE_XY (50*60)
#define HOMING_FEEDRATE_Z  (4*60)

// Valide se as paradas finais são acionadas em movimentos de homing
#define VALIDATE_HOMING_ENDSTOPS

// @section calibrate

/**
 * Compensação de inclinação da cama
 *
 * Este recurso corrige o desalinhamento nos eixos XYZ.
 *
 * Siga os seguintes passos para inclinar a cama no plano XY:
 * 1. Imprima um quadrado de teste (por exemplo, https://www.thingiverse.com/thing:2563185)
 * 2. Para XY_DIAG_AC meça a diagonal de A a C
 * 3. Para XY_DIAG_BD meça a diagonal B a D
 * 4. Para XY_SIDE_AD meça a aresta A a D
 *
 * Marlin calcula automaticamente os fatores de inclinação a partir dessas medições.
 * Fatores de inclinação também podem ser calculados e definidos manualmente:
 *
 * - Calcular AB: SQRT (2 * AC * AC + 2 * BD * BD-4 * AD * AD) / 2
 * - XY_SKEW_FACTOR: TAN (PI / 2-ACOS ((AC * AC-AB * AB-AD * AD) / (2 * AB * AD)))
 *
 * Se desejar, siga o mesmo procedimento para XZ e YZ.
 * Use estes diagramas para referência:
 *
 *    Y                     Z                     Z
 *    ^     B-------C       ^     B-------C       ^     B-------C
 *    |    /       /        |    /       /        |    /       /
 *    |   /       /         |   /       /         |   /       /
 *    |  A-------D          |  A-------D          |  A-------D
 *    +-------------->X     +-------------->X     +-------------->Y
 *     XY_SKEW_FACTOR        XZ_SKEW_FACTOR        YZ_SKEW_FACTOR
 */
//#define SKEW_CORRECTION

#if ENABLED(SKEW_CORRECTION)
  // Input all length measurements here:
  #define XY_DIAG_AC 282.8427124746
  #define XY_DIAG_BD 282.8427124746
  #define XY_SIDE_AD 200

  // Ou defina os fatores de inclinação padrão diretamente aqui
  // para substituir as medidas acima:
  #define XY_SKEW_FACTOR 0.0

  //#define SKEW_CORRECTION_FOR_Z
  #if ENABLED(SKEW_CORRECTION_FOR_Z)
    #define XZ_DIAG_AC 282.8427124746
    #define XZ_DIAG_BD 282.8427124746
    #define YZ_DIAG_AC 282.8427124746
    #define YZ_DIAG_BD 282.8427124746
    #define YZ_SIDE_AD 200
    #define XZ_SKEW_FACTOR 0.0
    #define YZ_SKEW_FACTOR 0.0
  #endif

  // Habilite esta opção para M852 para definir a inclinação em tempo de execução
  //#define SKEW_CORRECTION_GCODE
#endif

//=============================================================================
//============================= Additional Features ===========================
//=============================================================================

// @section extras

/**
 * EEPROM
 *
 * Armazenamento persistente para preservar as configurações configuráveis durante as reinicializações.
 *
 * M500 - Armazena configurações em EEPROM.
 * M501 - Lê as configurações da EEPROM. (ou seja, descartar as alterações não salvas)
 * M502 - Reverte as configurações para os padrões de "fábrica". (Siga com M500 para iniciar a EEPROM.)
 */
#define EEPROM_SETTINGS     // Armazenamento persistente com M500 e M501
//#define DISABLE_M503        // Salva ~ 2700 bytes de PROGMEM. Desativar para lançamento!
#define EEPROM_CHITCHAT       // Dê feedback sobre os comandos EEPROM. Desative para salvar PROGMEM.
#define EEPROM_BOOT_SILENT    // Mantenha M503 silencioso e forneça erros apenas durante o primeiro carregamento
#if ENABLED(EEPROM_SETTINGS)
  //#define EEPROM_AUTO_INIT  // Init EEPROM automaticamente em qualquer erro.
#endif

//
// Host Keepalive
//
// Quando habilitado, o Marlin enviará uma mensagem de status de ocupado para o host
// a cada dois segundos quando não pode aceitar comandos.
//
#define HOST_KEEPALIVE_FEATURE        // Desative isto se o seu host não gosta de mensagens de manutenção de atividade
#define DEFAULT_KEEPALIVE_INTERVAL 2  // Número de segundos entre mensagens de "ocupado". Definido com M113.
#define BUSY_WHILE_HEATING            // Alguns hosts exigem mensagens de "ocupado" mesmo durante o aquecimento

//
// Suporte ao modo G20 / G21 Inch
//
//#define INCH_MODE_SUPPORT

//
// M149 Definir suporte de unidades de temperatura
//
//#define TEMPERATURE_UNITS_SUPPORT

// @section temperature

// Constantes de pré-aquecimento
#define PREHEAT_1_LABEL       "PLA"
#define PREHEAT_1_TEMP_HOTEND 180
#define PREHEAT_1_TEMP_BED     50
#define PREHEAT_1_FAN_SPEED    50 // Value from 0 to 255

#define PREHEAT_2_LABEL       "ABS"
#define PREHEAT_2_TEMP_HOTEND 200
#define PREHEAT_2_TEMP_BED     80
#define PREHEAT_2_FAN_SPEED     0 // Value from 0 to 255

/**
* Nozzle Park
  *
  * Estacione o bico na posição XYZ fornecida em marcha lenta ou G27.
  *
  * O parâmetro "P" controla a ação aplicada ao eixo Z:
  *
  * P0 (padrão) Se Z estiver abaixo de Z estacionado, levante o bocal.
  * P1 Eleve o bocal sempre até a altura Z-park.
  * P2 Levante o bocal pela quantidade Z-park, limitada a Z_MAX_POS.
 */
#define NOZZLE_PARK_FEATURE

#if ENABLED(NOZZLE_PARK_FEATURE)
  // Especifique uma posição de estacionamento como{ X, Y, Z_raise }
  #define NOZZLE_PARK_POINT { (X_MIN_POS + 10), (Y_MAX_POS - 10), 20 }
  //#define NOZZLE_PARK_X_ONLY          // X mover apenas é necessário para estacionar
  //#define NOZZLE_PARK_Y_ONLY          // Y mover apenas é necessário para estacionar
  #define NOZZLE_PARK_Z_RAISE_MIN   2   // (mm) Sempre eleve Z por pelo menos esta distância
  #define NOZZLE_PARK_XY_FEEDRATE 100   // (mm/s) Avanço dos eixos X e Y (também usado para o eixo delta Z)
  #define NOZZLE_PARK_Z_FEEDRATE    5   // (mm/s) Taxa de avanço do eixo Z (não usado para impressoras delta)
#endif

/**
* Recurso de limpeza do bico - EXPERIMENTAL
 *
 * Adiciona o comando G12 para realizar um processo de limpeza do bico.
 *
 * Parâmetros:
 * Padrão P
 * S Strokes / Repetições
 * Triângulos T (apenas P1)
 *
 * Padrões:
 * P0 Linha reta (padrão). Este processo requer um material tipo esponja
 * em um local de leito fixo. "S" especifica golpes (ou seja, movimentos para trás)
 * entre os pontos inicial / final.
 *
 * P1 Zig-zag padrão entre (X0, Y0) e (X1, Y1), "T" especifica o
 * número de triângulos em zigue-zague para fazer. "S" define o número de golpes.
 * Os ziguezagues são feitos na dimensão mais estreita.
 * Por exemplo, "G12 P1 S1 T3" executará:
 *
 *          --
 *         |  (X0, Y1) |     /\        /\        /\     | (X1, Y1)
 *         |           |    /  \      /  \      /  \    |
 *       A |           |   /    \    /    \    /    \   |
 *         |           |  /      \  /      \  /      \  |
 *         |  (X0, Y0) | /        \/        \/        \ | (X1, Y0)
 *          --         +--------------------------------+
 *                       |________|_________|_________|
 *                           T1        T2        T3
 *
 * Padrão circular P2 com meio em NOZZLE_CLEAN_CIRCLE_MIDDLE.
 * "R" especifica o raio. "S" especifica a contagem de traços.
 * Antes de iniciar, o bico move-se para NOZZLE_CLEAN_START_POINT.
 *
 * Advertências: O Z final deve ser igual ao Z inicial.
 * Atenção: EXPERIMENTAL. Os argumentos do código G podem mudar.
 *
 */
//#define NOZZLE_CLEAN_FEATURE

#if ENABLED(NOZZLE_CLEAN_FEATURE)
  // Número padrão de repetições de padrão
  #define NOZZLE_CLEAN_STROKES  12

  // Default number of triangles
  #define NOZZLE_CLEAN_TRIANGLES  3

  // Especifique as posições para cada ferramenta como {{X, Y, Z}, {X, Y, Z}}
  // Sistema de hotend duplo pode usar {{-20, (Y_BED_SIZE / 2), (Z_MIN_POS + 1)}, {420, (Y_BED_SIZE / 2), (Z_MIN_POS + 1)}}
  #define NOZZLE_CLEAN_START_POINT { {  30, 30, (Z_MIN_POS + 1) } }
  #define NOZZLE_CLEAN_END_POINT   { { 100, 60, (Z_MIN_POS + 1) } }

  // Raio de padrão circular
  #define NOZZLE_CLEAN_CIRCLE_RADIUS 6.5
  // Número de fragmentos de círculo de padrão circular
  #define NOZZLE_CLEAN_CIRCLE_FN 10
  // Ponto médio do círculo
  #define NOZZLE_CLEAN_CIRCLE_MIDDLE NOZZLE_CLEAN_START_POINT

  // Mova o bico para a posição inicial após a limpeza
  #define NOZZLE_CLEAN_GOBACK

  // Ative para uma estação de purga / limpeza que está sempre na altura do gantry (portanto, nenhum movimento Z)
  //#define NOZZLE_CLEAN_NO_Z

  // O script de apagamento explícito do código G se aplica a um G12 sem argumentos.
  //#define WIPE_SEQUENCE_COMMANDS "G1 X-17 Y25 Z10 F4000\nG1 Z1\nM114\nG1 X-17 Y25\nG1 X-17 Y95\nG1 X-17 Y25\nG1 X-17 Y95\nG1 X-17 Y25\nG1 X-17 Y95\nG1 X-17 Y25\nG1 X-17 Y95\nG1 X-17 Y25\nG1 X-17 Y95\nG1 X-17 Y25\nG1 X-17 Y95\nG1 Z15\nM400\nG0 X-10.0 Y-9.0"

#endif

/**
* Timer de trabalho de impressão
*
* Iniciar e parar automaticamente o temporizador do trabalho de impressão em M104 / M109 / M190.
*
* M104 (hotend, sem espera) - alta temperatura = nenhuma, baixa temperatura = parar o cronômetro
* M109 (hotend, esperar) - alta temperatura = iniciar cronômetro, baixa temperatura = parar cronômetro
* M190 (cama, espera) - alta temperatura = iniciar cronômetro, baixa temperatura = nenhum
*
* O cronômetro também pode ser controlado com os seguintes comandos:
*
* M75 - Iniciar o cronômetro do trabalho de impressão
* M76 - Pausar o cronômetro do trabalho de impressão
* M77 - Pare o cronômetro do trabalho de impressão
 */
//#define PRINTJOB_TIMER_AUTOSTART

/**
* Imprimir contador
*
* Rastreie dados estatísticos como:
*
* - Total de trabalhos de impressão
* - Total de trabalhos de impressão bem-sucedidos
* - Total de trabalhos de impressão com falha
* - Tempo total de impressão
*
* Veja as estatísticas atuais com M78.
 */
//#define PRINTCOUNTER

//=============================================================================
//============================= LCD and SD support ============================
//=============================================================================

// @section lcd

/**
 * LCD LANGUAGE
 *
 * Selecione o idioma a ser exibido no LCD. Esses idiomas estão disponíveis:
 *
 *   en, an, bg, ca, cz, da, de, el, el_gr, es, eu, fi, fr, gl, hr, hu, it,
 *   jp_kana, ko_KR, nl, pl, pt, pt_br, ro ru, sk, tr, uk, vi, zh_CN, zh_TW, test
 *
 * :{ 'en':'English', 'an':'Aragonese', 'bg':'Bulgarian', 'ca':'Catalan', 'cz':'Czech', 'da':'Danish', 'de':'German', 'el':'Greek', 'el_gr':'Greek (Greece)', 'es':'Spanish', 'eu':'Basque-Euskera', 'fi':'Finnish', 'fr':'French', 'gl':'Galician', 'hr':'Croatian', 'hu':'Hungarian', 'it':'Italian', 'jp_kana':'Japanese', 'ko_KR':'Korean (South Korea)', 'nl':'Dutch', 'pl':'Polish', 'pt':'Portuguese', 'pt_br':'Portuguese (Brazilian)', 'ro':'Romanian', 'ru':'Russian', 'sk':'Slovak', 'tr':'Turkish', 'uk':'Ukrainian', 'vi':'Vietnamese', 'zh_CN':'Chinese (Simplified)', 'zh_TW':'Chinese (Traditional)', 'test':'TEST' }
 */
#define LCD_LANGUAGE pt_br

/**
 * Conjunto de caracteres LCD
 *
 * Observação: esta opção NÃO se aplica a monitores gráficos.
 *
 * Todos os LCDs baseados em caracteres fornecem ASCII mais um destes
 * extensões de idioma:
 *
 * - JAPONÊS ... o mais comum
 * - OCIDENTAL ... com caracteres mais acentuados
 * - CIRÍLICO ... para o idioma russo
 *
 * Para determinar a extensão de idioma instalada em seu controlador:
 *
 * - Compile e carregue com LCD_LANGUAGE definido como 'teste'
 * - Clique no controlador para visualizar o menu LCD
 * - O LCD exibirá texto em japonês, ocidental ou cirílico
 *
 * Veja https://marlinfw.org/docs/development/lcd_language.html
 *
 * :['JAPANESE', 'WESTERN', 'CYRILLIC']
 */
#define DISPLAY_CHARSET_HD44780 JAPANESE

/**
 * Estilo da tela de informações (0: Clássico, 1: Prusa)
 *
 *: [0: 'Clássico', 1: 'Prusa']
 */
#define LCD_INFO_SCREEN_STYLE 0

/**
 * CARTÃO SD
 *
 * O suporte ao cartão SD está desabilitado por padrão. Se o seu controlador tiver um slot SD,
 * você deve descomentar a seguinte opção ou não funcionará.
 *
 */
#define SDSUPPORT

/**
* CARTÃO SD: SPI SPEED
*
* Ative um dos seguintes itens para uma velocidade de transferência SPI mais lenta.
* Isso pode ser necessário para resolver erros de "inicialização de volume".
 */
//#define SPI_SPEED SPI_HALF_SPEED
//#define SPI_SPEED SPI_QUARTER_SPEED
//#define SPI_SPEED SPI_EIGHTH_SPEED

/**
 * CARTÃO SD: ATIVAR CRC
 *
 * Use verificações e novas tentativas de CRC na comunicação SD.
 */
#define SD_CHECK_AND_RETRY

/**
 * Itens do menu LCD
 *
 * Desative todos os menus e exiba apenas a tela de status, ou
 * apenas remova alguns itens de menu estranhos para recuperar espaço.
 */
//#define NO_LCD_MENUS
//#define SLIM_LCD_MENUS

//
// CONFIGURAÇÕES DO ENCODER
//
// Esta opção substitui o número padrão de pulsos do codificador necessários para
// produz uma etapa. Deve ser aumentado para codificadores de alta resolução.
//
//#define ENCODER_PULSES_PER_STEP 4

//
// Use esta opção para substituir o número de sinais de etapa necessários para
// mover entre os itens do menu seguinte / anterior.
//
//#define ENCODER_STEPS_PER_MENU_ITEM 1

/**
 * Opções de direção do codificador
 *
 * Teste o comportamento do seu codificador primeiro com ambas as opções desabilitadas.
 *
 * Edição de valor invertida e navegação no menu? Ative REVERSE_ENCODER_DIRECTION.
 * Somente navegação de menu invertida? Ative REVERSE_MENU_DIRECTION.
 * Somente edição de valor invertido? Habilite AMBAS opções.
 */

//
// Esta opção inverte a direção do codificador em todos os lugares.
//
// Defina esta opção se CLOCKWISE fizer com que os valores diminuam
//
//#define REVERSE_ENCODER_DIRECTION

//
// Esta opção inverte a direção do codificador para navegar nos menus LCD.
//
// Se normalmente no sentido horário se move para BAIXO, isso o faz subir.
// Se no sentido horário normalmente move para cima, isso faz com que ele vá para baixo.
//
//#define REVERSE_MENU_DIRECTION

//
// Esta opção inverte a direção do codificador para a tela de seleção.
//
// Se normalmente no sentido HORÁRIO se move para a ESQUERDA, isso o torna para a DIREITA.
// Se normalmente no sentido HORÁRIO se mover para a DIREITA, ele irá para a ESQUERDA.
//
//#define REVERSE_SELECT_DIRECTION

//
// Homing de eixo individual
//
// Adicionar itens de homing de eixo individuais (Home X, Home Y e Home Z) ao menu LCD.
//
#define INDIVIDUAL_AXIS_HOMING_MENU

//
// ALTO-FALANTE / BUZZER
//
// Se você tem um alto-falante que pode produzir tons, habilite-o aqui.
// Por padrão, o Marlin assume que você tem uma campainha com frequência fixa.
//
#define SPEAKER

//
// A duração e frequência do som de feedback da IU.
// Defina como 0 para desativar o feedback de áudio nos menus LCD.
//
// Nota: Teste a saída de áudio com o Código G:
// M300 S <frequência Hz> P <duração ms>
//
#define LCD_FEEDBACK_FREQUENCY_DURATION_MS 8
#define LCD_FEEDBACK_FREQUENCY_HZ 3500

//=============================================================================
//======================== LCD / Controller Selection =========================
//========================   (Character-based LCDs)   =========================
//=============================================================================

//
// RepRapDiscount Smart Controller.
// https://reprap.org/wiki/RepRapDiscount_Smart_Controller
//
// Note: Usually sold with a white PCB.
//
//#define REPRAP_DISCOUNT_SMART_CONTROLLER

//
// Original RADDS LCD Display+Encoder+SDCardReader
// http://doku.radds.org/dokumentation/lcd-display/
//
//#define RADDS_DISPLAY

//
// ULTIMAKER Controller.
//
//#define ULTIMAKERCONTROLLER

//
// ULTIPANEL as seen on Thingiverse.
//
//#define ULTIPANEL

//
// PanelOne from T3P3 (via RAMPS 1.4 AUX2/AUX3)
// https://reprap.org/wiki/PanelOne
//
//#define PANEL_ONE

//
// GADGETS3D G3D LCD/SD Controller
// https://reprap.org/wiki/RAMPS_1.3/1.4_GADGETS3D_Shield_with_Panel
//
// Note: Usually sold with a blue PCB.
//
//#define G3D_PANEL

//
// RigidBot Panel V1.0
// http://www.inventapart.com/
//
//#define RIGIDBOT_PANEL

//
// Makeboard 3D Printer Parts 3D Printer Mini Display 1602 Mini Controller
// https://www.aliexpress.com/item/32765887917.html
//
//#define MAKEBOARD_MINI_2_LINE_DISPLAY_1602

//
// ANET and Tronxy 20x4 Controller
//
//#define ZONESTAR_LCD            // Requires ADC_KEYPAD_PIN to be assigned to an analog pin.
                                  // This LCD is known to be susceptible to electrical interference
                                  // which scrambles the display.  Pressing any button clears it up.
                                  // This is a LCD2004 display with 5 analog buttons.

//
// Generic 16x2, 16x4, 20x2, or 20x4 character-based LCD.
//
//#define ULTRA_LCD

//=============================================================================
//======================== LCD / Controller Selection =========================
//=====================   (I2C and Shift-Register LCDs)   =====================
//=============================================================================

//
// CONTROLLER TYPE: I2C
//
// Note: These controllers require the installation of Arduino's LiquidCrystal_I2C
// library. For more info: https://github.com/kiyoshigawa/LiquidCrystal_I2C
//

//
// Elefu RA Board Control Panel
// http://www.elefu.com/index.php?route=product/product&product_id=53
//
//#define RA_CONTROL_PANEL

//
// Sainsmart (YwRobot) LCD Displays
//
// These require F.Malpartida's LiquidCrystal_I2C library
// https://bitbucket.org/fmalpartida/new-liquidcrystal/wiki/Home
//
//#define LCD_SAINSMART_I2C_1602
//#define LCD_SAINSMART_I2C_2004

//
// Generic LCM1602 LCD adapter
//
//#define LCM1602

//
// PANELOLU2 LCD with status LEDs,
// separate encoder and click inputs.
//
// Note: This controller requires Arduino's LiquidTWI2 library v1.2.3 or later.
// For more info: https://github.com/lincomatic/LiquidTWI2
//
// Note: The PANELOLU2 encoder click input can either be directly connected to
// a pin (if BTN_ENC defined to != -1) or read through I2C (when BTN_ENC == -1).
//
//#define LCD_I2C_PANELOLU2

//
// Panucatt VIKI LCD with status LEDs,
// integrated click & L/R/U/D buttons, separate encoder inputs.
//
//#define LCD_I2C_VIKI

//
// CONTROLLER TYPE: Shift register panels
//

//
// 2-wire Non-latching LCD SR from https://goo.gl/aJJ4sH
// LCD configuration: https://reprap.org/wiki/SAV_3D_LCD
//
//#define SAV_3DLCD

//
// 3-wire SR LCD with strobe using 74HC4094
// https://github.com/mikeshub/SailfishLCD
// Uses the code directly from Sailfish
//
//#define FF_INTERFACEBOARD

//=============================================================================
//=======================   LCD / Controller Selection  =======================
//=========================      (Graphical LCDs)      ========================
//=============================================================================

//
// CONTROLLER TYPE: Graphical 128x64 (DOGM)
//
// IMPORTANT: The U8glib library is required for Graphical Display!
//            https://github.com/olikraus/U8glib_Arduino
//
// NOTE: If the LCD is unresponsive you may need to reverse the plugs.
//

//
// RepRapDiscount FULL GRAPHIC Smart Controller
// https://reprap.org/wiki/RepRapDiscount_Full_Graphic_Smart_Controller
//
#define REPRAP_DISCOUNT_FULL_GRAPHIC_SMART_CONTROLLER

//
// ReprapWorld Graphical LCD
// https://reprapworld.com/?products_details&products_id/1218
//
//#define REPRAPWORLD_GRAPHICAL_LCD

//
// Activate one of these if you have a Panucatt Devices
// Viki 2.0 or mini Viki with Graphic LCD
// https://www.panucatt.com
//
//#define VIKI2
//#define miniVIKI

//
// MakerLab Mini Panel with graphic
// controller and SD support - https://reprap.org/wiki/Mini_panel
//
//#define MINIPANEL

//
// MaKr3d Makr-Panel with graphic controller and SD support.
// https://reprap.org/wiki/MaKr3d_MaKrPanel
//
//#define MAKRPANEL

//
// Adafruit ST7565 Full Graphic Controller.
// https://github.com/eboston/Adafruit-ST7565-Full-Graphic-Controller/
//
//#define ELB_FULL_GRAPHIC_CONTROLLER

//
// BQ LCD Smart Controller shipped by
// default with the BQ Hephestos 2 and Witbox 2.
//
//#define BQ_LCD_SMART_CONTROLLER

//
// Cartesio UI
// http://mauk.cc/webshop/cartesio-shop/electronics/user-interface
//
//#define CARTESIO_UI

//
// LCD for Melzi Card with Graphical LCD
//
//#define LCD_FOR_MELZI

//
// Original Ulticontroller from Ultimaker 2 printer with SSD1309 I2C display and encoder
// https://github.com/Ultimaker/Ultimaker2/tree/master/1249_Ulticontroller_Board_(x1)
//
//#define ULTI_CONTROLLER

//
// MKS MINI12864 with graphic controller and SD support
// https://reprap.org/wiki/MKS_MINI_12864
//
//#define MKS_MINI_12864

//
// MKS LCD12864A/B with graphic controller and SD support. Follows MKS_MINI_12864 pinout.
// https://www.aliexpress.com/item/33018110072.html
//
//#define MKS_LCD12864

//
// FYSETC variant of the MINI12864 graphic controller with SD support
// https://wiki.fysetc.com/Mini12864_Panel/
//
//#define FYSETC_MINI_12864_X_X    // Type C/D/E/F. No tunable RGB Backlight by default
//#define FYSETC_MINI_12864_1_2    // Type C/D/E/F. Simple RGB Backlight (always on)
//#define FYSETC_MINI_12864_2_0    // Type A/B. Discreet RGB Backlight
//#define FYSETC_MINI_12864_2_1    // Type A/B. Neopixel RGB Backlight
//#define FYSETC_GENERIC_12864_1_1 // Larger display with basic ON/OFF backlight.

//
// Factory display for Creality CR-10
// https://www.aliexpress.com/item/32833148327.html
//
// This is RAMPS-compatible using a single 10-pin connector.
// (For CR-10 owners who want to replace the Melzi Creality board but retain the display)
//
//#define CR10_STOCKDISPLAY

//
// Ender-2 OEM display, a variant of the MKS_MINI_12864
//
//#define ENDER2_STOCKDISPLAY

//
// ANET and Tronxy Graphical Controller
//
// Anet 128x64 full graphics lcd with rotary encoder as used on Anet A6
// A clone of the RepRapDiscount full graphics display but with
// different pins/wiring (see pins_ANET_10.h).
//
//#define ANET_FULL_GRAPHICS_LCD

//
// AZSMZ 12864 LCD with SD
// https://www.aliexpress.com/item/32837222770.html
//
//#define AZSMZ_12864

//
// Silvergate GLCD controller
// https://github.com/android444/Silvergate
//
//#define SILVER_GATE_GLCD_CONTROLLER

//=============================================================================
//==============================  OLED Displays  ==============================
//=============================================================================

//
// SSD1306 OLED full graphics generic display
//
//#define U8GLIB_SSD1306

//
// SAV OLEd LCD module support using either SSD1306 or SH1106 based LCD modules
//
//#define SAV_3DGLCD
#if ENABLED(SAV_3DGLCD)
  #define U8GLIB_SSD1306
  //#define U8GLIB_SH1106
#endif

//
// TinyBoy2 128x64 OLED / Encoder Panel
//
//#define OLED_PANEL_TINYBOY2

//
// MKS OLED 1.3" 128 × 64 FULL GRAPHICS CONTROLLER
// https://reprap.org/wiki/MKS_12864OLED
//
// Tiny, but very sharp OLED display
//
//#define MKS_12864OLED          // Uses the SH1106 controller (default)
//#define MKS_12864OLED_SSD1306  // Uses the SSD1306 controller

//
// Einstart S OLED SSD1306
//
//#define U8GLIB_SH1106_EINSTART

//
// Overlord OLED display/controller with i2c buzzer and LEDs
//
//#define OVERLORD_OLED

//
// FYSETC OLED 2.42" 128 × 64 FULL GRAPHICS CONTROLLER with WS2812 RGB
// Where to find : https://www.aliexpress.com/item/4000345255731.html
//#define FYSETC_242_OLED_12864   // Uses the SSD1309 controller

//=============================================================================
//========================== Extensible UI Displays ===========================
//=============================================================================

//
// DGUS Touch Display with DWIN OS. (Choose one.)
// ORIGIN : https://www.aliexpress.com/item/32993409517.html
// FYSETC : https://www.aliexpress.com/item/32961471929.html
//
//#define DGUS_LCD_UI_ORIGIN
//#define DGUS_LCD_UI_FYSETC
//#define DGUS_LCD_UI_HIPRECY

//
// Touch-screen LCD for Malyan M200/M300 printers
//
//#define MALYAN_LCD

//
// Touch UI for FTDI EVE (FT800/FT810) displays
// See Configuration_adv.h for all configuration options.
//
//#define TOUCH_UI_FTDI_EVE

//
// Third-party or vendor-customized controller interfaces.
// Sources should be installed in 'src/lcd/extensible_ui'.
//
//#define EXTENSIBLE_UI

#if ENABLED(EXTENSIBLE_UI)
  //#define EXTUI_LOCAL_BEEPER // Enables use of local Beeper pin with external display
#endif

//=============================================================================
//=============================== Graphical TFTs ==============================
//=============================================================================

//
// FSMC display (MKS Robin, Alfawise U20, JGAurora A5S, REXYZ A1, etc.)
// Upscaled 128x64 Marlin UI
//
//#define FSMC_GRAPHICAL_TFT

//
// TFT LVGL UI
//
// Using default MKS icons and fonts from: https://git.io/JJvzK
// Just copy the 'assets' folder from the build directory to the
// root of your SD card, together with the compiled firmware.
//
//#define TFT_LVGL_UI_FSMC  // Robin nano v1.2 uses FSMC
//#define TFT_LVGL_UI_SPI   // Robin nano v2.0 uses SPI

//
// Anycubic Mega TFT (AI3M)
//
//#define ANYCUBIC_TFT_MODEL
//#define ANYCUBIC_TFT_DEBUG

//=============================================================================
//============================  Other Controllers  ============================
//=============================================================================

//
// Ender-3 v2 OEM display. A DWIN display with Rotary Encoder.
//
//#define DWIN_CREALITY_LCD

//
// ADS7843/XPT2046 ADC Touchscreen such as ILI9341 2.8
//
//#define TOUCH_BUTTONS
#if ENABLED(TOUCH_BUTTONS)
  #define BUTTON_DELAY_EDIT  50 // (ms) Button repeat delay for edit screens
  #define BUTTON_DELAY_MENU 250 // (ms) Button repeat delay for menus

  #define XPT2046_X_CALIBRATION   12316
  #define XPT2046_Y_CALIBRATION  -8981
  #define XPT2046_X_OFFSET       -43
  #define XPT2046_Y_OFFSET        257
#endif

//
// RepRapWorld REPRAPWORLD_KEYPAD v1.1
// https://reprapworld.com/?products_details&products_id=202&cPath=1591_1626
//
//#define REPRAPWORLD_KEYPAD
//#define REPRAPWORLD_KEYPAD_MOVE_STEP 10.0 // (mm) Distance to move per key-press

//=============================================================================
//=============================== Extra Features ==============================
//=============================================================================

// @section extras

// Aumente a frequência FAN PWM. Remove o ruído PWM, mas aumenta o aquecimento no FET / Arduino
// # define FAST_PWM_FAN

// Use o software PWM para acionar a ventoinha, assim como os aquecedores. Isso usa uma frequência muito baixa
// o que não é tão chato quanto com o hardware PWM. Por outro lado, se esta frequência
// é muito baixo, você também deve incrementar SOFT_PWM_SCALE.
// # define FAN_SOFT_PWM

// Incrementar em 1 dobrará a frequência PWM do software,
// afetando os aquecedores e o ventilador se FAN_SOFT_PWM estiver habilitado.
// No entanto, a resolução do controle será reduzida à metade para cada incremento;
// no valor zero, existem 128 posições de controle efetivas.
// :[0,1,2,3,4,5,6,7]
#define SOFT_PWM_SCALE 0

// Se SOFT_PWM_SCALE for definido com um valor superior a 0, o pontilhamento pode
// ser usado para mitigar a perda de resolução associada. Se habilitado,
// alguns dos ciclos PWM são alongados, então, em média, o desejado
// o ciclo de trabalho é atingido.
//#define SOFT_PWM_DITHER

// Temperature status LEDs that display the hotend and bed temperature.
// If all hotends, bed temperature, and target temperature are under 54C
// then the BLUE led is on. Otherwise the RED led is on. (1C hysteresis)
//#define TEMP_STAT_LEDS

// SkeinForge sends the wrong arc G-codes when using Arc Point as fillet procedure
//#define SF_ARC_FIX

// Support for the BariCUDA Paste Extruder
//#define BARICUDA

// Support for BlinkM/CyzRgb
//#define BLINKM

// Support for PCA9632 PWM LED driver
//#define PCA9632

// Support for PCA9533 PWM LED driver
//#define PCA9533

/**
 * RGB LED / LED Strip Control
 *
 * Enable support for an RGB LED connected to 5V digital pins, or
 * an RGB Strip connected to MOSFETs controlled by digital pins.
 *
 * Adds the M150 command to set the LED (or LED strip) color.
 * If pins are PWM capable (e.g., 4, 5, 6, 11) then a range of
 * luminance values can be set from 0 to 255.
 * For Neopixel LED an overall brightness parameter is also available.
 *
 * *** CAUTION ***
 *  LED Strips require a MOSFET Chip between PWM lines and LEDs,
 *  as the Arduino cannot handle the current the LEDs will require.
 *  Failure to follow this precaution can destroy your Arduino!
 *  NOTE: A separate 5V power supply is required! The Neopixel LED needs
 *  more current than the Arduino 5V linear regulator can produce.
 * *** CAUTION ***
 *
 * LED Type. Enable only one of the following two options.
 *
 */
//#define RGB_LED
//#define RGBW_LED

#if EITHER(RGB_LED, RGBW_LED)
  //#define RGB_LED_R_PIN 34
  //#define RGB_LED_G_PIN 43
  //#define RGB_LED_B_PIN 35
  //#define RGB_LED_W_PIN -1
#endif

// Support for Adafruit Neopixel LED driver
//#define NEOPIXEL_LED
#if ENABLED(NEOPIXEL_LED)
  #define NEOPIXEL_TYPE   NEO_GRBW // NEO_GRBW / NEO_GRB - four/three channel driver type (defined in Adafruit_NeoPixel.h)
  #define NEOPIXEL_PIN     4       // LED driving pin
  //#define NEOPIXEL2_TYPE NEOPIXEL_TYPE
  //#define NEOPIXEL2_PIN    5
  #define NEOPIXEL_PIXELS 30       // Number of LEDs in the strip, larger of 2 strips if 2 neopixel strips are used
  #define NEOPIXEL_IS_SEQUENTIAL   // Sequential display for temperature change - LED by LED. Disable to change all LEDs at once.
  #define NEOPIXEL_BRIGHTNESS 127  // Initial brightness (0-255)
  //#define NEOPIXEL_STARTUP_TEST  // Cycle through colors at startup

  // Use a single Neopixel LED for static (background) lighting
  //#define NEOPIXEL_BKGD_LED_INDEX  0               // Index of the LED to use
  //#define NEOPIXEL_BKGD_COLOR { 255, 255, 255, 0 } // R, G, B, W
#endif

/**
 * Printer Event LEDs
 *
 * During printing, the LEDs will reflect the printer status:
 *
 *  - Gradually change from blue to violet as the heated bed gets to target temp
 *  - Gradually change from violet to red as the hotend gets to temperature
 *  - Change to white to illuminate work surface
 *  - Change to green once print has finished
 *  - Turn off after the print has finished and the user has pushed a button
 */
#if ANY(BLINKM, RGB_LED, RGBW_LED, PCA9632, PCA9533, NEOPIXEL_LED)
  #define PRINTER_EVENT_LEDS
#endif

/**
 * R/C SERVO support
 * Sponsored by TrinityLabs, Reworked by codexmas
 */

/**
 * Number of servos
 *
 * For some servo-related options NUM_SERVOS will be set automatically.
 * Set this manually if there are extra servos needing manual control.
 * Leave undefined or set to 0 to entirely disable the servo subsystem.
 */
//#define NUM_SERVOS 3 // Servo index starts with 0 for M280 command

// (ms) Delay  before the next move will start, to give the servo time to reach its target angle.
// 300ms is a good value but you can try less delay.
// If the servo can't reach the requested position, increase it.
#define SERVO_DELAY { 300 }

// Only power servos during movement, otherwise leave off to prevent jitter
//#define DEACTIVATE_SERVOS_AFTER_MOVE

// Allow servo angle to be edited and saved to EEPROM
//#define EDITABLE_SERVO_ANGLES
