// Wrapper around a native window
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

#include "platform.h"
#include "types.h"

// Structure to store details of a window
struct window {
	native_window_t window; // A window
	struct string *title; // Window title
	struct vec2i pos; // Window position
	struct vec2i size; // Window size
};

// Create a window
extern struct window *create_window(const int8_t *title, int x, int y,
				    int width, int height);

// Create a window
extern struct window *create_window2(const struct string *title, struct vec2i pos,
				     struct vec2i size);

// Update a window
extern void update_window(const struct window *wnd);

// Set a window's title
extern void set_window_title(const struct window *wnd, const struct string *title);

// Set a window's position and size
extern void set_window_size(const struct window *wnd, struct vec2i pos,
			struct vec2i size);

// Close a window
extern void close_window(struct window *wnd);
