/*
 * Synaptics TCM touchscreen driver
 *
 * Copyright (C) 2017-2018 Synaptics Incorporated. All rights reserved.
 *
 * Copyright (C) 2017-2018 Scott Lin <scott.lin@tw.synaptics.com>
 * Copyright (C) 2018-2019 Ian Su <ian.su@tw.synaptics.com>
 * Copyright (C) 2018-2019 Joey Zhou <joey.zhou@synaptics.com>
 * Copyright (C) 2018-2019 Yuehao Qiu <yuehao.qiu@synaptics.com>
 * Copyright (C) 2018-2019 Aaron Chen <aaron.chen@tw.synaptics.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * INFORMATION CONTAINED IN THIS DOCUMENT IS PROVIDED "AS-IS, " AND SYNAPTICS
 * EXPRESSLY DISCLAIMS ALL EXPRESS AND IMPLIED WARRANTIES, INCLUDING ANY
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE,
 * AND ANY WARRANTIES OF NON-INFRINGEMENT OF ANY INTELLECTUAL PROPERTY RIGHTS.
 * IN NO EVENT SHALL SYNAPTICS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, PUNITIVE, OR CONSEQUENTIAL DAMAGES ARISING OUT OF OR IN CONNECTION
 * WITH THE USE OF THE INFORMATION CONTAINED IN THIS DOCUMENT, HOWEVER CAUSED
 * AND BASED ON ANY THEORY OF LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * NEGLIGENCE OR OTHER TORTIOUS ACTION, AND EVEN IF SYNAPTICS WAS ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE. IF A TRIBUNAL OF COMPETENT JURISDICTION DOES
 * NOT PERMIT THE DISCLAIMER OF DIRECT DAMAGES OR ANY OTHER DAMAGES, SYNAPTICS'
 * TOTAL CUMULATIVE LIABILITY TO ANY PARTY SHALL NOT EXCEED ONE HUNDRED U.S.
 * DOLLARS.
 */

#ifndef _SYNAPTICS_TCM_TESTING_H_
#define _SYNAPTICS_TCM_TESTING_H_

#define ABS(x) (((x) < 0) ? (-(x)) : (x))
#define DATA_SIZE_MAX (30)
#define SAVE_BUF_SIZE (4096 * 3)
#define RESULT_INFO_LEN (200)

#define PT1_PT3_LIMITS_BYTES_SIZE (8)
#define PT10_LIMITS_BYTES_SIZE (1)

#define SYNA_TCM_TESTING_LIMITS_FILE_NAME "CSOT_M9_test_limits_S3907.csv"
#define SYNA_TCM_SECOND_TESTING_LIMITS_FILE_NAME                               \
	"CSOT_M9_second_test_limits_S3907.csv"
#define M9_TOUCH_PANEL_MAKER 0x53
#define M9_SECOND_TOUCH_PANEL_MAKER 0x46

#define CSV_PT1_TESTING_LIMITS "PT1_TRx_TRx_short_test"
#define CSV_PT3_TESTING_LIMITS "PT3_TRX_GND_short_test"
#define CSV_PT5_TESTING_LIMITS_MIN "PT5_Full_raw_cap_test_min"
#define CSV_PT5_TESTING_LIMITS_MAX "PT5_Full_raw_cap_test_max"
#define CSV_PT10_TESTING_LIMITS "PT10_(Mutal)_noise_test"
#define CSV_PT18_TESTING_LIMITS_MIN "PT18_Abs_raw_cap_test_min"
#define CSV_PT18_TESTING_LIMITS_MAX "PT18_Abs_raw_cap_test_max"
#define CSV_PT22_TESTING_LIMITS_MIN "PT22_Trans_raw_cap_test_min"
#define CSV_PT22_TESTING_LIMITS_MAX "PT22_Trans_raw_cap_test_max"
#define CSV_GAP_DIFF_TESTING_LIMITS_MAX "Gap_Diff_test_max"

#define TESTING_RESULT_IN_CSV (1)

static inline void uint_to_le1(unsigned char *dest, unsigned int val)
{
	dest[0] = val % 0x100;
}

static inline void uint_to_le2(unsigned char *dest, unsigned int val)
{
	dest[0] = val % 0x100;
	dest[1] = val / 0x100;
}

static inline void uint_to_le4(unsigned char *dest, unsigned int val)
{
	unsigned int vl, vh;
	vl = val % 0x10000;
	vh = val / 0x10000;
	uint_to_le2(dest, vl);
	uint_to_le2(dest + 2, vh);
}

/* test limit for the device id checking */
static const char *device_id_limit = "S3907 A1A0-15.10";

/* test limit for the config id checking */
static const char config_id_limit[16] = { 0x30, 0x31, 0x32, 0x33, 0x34, 0x35,
					  0x36, 0x37, 0x38, 0x39, 0x41, 0x42,
					  0x43, 0x44, 0x45, 0x47 };

/* test limit for the pt7 testing */
/*   including upper and lower bounds */
static const unsigned short pt7_hi_limits[40][40] = {
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
	{ 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700,
	  1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700, 1700 },
};

static const unsigned short pt7_lo_limits[40][40] = {
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 },
	{ 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300,
	  300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300 }
};

/* test limit for the pt11 testing */
/*   including upper and lower bounds */
static const short pt11_hi_limits[40][40] = {
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	  8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 },
};

static const short pt11_lo_limits[40][40] = {
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
	{ -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
	  -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8 },
};

/* test limit for the hw reset pin testing */
static const unsigned char reset_open_limit = 0x13;

/*selftest for cit or factory*/
static bool iscit = false;

#endif /* end of _SYNAPTICS_TCM_TESTING_H_ */
