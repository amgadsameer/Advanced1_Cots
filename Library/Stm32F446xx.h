#ifndef STM32F446xx_H
#define STM32F446xx_H


/*************************		Various Memories Base Addresses		************************/

#define FLASH_BASE_ADDRESS				0x08000000UL
#define SRAM_BASE_ADDRESS				0x20000000UL
#define ROM_BASE_ADDRESS				0x1FFF0000UL


/*************************		AHB1 Peripgheral Base Addresses		************************/

#define GPIOA_BASE_ADDRESS				0x40020000U
#define GPIOB_BASE_ADDRESS				0x40020400U	
#define GPIOC_BASE_ADDRESS				0x40020800U	
#define GPIOD_BASE_ADDRESS				0x40020C00U		
#define GPIOE_BASE_ADDRESS				0x40021000U		
#define GPIOF_BASE_ADDRESS				0x40021400U		
#define GPIOG_BASE_ADDRESS				0x40021800U		
#define GPIOH_BASE_ADDRESS				0x40021C00U		

#define RCC_BASE_ADDRESS				0x40023800U

#define EXTI_BASE_ADDRESS				0x40013C00U


/*************************		AHB2 Peripgheral Base Addresses		************************/




/*************************		AHB3 Peripgheral Base Addresses		************************/



/*************************		APB1 Peripgheral Base Addresses		************************/



/*************************		APB2 Peripgheral Base Addresses		************************/




/*************************		GPIO Register Definition Structure	************************/

typedef struct
{
	volatile uint32_t  MODER;								/*GPIO PORT Mode Register*/
	volatile uint32_t  OTYPER;								/*GPIO PORT Output type Register*/
	volatile uint32_t  OSPEEDR;								/*GPIO PORT Output speed Register*/
	volatile uint32_t  PUPDR;								/*GPIO PORT Pull up/down Register*/
	volatile uint32_t  IDR;									/*GPIO PORT Input Data Register*/
	volatile uint32_t  ODR;									/*GPIO PORT Output data Register*/
	volatile uint32_t  BSRR;								/*GPIO PORT Bit set/Reset Register*/
	volatile uint32_t  LCKR;								/*GPIO PORT Lock Register*/
	volatile uint32_t  AFR[2];								/*GPIO PORT Alternate function Register*/
}GPIO_RegDef_t;


/*************************		RCC Register Definition Structure	************************/

typedef struct
{
  volatile uint32_t CR;            /*!< RCC clock control register,                                   */
  volatile uint32_t PLLCFGR;       /*!< RCC PLL configuration register,                               */
  volatile uint32_t CFGR;          /*!< RCC clock configuration register,                             */
  volatile uint32_t CIR;           /*!< RCC clock interrupt register,                                 */
  volatile uint32_t AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                           */
  volatile uint32_t AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                           */
  volatile uint32_t AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                           */
  uint32_t      RESERVED0;     		/*!< Reserved, 0x1C                                                */
  volatile uint32_t APB1RSTR;      /*!< RCC APB1 peripheral reset register,                           */
  volatile uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,                           */
  uint32_t      RESERVED1[2];  		/*!< Reserved, 0x28-0x2C                                           */
  volatile uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                           */
  volatile uint32_t AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                           */
  volatile uint32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                           */
  uint32_t      RESERVED2;     		/*!< Reserved, 0x3C                                                */
  volatile uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                    */
  volatile uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                    */
  uint32_t      RESERVED3[2];  		/*!< Reserved, 0x48-0x4C                                           */
  volatile uint32_t AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register,  */
  volatile uint32_t AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register,  */
  volatile uint32_t AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register,  */
  uint32_t      RESERVED4;     		/*!< Reserved, 0x5C                                                */
  volatile uint32_t APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register,  */
  volatile uint32_t APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register,  */
  uint32_t      RESERVED5[2];  		/*!< Reserved, 0x68-0x6C                                           */
  volatile uint32_t BDCR;          /*!< RCC Backup domain control register,                           */
  volatile uint32_t CSR;           /*!< RCC clock control & status register,                          */
  uint32_t      RESERVED6[2];  		/*!< Reserved, 0x78-0x7C                                           */
  volatile uint32_t SSCGR;         /*!< RCC spread spectrum clock generation register,                */
  volatile uint32_t PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                            */
  volatile uint32_t PLLSAICFGR;    /*!< RCC PLLSAI configuration register,                            */
  volatile uint32_t DCKCFGR;       /*!< RCC Dedicated Clocks configuration register,                  */
  volatile uint32_t CKGATENR;      /*!< RCC Clocks Gated ENable Register,                             */
  volatile uint32_t DCKCFGR2;      /*!< RCC Dedicated Clocks configuration register 2,                */
} RCC_RegDef_t;



/*************************		EXTI Register Definition Structure	************************/
typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
	
}EXTI_RegDef_t;


/*************************		GPIO Peripgheral Definitions		************************/

#define GPIOA			               	((GPIO_RegDef_t*)GPIOA_BASE_ADDRESS)
#define GPIOB                           ((GPIO_RegDef_t*)GPIOB_BASE_ADDRESS)
#define GPIOC                           ((GPIO_RegDef_t*)GPIOC_BASE_ADDRESS)
#define GPIOD                           ((GPIO_RegDef_t*)GPIOD_BASE_ADDRESS)
#define GPIOE                           ((GPIO_RegDef_t*)GPIOE_BASE_ADDRESS)
#define GPIOF                           ((GPIO_RegDef_t*)GPIOF_BASE_ADDRESS)
#define GPIOG                           ((GPIO_RegDef_t*)GPIOG_BASE_ADDRESS)
#define GPIOH                           ((GPIO_RegDef_t*)GPIOH_BASE_ADDRESS)


/*************************		RCC Peripgheral Definition		************************/

#define RCC			               	((RCC_RegDef_t*)RCC_BASE_ADDRESS)

/*************************		EXTI Peripgheral Definition		************************/

#define EXTI						((EXTI_RegDef_t*)EXTI_BASE_ADDRESS)


#endif