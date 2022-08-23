/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

#define NVIC_ST_CTRL            0xE000E010  // SysTick Control and Status Register
#define NVIC_ST_RELOAD          0xE000E014  // SysTick Reload Value Register
#define NVIC_ST_CURRENT         0xE000E018  // SysTick Current Value Register
#define NVIC_EN0                0xE000E100  // Interrupt 0-31 Set Enable
#define NVIC_EN1                0xE000E104  // Interrupt 32-63 Set Enable
#define NVIC_EN2                0xE000E108  // Interrupt 64-95 Set Enable
#define NVIC_EN3                0xE000E10C  // Interrupt 96-127 Set Enable
#define NVIC_EN4                0xE000E110  // Interrupt 128-159 Set Enable
#define NVIC_SYS_HND_CTRL       0xE000ED24  // System Handler Control and State

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_ST_CTRL register.
//
//*****************************************************************************
#define NVIC_ST_CTRL_COUNT      0x00010000  // Count Flag
#define NVIC_ST_CTRL_CLK_SRC    0x00000004  // Clock Source
#define NVIC_ST_CTRL_INTEN      0x00000002  // Interrupt Enable
#define NVIC_ST_CTRL_ENABLE     0x00000001  // Enable

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_ST_RELOAD register.
//
//*****************************************************************************
#define NVIC_ST_RELOAD_M        0x00FFFFFF  // Reload Value
#define NVIC_ST_RELOAD_S        0

//*****************************************************************************
//
// The following are defines for the bit fields in the NVIC_ST_CURRENT
// register.
//
//*****************************************************************************
#define NVIC_ST_CURRENT_M       0x00FFFFFF  // Current Value
#define NVIC_ST_CURRENT_S       0

/**************************************
*   GPIO REGISTRE
***************************************/
#define GPIO_BASE_ADDRESS_A          0x40004000
#define GPIO_BASE_ADDRESS_B          0x40005000
#define GPIO_BASE_ADDRESS_C          0x40006000
#define GPIO_BASE_ADDRESS_D          0x40007000
#define GPIO_BASE_ADDRESS_E          0x40024000
#define GPIO_BASE_ADDRESS_F          0x40025000

#define GPIODATA_OFFSET     0X3FC
#define GPIODIR_OFFSET      0x400
#define GPIOAFSEL_OFFSET    0x420
#define GPIOLOCK_OFFSET     0x520
#define GPIOCR_OFFSET       0x524
#define GPIOPCTL_OFFSET     0x52C
#define GPIODR2R_OFFSET     0x500
#define GPIODR4R_OFFSET     0x504
#define GPIODR8R_OFFSET     0x508
#define GPIOPUR_OFFSET      0x510
#define GPIOPDR_OFFSET      0x514
#define GPIOODR_OFFSET      0x50C
#define GPIOIS_OFFSET       0x404
#define GPIOIBE_OFFSET      0x408
#define GPIOIEV_OFFSET      0x40c
#define GPIOIM_OFFSET       0x410
#define GPIORIS_OFFSET      0x414

/**************************************
*   RCC REGISTRE
***************************************/
typedef struct
{
    uint32 R0:1;
    uint32 R1:1;
    uint32 R2:1;
    uint32 R3:1;
    uint32 R4:1;
    uint32 R5:1;
    uint32 R6:1;
    uint32 R7:1;
}RCGC_TagType;
#define RCGCGPIO_OFFSET     0x608
//#define RCGCGPIO *((volatile RCGC_TagType*)(0x400FE000+RCGCGPIO_OFFSET))
#define RCGCGPIO    (*((volatile RCGC_TagType*)(0x400FE000+RCGCGPIO_OFFSET)))
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define GPIODIR(BaseAddr)                                   *((volatile uint32*)(BaseAddr+GPIODIR_OFFSET))
#define GPIOAFSEL(BaseAddr)                                 *((volatile uint32*)(BaseAddr+GPIOAFSEL_OFFSET))
#define GPIOLOCK(BaseAddr)                                  *((volatile uint32*)(BaseAddr+GPIOLOCK_OFFSET))
#define GPIOCR(BaseAddr)                                    *((volatile uint32*)(BaseAddr+GPIOCR_OFFSET))
#define GPIOPCTL(BaseAddr)                                  *((volatile uint32*)(BaseAddr+GPIOPCTL_OFFSET))
#define GPIODR2R(BaseAddr)                                  *((volatile uint32*)(BaseAddr+GPIODR2R_OFFSET))
#define GPIODR4R(BaseAddr)                                  *((volatile uint32*)(BaseAddr+GPIODR4R_OFFSET))
#define GPIODR8R(BaseAddr)                                  *((volatile uint32*)(BaseAddr+GPIODR8R_OFFSET))
#define GPIOPUR(BaseAddr)                                   *((volatile uint32*)(BaseAddr+GPIOPUR_OFFSET))
#define GPIOPDR(BaseAddr)                                   *((volatile uint32*)(BaseAddr+GPIOPDR_OFFSET))
#define GPIOODR(BaseAddr)                                   *((volatile uint32*)(BaseAddr+GPIOODR_OFFSET))
#define GPIOIS(BaseAddr)                                    *((volatile uint32*)(BaseAddr+GPIOIS_OFFSET))
#define GPIOIBE(BaseAddr)                                   *((volatile uint32*)(BaseAddr+GPIOIBE_OFFSET))
#define GPIOIEV(BaseAddr)                                   *((volatile uint32*)(BaseAddr+GPIOIEV_OFFSET))
#define GPIOIM(BaseAddr)                                    *((volatile uint32*)(BaseAddr+GPIOIM_OFFSET))
#define GPIORIS(BaseAddr)                                   *((volatile uint32*)(BaseAddr+GPIORIS_OFFSET))
#define GPIODATA(BaseAddr)                                  *((volatile uint32*)(BaseAddr+GPIODATA_OFFSET))
#define HWREG(x)                                            (*((volatile uint32*)(x)))

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
