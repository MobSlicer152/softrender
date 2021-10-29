// Implementations of functions from types.h
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

#include "types.h"

struct string *make_string(const int8_t *src, size_t max_opt)
{
	struct string *str;

	str = calloc(1, sizeof(struct string));
	str->len = strlen(src);
	str->max_len = max_opt ? max_opt : str->len;
	str->buf = calloc(str->max_len, sizeof(int8_t));

	return str;
}

struct wstring *make_wstring(const wchar_t *src, size_t max_opt)
{
	struct wstring *str;

	str = calloc(1, sizeof(struct wstring));
	str->len = wcslen(src);
	str->max_len = max_opt ? max_opt : str->len;
	str->buf = calloc(str->max_len, sizeof(wchar_t));

	return str;
}

void free_string(void *str)
{
	struct string *real = str; // string or wstring doesn't matter, it's always a pointer

	free(real->buf);
	free(real);
}
