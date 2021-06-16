///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// A word ladder should not contain any duplicates i.e. duplicate words within a word ladder or
// duplicate word ladders.
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

TEST_CASE("Word ladders should not contain duplicate words") {
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");

	SECTION("tree -> roof") {
		auto ladders = word_ladder::generate("tree", "roof", english_lexicon);

		REQUIRE(ladders.empty() == false);
		std::sort(ladders.begin(), ladders.end()); // sort() before adjacent_find()

		for (auto const& ladder : ladders) {
			CHECK(std::adjacent_find(ladder.begin(), ladder.end()) == ladder.end());
		}
	}

	SECTION("weak -> veal") {
		auto ladders = word_ladder::generate("weak", "veal", english_lexicon);

		REQUIRE(ladders.empty() == false);
		std::sort(ladders.begin(), ladders.end()); // sort() before adjacent_find()

		for (auto const& ladder : ladders) {
			CHECK(std::adjacent_find(ladder.begin(), ladder.end()) == ladder.end());
		}
	}
}

TEST_CASE("Word ladders should not contain duplicate word ladders") {
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");

	SECTION("trout -> mound") {
		auto const ladders = word_ladder::generate("too", "two", english_lexicon);

		REQUIRE(ladders.empty() == false);
		REQUIRE(std::is_sorted(ladders.begin(), ladders.end()));
		CHECK(std::adjacent_find(ladders.begin(), ladders.end()) == ladders.end());
	}

	SECTION("when -> what") {
		auto const ladders = word_ladder::generate("when", "what", english_lexicon);

		REQUIRE(ladders.empty() == false);
		REQUIRE(std::is_sorted(ladders.begin(), ladders.end()));
		CHECK(std::adjacent_find(ladders.begin(), ladders.end()) == ladders.end());
	}
}