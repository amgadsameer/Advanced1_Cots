#include <stdint.h>
#include "Stm32F446xx.h"
#include "ErrType.h"
#include "EXTI_interface.h"
#include "EXTI_prv.h"

/*Global array of pointer to function to hold callback functions*/
static void(*EXTI_CallBackFunc[EXTI_LINE_NUM])(void) = {NULL};

uint8_t EXTI_u8Init(EXTI_config_t* copy_cfg)
{
	uint8_t Local_u8ErrorState = OK;
	if(copy_cfg != NULL)
	{
		/*Setting trigger source configuration*/
		switch(copy_cfg ->TrigSrc)
		{
		case RISING_TRIG:
			EXTI->RTSR |= 1<< (copy_cfg->PinNum);
			EXTI->FTSR &= (~(1<<(copy_cfg->PinNum)));
			break;
		case FALLING_TRIG:
			EXTI->FTSR |= 1<< (copy_cfg->PinNum);
			EXTI->RTSR &= (~(1<<(copy_cfg->PinNum)));
			break;
		case FALLING_RISING_TRIG:
			EXTI->RTSR |= 1<< (copy_cfg->PinNum);
			EXTI->FTSR |= 1<< (copy_cfg->PinNum);
			break;
		default: Local_u8ErrorState = NOK; break;
		}

		/*Set interrupt enable/disable initial state*/
		if(copy_cfg->InitState == ENABLED)
		{
			EXTI->IMR |= (1<<(copy_cfg->PinNum));
		}
		else if(copy_cfg->InitState == DISABLED)
		{
			EXTI->IMR &= (~(1<<(copy_cfg->PinNum)));
		}
		else
		{
			Local_u8ErrorState = NOK;
		}

		/*Setting callback function pointer*/
		if(copy_cfg->CallBackFunc != NULL)
		{
			EXTI_CallBackFunc[copy_cfg->PinNum] = copy_cfg->CallBackFunc;
		}
		else
		{
			Local_u8ErrorState = NULL_PTR_ERR;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}


	return Local_u8ErrorState;
}

uint8_t EXTI_u8SetTrigSrc(EXTI_TrigSrc_t copy_TrigSrc,EXTI_LineNum copy_PinNum )
{
	uint8_t Local_u8ErrorState = OK;
	switch(copy_TrigSrc)
	{
	case RISING_TRIG:
		EXTI->RTSR |= 1<< (copy_PinNum);
		EXTI->FTSR &= (~(1<<(copy_PinNum)));
		break;
	case FALLING_TRIG:
		EXTI->FTSR |= 1<< (copy_PinNum);
		EXTI->RTSR &= (~(1<<(copy_PinNum)));
		break;
	case FALLING_RISING_TRIG:
		EXTI->RTSR |= 1<< (copy_PinNum);
		EXTI->FTSR |= 1<< (copy_PinNum);
		break;
	default: Local_u8ErrorState = NOK; break;
	}

	return Local_u8ErrorState;
}
void EXTI_voidEnableInt(EXTI_LineNum copy_line)
{
	EXTI->IMR |= (1<<copy_line);
}

void EXTI_voidDisableInt(EXTI_LineNum copy_line)
{
	EXTI->IMR &= (~(1<<copy_line));
}

void EXTI_voidClearPendingFlag(EXTI_LineNum copy_line)
{
	EXTI->PR = 1<<copy_line;
}

uint8_t EXTI_u8GetPendingFlag(EXTI_LineNum copy_line,uint8_t* copy_FlagStatus)
{
	uint8_t Local_u8ErrorState = OK;

	if(copy_FlagStatus != NULL)
	{
		*copy_FlagStatus = ((EXTI->PR >> copy_line)&1);
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}
