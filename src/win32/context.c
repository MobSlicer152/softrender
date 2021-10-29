// Windows utility functions
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

#include "context.h"

bool load_win32_funcs(struct context *ctx)
{
	IMAGE_EXPORT_DIRECTORY *edt;

	// Check the context pointer
	if (!ctx) {
		ctx->win32_funcs_loaded = false;
		return false;
	}

	// Load DLLs
	__LdrLoadDll(NULL, NULL,
		     &(UNICODE_STRING)RTL_CONSTANT_STRING(L"user32.dll"),
		     &user32_base);

	// Load functions pointers
	edt = __get_export_dir(user32_base);
	GetModuleHandleA_l = __load_symbol(
		user32_base, edt, "GetModuleHandleA");

	// Set the context to know it can use the functions
	ctx->win32_funcs_loaded = true;

	return true;
}

bool platform_init(struct context *ctx)
{
	
}
