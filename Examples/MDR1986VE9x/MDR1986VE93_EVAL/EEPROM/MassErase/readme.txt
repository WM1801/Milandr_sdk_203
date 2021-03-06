  /**
  @addtogroup EEPROM_Mass_Erase_93 EEPROM_Mass_Erase for MDR1986VE93 evaluation board
  @latexonly
  @verbatim
  ******************** (C) COPYRIGHT 2021 Milandr *******************************
  * @file    readme.txt
  * @author  Milandr Application Team
  * @version V2.0.0
  * @date    28/07/2021
  * @brief   Description of the EEPROM_Mass_Erase Example.
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

This example shows how to use EEPROM.
    - Erase main and information memory banks
    - Blank check main and information memory banks
    - Word programm and verification main memory bank
    - Word programm and verification information memory bank
    - Erase main memory bank only
    - Blank check main memory bank
    - Verification information memory bank
    - Word programm and verification main memory bank
    - Erase main and information memory banks
    - Blank check main and information memory banks


@par Directory contains:

    - main.c              Main program


@par Hardware and Software environment:

    - This example is intended to run on MDR1986VE93 eval board with MDR1986VE93 microcontroller.
    - VD2 (LED0), VD3 (LED1) are connected to PF.0, PF.1 pins, respectively.


@par How to use.

To launch the example, you must do the following:
    - Create a project and setup all project configurations.
    - Add main.c file.
    - Add the required files from "Library" folder:
        MDR32F9Qx_config.h
        MDR32F9Qx_port.c
        MDR32F9Qx_rst_clk.c
        MDR32F9Qx_eeprom.c
    - Edit the MDR32F9Qx_config.h to set appropriate run-time parameter checking level.
    - To allocate all code in RAM edit appropriate linker options.
      Place EEPROM functions in RAM by defining section "EXECUTABLE_MEMORY_SECTION" as RAM section.
    - Compile and link together all .c files and load your image into the target board.
    - Run the example.

 * <h3><center>&copy; COPYRIGHT 2021 Milandr</center></h3>
 */
