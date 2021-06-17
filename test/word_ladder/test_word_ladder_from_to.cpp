///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// A property of word ladders is that the "from" and "to" words given to generate() will always appear at the start and end of a word ladder respectively.
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

TEST_CASE("A word ladder should contain 'from' and 'to' at start and end") {
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");

	SECTION("feat -> wool") {
		auto const ladders = word_ladder::generate("feat", "wool", english_lexicon);

		REQUIRE(ladders.size() == 1);
		
		CHECK(ladder.front() == "feat");
		CHECK(ladder.back() == "wool");
	}
}

TEST_CASE("All returned word ladders should contain 'from' and 'to' at start and end") {
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");

	SECTION("war -> pin") {
		auto ladders = word_ladder::generate("war", "pin", english_lexicon);

		REQUIRE(ladders.empty() == false);

		for (auto const& ladder : ladders) {
			CHECK(ladder.front() == "war");
			CHECK(ladder.back() == "pin");
		}
	}

	SECTION("tree -> roof") {
		auto ladders = word_ladder::generate("tree", "roof", english_lexicon);

		REQUIRE(ladders.empty() == false);

		for (auto const& ladder : ladders) {
			CHECK(ladder.front() == "tree");
			CHECK(ladder.back() == "roof");
		}
	}

	SECTION("want -> pail") {
		auto ladders = word_ladder::generate("want", "pail", english_lexicon);

		REQUIRE(ladders.empty() == false);

		for (auto const& ladder : ladders) {
			CHECK(ladder.front() == "want");
			CHECK(ladder.back() == "pail");
		}
	}
}
