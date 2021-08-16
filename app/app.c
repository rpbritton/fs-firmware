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

#include "app.h"

#include "core/router.h"
#include "core/layout.h"

#include "inputs/scanner.h"

#include "outputs/blinky.h"
#include "outputs/printer.h"

void app_init()
{
	router_init();
#ifdef FS_USE_SCANNER
	scanner_init();
#endif
#ifdef FS_USE_BLINKY
	blinky_init();
#endif
#ifdef FS_USE_PRINTER
	printer_init();
#endif
}

void app_run()
{
	router_run();
#ifdef FS_USE_SCANNER
	scanner_run();
#endif
#ifdef FS_USE_BLINKY
	blinky_run();
#endif
#ifdef FS_USE_PRINTER
	printer_run();
#endif
}

void app_stop()
{

}
