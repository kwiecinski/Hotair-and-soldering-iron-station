/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f1xx_hal.h"

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
#define LCD_RW_Pin GPIO_PIN_13
#define LCD_RW_GPIO_Port GPIOC
#define LCD_RS_Pin GPIO_PIN_14
#define LCD_RS_GPIO_Port GPIOC
#define HOTAIR_FAN_DOWN_SW_Pin GPIO_PIN_15
#define HOTAIR_FAN_DOWN_SW_GPIO_Port GPIOC
#define HOTAIR_ON_SW_Pin GPIO_PIN_0
#define HOTAIR_ON_SW_GPIO_Port GPIOD
#define HOTAIR_FAN_UP_SW_Pin GPIO_PIN_1
#define HOTAIR_FAN_UP_SW_GPIO_Port GPIOD
#define HOTAIR_DOWN_SW_Pin GPIO_PIN_0
#define HOTAIR_DOWN_SW_GPIO_Port GPIOA
#define HOTAIR_FAN_ADC_Pin GPIO_PIN_1
#define HOTAIR_FAN_ADC_GPIO_Port GPIOA
#define UART_DBG_TX_Pin GPIO_PIN_2
#define UART_DBG_TX_GPIO_Port GPIOA
#define MAX31855_IRON_CS_Pin GPIO_PIN_3
#define MAX31855_IRON_CS_GPIO_Port GPIOA
#define MAX31855_HOTAIR_CS_Pin GPIO_PIN_4
#define MAX31855_HOTAIR_CS_GPIO_Port GPIOA
#define IRON_WEP_HEATER_CTRL_Pin GPIO_PIN_7
#define IRON_WEP_HEATER_CTRL_GPIO_Port GPIOA
#define IRON_T12_TEMP_ADC_Pin GPIO_PIN_0
#define IRON_T12_TEMP_ADC_GPIO_Port GPIOB
#define HOTAIR_TEMP_ADC_Pin GPIO_PIN_1
#define HOTAIR_TEMP_ADC_GPIO_Port GPIOB
#define HOTAIR_REED_SW_Pin GPIO_PIN_2
#define HOTAIR_REED_SW_GPIO_Port GPIOB
#define SOLDER_SELECT_SW_Pin GPIO_PIN_10
#define SOLDER_SELECT_SW_GPIO_Port GPIOB
#define MENU_OK_SW_Pin GPIO_PIN_11
#define MENU_OK_SW_GPIO_Port GPIOB
#define MENU_DOWN_SW_Pin GPIO_PIN_12
#define MENU_DOWN_SW_GPIO_Port GPIOB
#define SOLDER_DOWN_SW_Pin GPIO_PIN_13
#define SOLDER_DOWN_SW_GPIO_Port GPIOB
#define IRON_T12_MOTION_SW_Pin GPIO_PIN_14
#define IRON_T12_MOTION_SW_GPIO_Port GPIOB
#define SOLDER_UP_SW_Pin GPIO_PIN_15
#define SOLDER_UP_SW_GPIO_Port GPIOB
#define HOTAIR_FAN_PWM_Pin GPIO_PIN_8
#define HOTAIR_FAN_PWM_GPIO_Port GPIOA
#define HOTAIR_HEATER_CTRL_Pin GPIO_PIN_9
#define HOTAIR_HEATER_CTRL_GPIO_Port GPIOA
#define MENU_UP_SW_Pin GPIO_PIN_10
#define MENU_UP_SW_GPIO_Port GPIOA
#define SOLDER_ON_SW_Pin GPIO_PIN_11
#define SOLDER_ON_SW_GPIO_Port GPIOA
#define HOTAIR_UP_SW_Pin GPIO_PIN_12
#define HOTAIR_UP_SW_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define BUZZER_PWM_Pin GPIO_PIN_15
#define BUZZER_PWM_GPIO_Port GPIOA
#define LED_BACKLIGHT_PWM_Pin GPIO_PIN_3
#define LED_BACKLIGHT_PWM_GPIO_Port GPIOB
#define LCD_D7_Pin GPIO_PIN_4
#define LCD_D7_GPIO_Port GPIOB
#define LCD_D6_Pin GPIO_PIN_5
#define LCD_D6_GPIO_Port GPIOB
#define IRON_T12_HEATER_CTRL_Pin GPIO_PIN_6
#define IRON_T12_HEATER_CTRL_GPIO_Port GPIOB
#define LCD_D5_Pin GPIO_PIN_7
#define LCD_D5_GPIO_Port GPIOB
#define LCD_D4_Pin GPIO_PIN_8
#define LCD_D4_GPIO_Port GPIOB
#define LCD_EN_Pin GPIO_PIN_9
#define LCD_EN_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
