# Copyright 2024 Tadashi G. Takaoka
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

CXX = g++
CXX_FLAGS = -std=gnu++17
LD_FLAGS = -lm -lquadmath

TEST = float float32 float64 float80 float128

all: $(TEST)

%.o: %.cpp
	$(CXX) $(CXX_FLAGS) -c $^

float: float.o
	$(CXX) $(CXX_FLAGS) $^ $(LD_FLAGS) -o $@
float32: float32.o
	$(CXX) $(CXX_FLAGS) $^ $(LD_FLAGS) -o $@
float64: float64.o
	$(CXX) $(CXX_FLAGS) $^ $(LD_FLAGS) -o $@
float80: float80.o
	$(CXX) $(CXX_FLAGS) $^ $(LD_FLAGS) -o $@
float128: float128.o
	$(CXX) $(CXX_FLAGS) $^ $(LD_FLAGS) -o $@

clean:
	rm -f $(TEST:%=%.o) $(TEST)

# Local Variables:
# mode: makefile-gmake
# End:
# vim: set ft=make:
