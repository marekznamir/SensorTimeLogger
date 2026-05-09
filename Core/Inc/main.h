/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim9;
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
extern TIM_HandleTypeDef htim2;
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LD2_Pin GPIO_PIN_13
#define LD2_GPIO_Port GPIOC
#define GPIO_CS_Pin GPIO_PIN_4
#define GPIO_CS_GPIO_Port GPIOA
#define DISP_A_Pin GPIO_PIN_0
#define DISP_A_GPIO_Port GPIOB
#define DISP_B_Pin GPIO_PIN_1
#define DISP_B_GPIO_Port GPIOB
#define DISP_C_Pin GPIO_PIN_2
#define DISP_C_GPIO_Port GPIOB
#define DISP_COMM_3_Pin GPIO_PIN_10
#define DISP_COMM_3_GPIO_Port GPIOB
#define DISP_COMM_4_Pin GPIO_PIN_12
#define DISP_COMM_4_GPIO_Port GPIOB
#define MINUS_Pin GPIO_PIN_13
#define MINUS_GPIO_Port GPIOB
#define BUTTON_INC_Pin GPIO_PIN_8
#define BUTTON_INC_GPIO_Port GPIOA
#define BUTTON_DEC_Pin GPIO_PIN_9
#define BUTTON_DEC_GPIO_Port GPIOA
#define BUTTON_EXTI_MODE_Pin GPIO_PIN_10
#define BUTTON_EXTI_MODE_GPIO_Port GPIOA
#define BUTTON_EXTI_MODE_EXTI_IRQn EXTI15_10_IRQn
#define SENSOR_EXTI_Pin GPIO_PIN_11
#define SENSOR_EXTI_GPIO_Port GPIOA
#define SENSOR_EXTI_EXTI_IRQn EXTI15_10_IRQn
#define DISP_D_Pin GPIO_PIN_3
#define DISP_D_GPIO_Port GPIOB
#define DISP_E_Pin GPIO_PIN_4
#define DISP_E_GPIO_Port GPIOB
#define DISP_F_Pin GPIO_PIN_5
#define DISP_F_GPIO_Port GPIOB
#define DISP_G_Pin GPIO_PIN_6
#define DISP_G_GPIO_Port GPIOB
#define DISP_DOT_Pin GPIO_PIN_7
#define DISP_DOT_GPIO_Port GPIOB
#define DISP_COMM_1_Pin GPIO_PIN_8
#define DISP_COMM_1_GPIO_Port GPIOB
#define DISP_COMM_2_Pin GPIO_PIN_9
#define DISP_COMM_2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
#define SD_SPI_HANDLE hspi1
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
