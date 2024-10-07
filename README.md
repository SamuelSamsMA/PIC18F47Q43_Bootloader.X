# Bootloader para el MCU PIC18F47Q43

Esta aplicación implementa un sistema de arranque desarrollado con el MPLAB
Code Configurator (MCC) de Microchip, para grabar cualquier aplicación
en el PIC sin necesidad de un programador.

El tutorial completo de Microchip se puede encontrar [aquí](https://onlinedocs.microchip.com/oxy/GUID-67539092-2179-43C1-8600-118A85E49693-en-US-6/GUID-20665109-2EE3-4095-BAED-C0D0497A0221.html).

## Requerimientos del sistema
Esta aplicación ha sido probada con el siguiente software y hardware:

+ MPLABX IDE v6.20
+ MPLAB Code Configurator (MCC) v5.5.1
+ Librería de dispositivos
    + PIC10/PIC12/PIC16/PIC18 v5.28.2
+ XC8 Compiler v2.5
+ Microchip Firmware Image Builder
    + pyfwimagebuilder v1.0.1.14 or later
+ Microchip Device Firmware Upgrade
    + pymdfu v2.4.0.8 or later
+ Programador
    + ICD4
+ Microcontrolador
    + PIC18F47Q43, 40 Pin PDIP

## Parámetros del bootloader

+ Communication Protocol: UART
+ Application Start Address: 0x2000
+ Memory Verification: Checksum

## Asignación de pines

| Dirección | Función        |
|-----------|----------------|
| RA0       | UART: RX       |
| RA1       | UART: TX       |
| RE0       | BOOT: ENTRY    |
| RE1       | BOOT: INDICATE |

## Parámetros de la comunicación serial

+ Baudrate: **9600**
+ Parity: **None**
+ Data size: **8**
+ Stop bits: **1**

## Configuración del MCC para otros proyectos

Todos los proyectos que utilicen este bootloader como base deberán configurar
los siguientes puntos tal cual en el MCC:

+ Clock Settings
    + Clock Source: **HFINTOSC**
    + HF Internal Clock: **64_MHz**
    + Clock Divider: **1**

+ CONFIG1
    + External Oscillator Selection: **Oscillator not enabled**
    + Reset Oscillator Selection: **HFINTOSC with HFFRQ = 64 MHz and CDIV = 1:1**

+ CONFIG2
    + Clock out Enable bit: **CLKOUT function is disabled**
    + Fail-Safe Clock Monitor Enable bit: **Fail-Safe Clock Monitor enabled**
    + Clock Switch Enable bit: **Writing to NOSC and NDIV is allowed**
    + PRLOCKED One-Way Set Enable bit: **PRLOCKED bit can be cleared and set only once**

+ CONFIG3
    + Multi-vector enable bit: **Interrupt contoller does not use vector table to prioritze interrupts**
    + MCLR Enable bit: **If LVP = 0, MCLR pin is MCLR; If LVP = 1, RE3 pin function is MCLR**
    + Brown-out Reset Enable bits: **Brown-out Reset enabled , SBOREN bit is ignored**
    + Power-up timer selection bits: **PWRT set at 16ms**
    + IVTLOCK bit One-way set enable bit: **IVTLOCKED bit can be cleared and set only once**
    + Low Power BOR Enable bit: **Low-Power BOR disabled**

+ CONFIG4
    + Extended Instruction Set Enable bit: **Extended Instruction Set and Indexed Addressing Mode disabled**
    + Low Voltage Programming Enable bit: **Low voltage programming enabled. MCLR/VPP pin function is MCLR. MCLRE configuration bit is ignored**
    + ZCD Disable bit: **ZCD module is disabled. ZCD can be enabled by setting the ZCDSEN bit of ZCDCON**
    + Stack Full/Underflow Reset Enable bit: **Stack full/underflow will cause Reset**
    + Brown-out Reset Voltage Selection bits: **Brown-out Reset Voltage (VBOR) set to 1.9V**
    + PPSLOCK bit One-Way Set Enable bit: **PPSLOCKED bit can be cleared and set only once; PPS registers remain locked after one clear/set cycle**

+ CONFIG5
    + WDT Period selection bits: **Divider ratio 1:65536; software control of WDTPS**
    + WDT operating mode: **WDT Disabled; SWDTEN is ignored**

+ CONFIG6
    + WDT Window Select bits: **window always open (100%); software control; keyed access not required**
    + WDT input clock selector: **Software Control**

+ CONFIG7
    + Storage Area Flash enable bit: **SAF disabled**
    + Boot Block enable bit: **Boot block disabled**
    + Boot Block Size selection bits: **Boot Block size is 512 words**

+ CONFIG8
    + Boot Block Write Protection bit: **Boot Block not Write protected**
    + Configuration Register Write Protection bit: **Configuration registers not Write protected**
    + Data EEPROM Write Protection bit: **Data EEPROM not Write protected**
    + Application Block write protection bit: **Application Block not write protected**
    + SAF Write protection bit: **SAF not Write Protected**

+ CONFIG10
    + PFM and Data EEPROM Code Protection bit: **PFM and Data EEPROM code protection disabled**

