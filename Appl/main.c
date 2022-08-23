

/**
 * main.c
 */
#include "../Mcal/Inc/GPIO/io.h"
#include "../User_Config/port_Cfg.h"
#include "../Mcal/Inc/SYSTICK/systick.h"
#include "../Mcal/Inc/NVIC/nvic.h"
#include "../Mcal/Inc/SYSTICK/systick.h"
extern const Port_ConfigType Port_Config[];

int main(void)
{
    Nvic_Init(FAULT_SYSTICK);
	Port_Init(Port_Config);
	SysTick_Init();
    GPIO_WriteChannel(PORTF,P1,HIGH);
    SysTick_PeriodSet(NVIC_ST_RELOAD_M);
    return 0;
}
void SysTick_Handler(void){
    static int counter=0;
    counter++;
}
