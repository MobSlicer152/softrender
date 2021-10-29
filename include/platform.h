// Definitions for different functions
//
// Copyright 2021 MobSlicer152
// This file is part of Shard C Library 2
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "types.h"

#ifdef _WIN32
#define PHNT_VERSION PHNT_WIN7
#include <phnt_windows.h>
#include <phnt.h>

#include "internal/win32/ldr.h"

// Native window type
typedef void *native_window_t;

// Instance handle, Win32 functions need this
HINSTANCE instance_handle;

// Loaded DLLs
extern void *user32_base;

// Win32 function pointers
extern void *(*GetModuleHandleA_l)(const int8_t *module_name);
#endif // _WIN32
