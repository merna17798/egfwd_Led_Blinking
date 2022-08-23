/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**       file  port.c
 *
 *        details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../../Mcal/Inc/PORT/port.h"
#include "../../comman/Std_Types.h"
#include "../../comman/BitMath.h"
#include "../../comman/platform_Types.h"
#include "../../comman/Mcu_Hw.h"
#include "../../User_Config/port_Cfg.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define MAX_NUMBER_OF_GPIO_PORTS           6u
#define GPIO_COMMIT_UNLOCKING_VALUE              0x4C4F434B
#define PIN_FIELD_SIZE_IN_GPIOPCTL               4
#define CHANNEL_SIZE_IN_PORT               8u
/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
static const uint32 Port_BaseAddr[MAX_NUMBER_OF_GPIO_PORTS] =
{GPIO_BASE_ADDRESS_A, GPIO_BASE_ADDRESS_B, GPIO_BASE_ADDRESS_C,
GPIO_BASE_ADDRESS_D, GPIO_BASE_ADDRESS_E, GPIO_BASE_ADDRESS_F};
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void Port_Init ( const Port_ConfigType* ConfigPtr )
* \Description     : initialising the port diver module
*
* \Sync\ASync      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : ConfigPtr Pointer to configuration Structure.
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void Port_Init ( const Port_ConfigType* ConfigPtr )
{
    Port_PortID locPortId;
    PORT_PinID  locPinId;
    Port_PinDirectionType locPinDir;
    Port_PinModeType locPinMode;
    Port_PinOutputCurrentType locCurrentStrength;
    Port_PinInternalAttachType locInternalAttach;
    Port_PinExternalIntType locExternalInt;
    uint8 PortIndex,PinIndex,i;
    uint32 PortBaseAddr;

for(i=0; i< PORT_ACTIVATED_CHANNELS_SIZE; i++)
{
        locPortId          = ConfigPtr[i].portId;
        locPinId           = ConfigPtr[i].pinId;
        locPinDir          = ConfigPtr[i].pinDir;
        locPinMode         = ConfigPtr[i].pinMode;
        locCurrentStrength = ConfigPtr[i].currentStrength;
        locInternalAttach  = ConfigPtr[i].internalAttach;
        locExternalInt     = ConfigPtr[i].externalInt;

        switch(locPortId){
        case (PORT_A):{
            RCGCGPIO.R0=1;
            break;
        }
        case (PORT_B):{
            RCGCGPIO.R1=1;
            break;
        }
        case (PORT_C):{
            RCGCGPIO.R2=1;
            break;
        }
        case (PORT_D):{
            RCGCGPIO.R3=1;
            break;
        }
        case (PORT_E):{
            RCGCGPIO.R4=1;
            break;
        }
        case (PORT_F):{
            RCGCGPIO.R5=1;
            break;
        }
        }


        PortIndex = locPortId;
        PinIndex  = locPinId;

        PortBaseAddr = Port_BaseAddr[PortIndex] ;

        GPIODIR(PortBaseAddr) |= (locPinDir << PinIndex);
        /* setting pin mode */
        if(locPinMode == Port_PinMode_X_DIO)
        {
            GPIOLOCK(PortBaseAddr) = GPIO_COMMIT_UNLOCKING_VALUE;
            GPIOAFSEL(PortBaseAddr) = 0;
        }
        else
        {
            GPIOLOCK(PortBaseAddr)  = GPIO_COMMIT_UNLOCKING_VALUE;
            GPIOCR(PortBaseAddr)        = 0x1;
            GPIOPCTL(PortBaseAddr) |= (locPinMode << (PIN_FIELD_SIZE_IN_GPIOPCTL * PinIndex));
        }

        /* setting current strength */
        if(locCurrentStrength == PORT_PIN_CURRENT_2m)
        {
            GPIODR2R(PortBaseAddr) |= (1 << PinIndex);
        }
        else if(locCurrentStrength == PORT_PIN_CURRENT_4m)
        {
            GPIODR4R(PortBaseAddr) |= (1 << PinIndex);
        }
        else if(locCurrentStrength == PORT_PIN_CURRENT_8m)
        {
            GPIODR8R(PortBaseAddr) |= (1 << PinIndex);
        }

        /* setting internal attach type */
        if (locInternalAttach == PORT_ATTACH_PULLUP)
        {
            GPIOLOCK(PortBaseAddr)  = GPIO_COMMIT_UNLOCKING_VALUE;
            GPIOCR(PortBaseAddr)        = 0x1;

            GPIOPUR(PortBaseAddr) |= (1 << PinIndex);

        }
        else if (locInternalAttach == PORT_ATTACH_PULLDOWN)
        {
            GPIOLOCK(PortBaseAddr)  = GPIO_COMMIT_UNLOCKING_VALUE;
            GPIOCR(PortBaseAddr)        = 0x1;

            GPIOPDR(PortBaseAddr) |= (1 << PinIndex);
        }
        else if (locInternalAttach == PORT_ATTACH_OPENDRAIN)
        {
            GPIOLOCK(PortBaseAddr)  = GPIO_COMMIT_UNLOCKING_VALUE;
            GPIOCR(PortBaseAddr)        = 0x1;

            GPIOODR(PortBaseAddr) |= (1 << PinIndex);
        }


        /* setting external interupt mode */
        if (locExternalInt == PORT_EXT_INT_DISABLE)
        {
            GPIOIM(PortBaseAddr) &= (~(1 << PinIndex));
        }
        /* configure the interupt with the edges */
        else if (locExternalInt == PORT_EXT_INT_RISING)
        {
            GPIOIM(PortBaseAddr)    &= (~(1 << PinIndex));
            GPIOIS(PortBaseAddr)    |= (1 << PinIndex);
            GPIOIBE(PortBaseAddr)   &= (~(1 << PinIndex));
            GPIOIEV(PortBaseAddr)   |= (1 << PinIndex);
            GPIORIS(PortBaseAddr)   &= (~(1 << PinIndex));
            GPIOIM(PortBaseAddr)    |= (1 << PinIndex);

        }
        else if (locExternalInt == PORT_EXT_INT_FALLING)
        {
            GPIOIM(PortBaseAddr)    &= (~(1 << PinIndex));
            GPIOIS(PortBaseAddr)    |= (1 << PinIndex);
            GPIOIBE(PortBaseAddr)   &= (~(1 << PinIndex));
            GPIOIEV(PortBaseAddr)   &= (~(1 << PinIndex));
            GPIORIS(PortBaseAddr)   &= (~(1 << PinIndex));
            GPIOIM(PortBaseAddr)    |= (1 << PinIndex);
        }
        else if (locExternalInt == PORT_EXT_INT_BOTH)
        {
            GPIOIM(PortBaseAddr)    &= (~(1 << PinIndex));
            GPIOIS(PortBaseAddr)    |= (1 << PinIndex);
            GPIOIBE(PortBaseAddr)   |= (1 << PinIndex);
            GPIORIS(PortBaseAddr)   &= (~(1 << PinIndex));
            GPIOIM(PortBaseAddr)    |= (1 << PinIndex);
        }
    }
}

/**********************************************************************************************************************
 *  END OF FILE: prot.c
 *********************************************************************************************************************/
