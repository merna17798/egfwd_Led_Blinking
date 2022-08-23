/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       File:  port_private_Cfg.h
 *
 *       Module:  PORT
 *
 *       Description:  The static part of code where we initialise all
 *       parameters will be put in config_structure
 *
 *********************************************************************************************************************/
#ifndef MCAL_INC_PORT_PORT_PRIVATE_CFG_H_
#define MCAL_INC_PORT_PORT_PRIVATE_CFG_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../../comman/Std_Types.h"
#include "../../../comman/platform_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*Port ID 0-5*/
typedef enum
{
    PORT_A,
    PORT_B,
    PORT_C,
    PORT_D,
    PORT_E,
    PORT_F
}Port_PortID;

/*Pin ID 0-7*/
typedef enum
{
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
    }PORT_PinID;

/*Choose the pin direction type*/
typedef enum
{
    PORT_PIN_IN,
    PORT_PIN_OUT
}Port_PinDirectionType;

/*Choose the current Type of port*/
typedef enum
{
    PORT_PIN_CURRENT_NA,
    PORT_PIN_CURRENT_2m,
    PORT_PIN_CURRENT_4m,
    PORT_PIN_CURRENT_8m
}Port_PinOutputCurrentType;

/*Choose the pin internal attach*/
typedef enum
{
    PORT_ATTACH_DEFAULT,
    PORT_ATTACH_PULLUP,
    PORT_ATTACH_PULLDOWN,
    PORT_ATTACH_OPENDRAIN
}Port_PinInternalAttachType;

/*Choose External Interrupt Type*/
typedef enum
{
    PORT_EXT_INT_DISABLE,
    PORT_EXT_INT_RISING,
    PORT_EXT_INT_FALLING,
    PORT_EXT_INT_BOTH,
}Port_PinExternalIntType;

typedef uint8 Port_PinModeType;

/*Normal mode of pin*/
#define Port_PinMode_X_DIO                  0
/*check the table Table 10-2. GPIO Pins and Alternate Functions*/

/*Alternate function Modes in PORTA */
#define Port_PinMode_PA0_U0RX           1
#define Port_PinMode_PA0_CAN1Rx         8

#define Port_PinMode_PA1_U0TX           1
#define Port_PinMode_PA1_CAN1Tx         8

#define Port_PinMode_PA2_SSI0Clk        2

#define Port_PinMode_PA3_SSI0Fss        2

#define Port_PinMode_PA4_SSI0Rx         2

#define Port_PinMode_PA5_SSI0Tx         2

#define Port_PinMode_PA6_I2C1SCL        3
#define Port_PinMode_PA6_M1PWM2         5

#define Port_PinMode_PA7_I2C1SDA        3
#define Port_PinMode_PA7_M1PWM3         5

/*Alternate function Modes in PORTB */
#define Port_PinMode_PB0_U1Rx           1
#define Port_PinMode_PB0_T2CCP0         7

#define Port_PinMode_PB1_U1Tx           1
#define Port_PinMode_PB1_T2CCP1         7

#define Port_PinMode_PB2_I2C0SCL        3
#define Port_PinMode_PB2_T3CCP0         7

#define Port_PinMode_PB3_I2C0SDA        3
#define Port_PinMode_PB3_T3CCP1         7

#define Port_PinMode_PB4_SSI2Clk        2
#define Port_PinMode_PB4_M0PWM2         4
#define Port_PinMode_PB4_T1CCP0         7
#define Port_PinMode_PB4_CAN0Rx         8

#define Port_PinMode_PB5_SSI2Fss        2
#define Port_PinMode_PB5_M0PWM3         4
#define Port_PinMode_PB5_T1CCP1         7
#define Port_PinMode_PB5_CAN0Tx         8

#define Port_PinMode_PB6_SSI2Rx         2
#define Port_PinMode_PB6_M0PWM0         4
#define Port_PinMode_PB6_T0CCP0         7

#define Port_PinMode_PB7_SSI2Tx         2
#define Port_PinMode_PB7_M0PWM1         4
#define Port_PinMode_PB7_T0CCP1         7

/*Alternate function Modes in PORTC */
#define Port_PinMode_PC0_TCK_SWCLK  1
#define Port_PinMode_PC0_T4CCP0     7

#define Port_PinMode_PC1_TMS_SWDIO  1
#define Port_PinMode_PC1_T4CCP1     7

#define Port_PinMode_PC2_TDI        1
#define Port_PinMode_PC2_T5CCP0     7

#define Port_PinMode_PC3_TDO_SWO    1
#define Port_PinMode_PC3_T5CCP1     7

#define Port_PinMode_PC4_U4Rx       1
#define Port_PinMode_PC4_M0PWM2     4
#define Port_PinMode_PC4_IDX1       6
#define Port_PinMode_PC4_WT0CCP0    7
#define Port_PinMode_PC4_U1RTS      8

#define Port_PinMode_PC5_U4Tx       1
#define Port_PinMode_PC5_M0PWM3     4
#define Port_PinMode_PC5_PhA1       6
#define Port_PinMode_PC5_WT0CCP1    7
#define Port_PinMode_PC5_U1CTS      8

