  /**
  @addtogroup COMP_Internal_Scale COMP_Internal_Scale for MDR1986VE91 evaluation board
  @latexonly
  @verbatim
  ******************** (C) COPYRIGHT 2021 Milandr ******************************
  * @file    readme.txt
  * @author  Milandr Application Team
  * @version V2.0.0
  * @date    16/07/2021
  * @brief   Description of the COMP_Internal_Scale Example.
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

This example shows how to use COMP module functions.
That action includes the following steps:
    - Configure PORTE line 8 as COMP_IN3;
    - COMP peripheral initialization;
    - COMP CVRef initialization;
    - Obtaining the result of comparison.


@par Directory contains:

    - main.c             Main program


@par Hardware and Software environment:

    - This example is intended to run on MDR1986VE91 eval board with MDR1986VE91 microcontroller.
    - Switch COMP_INP_SEL must be set on EXT_CON position.


@par How to use.

To launch the example, you must do the following:
    - Create a project and setup all project configurations.
    - Add main.c file.
    - Add the required files from "Libraries" folder:
        MDR32F9Qx_config.h
        MDR32F9Qx_port.c
        MDR32F9Qx_rst_clk.c
        MDR32F9Qx_comp.c
    - Edit the MDR32F9Qx_config.h to set appropriate run-time parameter checking level.
    - Compile and link together all .c files and load your image into the target board.
    - Run the example.

 * <h3><center>&copy; COPYRIGHT 2021 Milandr</center></h3>
 */
