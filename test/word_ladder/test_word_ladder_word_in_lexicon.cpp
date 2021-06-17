///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// A property of word ladders is that all the words within a word ladder come from the provided
// lexicon.
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

TEST_CASE("All words in a word ladder should be in the english lexicon") {
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");

	SECTION("feat -> wool") {
		auto const ladders = word_ladder::generate("feat", "wool", english_lexicon);

		REQUIRE(ladders.size() == 1);
		auto const& ladder = ladders.front();

		CHECK(std::all_of(ladder.begin(), ladder.end(), [english_lexicon](auto const& word) {
			return english_lexicon.contains(word) == true;
		}));
	}

	SECTION("rack -> pool") {
		auto const ladders = word_ladder::generate("rack", "pool", english_lexicon);

		REQUIRE(ladders.size() > 1);
		for (auto const& ladder : ladders) {
			CHECK(std::all_of(ladder.begin(), ladder.end(), [english_lexicon](auto const& word) {
				return english_lexicon.contains(word) == true;
			}));
		}
	}

	SECTION("wine -> trip") {
		auto const ladders = word_ladder::generate("wine", "trip", english_lexicon);

		REQUIRE(ladders.size() > 1);
		for (auto const& ladder : ladders) {
			CHECK(std::all_of(ladder.begin(), ladder.end(), [english_lexicon](auto const& word) {
				return english_lexicon.contains(word) == true;
			}));
		}
	}
}
