// Definitions for contexts
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
#include "window.h"

// Structure containing information about a context
struct context {
	struct window *wnd; // Main window
	
#ifdef _WIN32
	// Whether the Win32 functions are safe to use yet
	bool win32_funcs_loaded;
#endif
};

// Initialize a context
extern bool context_init(struct context *ctx);

// Platform-specific initialization
extern bool context_platform_init(struct context *ctx);

#ifdef _WIN32
// Load Win32 functions
extern bool load_win32_funcs(struct context *ctx);
#endif // _WIN32
