/*
 * som1ee - Simple example to read EEPROM on SOM1-EK using shared object.  
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
#include "libsom1ee.h"

int main(int argc, char **argv)
{
    unsigned char *brdInfo;

    brdInfo = getBrdInfo();

	printf("Board info: %s\r\n", brdInfo);

	return 0;
}

