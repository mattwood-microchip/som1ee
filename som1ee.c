/*
 * som1ee - Simple example to read EEPROM on SOM1-EK.  
 * 
 * Copyright 2019 Microchip
 * 		  Matt Wood <matt.wood@microchip.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
#include <assert.h>
#include <errno.h>

#define EE_DATA_OFFSET	0x60

int main(int argc, char **argv)
{
	char *eeprom = "/sys/bus/i2c/devices/3-0050/eeprom";
	unsigned char buf[32];
	FILE *fp;
	int ret;

	fp = fopen(eeprom, "r");
		if (fp != NULL) {
			ret = fseek(fp, EE_DATA_OFFSET, SEEK_SET);
			if (ret) {
				printf("Cannot set offset of EEPROM\r\n");
				return -EIO;
			}

			ret = fread(buf, 1, 32, fp);

			printf("Board info: %s\r\n", buf);
		}

	return 0;
}

