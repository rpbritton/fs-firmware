/**
 * Copyright 2021 Ryan Britton
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

#ifndef APP_OUTPUTS_USB_HID_SENDER_H_
#define APP_OUTPUTS_USB_HID_SENDER_H_

#if FS_USE_USB

#include "osal.h"
#include "USB.h"
#include "USB_HID.h"

void usb_hid_sender_run(USB_HID_HANDLE usb_hid_handle);
void usb_hid_sender_stop();
unsigned usb_hid_sender_endpoint();
void usb_hid_sender_send(uint8_t *report);

#endif /* FS_USE_USB */

#endif /* APP_OUTPUTS_USB_HID_SENDER_H_ */
