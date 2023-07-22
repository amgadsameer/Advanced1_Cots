#include <stdint.h>
#include "ErrType.h"
#include "Stm32F446xx.h"
#include "SysCfg_interface.h"
#include "SysCfg_prv.h"

void SysCfg_voidSetEXTIPort(SYSCFG_LineNum_t copy_PinNum,SYSCFG_Port_t copy_Port )
{
	uint8_t Local_u8RegisterNum = copy_PinNum / EXTI_CTRL_REG_LINEBITS;
	uint8_t Local_u8BitNum = (copy_PinNum % EXTI_CTRL_REG_LINEBITS) * EXTI_CTRL_REG_LINEBITS;

	SYSCFG->CR[Local_u8RegisterNum] &= (~(EXTI_CTRL_REG_MASK<< Local_u8BitNum ));	/*clear the required 4 bits*/
	SYSCFG->CR[Local_u8RegisterNum] |= (copy_Port << Local_u8BitNum);	/*Set the port number value*/
}
