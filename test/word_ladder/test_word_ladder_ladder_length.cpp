///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// A property of word ladders is that multiple-returned word ladders will have the same length as
// they are all valid shortest-distance word ladders.
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

TEST_CASE("Multiple word ladder solutions should have the same length") {
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");

	SECTION("bee -> man") {
		auto const ladders = word_ladder::generate("bee", "man", english_lexicon);

		REQUIRE(ladders.size() > 1);
		auto const& size = ladders.at(0).size();

		CHECK(std::all_of(ladders.begin(),
		                  ladders.end(),
		                  [size](auto const& word) { return word.size() == size; })
		      == true);
	}

	SECTION("caved -> train") {
		auto const ladders = word_ladder::generate("caved", "train", english_lexicon);

		REQUIRE(ladders.size() > 1);
		auto const& size = ladders.at(0).size();

		CHECK(std::all_of(ladders.begin(),
		                  ladders.end(),
		                  [size](auto const& word) { return word.size() == size; })
		      == true);
	}
}
