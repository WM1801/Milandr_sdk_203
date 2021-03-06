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
#include "MDR32F9Qx_port.h"
#include "MDR32F9Qx_rst_clk.h"
#include "MDR32F9Qx_adc.h"
#include "MDR32F9Qx_it.h"

/** @addtogroup __MDR32Fx_StdPeriph_Examples MDR32Fx StdPeriph Examples
  * @{
  */

/** @addtogroup __MDR1986VE91_EVAL MDR1986VE91 Evaluation Board
  * @{
  */

/** @addtogroup ADC_AnalogWatchdog ADC_AnalogWatchdog
  * @{
  */

/* Private variables ---------------------------------------------------------*/
__IO uint32_t H_Level = 0x900;
__IO uint32_t L_Level = 0x800;

PORT_InitTypeDef PORT_InitStructure;
ADC_InitTypeDef sADC;
ADCx_InitTypeDef sADCx;

/* Private functions ---------------------------------------------------------*/
/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
    RST_CLK_DeInit();
    /* Enable peripheral clocks */
    RST_CLK_PCLKcmd((RST_CLK_PCLK_RST_CLK | RST_CLK_PCLK_ADC | RST_CLK_PCLK_PORTD),ENABLE);

    /* Init NVIC */
    SCB->AIRCR = 0x05FA0000 | ((uint32_t)0x500);
    SCB->VTOR = 0x08000000;
    /* Disable all interrupt */
    NVIC->ICPR[0] = 0xFFFFFFFF;
    NVIC->ICER[0] = 0xFFFFFFFF;

    /* Enable ADC interrupt  */
    NVIC->ISER[0] = (1<<ADC_IRQn);

    /* Reset PORTD settings */
    PORT_DeInit(MDR_PORTD);

    /* Configure ADC pin: ADC7 */
    /* Configure PORTD pin 7 */
    PORT_InitStructure.PORT_Pin   = PORT_Pin_7;
    PORT_InitStructure.PORT_OE    = PORT_OE_IN;
    PORT_InitStructure.PORT_MODE  = PORT_MODE_ANALOG;
    PORT_Init(MDR_PORTD, &PORT_InitStructure);

    /* Configure PORTD pins 10, 11 for output to switch LED1,2 on/off */
    /* Configure PORTD pins 10, 11 */
    PORT_InitStructure.PORT_FUNC  = PORT_FUNC_PORT;
    PORT_InitStructure.PORT_Pin   = PORT_Pin_10 | PORT_Pin_11;
    PORT_InitStructure.PORT_OE    = PORT_OE_OUT;
    PORT_InitStructure.PORT_MODE  = PORT_MODE_DIGITAL;
    PORT_InitStructure.PORT_SPEED = PORT_SPEED_SLOW;
    PORT_Init(MDR_PORTD, &PORT_InitStructure);

    /* ADC Configuration */
    /* Reset all ADC settings */
    ADC_DeInit();
    ADC_StructInit(&sADC);
    ADC_Init (&sADC);

    ADCx_StructInit (&sADCx);
    sADCx.ADC_ClockSource      = ADC_CLOCK_SOURCE_CPU;
    sADCx.ADC_SamplingMode     = ADC_SAMPLING_MODE_CYCLIC_CONV;
    sADCx.ADC_ChannelSwitching = ADC_CH_SWITCHING_Disable;
    sADCx.ADC_ChannelNumber    = ADC_CH_ADC7;
    sADCx.ADC_Channels         = 0;
    sADCx.ADC_LevelControl     = ADC_LEVEL_CONTROL_Enable;
    sADCx.ADC_LowLevel         = L_Level;
    sADCx.ADC_HighLevel        = H_Level;
    sADCx.ADC_VRefSource       = ADC_VREF_SOURCE_INTERNAL;
    sADCx.ADC_IntVRefSource    = ADC_INT_VREF_SOURCE_INEXACT;
    sADCx.ADC_Prescaler        = ADC_CLK_div_2048;
    sADCx.ADC_DelayGo          = 0xF;
    ADC1_Init (&sADCx);

    /* Enable ADC1 EOCIF and AWOIFEN interupts */
    ADC1_ITConfig((ADC1_IT_END_OF_CONVERSION  | ADC1_IT_OUT_OF_RANGE), ENABLE);

    /* ADC1 enable */
    ADC1_Cmd (ENABLE);

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

/** @} */ /* End of group ADC_AnalogWatchdog */

/** @} */ /* End of group __MDR1986VE91_EVAL */

/** @} */ /* End of group __MDR32Fx_StdPeriph_Examples */

/******************* (C) COPYRIGHT 2021 Milandr *******************************/

/* END OF FILE main.c */
