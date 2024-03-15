/**
* @file
* @author Steve Karg
* @date October 2019
* @brief Header file for a basic UnconfirmedCOV notification handler
*
* @section LICENSE
*
* Permission is hereby granted, free of charge, to any person obtaining
* a copy of this software and associated documentation files (the
* "Software"), to deal in the Software without restriction, including
* without limitation the rights to use, copy, modify, merge, publish,
* distribute, sublicense, and/or sell copies of the Software, and to
* permit persons to whom the Software is furnished to do so, subject to
* the following conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#ifndef HANDLER_UCOV_NOTIFICATION_H
#define HANDLER_UCOV_NOTIFICATION_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdint.h>
/* BACnet Stack defines - first */
#include "bacnet/bacdef.h"
/* BACnet Stack API */
#include "bacnet/apdu.h"
#include "bacnet/cov.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
    BACNET_STACK_EXPORT
    void handler_ucov_notification_add(
        BACNET_COV_NOTIFICATION *callback);

    BACNET_STACK_EXPORT
    void handler_ucov_notification(
        uint8_t * service_request,
        uint16_t service_len,
        BACNET_ADDRESS * src);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif
