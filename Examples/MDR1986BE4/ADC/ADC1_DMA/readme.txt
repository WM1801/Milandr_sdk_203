  /**
  @addtogroup ADC_ADC1_DMA ADC_ADC1_DMA for MDR1986BE4 evaluation board
  @latexonly
  @verbatim
  ******************** (C) COPYRIGHT 2021 Milandr ******************************
  * @file    readme.txt
  * @author  Milandr Application Team
  * @version V2.0.0
  * @date    09/06/2021
  * @brief   Description of the ADC1_DMA Example.
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

This example describes how to use the ADC1 and DMA to transfer continuously
converted data from ADC1 to memory. The ADC1 is configured to converts 
continuously ADC channel31 - Temperature Sensor. Each time an end of conversion
occurs the DMA transfers, in ping-pong mode, the converted data from ADC1 RESULT
register to the ADC_ConvertedValue[10] array of variables.


@par Directory contains:

    - main.c              Main program
    - MDR32F9Qx_it.c      Main Interrupt Service Routines
    - MDR32F9Qx_it.h      Functions prototypes for the interrupt


@par Hardware and Software environment:

    - This example is intended to run on MDR1986BE4 eval board with MDR1986BE4 microcontroller.


@par How to use.

To launch the example, you must do the following:
    - Create a project and setup all project configurations.
    - Add main.c file.
    - Add MDR32F9Qx_it.c and MDR32F9Qx_it.h files.
    - Add the required files from "Libraries" folder:
        MDR32F9Qx_config.h
        MDR32F9Qx_rst_clk.c
        MDR32F9Qx_adc.c
        MDR32F9Qx_dma.c
    - Edit the MDR32F9Qx_config.h to set appropriate run-time parameter checking level.
    - Compile and link together all .c files and load your image into the target board.
    - Run the example.


 * <h3><center>&copy; COPYRIGHT 2021 Milandr</center></h3>
 */


