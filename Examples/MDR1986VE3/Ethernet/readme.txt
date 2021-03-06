  /**
  @addtogroup Ethernet_VE3 Ethernet for MDR1986VE3 evaluation board
  @latexonly
  @verbatim
  ******************** (C) COPYRIGHT 2021 Milandr ******************************
  * @file    readme.txt
  * @author  Milandr Application Team
  * @version V2.0.0
  * @date    02/08/2021
  * @brief   Description of the Ethernet Example.
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

This example contain:
    - the example of ICMP echo server.
    - the example of TELNET echo server.


@par Directory contains:

    - src/main.c               Main program.
    - src/MDR1986VE3_IT.c      Main Interrupt Service Routines.
    - src/tcpip.c              Functions for processing ethernet frames.
    - inc/MDR1986VE3_IT.h      Functions prototypes for the interrupt.
    - inc/tcpip.h              Functions prototypes for the interrupt.


@par Hardware and Software environment:

    - This example is intended to run on MDR1986VE3 eval board with MDR1986VE3 microcontroller.


@par How to use.

To launch the example, you must do the following:
    - Create a project and setup all project configurations.
    - Add main.c file.
    - Add the required files from "Libraries" folder:
        MDR32F9Qx_config.h
        MDR32F9Qx_port.c
        MDR32F9Qx_rst_clk.c
        MDR32F9Qx_eth.c
        MDR32F9Qx_timer.c
        MDR32F9Qx_eeprom.c
        MDR32F9Qx_uart.c
    - Edit the MDR32F9Qx_config.h to set appropriate run-time parameter checking level.
    - Compile and link together all .c files and load your image into the target board.
    - Run the example.

 * <h3><center>&copy; COPYRIGHT 2021 Milandr</center></h3>
 */
