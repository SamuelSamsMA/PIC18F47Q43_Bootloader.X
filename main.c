 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.2
 *
 * @version Package Version: 3.1.2
*/

#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/bootloader/example/bl_example.h"


int main(void)
{
    SYSTEM_Initialize();
    BL_ExampleInitialize();

    while(1)
    {
        /**
         *
         * An example has been provided to you to demonstrate one way that
         * the MDFU Client Library could be implemented.
         */
        BL_Example();
    }    
}