/*####COPYRIGHTBEGIN####
 -------------------------------------------
 Copyright (C) 2004 Steve Karg

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to:
 The Free Software Foundation, Inc.
 59 Temple Place - Suite 330
 Boston, MA  02111-1307, USA.

 As a special exception, if other files instantiate templates or
 use macros or inline functions from this file, or you compile
 this file and link it with other works to produce a work based
 on this file, this file does not by itself cause the resulting
 work to be covered by the GNU General Public License. However
 the source code for this file must still be made available in
 accordance with section (3) of the GNU General Public License.

 This exception does not invalidate any other reasons why a work
 based on this file might be covered by the GNU General Public
 License.
 -------------------------------------------
####COPYRIGHTEND####*/

#include <stdbool.h>
#include <stdint.h>
#include <string.h>             /* for strlen */
#include "bacstr.h"
#include "bits.h"

#include <assert.h>
#include <string.h>
#include "ctest.h"

void testBitString(Test * pTest)
{
    uint8_t bit = 0;
    BACNET_BIT_STRING bit_string;

    bitstring_init(&bit_string);
    /* verify initialization */
    ct_test(pTest, bitstring_bits_used(&bit_string) == 0);
    for (bit = 0; bit < (MAX_BITSTRING_BYTES * 8); bit++) {
        ct_test(pTest, bitstring_bit(&bit_string, bit) == false);
    }

    /* test for true */
    for (bit = 0; bit < (MAX_BITSTRING_BYTES * 8); bit++) {
        bitstring_set_bit(&bit_string, bit, true);
        ct_test(pTest, bitstring_bits_used(&bit_string) == (bit + 1));
        ct_test(pTest, bitstring_bit(&bit_string, bit) == true);
    }
    /* test for false */
    bitstring_init(&bit_string);
    for (bit = 0; bit < (MAX_BITSTRING_BYTES * 8); bit++) {
        bitstring_set_bit(&bit_string, bit, false);
        ct_test(pTest, bitstring_bits_used(&bit_string) == (bit + 1));
        ct_test(pTest, bitstring_bit(&bit_string, bit) == false);
    }
}