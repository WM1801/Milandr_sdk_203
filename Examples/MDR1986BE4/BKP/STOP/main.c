/**
  ******************************************************************************
  * @file    main.c
  * @author  Milandr Application Team
  * @version V2.0.2
  * @date    23/09/2021
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
#include "MDR32F9Qx_bkp.h"
#include "MDR32F9Qx_it.h"

/** @addtogroup __MDR1986BE4_StdPeriph_Examples MDR1986BE4 StdPeriph Examples
  * @{
  */

/** @addtogroup __MDR1986BE4_EVAL MDR1986BE4 Evaluation Board
  * @{
  */

/** @addtogroup BKP_STOP BKP_STOP
  * @{
  */

/* Private variables ---------------------------------------------------------*/
PORT_InitTypeDef PORT_InitStructure;

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
    /* Enables the HSI clock on PORTA */
    RST_CLK_PCLKcmd(RST_CLK_PCLK_PORTA, ENABLE);

    /* Configure all unused PORT pins to low power consumption */
    PORT_StructInit(&PORT_InitStructure);
    PORT_InitStructure.PORT_Pin = (PORT_Pin_All & ~PORT_Pin_11 );
    PORT_Init(MDR_PORTA, &PORT_InitStructure);

    /* Configure PORTA pins 11 for output to switch LEDs on/off */
    PORT_InitStructure.PORT_Pin   = PORT_Pin_11;
    PORT_InitStructure.PORT_OE    = PORT_OE_OUT;
    PORT_InitStructure.PORT_FUNC  = PORT_FUNC_PORT;
    PORT_InitStructure.PORT_MODE  = PORT_MODE_DIGITAL;
    PORT_InitStructure.PORT_SPEED = PORT_SPEED_SLOW;

    PORT_Init(MDR_PORTA, &PORT_InitStructure);

    /* Enables the HSI clock on PORTC */
    RST_CLK_PCLKcmd(RST_CLK_PCLK_PORTC, ENABLE);

    /* Configure PORTC pins 5 for input EXT_INT3 */
    PORT_InitStructure.PORT_Pin = PORT_Pin_5;
    PORT_InitStructure.PORT_FUNC = PORT_FUNC_MAIN;
    PORT_InitStructure.PORT_OE = PORT_OE_IN;
    PORT_InitStructure.PORT_MODE = PORT_MODE_DIGITAL;

    PORT_Init(MDR_PORTC, &PORT_InitStructure);

    /* Enable EXT_INT3 */
    NVIC_EnableIRQ(EXT_INT2_IRQn);

    /* STOP mode */
    BKP_EnterSTOPMode(ENABLE, BKP_STOPentry_WFI);

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

/** @} */ /* End of group BKP_STOP */

/** @} */ /* End of group __MDR1986BE4_EVAL */

/** @} */ /* End of group __MDR1986BE4_StdPeriph_Examples */

/******************* (C) COPYRIGHT 2021 Milandr *******************************/

/* END OF FILE main.c */



