/**
  ******************************************************************************
  * @file    MDR32F9Qx_comp.h
  * @author  Milandr Application Team
  * @version V2.0.2
  * @date    22/09/2021
  * @brief   This file contains all the functions prototypes for the COMP
  *          firmware library.
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
  * <h2><center>&copy; COPYRIGHT 2021 Milandr</center></h2>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MDR32F9QX_COMP_H
#define __MDR32F9QX_COMP_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "MDR32F9Qx_config.h"

/** @addtogroup __MDR1986BE4_StdPeriph_Driver MDR1986BE4 Standard Peripherial Driver
  * @{
  */

/** @addtogroup COMP
  * @{
  */

/** @defgroup COMP_Exported_Types COMP Exported Types
  * @{
  */

/**
  * @brief COMP non-inverting input source
  */
typedef enum
{
    COMP_PlusInput_IN1   = (((uint32_t)0x0) << COMP_CFG_CREF_Pos), /*!< The non-inverting comparator input connected to IN1. */
    COMP_PlusInput_CVREF = (((uint32_t)0x1) << COMP_CFG_CREF_Pos)  /*!< The non-inverting comparator input connected to CVREF. */
} COMP_Plus_Inp_Src;

#define IS_COMP_PLUS_INPUT_CONFIG(CONFIG) (((CONFIG) == COMP_PlusInput_IN1  ) || \
                                           ((CONFIG) == COMP_PlusInput_CVREF))

/**
  * @brief COMP inverting input source
  */
typedef enum
{
    COMP_MinusInput_IN2   = (((uint32_t)0x0) << COMP_CFG_CCH_Pos), /*!< The inverting comparator input connected to IN2. */
    COMP_MinusInput_IN1   = (((uint32_t)0x1) << COMP_CFG_CCH_Pos), /*!< The inverting comparator input connected to IN1. */
    COMP_MinusInput_IN3   = (((uint32_t)0x2) << COMP_CFG_CCH_Pos), /*!< The inverting comparator input connected to IN3. */
    COMP_MinusInput_IVREF = (((uint32_t)0x3) << COMP_CFG_CCH_Pos)  /*!< The inverting comparator input connected to IVREF. */
} COMP_Minus_Inp_Src;

#define IS_COMP_MINUS_INPUT_CONFIG(CONFIG) (((CONFIG) == COMP_MinusInput_IN2  ) || \
                                            ((CONFIG) == COMP_MinusInput_IN1  ) || \
                                            ((CONFIG) == COMP_MinusInput_IN3  ) || \
                                            ((CONFIG) == COMP_MinusInput_IVREF))

/**
  * @brief COMP output inversion
  */
typedef enum
{
    COMP_OUT_INV_Disable = (((uint32_t)0x0) << COMP_CFG_INV_Pos), /*!< Disables the Comparator output inversion. */
    COMP_OUT_INV_Enable  = (((uint32_t)0x1) << COMP_CFG_INV_Pos)  /*!< Enables the Comparator output inversion. */
} COMP_Out_Inv_State;

#define IS_COMP_OUT_INV_CONFIG(CONFIG) (((CONFIG) == COMP_OUT_INV_Disable) || \
                                        ((CONFIG) == COMP_OUT_INV_Enable ))

typedef enum
{
    COMP_CVREF_SOURCE_AVdd = (((uint32_t)0x0) << COMP_CFG_CVRSS_Pos), /*!< The CVREF source is (AVdd, AGND). */
    COMP_CVREF_SOURCE_VRef = (((uint32_t)0x1) << COMP_CFG_CVRSS_Pos)  /*!< The CVREF source is (VRef+, VRef-). */
} COMP_CVRef_Src;

#define IS_COMP_CVREF_SOURCE_CONFIG(CONFIG) (((CONFIG) == COMP_CVREF_SOURCE_AVdd) || \
                                             ((CONFIG) == COMP_CVREF_SOURCE_VRef))

#if defined (MDR_LEGACY_SUPPORT) && (MDR_LEGACY_SUPPORT) == 153
    #warning "Legacy v1.5.3: @ref COMP_CVRef_Range enum will be removed - use @ref COMP_CVRef_Scale enum instead"
/**
  * @brief COMP CVRef range
  */
