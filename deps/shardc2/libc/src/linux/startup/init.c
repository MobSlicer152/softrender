// Linux-specific initialization
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

#include "internal/crt0.h"

struct __cpu_features __features;

void __libc_linux_init(int argc, char **argv)
{
	int ret;

	// Detect CPU features
	__libc_detect_features();

	// Call main
	ret = main(argc, argv);

	// Exit
	exit(ret);
}