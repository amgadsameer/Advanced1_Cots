#include "Stdint.h"
#include "Stm32F446xx.h"

#include "RCC_interface.h"


void RCC_voidAHB1EnablePeripheralClock(uint8_t Peripheral)
{
	RCC -> AHB1ENR |= (1 << Peripheral);
}