#define Port_PinMode_PC6_U3Rx       1
#define Port_PinMode_PC6_M0PWM0     4
#define Port_PinMode_PC6_PhB1       6
#define Port_PinMode_PC6_WT1CCP0    7
#define Port_PinMode_PC6_USB0EPEN   8

#define Port_PinMode_PC7_U3Tx       1
#define Port_PinMode_PC7_M0PWM1     4
#define Port_PinMode_PC7_WT1CCP1    7
#define Port_PinMode_PC7_USB0PFLT   8

/*Alternate function Modes in PORTD */
#define Port_PinMode_PD0_SSI3Clk        1
#define Port_PinMode_PD0_SSI1Clk        2
#define Port_PinMode_PD0_I2C3SCL        3
#define Port_PinMode_PD0_M0PWM6         4
#define Port_PinMode_PD0_M1PWM0         5
#define Port_PinMode_PD0_WT2CCP0        7

#define Port_PinMode_PD1_SSI3Fss        1
#define Port_PinMode_PD1_SSI1Fss        2
#define Port_PinMode_PD1_I2C3SDA        3
#define Port_PinMode_PD1_M0PWM7         4
#define Port_PinMode_PD1_M1PWM1         5
#define Port_PinMode_PD1_WT2CCP1        7

#define Port_PinMode_PD2_SSI3Rx         1
#define Port_PinMode_PD2_SSI1Rx         2
#define Port_PinMode_PD2_M0FAULT0       4
#define Port_PinMode_PD2_WT3CCP0        7
#define Port_PinMode_PD2_USB0EPEN       8

#define Port_PinMode_PD3_SSI3Tx         1
#define Port_PinMode_PD3_SSI1Tx         2
#define Port_PinMode_PD3_IDX0           6
#define Port_PinMode_PD3_WT3CCP1        7
#define Port_PinMode_PD3_USB0PFLT       8

#define Port_PinMode_PD4_U6Rx           1
#define Port_PinMode_PD4_WT4CCP0        7

#define Port_PinMode_PD5_U6Tx           1
#define Port_PinMode_PD5_WT4CCP1        7

#define Port_PinMode_PD6_U2Rx           1
#define Port_PinMode_PD6_PhA0           6
#define Port_PinMode_PD6_WT5CCP0        7

#define Port_PinMode_PD7_U2Tx           1
#define Port_PinMode_PD7_PhB0           6
#define Port_PinMode_PD7_WT5CCP1        7
#define Port_PinMode_PD7_NMI            8

/*Alternate function Modes in PORTE */
#define Port_PinMode_PE0_U7Rx           1

#define Port_PinMode_PE1_U7Tx           1

#define Port_PinMode_PE4_U5Rx           1
#define Port_PinMode_PE4_I2C2SCL        3
#define Port_PinMode_PE4_M0PWM4         4
#define Port_PinMode_PE4_M1PWM2         5
#define Port_PinMode_PE4_CAN0Rx         8

#define Port_PinMode_PE5_U5Tx           1
#define Port_PinMode_PE5_I2C2SDA        3
#define Port_PinMode_PE5_M0PWM5         4
#define Port_PinMode_PE5_M1PWM3         5
#define Port_PinMode_PE5_CAN0Tx         8

/*Alternate function Modes in PORTF */
#define Port_PinMode_PF0_U1RTS      1
#define Port_PinMode_PF0_SSI1Rx     2
#define Port_PinMode_PF0_CAN0Rx     3
#define Port_PinMode_PF0_M1PWM4     5
#define Port_PinMode_PF0_PhA0       6
#define Port_PinMode_PF0_T0CCP0     7
#define Port_PinMode_PF0_NMI        8
#define Port_PinMode_PF0_C0o        9

#define Port_PinMode_PF1_U1CTS      1
#define Port_PinMode_PF1_SSI1Tx     2
#define Port_PinMode_PF1_M1PWM5     5
#define Port_PinMode_PF1_PhB0       6
#define Port_PinMode_PF1_T0CCP1     7
#define Port_PinMode_PF1_C1o        9
#define Port_PinMode_PF1_TRD1       14

#define Port_PinMode_PF2_SSI1Clk    2
#define Port_PinMode_PF2_M0FAULT0   4
#define Port_PinMode_PF2_M1PWM6     5
#define Port_PinMode_PF2_T1CCP0     7
#define Port_PinMode_PF2_TRD0       14

#define Port_PinMode_PF3_SSI1Fss    2
#define Port_PinMode_PF3_CAN0Tx     3
#define Port_PinMode_PF3_M1PWM7     5
#define Port_PinMode_PF3_T1CCP1     7
#define Port_PinMode_PF3_TRCLK      14

#define Port_PinMode_PF4_M1FAULT0   5
#define Port_PinMode_PF4_IDX0       6
#define Port_PinMode_PF4_T2CCP0     7
#define Port_PinMode_PF4_USB0EPEN   8

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* MCAL_INC_PORT_PORT_PRIVATE_CFG_H_ */

/**********************************************************************************************************************
 *  END OF FILE: port_private_Cfg.h
 *********************************************************************************************************************/






