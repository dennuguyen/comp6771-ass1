///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// A property of word ladders is that word ladders are reversible when order of "from" and "to" words is
// reversed when passed into generate().
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

TEST_CASE("Word ladders when reversed should be the same") {
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");

	SECTION("war -> bro") {
		auto const ladders1 = word_ladder::generate("war", "roe", english_lexicon);

		REQUIRE(ladders1.empty() == false);

		auto ladders2 = word_ladder::generate("roe", "war", english_lexicon);
		std::reverse(ladders2.at(0).begin(), ladders2.at(0).end());

		CHECK(ladders1 == ladders2);
	}
}

TEST_CASE("Word ladders with multiple solutions when each reversed should each be the same") {
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");

	SECTION("aal -> log") {
		auto const ladders1 = word_ladder::generate("aal", "log", english_lexicon);

		REQUIRE(ladders1.empty() == false);

		auto ladders2 = word_ladder::generate("log", "aal", english_lexicon);
		for (auto& ladder : ladders2) {
			std::reverse(ladder.begin(), ladder.end());
		}
		std::sort(ladders2.begin(), ladders2.end());

		CHECK(ladders1 == ladders2);
	}

	SECTION("try -> rat") {
		auto const ladders1 = word_ladder::generate("try", "rat", english_lexicon);

		REQUIRE(ladders1.empty() == false);

		auto ladders2 = word_ladder::generate("rat", "try", english_lexicon);
		for (auto& ladder : ladders2) {
			std::reverse(ladder.begin(), ladder.end());
		}
		std::sort(ladders2.begin(), ladders2.end());

		CHECK(ladders1 == ladders2);
	}

	SECTION("menu -> trap") {
		auto const ladders1 = word_ladder::generate("menu", "trap", english_lexicon);

		REQUIRE(ladders1.empty() == false);

		auto ladders2 = word_ladder::generate("trap", "menu", english_lexicon);
		for (auto& ladder : ladders2) {
			std::reverse(ladder.begin(), ladder.end());
		}
		std::sort(ladders2.begin(), ladders2.end());

		CHECK(ladders1 == ladders2);
	}
}
