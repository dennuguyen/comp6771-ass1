///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// Test solutions can have multiple shortest-distance word ladders however these word ladders must
// have the same length for the shortest distance to be valid.
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

		REQUIRE(ladders.empty() == false);
		auto const size = ladders.at(0).size();

		CHECK(std::all_of(ladders.begin(),
		                  ladders.end(),
		                  [size](auto const& l) { return l.size() == size; })
		      == true);
	}

	SECTION("waver -> power") {
		auto const ladders = word_ladder::generate("waver", "power", english_lexicon);

		REQUIRE(ladders.empty() == false);
		auto const size = ladders.at(0).size();

		CHECK(std::all_of(ladders.begin(),
		                  ladders.end(),
		                  [size](auto const& l) { return l.size() == size; })
		      == true);
	}
}
