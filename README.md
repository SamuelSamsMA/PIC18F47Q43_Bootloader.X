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

## Configuración para otros proyectos

A continuación se muestran los pasos a seguir para configurar un nuevo proyecto que ocupe como base este bootloader:

1. Crear un nuevo proyecto de MPLABX.

2. Abrir el MCC Melody.

3. Configuración del reloj:
    + Clock Source: **HFINTOSC**
    + HF Internal Clock: **64_MHz**
    + Clock Divider: **1**

4. Bits de configuración:
    + CONFIG1
        + External Oscillator Selection: **Oscillator not enabled**
        + Reset Oscillator Selection: **HFINTOSC with HFFRQ = 64 MHz and CDIV = 1:1**
    + CONFIG3
        + Multi-vector enable bit: **Interrupt contoller does not use vector table to prioritze interrupts**
        + MCLR Enable bit: **If LVP = 0, MCLR pin is MCLR; If LVP = 1, RE3 pin function is MCLR**
        + Brown-out Reset Enable bits: **Brown-out Reset enabled , SBOREN bit is ignored**
        + Power-up timer selection bits: **PWRT set at 16ms**
        + IVTLOCK bit One-way set enable bit: **IVTLOCKED bit can be cleared and set only once**
        + Low Power BOR Enable bit: **Low-Power BOR disabled**
    + El resto de bits se dejan con su valor por defecto.

5. Configurar el resto de periféricos de acuerdo a la aplicación en particular.

6. Generar el código del MCC.

7. Pegar el siguiente código en el archivo **main.c** antes de la función `main`:
```c
#include <stdint.h> 
#ifdef __XC8__ 
#include <xc.h> 
#endif 
volatile const uint16_t 
#ifdef __XC8__ 
__at(0x1FFFE) 
#endif 
applicationFooter __attribute__((used, section("application_footer"))) = 0xFFFF;
```

8. Ir a *Propiedades del proyecto* y elegir el páquete y compilador correspondiente.

9. *XC8 Linker -> Aditional options*
    + Codeoffset = **2000h**
    + Checksum = **2000-1FFFD@1FFFE,width=-2,algorithm=2**

10. *XC8 Linker -> Fill Flash Memory*
    + Which area to fill: **Provide Range to fill**
    + How to fill it: **Provide sequence of values**
    + Sequence: **0xFFFF**
    + Memory address range: **0x2000:0x1FFFF**

11. *Building*
    + ☑ Execute this line after build:
    + `pyfwimagebuilder build -i ./dist/default/production/NOMBRE_DEL_PROYECTO.X.production.hex -c bootloader_configuration.toml -o output.img`
    + (Este comando se ejecutará automáticamente después de cada compilación y combinará los archivos *.hex* y *.toml* para generar la imagen que se cargará al PIC).

12. Copiar el archivo **bootloader_configuration.toml** generado en este proyecto al directorio del nuevo proyecto.
    + La ruta de ese archivo es **mcc_generated_files\bootloader\configurations\\**

13. Escribir el código de la aplicación.

14. Compilar el proyecto.

15. Entrar al modo boot en el PIC (RESET -> BOOT_BUTTON).

16. Cargar el archivo de imagen **output.img** en el PIC mediante la herramienta **pymdfu** en la términal.
    + `pymdfu update --tool serial --image output.img --baudrate 9600 --port COM3`

17. Si todo salió bien, el PIC saldrá del modo boot una vez que la aplicación se halla escrito y comprobado correctamente.