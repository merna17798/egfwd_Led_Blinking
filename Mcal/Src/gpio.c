/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        file  gpio.c
 *         Details: Implementationn of DIO Functions prototypes

 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../../Mcal/Inc/GPIO/io.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define CHANNEL_SIZE_IN_PORT                8u
#define MAX_NUMBER_OF_GPIO_PORTS                        6u
/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
static const uint32 Port_BaseAddr[MAX_NUMBER_OF_GPIO_PORTS] = {
GPIO_BASE_ADDRESS_A, GPIO_BASE_ADDRESS_B, GPIO_BASE_ADDRESS_C,
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
* \Syntax          : GPIO_LevelType GPIO_ReadChannel ( GPIO_PinID ChannelId )
* \Description     : Reads channel value
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : ChannelId   ID of DIO channel
* \Parameters (out): GPIO_LevelType
* \Return value:   : GPIO_LevelType  STD_LOW,
                                                                         STD_HIGH
*******************************************************************************/
GPIO_LevelType GPIO_ReadChannel ( GPIO_PortID PortId , GPIO_PinID ChannelId )
{
    GPIO_LevelType level;
    uint32 gpioDataOffset;
    uint32 portIndex,pinIndex,PortBaseAddr;

    portIndex = PortId;
    pinIndex = ChannelId;

    PortBaseAddr = Port_BaseAddr[portIndex];

    gpioDataOffset = 4 * (1<<pinIndex);
    level = (*((uint32*)(PortBaseAddr+gpioDataOffset))) >> pinIndex;

    return level;
}
/******************************************************************************
* \Syntax          : void GPIO_WriteChannel ( GPIO_PinID ChannelId, GPIO_LevelType Level )
* \Description     : Writes channel value
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : ChannelId   ID of DIO channel
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void GPIO_WriteChannel ( GPIO_PortID PortId, GPIO_PinID ChannelId, GPIO_LevelType Level )
{
    uint32 gpioDataOffset;
    uint32 portIndex,pinIndex,PortBaseAddr;

    portIndex = PortId;
    pinIndex = ChannelId;

    PortBaseAddr = Port_BaseAddr[portIndex];

    gpioDataOffset = 4 * (1<<pinIndex);
    *((uint32 volatile*)(PortBaseAddr+gpioDataOffset)) = (Level<<pinIndex);

}
/******************************************************************************
* \Syntax          : GPIO_PortLevelType GPIO_ReadPort ( GPIO_PortID PortId )
* \Description     : Reads Port value
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : PortId   ID of DIO port
* \Parameters (out): GPIO_PortLevelType
* \Return value:   : GPIO_PortLevelType   uint8
*******************************************************************************/
GPIO_PortLevelType GPIO_ReadPort ( GPIO_PortID PortId )
{
    GPIO_PortLevelType portLevel;
    uint32 PortBaseAddr;
    PortBaseAddr = Port_BaseAddr[PortId];

    portLevel = Port_BaseAddr[PortId];

    return portLevel;
}
/******************************************************************************
* \Syntax          : void GPIO_WritePort ( GPIO_PortID PortId, GPIO_PortLevelType Level );
* \Description     : writes Port value
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : PortId   ID of DIO port
                                         Level      Value to be written
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void GPIO_WritePort ( GPIO_PortID PortId, GPIO_PortLevelType Level )
{
    uint32 PortBaseAddr;

    PortBaseAddr = Port_BaseAddr[PortId];

    GPIODATA(PortBaseAddr) = Level;
}

/**********************************************************************************************************************
 *  END OF FILE: gpio.c
 *********************************************************************************************************************/
