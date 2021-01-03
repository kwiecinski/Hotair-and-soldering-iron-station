/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SOLDER_ON_SW_Pin GPIO_PIN_0
#define SOLDER_ON_SW_GPIO_Port GPIOF
#define HOTAIR_REED_SW_Pin GPIO_PIN_1
#define HOTAIR_REED_SW_GPIO_Port GPIOF
#define THERM_IRON_ADC_Pin GPIO_PIN_0
#define THERM_IRON_ADC_GPIO_Port GPIOA
#define THERM_HOTAIR_ADC_Pin GPIO_PIN_1
#define THERM_HOTAIR_ADC_GPIO_Port GPIOA
#define SOLDER_DOWN_SW_Pin GPIO_PIN_2
#define SOLDER_DOWN_SW_GPIO_Port GPIOA
#define HOTAIR_HEATER_CTRL_Pin GPIO_PIN_3
#define HOTAIR_HEATER_CTRL_GPIO_Port GPIOA
#define BUZZER_Pin GPIO_PIN_4
#define BUZZER_GPIO_Port GPIOA
#define DISP_CLK_Pin GPIO_PIN_5
#define DISP_CLK_GPIO_Port GPIOA
#define DISP_LATCH_Pin GPIO_PIN_6
#define DISP_LATCH_GPIO_Port GPIOA
#define DISP_DIN_Pin GPIO_PIN_7
#define DISP_DIN_GPIO_Port GPIOA
#define SOLDER_UP_SW_Pin GPIO_PIN_0
#define SOLDER_UP_SW_GPIO_Port GPIOB
#define HOTAIR_DOWN_SW_Pin GPIO_PIN_1
#define HOTAIR_DOWN_SW_GPIO_Port GPIOB
#define HOTAIR_UP_SW_Pin GPIO_PIN_8
#define HOTAIR_UP_SW_GPIO_Port GPIOA
#define UART_DBG_TX_Pin GPIO_PIN_9
#define UART_DBG_TX_GPIO_Port GPIOA
#define HOTAIR_FAN_UP_SW_Pin GPIO_PIN_10
#define HOTAIR_FAN_UP_SW_GPIO_Port GPIOA
#define HOTAIR_FAN_DOWN_SW_Pin GPIO_PIN_11
#define HOTAIR_FAN_DOWN_SW_GPIO_Port GPIOA
#define HOTAIR_ON_SW_Pin GPIO_PIN_12
#define HOTAIR_ON_SW_GPIO_Port GPIOA
#define EDS18B20_DATA_Pin GPIO_PIN_15
#define EDS18B20_DATA_GPIO_Port GPIOA
#define SOLD_IRON_HEATER_CTRL_Pin GPIO_PIN_3
#define SOLD_IRON_HEATER_CTRL_GPIO_Port GPIOB
#define FAN_PWM_Pin GPIO_PIN_5
#define FAN_PWM_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
