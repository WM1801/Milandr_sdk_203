/**
  ******************************************************************************
  * @file    main.c
  * @author  Milandr Application Team
  * @version V2.0.2
  * @date    21/09/2021
  * @brief   Main program body.
  ******************************************************************************
  * <br><br>
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, MILANDR SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2021 Milandr</center></h2>
  */

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"
#include "MDR32F9Qx_timer.h"
#include "MDR32F9Qx_rst_clk.h"
#include "MDR32F9Qx_port.h"

/** @addtogroup __MDR32Fx_StdPeriph_Examples MDR32Fx StdPeriph Examples
  * @{
  */

/** @addtogroup __MDR1986VE3_EVAL MDR1986VE3 Evaluation Board
  * @{
  */

/** @addtogroup TIMER_5PWM_Output_3T TIMER_5PWM_Output
  * @{
  */

/* Private variables ---------------------------------------------------------*/
TIMER_CntInitTypeDef sTIM_CntInit;
TIMER_ChnInitTypeDef sTIM_ChnInit;
TIMER_ChnOutInitTypeDef sTIM_ChnOutInit;
PORT_InitTypeDef PORT_InitStructure;

uint16_t CCR1_Val = 0x1FF;
uint16_t CCR2_Val = 0x3FF;
uint16_t CCR3_Val = 0x7FF;

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
    RST_CLK_DeInit();
    RST_CLK_HSEconfig(RST_CLK_HSE_ON);
    while(RST_CLK_HSEstatus() != SUCCESS);
    RST_CLK_CPU_PLLconfig (RST_CLK_CPU_PLLsrcHSEdiv2,0);
    /* Enable peripheral clocks --------------------------------------------------*/
    RST_CLK_PCLKcmd((RST_CLK_PCLK_RST_CLK | RST_CLK_PCLK_TIMER4),ENABLE);
    RST_CLK_PCLK2cmd((RST_CLK_PCLK2_PORTI), ENABLE);

    /* Reset PORTB settings */
    PORT_DeInit(MDR_PORTI);

    /* Configure TIMER4 pins: CH1, CH1N, CH2, CH2N, CH3 */
    /* Configure PORTA pins 6, 7, 8, 9, 10 */
    PORT_InitStructure.PORT_Pin   = (PORT_Pin_1 | PORT_Pin_2 | PORT_Pin_3 | PORT_Pin_4 | PORT_Pin_5);
    PORT_InitStructure.PORT_OE    = PORT_OE_OUT;
    PORT_InitStructure.PORT_FUNC  = PORT_FUNC_ALTER;
    PORT_InitStructure.PORT_MODE  = PORT_MODE_DIGITAL;
    PORT_InitStructure.PORT_SPEED = PORT_SPEED_MAXFAST;
    PORT_InitStructure.PORT_PD    = PORT_PD_DRIVER;
    PORT_Init(MDR_PORTI, &PORT_InitStructure);

    /* Reset all TIMER1 settings */
    TIMER_DeInit(MDR_TIMER4);

    /* TIM1 Configuration ---------------------------------------------------
     Generates 5 PWM signals with 4 different duty cycles:
     TIM1CLK = 8 MHz, Prescaler = 0, TIM1 counter clock = 8 MHz
     TIM1 frequency = TIM1CLK/(TIM1_Period + 1) = 1.95 KHz
    - TIM1 Channel1 & Channel1N duty cycle = TIM1->CCR1 / (TIM1_Period + 1) = 50%
    - TIM1 Channel2 & Channel2N duty cycle = TIM1->CCR2 / (TIM1_Period + 1) = 25%
    - TIM1 Channel3 duty cycle = TIM1->CCR3 / (TIM1_Period + 1) = 12.5%
    ----------------------------------------------------------------------- */

    /* Initializes the TIMERx Counter ------------------------------------*/
    sTIM_CntInit.TIMER_Prescaler              = 0x0;
    sTIM_CntInit.TIMER_Period                 = 0xFFF;
    sTIM_CntInit.TIMER_CounterMode            = TIMER_CntMode_ClkFixedDir;
    sTIM_CntInit.TIMER_CounterDirection       = TIMER_CntDir_Up;
    sTIM_CntInit.TIMER_EventSource            = TIMER_EvSrc_TIM_CLK;
    sTIM_CntInit.TIMER_FilterSampling         = TIMER_FDTS_TIMER_CLK_div_1;
    sTIM_CntInit.TIMER_ARR_UpdateMode         = TIMER_ARR_Update_Immediately;
    sTIM_CntInit.TIMER_ETR_FilterConf         = TIMER_Filter_1FF_at_TIMER_CLK;
    sTIM_CntInit.TIMER_ETR_Prescaler          = TIMER_ETR_Prescaler_None;
    sTIM_CntInit.TIMER_ETR_Polarity           = TIMER_ETRPolarity_NonInverted;
    sTIM_CntInit.TIMER_BRK_Polarity           = TIMER_BRKPolarity_NonInverted;
    TIMER_CntInit (MDR_TIMER4,&sTIM_CntInit);
    
    /* Initializes the TIMER1 Channel 1,1N,2,2N,3 ------------------------------*/
    TIMER_ChnStructInit(&sTIM_ChnInit);

    sTIM_ChnInit.TIMER_CH_Mode                = TIMER_CH_MODE_PWM;
    sTIM_ChnInit.TIMER_CH_REF_Format          = TIMER_CH_REF_Format6;
    sTIM_ChnInit.TIMER_CH_Number              = TIMER_CHANNEL1;
    TIMER_ChnInit(MDR_TIMER4, &sTIM_ChnInit);

    sTIM_ChnInit.TIMER_CH_Number              = TIMER_CHANNEL2;
    TIMER_ChnInit(MDR_TIMER4, &sTIM_ChnInit);

    sTIM_ChnInit.TIMER_CH_Number              = TIMER_CHANNEL3;
    TIMER_ChnInit(MDR_TIMER4, &sTIM_ChnInit);

    TIMER_SetChnCompare(MDR_TIMER4, TIMER_CHANNEL1, CCR1_Val);
    TIMER_SetChnCompare(MDR_TIMER4, TIMER_CHANNEL2, CCR2_Val);
    TIMER_SetChnCompare(MDR_TIMER4, TIMER_CHANNEL3, CCR3_Val);

    /* Initializes the TIMER1 Channel 1,1N,2,2N,3 Output -----------------------*/

    TIMER_ChnOutStructInit(&sTIM_ChnOutInit);

    sTIM_ChnOutInit.TIMER_CH_DirOut_Polarity          = TIMER_CHOPolarity_NonInverted;
    sTIM_ChnOutInit.TIMER_CH_DirOut_Source            = TIMER_CH_OutSrc_REF;
    sTIM_ChnOutInit.TIMER_CH_DirOut_Mode              = TIMER_CH_OutMode_Output;
    sTIM_ChnOutInit.TIMER_CH_NegOut_Polarity          = TIMER_CHOPolarity_NonInverted;
    sTIM_ChnOutInit.TIMER_CH_NegOut_Source            = TIMER_CH_OutSrc_REF;
    sTIM_ChnOutInit.TIMER_CH_NegOut_Mode              = TIMER_CH_OutMode_Output;
    sTIM_ChnOutInit.TIMER_CH_Number                   = TIMER_CHANNEL1;
    TIMER_ChnOutInit(MDR_TIMER4, &sTIM_ChnOutInit);

    sTIM_ChnOutInit.TIMER_CH_Number                   = TIMER_CHANNEL2;
    TIMER_ChnOutInit(MDR_TIMER4, &sTIM_ChnOutInit);

    sTIM_ChnOutInit.TIMER_CH_Number                   = TIMER_CHANNEL3;
    TIMER_ChnOutInit(MDR_TIMER4, &sTIM_ChnOutInit);

    /* Enable TIMER1 clock */
    TIMER_BRGInit(MDR_TIMER4,TIMER_HCLKdiv1);

    /* Enable TIMER1 */
    TIMER_Cmd(MDR_TIMER4,ENABLE);

    while(1);
}

/**
  * @brief  Reports the source file name, the source line number
  *         and expression text (if USE_ASSERT_INFO == 2) where
  *         the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @param  expr:
  * @retval None
  */
#if (USE_ASSERT_INFO == 1)
void assert_failed(uint8_t* file, uint32_t line)
{
    /* User can add his own implementation to report the source file name and line number.
       Ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

    /* Infinite loop */
    while (1)
    {
    }
}
#elif (USE_ASSERT_INFO == 2)
void assert_failed(uint8_t* file, uint32_t line, const uint8_t* expr)
{
    /* User can add his own implementation to report the source file name, line number and
       expression text.
       Ex: printf("Wrong parameters value (%s): file %s on line %d\r\n", expr, file, line) */

    /* Infinite loop */
    while (1)
    {
    }
}
#endif /* USE_ASSERT_INFO */

/** @} */ /* End of group TIMER_5PWM_Output_3T */

/** @} */ /* End of group __MDR1986VE3_EVAL */

/** @} */ /* End of group __MDR32Fx_StdPeriph_Examples */

/******************* (C) COPYRIGHT 2021 Milandr *******************************/

/* END OF FILE main.c */
