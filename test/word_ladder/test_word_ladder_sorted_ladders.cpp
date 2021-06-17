///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// A property of word ladders is that when multiple word ladders are returned, they are sorted
// lexicographically.
//
// Please refer to test_word_ladder_simple.cpp for the test design rationale.
//
///////////////////////////////////////////////////////////////////////////////////////////////////
//
// Copyright UNSW Sydney School of Computer Science and Engineering
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#include "comp6771/word_ladder.hpp"

#include <algorithm>
#include <string>
#include <vector>

#include "catch2/catch.hpp"

TEST_CASE("Words with multiple word ladder solutions should be sorted lexicographically") {
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");

	SECTION("wry -> lip") {
		auto const ladders = word_ladder::generate("wry", "lip", english_lexicon);

		REQUIRE(ladders.size() > 1);
		CHECK(std::is_sorted(ladders.begin(), ladders.end()));
	}

	SECTION("read -> loop") {
		auto ladders = word_ladder::generate("read", "loop", english_lexicon);

		REQUIRE(ladders.size() > 1);
		CHECK(std::is_sorted(ladders.begin(), ladders.end()));
	}
}
