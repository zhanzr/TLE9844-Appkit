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
/* 
 * V1.5: 2017-01-24:  BootROM error codes added, flash page size,
 *                    flash sector size added
 * V1.4: 2016-01-21:  update reflecting AD and AE step silicon
 *                    removed user_ram_init (patch)
 * V1.3: 2015-09-22:  added typedef VBG_TEMP_SELECT_t
 * V1.2: 2015-08-14:  update reflecting AC step silicon
 *                    added user_nvm_mapram_init
 *                    added user_vbg_temperature_get
 *                    added user_ram_init
 *                    changed return type of user_nvm_clk_factor_set
 * V1.1: 2015-08-14:  update reflecting AB step silicon
 *                    removed user_nvm_page_invalid
 * V1.0: 2015-01-28:  Initial version
 *                    matching to Preliminary Firmware User Manual
 *                    Rev0.1 from 2014-11-14
 *                     
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "bootrom.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/*******************************************************************************
** Entry points into the BootROM                                              **
*******************************************************************************/
#define addr_of_user_bsl_config_get             (0x00000101)
#define addr_of_user_bsl_config_set             (0x00000103)
#define addr_of_user_nvm_protect_clear          (0x00000105)
#define addr_of_user_nvm_protect_set            (0x00000107)
#define addr_of_user_nvm_protect_get            (0x00000109)
#define addr_of_user_ecc_events_get             (0x0000010d)
#define addr_of_user_ecc_check                  (0x0000010f)
#define addr_of_user_mbist_set                  (0x00000111)
#define addr_of_user_nac_get                    (0x00000113)
#define addr_of_user_nac_set                    (0x00000115)
#define addr_of_user_nad_get                    (0x00000117)
#define addr_of_user_nad_set                    (0x00000119)
#define addr_of_user_nvm_100tp_read             (0x0000011b)
#define addr_of_user_nvm_100tp_write            (0x0000011d)
#define addr_of_user_nvm_config_get             (0x0000011f)
#define addr_of_user_nvm_page_erase             (0x00000121)
#define addr_of_user_nvm_page_erase_branch      (0x00000123)
#define addr_of_user_nvm_ready_poll             (0x00000125)
#define addr_of_user_nvm_sector_erase           (0x00000127)
#define addr_of_user_nvm_write                  (0x00000129)
#define addr_of_user_nvm_write_branch           (0x0000012b)
#define addr_of_user_ram_mbist                  (0x0000012d)
#define addr_of_user_nvm_mapram_init            (0x00000131)
#define addr_of_user_nvm_clk_factor_set         (0x00000133)
#define addr_of_user_nvm_password_set           (0x00000135)
#define addr_of_user_nvm_password_clear         (0x00000137)
#define addr_of_user_vbg_temperature_get        (0x00000139)
 
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*******************************************************************************
** BootROM User Function declaration                                          **
*******************************************************************************/

/*lint -e19 Supressing MISRA 2012 Error 19: Useless Declaration */
/*lint -e970 Supressing MISRA 2012 MISRA 2012 Directive 4.6 */
BSL_INTERFACE_SELECT_t (*const user_bsl_config_get)(void) = (BSL_INTERFACE_SELECT_t (*)(void)) addr_of_user_bsl_config_get;
int32_t  (*const user_bsl_config_set)(BSL_INTERFACE_SELECT_t ser_if) = (int32_t (*)(BSL_INTERFACE_SELECT_t ser_if)) addr_of_user_bsl_config_set;
int32_t  (*const user_nvm_protect_clear)(uint32_t password, NVM_PASSWORD_SEGMENT_t segment) = (int32_t (*)(uint32_t password, NVM_PASSWORD_SEGMENT_t segment)) addr_of_user_nvm_protect_clear;
int32_t  (*const user_nvm_protect_set)(uint32_t password, NVM_PASSWORD_SEGMENT_t segment) = (int32_t (*)(uint32_t password, NVM_PASSWORD_SEGMENT_t segment)) addr_of_user_nvm_protect_set;
uint32_t (*const user_nvm_protect_get)(NVM_PASSWORD_SEGMENT_t segment) = (uint32_t (*)(NVM_PASSWORD_SEGMENT_t segment)) addr_of_user_nvm_protect_get;
int32_t  (*const user_ecc_events_get)(uint32_t *pNVM_Addr) = (int32_t (*)(uint32_t *pNVM_Addr)) addr_of_user_ecc_events_get;
int32_t  (*const user_ecc_check)(void) = (int32_t (*)(void)) addr_of_user_ecc_check;
int32_t  (*const user_mbist_set)(bool bEnable) = (int32_t (*)(bool bEnable)) addr_of_user_mbist_set;
uint8_t  (*const user_nac_get)(void) = (uint8_t (*)(void)) addr_of_user_nac_get;
int32_t  (*const user_nac_set)(uint8_t nac) = (int32_t (*)(uint8_t nac)) addr_of_user_nac_set;
uint8_t  (*const user_nad_get)(void) = (uint8_t (*)(void)) addr_of_user_nad_get;
int32_t  (*const user_nad_set)(uint8_t nad) = (int32_t (*)(uint8_t nad)) addr_of_user_nad_set;
int32_t  (*const user_nvm_100tp_read)(uint32_t page_addr, uint32_t offset, void *data, uint32_t count) = (int32_t (*)(uint32_t page_addr, uint32_t offset, void *data, uint32_t count)) addr_of_user_nvm_100tp_read;
int32_t  (*const user_nvm_100tp_write)(uint32_t page_addr, uint32_t offset, const void *data, uint32_t count) = (int32_t (*)(uint32_t page_addr, uint32_t offset, const void *data, uint32_t count)) addr_of_user_nvm_100tp_write;
int32_t  (*const user_nvm_config_get)(uint8_t * cbsl_nvm_size, uint8_t *code_nvm_size, uint8_t *data_nvm_size) = (int32_t (*)(uint8_t * cbsl_nvm_size, uint8_t *code_nvm_size, uint8_t *data_nvm_size)) addr_of_user_nvm_config_get;
int32_t  (*const user_nvm_page_erase)(uint32_t address) = (int32_t (*)(uint32_t address)) addr_of_user_nvm_page_erase;
int32_t  (*const user_nvm_page_erase_branch)(uint32_t address, user_callback_t branch_address) = (int32_t (*)(uint32_t address, user_callback_t branch_address)) addr_of_user_nvm_page_erase_branch;
bool     (*const user_nvm_ready_poll)(void) = (bool (*)(void)) addr_of_user_nvm_ready_poll;
int32_t  (*const user_nvm_sector_erase)(uint32_t address) = (int32_t (*)(uint32_t address)) addr_of_user_nvm_sector_erase;
int32_t  (*const user_nvm_write)(uint32_t address, const void *data, uint8_t count, uint8_t options) = (int32_t (*)(uint32_t address, const void *data, uint8_t count, uint8_t options)) addr_of_user_nvm_write;
int32_t  (*const user_nvm_write_branch)(uint32_t address, const void *data, uint8_t count, uint8_t options, user_callback_t branch_address) = (int32_t (*)(uint32_t address, const void *data, uint8_t count, uint8_t options, user_callback_t branch_address)) addr_of_user_nvm_write_branch;
int32_t  (*const user_ram_mbist)(uint32_t start_address, uint32_t end_address) = (int32_t (*)(uint32_t start_address, uint32_t end_address)) addr_of_user_ram_mbist;
int32_t  (*const user_nvm_mapram_init)(void) = (int32_t (*)(void)) addr_of_user_nvm_mapram_init;
void     (*const user_nvm_clk_factor_set)(uint8_t clk_factor) = (void (*)(uint8_t clk_factor)) addr_of_user_nvm_clk_factor_set;
int32_t  (*const user_nvm_password_set)(uint32_t password, NVM_PASSWORD_SEGMENT_t segment) = (int32_t (*)(uint32_t password, NVM_PASSWORD_SEGMENT_t segment)) addr_of_user_nvm_password_set;
int32_t  (*const user_nvm_password_clear)(uint32_t password, NVM_PASSWORD_SEGMENT_t segment) = (int32_t (*)(uint32_t password, NVM_PASSWORD_SEGMENT_t segment)) addr_of_user_nvm_password_clear;
uint32_t (*const user_vbg_temperature_get)(VBG_TEMP_SELECT_t temperature) = (uint32_t (*)(VBG_TEMP_SELECT_t temperature)) addr_of_user_vbg_temperature_get;
/*lin +e19 */
/*lin +e970 */

