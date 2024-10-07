/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.1.1
*/

/*
© [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 aliases
#define RX_RA0_TRIS                 TRISAbits.TRISA0
#define RX_RA0_LAT                  LATAbits.LATA0
#define RX_RA0_PORT                 PORTAbits.RA0
#define RX_RA0_WPU                  WPUAbits.WPUA0
#define RX_RA0_OD                   ODCONAbits.ODCA0
#define RX_RA0_ANS                  ANSELAbits.ANSELA0
#define RX_RA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define RX_RA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define RX_RA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define RX_RA0_GetValue()           PORTAbits.RA0
#define RX_RA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define RX_RA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define RX_RA0_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define RX_RA0_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define RX_RA0_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define RX_RA0_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define RX_RA0_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define RX_RA0_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set RA1 aliases
#define TX_RA1_TRIS                 TRISAbits.TRISA1
#define TX_RA1_LAT                  LATAbits.LATA1
#define TX_RA1_PORT                 PORTAbits.RA1
#define TX_RA1_WPU                  WPUAbits.WPUA1
#define TX_RA1_OD                   ODCONAbits.ODCA1
#define TX_RA1_ANS                  ANSELAbits.ANSELA1
#define TX_RA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define TX_RA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define TX_RA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define TX_RA1_GetValue()           PORTAbits.RA1
#define TX_RA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define TX_RA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define TX_RA1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define TX_RA1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define TX_RA1_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define TX_RA1_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define TX_RA1_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define TX_RA1_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set RE0 aliases
#define BL_ENTRY_TRIS                 TRISEbits.TRISE0
#define BL_ENTRY_LAT                  LATEbits.LATE0
#define BL_ENTRY_PORT                 PORTEbits.RE0
#define BL_ENTRY_WPU                  WPUEbits.WPUE0
#define BL_ENTRY_OD                   ODCONEbits.ODCE0
#define BL_ENTRY_ANS                  ANSELEbits.ANSELE0
#define BL_ENTRY_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define BL_ENTRY_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define BL_ENTRY_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define BL_ENTRY_GetValue()           PORTEbits.RE0
#define BL_ENTRY_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define BL_ENTRY_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define BL_ENTRY_SetPullup()          do { WPUEbits.WPUE0 = 1; } while(0)
#define BL_ENTRY_ResetPullup()        do { WPUEbits.WPUE0 = 0; } while(0)
#define BL_ENTRY_SetPushPull()        do { ODCONEbits.ODCE0 = 0; } while(0)
#define BL_ENTRY_SetOpenDrain()       do { ODCONEbits.ODCE0 = 1; } while(0)
#define BL_ENTRY_SetAnalogMode()      do { ANSELEbits.ANSELE0 = 1; } while(0)
#define BL_ENTRY_SetDigitalMode()     do { ANSELEbits.ANSELE0 = 0; } while(0)

// get/set RE1 aliases
#define BL_INDICATOR_TRIS                 TRISEbits.TRISE1
#define BL_INDICATOR_LAT                  LATEbits.LATE1
#define BL_INDICATOR_PORT                 PORTEbits.RE1
#define BL_INDICATOR_WPU                  WPUEbits.WPUE1
#define BL_INDICATOR_OD                   ODCONEbits.ODCE1
#define BL_INDICATOR_ANS                  ANSELEbits.ANSELE1
#define BL_INDICATOR_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define BL_INDICATOR_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define BL_INDICATOR_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define BL_INDICATOR_GetValue()           PORTEbits.RE1
#define BL_INDICATOR_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define BL_INDICATOR_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define BL_INDICATOR_SetPullup()          do { WPUEbits.WPUE1 = 1; } while(0)
#define BL_INDICATOR_ResetPullup()        do { WPUEbits.WPUE1 = 0; } while(0)
#define BL_INDICATOR_SetPushPull()        do { ODCONEbits.ODCE1 = 0; } while(0)
#define BL_INDICATOR_SetOpenDrain()       do { ODCONEbits.ODCE1 = 1; } while(0)
#define BL_INDICATOR_SetAnalogMode()      do { ANSELEbits.ANSELE1 = 1; } while(0)
#define BL_INDICATOR_SetDigitalMode()     do { ANSELEbits.ANSELE1 = 0; } while(0)

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/