typedef enum
{
    COMP_CVREF_RANGE_Up = (((uint32_t)0x0) << COMP_CFG_CVRR_Pos), /*!< CVREF works in Up Range. */
    COMP_CVREF_RANGE_Dn = (((uint32_t)0x1) << COMP_CFG_CVRR_Pos)  /*!< CVREF works in Down Range. */
} COMP_CVRef_Range;

#define IS_COMP_CVREF_RANGE_CONFIG(CONFIG) (((CONFIG) == COMP_CVREF_RANGE_Up) || \
                                            ((CONFIG) == COMP_CVREF_RANGE_Dn))
#endif /* MDR_LEGACY_SUPPORT 153 */

/**
  * @brief COMP CVRef scale
  */
typedef enum
{
    COMP_CVREF_SCALE_0_div_24  = (((uint32_t)0x0) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef down range scale 0/24.  */
    COMP_CVREF_SCALE_1_div_24  = (((uint32_t)0x1) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef down range scale 1/24.  */
    COMP_CVREF_SCALE_2_div_24  = (((uint32_t)0x2) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef down range scale 2/24.  */
    COMP_CVREF_SCALE_3_div_24  = (((uint32_t)0x3) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef down range scale 3/24.  */
    COMP_CVREF_SCALE_4_div_24  = (((uint32_t)0x4) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef down range scale 4/24.  */
    COMP_CVREF_SCALE_5_div_24  = (((uint32_t)0x5) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef down range scale 5/24.  */
    COMP_CVREF_SCALE_6_div_24  = (((uint32_t)0x6) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef down range scale 6/24.  */
    COMP_CVREF_SCALE_7_div_24  = (((uint32_t)0x7) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef down range scale 7/24.  */
    COMP_CVREF_SCALE_8_div_24  = (((uint32_t)0x8) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef down range scale 8/24.  */
    COMP_CVREF_SCALE_9_div_24  = (((uint32_t)0x9) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef down range scale 9/24.  */
    COMP_CVREF_SCALE_10_div_24 = (((uint32_t)0xA) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef down range scale 10/24. */
    COMP_CVREF_SCALE_11_div_24 = (((uint32_t)0xB) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef down range scale 11/24. */
    COMP_CVREF_SCALE_12_div_24 = (((uint32_t)0xC) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef down range scale 12/24. */
    COMP_CVREF_SCALE_13_div_24 = (((uint32_t)0xD) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef down range scale 13/24. */
    COMP_CVREF_SCALE_14_div_24 = (((uint32_t)0xE) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef down range scale 14/24. */
    COMP_CVREF_SCALE_15_div_24 = (((uint32_t)0xF) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef down range scale 15/24. */

#if defined (MDR_LEGACY_SUPPORT) && (MDR_LEGACY_SUPPORT) == 153
    #warning "Legacy v1.5.3: COMP_CVREF_SCALE_x_div_32 will be replaced with correct CVR+CVRR values"
    COMP_CVREF_SCALE_8_div_32  = (((uint32_t)0x0) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef up range scale 8/32.  */
    COMP_CVREF_SCALE_9_div_32  = (((uint32_t)0x1) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef up range scale 9/32.  */
    COMP_CVREF_SCALE_10_div_32 = (((uint32_t)0x2) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef up range scale 10/32. */
    COMP_CVREF_SCALE_11_div_32 = (((uint32_t)0x3) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef up range scale 11/32. */
    COMP_CVREF_SCALE_12_div_32 = (((uint32_t)0x4) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef up range scale 12/32. */
    COMP_CVREF_SCALE_13_div_32 = (((uint32_t)0x5) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef up range scale 13/32. */
    COMP_CVREF_SCALE_14_div_32 = (((uint32_t)0x6) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef up range scale 14/32. */
    COMP_CVREF_SCALE_15_div_32 = (((uint32_t)0x7) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef up range scale 15/32. */
    COMP_CVREF_SCALE_16_div_32 = (((uint32_t)0x8) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef up range scale 16/32. */
    COMP_CVREF_SCALE_17_div_32 = (((uint32_t)0x9) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef up range scale 17/32. */
    COMP_CVREF_SCALE_18_div_32 = (((uint32_t)0xA) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef up range scale 18/32. */
    COMP_CVREF_SCALE_19_div_32 = (((uint32_t)0xB) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef up range scale 19/32. */
    COMP_CVREF_SCALE_20_div_32 = (((uint32_t)0xC) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef up range scale 20/32. */
    COMP_CVREF_SCALE_21_div_32 = (((uint32_t)0xD) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef up range scale 21/32. */
    COMP_CVREF_SCALE_22_div_32 = (((uint32_t)0xE) << COMP_CFG_CVR_Pos), /*!< Selects the COMP CVRef up range scale 22/32. */
    COMP_CVREF_SCALE_23_div_32 = (((uint32_t)0xF) << COMP_CFG_CVR_Pos)  /*!< Selects the COMP CVRef up range scale 23/32. */
#else
    COMP_CVREF_SCALE_8_div_32  = (((uint32_t)0x0) << COMP_CFG_CVR_Pos) + (((uint32_t)0x1) << COMP_CFG_CVRR_Pos), /*!< Selects the COMP CVRef up range scale 8/32.  */
    COMP_CVREF_SCALE_9_div_32  = (((uint32_t)0x1) << COMP_CFG_CVR_Pos) + (((uint32_t)0x1) << COMP_CFG_CVRR_Pos), /*!< Selects the COMP CVRef up range scale 9/32.  */
    COMP_CVREF_SCALE_10_div_32 = (((uint32_t)0x2) << COMP_CFG_CVR_Pos) + (((uint32_t)0x1) << COMP_CFG_CVRR_Pos), /*!< Selects the COMP CVRef up range scale 10/32. */
    COMP_CVREF_SCALE_11_div_32 = (((uint32_t)0x3) << COMP_CFG_CVR_Pos) + (((uint32_t)0x1) << COMP_CFG_CVRR_Pos), /*!< Selects the COMP CVRef up range scale 11/32. */
    COMP_CVREF_SCALE_12_div_32 = (((uint32_t)0x4) << COMP_CFG_CVR_Pos) + (((uint32_t)0x1) << COMP_CFG_CVRR_Pos), /*!< Selects the COMP CVRef up range scale 12/32. */
    COMP_CVREF_SCALE_13_div_32 = (((uint32_t)0x5) << COMP_CFG_CVR_Pos) + (((uint32_t)0x1) << COMP_CFG_CVRR_Pos), /*!< Selects the COMP CVRef up range scale 13/32. */
    COMP_CVREF_SCALE_14_div_32 = (((uint32_t)0x6) << COMP_CFG_CVR_Pos) + (((uint32_t)0x1) << COMP_CFG_CVRR_Pos), /*!< Selects the COMP CVRef up range scale 14/32. */
    COMP_CVREF_SCALE_15_div_32 = (((uint32_t)0x7) << COMP_CFG_CVR_Pos) + (((uint32_t)0x1) << COMP_CFG_CVRR_Pos), /*!< Selects the COMP CVRef up range scale 15/32. */
    COMP_CVREF_SCALE_16_div_32 = (((uint32_t)0x8) << COMP_CFG_CVR_Pos) + (((uint32_t)0x1) << COMP_CFG_CVRR_Pos), /*!< Selects the COMP CVRef up range scale 16/32. */
    COMP_CVREF_SCALE_17_div_32 = (((uint32_t)0x9) << COMP_CFG_CVR_Pos) + (((uint32_t)0x1) << COMP_CFG_CVRR_Pos), /*!< Selects the COMP CVRef up range scale 17/32. */
    COMP_CVREF_SCALE_18_div_32 = (((uint32_t)0xA) << COMP_CFG_CVR_Pos) + (((uint32_t)0x1) << COMP_CFG_CVRR_Pos), /*!< Selects the COMP CVRef up range scale 18/32. */
    COMP_CVREF_SCALE_19_div_32 = (((uint32_t)0xB) << COMP_CFG_CVR_Pos) + (((uint32_t)0x1) << COMP_CFG_CVRR_Pos), /*!< Selects the COMP CVRef up range scale 19/32. */
    COMP_CVREF_SCALE_20_div_32 = (((uint32_t)0xC) << COMP_CFG_CVR_Pos) + (((uint32_t)0x1) << COMP_CFG_CVRR_Pos), /*!< Selects the COMP CVRef up range scale 20/32. */
    COMP_CVREF_SCALE_21_div_32 = (((uint32_t)0xD) << COMP_CFG_CVR_Pos) + (((uint32_t)0x1) << COMP_CFG_CVRR_Pos), /*!< Selects the COMP CVRef up range scale 21/32. */
    COMP_CVREF_SCALE_22_div_32 = (((uint32_t)0xE) << COMP_CFG_CVR_Pos) + (((uint32_t)0x1) << COMP_CFG_CVRR_Pos), /*!< Selects the COMP CVRef up range scale 22/32. */
    COMP_CVREF_SCALE_23_div_32 = (((uint32_t)0xF) << COMP_CFG_CVR_Pos) + (((uint32_t)0x1) << COMP_CFG_CVRR_Pos)  /*!< Selects the COMP CVRef up range scale 23/32. */
#endif /* MDR_LEGACY_SUPPORT 153 */
} COMP_CVRef_Scale;

#define IS_COMP_CVREF_SCALE_CONFIG(CONFIG) (((CONFIG) == COMP_CVREF_SCALE_0_div_24 ) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_1_div_24 ) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_2_div_24 ) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_3_div_24 ) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_4_div_24 ) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_5_div_24 ) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_6_div_24 ) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_7_div_24 ) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_8_div_24 ) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_9_div_24 ) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_10_div_24) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_11_div_24) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_12_div_24) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_13_div_24) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_14_div_24) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_15_div_24) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_8_div_32 ) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_9_div_32 ) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_10_div_32) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_11_div_32) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_12_div_32) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_13_div_32) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_14_div_32) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_15_div_32) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_16_div_32) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_17_div_32) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_18_div_32) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_19_div_32) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_20_div_32) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_21_div_32) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_22_div_32) || \
                                            ((CONFIG) == COMP_CVREF_SCALE_23_div_32))

/**
  * @brief COMP CFG Flags
  */
typedef enum
{
    COMP_CFG_FLAG_READY = (((uint32_t)0x1) << COMP_CFG_READY_Pos), /*!< Comparator is ready. */
    COMP_CFG_FLAG_IE    = (((uint32_t)0x1) << COMP_CFG_CMPIE_Pos)  /*!< The Comparator interrupt enabled. */
} COMP_CFG_Flags;

#define IS_COMP_CFG_FLAG(FLAG) (((FLAG) == COMP_CFG_FLAG_READY) || \
                                ((FLAG) == COMP_CFG_FLAG_IE   ))

/**
  * @brief COMP STATUS Flags
  */
typedef enum
{
    COMP_STATUS_FLAG_SY  = (((uint32_t)0x1) << COMP_RESULT_RSLT_SY_Pos), /*!< The latched Comparator output value. */
    COMP_STATUS_FLAG_AS  = (((uint32_t)0x1) << COMP_RESULT_RSLT_AS_Pos), /*!< The Comparator output value. */
    COMP_STATUS_FLAG_LCH = (((uint32_t)0x1) << COMP_RESULT_RST_LCH_Pos)  /*!< The clocked Comparator output value. */
} COMP_STATUS_Flags;

#define IS_COMP_STATUS_FLAG(FLAG) (((FLAG) == COMP_STATUS_FLAG_SY ) || \
                                   ((FLAG) == COMP_STATUS_FLAG_AS ) || \
                                   ((FLAG) == COMP_STATUS_FLAG_LCH))


/**
  * @brief COMP Init structure definition
  */
typedef struct
{
    COMP_Plus_Inp_Src  COMP_PlusInputSource;  /*!< Specifies the Comparator non-inverting input source.
                                                    This parameter can be a value of @ref COMP_Plus_Inp_Src */
    COMP_Minus_Inp_Src COMP_MinusInputSource; /*!< Specifies the Comparator inverting input source.
                                                   This parameter can be a value of @ref COMP_Minus_Inp_Src */
    COMP_Out_Inv_State COMP_OutInversion;     /*!< Enables or disables the Comparator output innversion.
                                                   This parameter can be a value of @ref COMP_Out_Inv_State */
} COMP_InitTypeDef;

/**
  * @brief COMP CVRef Init structure definition
  */
typedef struct
{
    COMP_CVRef_Src   COMP_CVRefSource; /*!< Specifies the CVREF voltage source.
                                            This parameter can be a value of @ref COMP_CVRef_Src */
#if defined (MDR_LEGACY_SUPPORT) && (MDR_LEGACY_SUPPORT) == 153
    #warning "Legacy v1.5.3: COMP_CVRefRange field of @ref COMP_CVRefInitTypeDef struct will be suppressed by @ref COMP_CVRefScale field and @ref COMP_CVRef_Scale enum. Also COMP_CVRefInit() COMP_CVRefStructInit() and COMP_CVRefScaleConfig() functionality will change according to these changes, and COMP_CVRefRangeConfig() will be removed"
    COMP_CVRef_Range COMP_CVRefRange;  /*!< Specifies the CVREF range (Up or Down).
                                            This parameter can be a value of @ref COMP_CVRef_Range */
#endif /* MDR_LEGACY_SUPPORT 153 */
    COMP_CVRef_Scale COMP_CVRefScale;  /*!< Specifies the CVREF internal voltage scale.
                                            This parameter can be a value of @ref COMP_CVRef_Scale */
} COMP_CVRefInitTypeDef;

/** @} */ /* End of group COMP_Exported_Types */


/** @defgroup COMP_Exported_Constants COMP Exported Constants
  * @{
  */

/** @defgroup COMP_Interrupt_definition COMP Interrupt definition
  * @{
  */

#define COMP_IT_LCH                         (((uint32_t)0x1) << COMP_RESULT_RST_LCH_Pos)

#define IS_COMP_CONFIG_IT(IT)               ((IT) == COMP_IT_LCH)

/** @} */ /* End of group COMP_Interrupt_definition */

/** @} */ /* End of group COMP_Exported_Constants */

/** @defgroup COMP_Exported_Functions COMP Exported Functions
  * @{
  */

void COMP_DeInit(void);

void COMP_Init(const COMP_InitTypeDef* COMP_InitStruct);
void COMP_StructInit(COMP_InitTypeDef* COMP_InitStruct);

void COMP_Cmd(FunctionalState NewState);

FlagStatus COMP_GetCfgFlagStatus(COMP_CFG_Flags Flag);

void COMP_PInpSourceConfig(COMP_Plus_Inp_Src Source);
void COMP_MInpSourceConfig(COMP_Minus_Inp_Src Source);
void COMP_OutInversionConfig(COMP_Out_Inv_State Inversion);

void COMP_CVRefInit(const COMP_CVRefInitTypeDef* COMP_CVRefInitStruct);
void COMP_CVRefStructInit(COMP_CVRefInitTypeDef* COMP_CVRefInitStruct);

void COMP_CVRefCmd(FunctionalState NewState);

void COMP_CVRefSourceConfig(COMP_CVRef_Src Source);
#if defined (MDR_LEGACY_SUPPORT) && (MDR_LEGACY_SUPPORT) == 153
    #warning "Legacy v1.5.3: COMP_CVRefRangeConfig() will be removed as suppressed by new COMP_CVRefRangeConfig() functionality (@ref COMP_CVRef_Range is suppressed by @ref COMP_CVRef_Scale)"
void COMP_CVRefRangeConfig(COMP_CVRef_Range Range);
#endif /* MDR_LEGACY_SUPPORT 153 */
void COMP_CVRefScaleConfig(COMP_CVRef_Scale Scale);

uint32_t COMP_GetResultLatch(void);
uint32_t COMP_GetStatus(void);

FlagStatus COMP_GetFlagStatus(COMP_STATUS_Flags Flag);

void COMP_ITConfig(FunctionalState NewState);

/** @} */ /* End of group COMP_Exported_Functions */

/** @} */ /* End of group COMP */

/** @} */ /* End of group __MDR1986BE4_StdPeriph_Driver */

#ifdef __cplusplus
} // extern "C" block end
#endif

#endif /* __MDR32F9QX_COMP_H */

/*********************** (C) COPYRIGHT 2021 Milandr ****************************
*
* END OF FILE MDR32F9Qx_comp.h */
