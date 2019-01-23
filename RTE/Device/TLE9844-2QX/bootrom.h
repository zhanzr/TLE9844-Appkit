/**
 * @cond
 ***********************************************************************************************************************
 *
 * Copyright (c) 2017, Infineon Technologies AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the
 * following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, this list of conditions and the  following
 *   disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *   following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *   Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 *   products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 **********************************************************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/* See bootrom.c */

#ifndef _BOOTROM_H
#define _BOOTROM_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "TLE984x.h"
#include "types.h"

/******************************************************************************
**                      Global Macro Definitions                             **
*******************************************************************************/
#define FlashPageSize               (128U)
#define FlashSectorSize             (4096U)

/* Error codes */
typedef enum
{
        ERR_LOG_SUCCESS                                    = 0,
        ERR_LOG_ERROR                                      = -1,
        ERR_LOG_CODE_INVALID_BSL_PARAMETERS                = -2,
        ERR_LOG_CODE_NO_BSL_RESPONSE_TO_SEND               = -3,
        ERR_LOG_CODE_WRONG_BSL_MEDIA_TYPE                  = -4,
        ERR_LOG_CODE_MEDIA_INFO_FAIL                       = -5,
        ERR_LOG_CODE_INVALID_BSL_STRUCTURE                 = -6,
        ERR_LOG_CODE_MEM_READWRITE_PARAMS_INVALID          = -7,
        ERR_LOG_CODE_NVM_IS_READ_PROTECTED                 = -8,
        ERR_LOG_CODE_NVM_RAM_EXEC_PARAMS_INVALID           = -9,
        ERR_LOG_CODE_NVM_ERASE_PARAMS_INVALID              = -10,
        ERR_LOG_CODE_FASTLIN_BAUDRATE_SET_FAIL             = -11,
        ERR_LOG_CODE_BSL_USER_MODE_PATCH_NOT_ALLOWED       = -12,
        ERR_LOG_CODE_BSL_PATCH_ID_EXCEEDED                 = -13,
        ERR_LOG_CODE_SFR_WRITE_PARAMS_INVALID              = -14,
        ERR_LOG_CODE_BSL_NVM_UNLOCK_PASSWD_INVALID         = -15,
        ERR_LOG_CODE_MSG_VALIDITY_FAIL                     = -16,
        ERR_LOG_CODE_USER_PATCH_ECC2_FAIL_FOREVER_LOOP     = -17,
        ERR_LOG_CODE_TEST_HTOL_FBI_MATH_FAIL               = -18,
        ERR_LOG_CODE_TEST_HTOL_FBI_RAM_FAIL                = -19,
        ERR_LOG_CODE_FTEST_BOOTROM_SIGNATURE_READ          = -20,
        ERR_LOG_CODE_NVM_ADDR_RANGE_INVALID                = -21,
        ERR_LOG_CODE_ECC2READ_ERROR                        = -22,
        ERR_LOG_CODE_NVM_MISC_WRITE_ADDR_INVALID           = -23,
        ERR_LOG_CODE_NVM_SEMAPHORE_RESERVED                = -24,
        ERR_LOG_CODE_ECC1_READ_ERROR                       = -25,
        ERR_LOG_CODE_NO_ERASE_PERFORMED                    = -26,
        ERR_LOG_CODE_NVM_ERASE_ADDR_INVALID                = -27,
        ERR_LOG_CODE_NVM_SECT_ERASE_ADDR_INVALID           = -28,
        ERR_LOG_CODE_NVM_LIN_ADDR_INVALID                  = -29,
        ERR_LOG_CODE_NVM_VER_ERROR                         = -30,
        ERR_LOG_CODE_NVM_PROG_MAPRAM_INIT_FAIL             = -31,
        ERR_LOG_CODE_NVM_PROG_VERIFY_MAPRAM_INIT_FAIL      = -32,
        ERR_LOG_CODE_NVM_MAPRAM_UNKNOWN_TYPE_USAGE         = -33,
        ERR_LOG_CODE_NVM_PAGE_NOT_MAPPED                   = -34,
        ERR_LOG_CODE_NVM_INIT_MAPRAM_SECTOR                = -35,
        ERR_LOG_CODE_NVM_MAPRAM_MANUAL_SPARE_PAGE_FAILED   = -36,
        ERR_LOG_CODE_ACCESS_AB_MODE_ERROR                  = -37,
        ERR_LOG_CODE_ACCESS_AB_MODE1                       = -38,
        ERR_LOG_CODE_NVM_PROTECT_REMOVE_PASSWORD_FAILED    = -39,
        ERR_LOG_CODE_VIRGIN                                = -40,
        ERR_LOG_CODE_ADDRESS_RANGE_CROSSING_PAGE_BOUNDARY  = -41,
        ERR_LOG_CODE_ADDRESS_RANGE_INVALID                 = -42,
        ERR_LOG_CODE_100TP_READ_ADDRESS_INVALID            = -43,
        ERR_LOG_CODE_100TP_WRITE_COUNT_EXCEEDED            = -44,
        ERR_LOG_CODE_100TP_WRITE_ADDRESS_INVALID           = -45,
        ERR_LOG_CODE_CS_PAGE_CHECKSUM                      = -46,
        ERR_LOG_CODE_CS_PAGE_ECC2READ                      = -47,
        ERR_LOG_CODE_ANA_TRIM_ADDRESS                      = -48,
        ERR_LOG_CODE_ANA_TRIM_MAGIC                        = -49,
        ERR_LOG_CODE_ANA_TRIM_NOT_ALIGNED                  = -50,
        ERR_LOG_CODE_AM_TRIM_INTERNAL_1                    = -51,
        ERR_LOG_CODE_AM_TRIM_INTERNAL_2                    = -52,
        ERR_LOG_CODE_AM_TRIM_CUSTOMER                      = -53,
        ERR_LOG_CODE_AM_TRIM_DATA_NOT_VALID                = -54,
        ERR_LOG_CODE_ARM_VECT_NMI_EXCEP                    = -55,
        ERR_LOG_CODE_ARM_VECT_HARDFAULT_EXCEP              = -56,
        ERR_LOG_CODE_ARM_VECT_SVCALL_EXCEP                 = -57,
        ERR_LOG_CODE_ARM_VECT_PENDSV_EXCEP                 = -58,
        ERR_LOG_CODE_ARM_VECT_SYSTICK_EXCEP                = -59,
        ERR_LOG_CODE_NVM_APPLY_PROTECTION_FAIL             = -60,
        ERR_LOG_CODE_NVM_NOT_AVAILABLE                     = -61,
        ERR_LOG_CODE_MBIST_FAILED                          = -62,
        ERR_LOG_CODE_MBIST_TIMEOUT                         = -63,
        ERR_LOG_CODE_USERAPI_CONFIG_SECTOR_WRITE_PROTECTED = -64,
        ERR_LOG_CODE_USERAPI_CONFIG_SET_PARAMS_INVALID     = -65,
        ERR_LOG_CODE_NAD_VALUE_INVALID                     = -66,
        ERR_LOG_CODE_100TP_PARAM_INVALID                   = -67,
        ERR_LOG_CODE_NVM_CONFIG_NOT_READY                  = -68,
        ERR_LOG_CODE_PARAM_INVALID                         = -69,
        ERR_LOG_CODE_USER_CROSS_PAGE_PRG_NOT_SUPPORTED     = -70,
        ERR_LOG_CODE_USER_PROTECT_NVM_WRITE_PROTECTED      = -71,
        ERR_LOG_CODE_MBIST_RAM_RANGE_INVALID               = -72,
        ERR_LOG_CODE_PARAM_LENGTH                          = -73,
        ERR_LOG_CODE_USER_PROTECT_NO_PASSWORD_EXISTS       = -74,
        ERR_LOG_CODE_USER_PROTECT_NVM_AND_PWD_ERASED       = -75,
        ERR_LOG_CODE_USER_PROTECT_NO_CBSL_PWD_CLEAR        = -76,
        ERR_LOG_CODE_USER_PROTECT_PWD_INVALID              = -77,
        ERR_LOG_CODE_USER_PROTECT_PWD_EXISTS               = -78,
        ERR_LOG_CODE_USER_NVM_PROTECT_SEGMENT_INVALID      = -79,
        ERR_LOG_CODE_SINGLE_ECC_EVENT_OCCURRED             = -80,
        ERR_LOG_CODE_DOUBLE_ECC_EVENT_OCCURRED             = -81,
        ERR_LOG_CODE_SINGLE_AND_DOUBLE_ECC_EVENT_OCCURRED  = -82,
        ERR_LOG_CODE_USERAPI_POINTER_RAM_RANGE_INVALID     = -83,
        ERR_LOG_CODE_USER_API_BRANCH_ADDRESS_INVALID       = -84
} BOOTROM_RETURN_CODE_t;

