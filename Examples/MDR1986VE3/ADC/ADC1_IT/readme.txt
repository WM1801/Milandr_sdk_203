  /**
  @addtogroup ADC_ADC1_IT_3T ADC_ADC1_IT for MDR1986VE3 evaluation board
  @latexonly
  @verbatim
  ******************** (C) COPYRIGHT 2021 Milandr ******************************
  * @file    readme.txt
  * @author  Milandr Application Team
  * @version V2.0.0
  * @date    02/08/2021
  * @brief   Description of the ADC_ADC1_IT Example.
  ******************************************************************************
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, MILANDR SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  ******************************************************************************
  @endverbatim
  @endlatexonly

@par Example Description

This example describes how to use the ADC to transfer continuously converted 
data from ADC to memory. The ADC is configured to converts continuously 
ADC channel 31 - Temperature Sensor. Each time an end of conversion occurs the 
IT, the converted data from ADC RESULT register to the ADC_ConvertedValue[16] 
array of variables.


@par Directory contains:

    - main.c               Main program
    - MDR1986VE3T_IT.c     Main Interrupt Service Routines
    - MDR1986VE3T_IT.h     Functions prototypes for the interrupt


@par Hardware and Software environment:

    - This example is intended to run on MDR1986VE3 eval board with MDR1986VE3 microcontroller.


@par How to use.

To launch the example, you must do the following:
    - Create a project and setup all project configurations.
    - Add main.c file.
    - Add MDR1986VE3T_IT.c and MDR1986VE3T_IT.h files.
    - Add the required files from "Libraries" folder:
        MDR32F9Qx_config.h
        MDR32F9Qx_port.c
        MDR32F9Qx_rst_clk.c
        MDR32F9Qx_adc.c
        MDR32F9Qx_uart.h
        MDR32F9Qx_eeprom.h
        MDR32F9Qx_rst_clk.h
    - Edit the MDR32F9Qx_config.h to set appropriate run-time parameter checking level.
    - Compile and link together all .c files and load your image into the target board.
    - Run the example.

 * <h3><center>&copy; COPYRIGHT 2021 Milandr</center></h3>
 */
