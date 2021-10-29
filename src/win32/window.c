// Windows functions to create and change windows
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

#include "platform.h"
#include "types.h"
#include "window.h"

// Window procedure
intptr_t __stdcall wndproc(HWND wnd, uint32_t msg, uintptr_t wparam,
			   intptr_t lparam);

struct window *create_window(const int8_t *title, int x, int y, int width,
			     int height)
{
	return create_window2(make_string(title, 0), (struct vec2i){ x, y },
			      (struct vec2i){ width, height });
}

struct window *create_window2(const struct string *title, struct vec2i pos,
			      struct vec2i size)
{
	struct window *ret;
	WNDCLASS wc = { 0 };

	wc.lpfnWndProc = wndproc;
	wc.hInstance = instance_handle;
}

void close_window(struct window *wnd)
{
}

intptr_t __stdcall wndproc(HWND wnd, uint32_t msg, uintptr_t wparam,
			   intptr_t lparam)
{
}
