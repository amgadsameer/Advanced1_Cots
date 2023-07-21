/*****************************************************************/
/*	@file GPIO_prog.c
 * 	@author Amgad Samir
 * 	@brief The GPIO main source file, including functions' definitions
 *
 */

#include <stdint.h>
#include "Stm32F446xx.h"
#include "ErrType.h"

#include "GPIO_interface.h"
#include "GPIO_prv.h"

static GPIO_RegDef_t* GPIOPort[GPIO_PERIPHERAL_NUM] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOF,GPIOG,GPIOH};

/************************************************************************
 * @fn GPIO_u8PinInit
 * @brief the function initializes the GPIO pin according to the input parameters
 * @param[in] PinConfig : the initialization values of the pin
 * @retval ErrorStatus
 *
 */

uint8_t GPIO_u8PinInit(const GPIO_PinConfig_t* PinConfig)
{
	uint8_t Local_u8ErrorState = OK;
	if(PinConfig != NULL)
	{
		if((PinConfig->Port <= PORTH ) && (PinConfig ->PinNum <= PIN15))
		{
			/*Select GPIO mode : Input , Output, Analog, Alternate function*/
			(GPIOPort[PinConfig->Port]->MODER) &= ~(MODER_MASK << ((PinConfig->PinNum) * MODER_PIN_ACCESS)); /*Clear the mode bits*/
			(GPIOPort[PinConfig->Port]->MODER) |= ((PinConfig->Mode) << (PinConfig->PinNum) * MODER_PIN_ACCESS);

			/*Select GPIO pull state : Pullup, Pulldown, NoPull*/
			(GPIOPort[PinConfig->Port]->PUPDR) &= ~(PUPDR_MASK << ((PinConfig->PinNum)* PUPDR_PIN_ACCESS));
			(GPIOPort[PinConfig->Port]->PUPDR) |= ((PinConfig ->PullType) << (PinConfig->PinNum) * PUPDR_PIN_ACCESS);

			/*Select Output type & Output speed in case of general purpose output or Alternate function */
			if((PinConfig ->Mode == OUTPUT) || (PinConfig->Mode == ALTERNATE_FUNCTION))
			{
				/*Select Output type: Pushpull or Open drain*/
				(GPIOPort[PinConfig->Port]->OTYPER) &= ~(OTYPER_MASK << (PinConfig->PinNum));
				(GPIOPort[PinConfig->Port]->OTYPER) |= ((PinConfig->OutputType) << (PinConfig->PinNum));

				/*Select Output speed : Low, Medium, High, Fast*/
				(GPIOPort[PinConfig->Port]->OSPEEDR) &= ~(OSPEEDR_MASK << (PinConfig->PinNum)* OSPEEDR_PIN_ACCESS);
				(GPIOPort[PinConfig->Port]->OSPEEDR) |= ((PinConfig->Speed) << (PinConfig->PinNum) * OSPEEDR_PIN_ACCESS);

				/*Select the pin Alternate function*/
				if(PinConfig->Mode == ALTERNATE_FUNCTION)
				{
					uint8_t Local_u8RegNum = (PinConfig->PinNum) / AFR_PIN_SHIFTING;
					uint8_t Local_u8BitNum = (PinConfig->PinNum) % AFR_PIN_SHIFTING;

					(GPIOPort[PinConfig->Port]->AFR[Local_u8RegNum]) &= ~(AFR_MASK << Local_u8BitNum * AFR_PIN_ACCESS);
					(GPIOPort[PinConfig->Port]->AFR[Local_u8RegNum]) |= ((PinConfig->AltFunc) << (Local_u8BitNum * AFR_PIN_ACCESS ));
				}
			}
		}
		else
		{
			Local_u8ErrorState = NOK;
		}
	}
	else
	{
		Local_u8ErrorState = NULL_PTR_ERR;
	}


	return Local_u8ErrorState;
}

/*********************************************************
 * @fn GPIO_u8SetPinValue
 * @brief The function outputs a certain value on an output pin
 * @param[in] Port : the Port number, get options @Port_t enum
 * @param[in] PinNum: The pin number, get options @Pin_t enum
 * @param[in] PinVal: The output value , get options @PinVal_t enum
 * @retval ErrorStatus
 *
 */
uint8_t GPIO_u8SetPinValue(Port_t Port, Pin_t PinNum,PinVal_t PinVal )
{
	uint8_t Local_u8ErrorState= OK;
	if((Port <= PORTH ) && (PinNum <= PIN15))
	{
		if(PinVal == PIN_LOW)
		{
			GPIOPort[Port] -> ODR &= ~ (1<< PinNum);
			/*GPIOPort[Port] -> BSRR = 1 << (16 + PinNum);*/
		}
		else if(PinVal == PIN_HIGH)
		{
			GPIOPort[Port] -> ODR |=  (1<< PinNum);
			/*GPIOPort[Port] -> BSRR = 1 << PinNum;*/
		}
		else
		{
			Local_u8ErrorState = NOK;
		}
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}
