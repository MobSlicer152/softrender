// Types
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

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <limits.h>
#include <wchar.h>

// Strings
struct string {
	const int8_t *buf; // Buffer
	size_t len; // Current string length (characters)
	size_t max_len; // Maximum string length (characters)
};

struct wstring {
	const wchar_t *buf; // Buffer
	size_t len; // Current string length (characters)
	size_t max_len; // Maximum string length (characters)
};

// Make a string
extern struct string *make_string(const int8_t *src, size_t max_opt);

// Make a wide string
extern struct wstring *make_wstring(const wchar_t *src, size_t max_opt);

// Vectors
struct vec2i {
	uint32_t x;
	uint32_t y;
};

struct vec3i {
	uint32_t x;
	uint32_t y;
	uint32_t z;
};

struct vec4i {
	uint32_t x;
	uint32_t y;
	uint32_t z;
	uint32_t w;
};

struct vec2f {
	float x;
	float y;
};

struct vec3f {
	float x;
	float y;
	float z;
};

struct vec4f {
	float x;
	float y;
	float z;
	float w;
};

struct vec2d {
	double x;
	double y;
};

struct vec3d {
	double x;
	double y;
	double z;
};

struct vec4d {
	double x;
	double y;
	double z;
	double w;
};
