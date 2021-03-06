/**
  ******************************************************************************
  * @file    TIMER_IT_handler.h
  * @author  Milandr Application Team
  * @version V2.0.2
  * @date    22/09/2021
  * @brief   This file contains the user defines and typedef and functions prototypes.
  ******************************************************************************
  * <br><br>
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, MILANDR SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT
  * OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2021 Milandr </center></h2>
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef TIMER_IT_HANDLER_H_
#define TIMER_IT_HANDLER_H_

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup __MDR32Fx_StdPeriph_Examples MDR32Fx StdPeriph Examples
  * @{
  */

/** @addtogroup __MDR1986VE3_EVAL MDR1986VE3 Evaluation Board
  * @{
  */

/** @addtogroup MIL_STD_1553_Terminal_Device_VE3 MIL_STD_1553 Terminal Device
 *  @{
 */

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_timer.h"


/* Function prototypes -------------------------------------------------------*/
void My_TIMER1_IRQ_Handler(MDR_TIMER_TypeDef * TIMERx, MDR_MIL_STD_1553_TypeDef * MIL_STD_1553x);

/** @} */ /* End of MIL_STD_1553_Terminal_Device_VE3 */

/** @} */ /* End of group __MDR1986VE3_EVAL */

/** @} */ /* End of group __MDR32Fx_StdPeriph_Examples */

#ifdef __cplusplus
}
#endif

#endif /* TIMER_IT_HANDLER_H_ */

/******************* (C) COPYRIGHT 2021 Milandr *******************************/

/* END OF FILE TIMER_IT_handler.h */
