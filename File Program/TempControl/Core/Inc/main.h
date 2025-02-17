/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32g4xx_hal.h"

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
#define ADC_VOLT_Pin GPIO_PIN_0
#define ADC_VOLT_GPIO_Port GPIOC
#define ADC_CUR_Pin GPIO_PIN_1
#define ADC_CUR_GPIO_Port GPIOC
#define ADC_TEMP_Pin GPIO_PIN_2
#define ADC_TEMP_GPIO_Port GPIOC
#define PB_Mode_Pin GPIO_PIN_0
#define PB_Mode_GPIO_Port GPIOA
#define PB_Mode_EXTI_IRQn EXTI0_IRQn
#define PB_StartStop_Pin GPIO_PIN_1
#define PB_StartStop_GPIO_Port GPIOA
#define PB_StartStop_EXTI_IRQn EXTI1_IRQn
#define Reset_state_Pin GPIO_PIN_2
#define Reset_state_GPIO_Port GPIOA
#define Reset_state_EXTI_IRQn EXTI2_IRQn
#define POT_TIMER_Pin GPIO_PIN_0
#define POT_TIMER_GPIO_Port GPIOB
#define POT_SETPOINT_Pin GPIO_PIN_1
#define POT_SETPOINT_GPIO_Port GPIOB
#define PWM_GEN_Pin GPIO_PIN_6
#define PWM_GEN_GPIO_Port GPIOC
#define LED_MODE_Pin GPIO_PIN_9
#define LED_MODE_GPIO_Port GPIOA
#define LED_STOPRUN_Pin GPIO_PIN_10
#define LED_STOPRUN_GPIO_Port GPIOA
#define LED_SETPOINT_Pin GPIO_PIN_11
#define LED_SETPOINT_GPIO_Port GPIOA
#define LED_Pin GPIO_PIN_12
#define LED_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
