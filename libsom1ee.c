/*
 * Copyright (C) 2019 Microchip Technology Inc.  All rights reserved.
 *   Matt Wood <matt.wood@microchip.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
#include <assert.h>
#include <errno.h>
#include "libsom1ee.h"

unsigned char buf[32];

unsigned char* getBrdInfo(void)
{
	char *eeprom = "/sys/bus/i2c/devices/0-0050/eeprom";
	FILE *fp;
	int ret;
	unsigned char *bufPtr = buf;

	fp = fopen(eeprom, "r");

	if (fp != NULL) {
		ret = fseek(fp, EE_DATA_OFFSET+1, SEEK_SET);
		if (ret) {
		printf("Cannot set offset of EEPROM\r\n");
		return NULL;
	}

		ret = fread(bufPtr, 1, 32, fp);

		fclose(fp);

		return (unsigned char *)&buf;
	}

	return NULL;
}
