///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// Only have words of the same length as "from" and "to" are valid in a word ladder.
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

TEST_CASE("Word ladders should have same-length words") {
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");

	SECTION("four -> tool") {
		auto const ladders = word_ladder::generate("four", "tool", english_lexicon);

		REQUIRE(ladders.empty() == false);
		for (auto const& ladder : ladders) {
			CHECK(std::all_of(ladder.begin(), ladder.end(), [](auto const& word) {
				return word.size() == 4;
			}));
		}
	}

	SECTION("crack -> trick") {
		auto const ladders = word_ladder::generate("crack", "trick", english_lexicon);

		REQUIRE(ladders.empty() == false);
		for (auto const& ladder : ladders) {
			CHECK(std::all_of(ladder.begin(), ladder.end(), [](auto const& word) {
				return word.size() == 5;
			}));
		}
	}

	SECTION("beetles -> trample") {
		auto const ladders = word_ladder::generate("beetles", "trample", english_lexicon);

		REQUIRE(ladders.empty() == false);
		for (auto const& ladder : ladders) {
			CHECK(std::all_of(ladder.begin(), ladder.end(), [](auto const& word) {
				return word.size() == 7;
			}));
		}
	}
}
