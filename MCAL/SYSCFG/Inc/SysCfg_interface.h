#ifndef SYSCFG_INTERFACE_H
#define SYSCFG_INTERFACE_H

typedef enum
{
	PORTA=0,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF,
	PORTG,
	PORTH,
}SYSCFG_Port_t;

typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15,
}SYSCFG_LineNum_t;

void SysCfg_voidSetEXTIPort(SYSCFG_LineNum_t copy_PinNum,SYSCFG_Port_t copy_Port );

#endif