typedef enum
{
  BSL_IF_LIN = 0,
  BSL_IF_FAST_LIN = 1,
} BSL_INTERFACE_SELECT_t;

typedef enum
{
  NVM_PASSWORD_SEGMENT_BOOT = 0,
  NVM_PASSWORD_SEGMENT_CODE = 1,
  NVM_PASSWORD_SEGMENT_DATA = 2,
} NVM_PASSWORD_SEGMENT_t;

typedef void(* user_callback_t) (void);

typedef enum
{
  VBG_TEMP_HOT = 0,
  VBG_TEMP_COLD = 1,
} VBG_TEMP_SELECT_t;


/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
extern BSL_INTERFACE_SELECT_t (*const user_bsl_config_get)(void);
extern int32_t  (*const user_bsl_config_set)(BSL_INTERFACE_SELECT_t ser_if);
extern int32_t  (*const user_nvm_protect_clear)(uint32_t password, NVM_PASSWORD_SEGMENT_t segment);
extern int32_t  (*const user_nvm_protect_set)(uint32_t password, NVM_PASSWORD_SEGMENT_t segment);
extern uint32_t (*const user_nvm_protect_get)(NVM_PASSWORD_SEGMENT_t segment);
extern int32_t  (*const user_ecc_events_get)(uint32_t *pNVM_Addr);
extern int32_t  (*const user_ecc_check)(void);
extern int32_t  (*const user_mbist_set)(bool bEnable);
extern uint8_t  (*const user_nac_get)(void);
extern int32_t  (*const user_nac_set)(uint8_t nac);
extern uint8_t  (*const user_nad_get)(void);
extern int32_t  (*const user_nad_set)(uint8_t nad);
extern int32_t  (*const user_nvm_100tp_read)(uint32_t page_addr, uint32_t offset, void *data, uint32_t count);
extern int32_t  (*const user_nvm_100tp_write)(uint32_t page_addr, uint32_t offset, const void *data, uint32_t count);
extern int32_t  (*const user_nvm_config_get)(uint8_t * cbsl_nvm_size, uint8_t *code_nvm_size, uint8_t *data_nvm_size);
extern int32_t  (*const user_nvm_page_erase)(uint32_t address);
extern int32_t  (*const user_nvm_page_erase_branch)(uint32_t address, user_callback_t branch_address);
extern bool     (*const user_nvm_ready_poll)(void);
extern int32_t  (*const user_nvm_sector_erase)(uint32_t address);
extern int32_t  (*const user_nvm_write)(uint32_t address, const void *data, uint8_t count, uint8_t options);
extern int32_t  (*const user_nvm_write_branch)(uint32_t address, const void *data, uint8_t count, uint8_t options, user_callback_t branch_address);
extern int32_t  (*const user_ram_mbist)(uint32_t start_address, uint32_t end_address);
extern int32_t  (*const user_nvm_mapram_init)(void);
extern void     (*const user_nvm_clk_factor_set)(uint8_t clk_factor);
extern int32_t  (*const user_nvm_password_set)(uint32_t password, NVM_PASSWORD_SEGMENT_t segment);
extern int32_t  (*const user_nvm_password_clear)(uint32_t password, NVM_PASSWORD_SEGMENT_t segment);
extern uint32_t (*const user_vbg_temperature_get)(VBG_TEMP_SELECT_t temperature);
#endif
