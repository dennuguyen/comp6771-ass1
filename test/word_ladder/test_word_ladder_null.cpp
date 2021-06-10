///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// Test cases where two words will have no valid word ladder solution.
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

TEST_CASE("Words with no word ladder solutions") {
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");

	SECTION("below -> above") {
		auto const ladders = word_ladder::generate("below", "above", english_lexicon);

		CHECK(ladders.empty() == true);
	}

	SECTION("vehicle -> hexagon") {
		auto const ladders = word_ladder::generate("vehicle", "hexagon", english_lexicon);

		CHECK(ladders.empty() == true);
	}

	SECTION("numbers -> truffle") {
		auto const ladders = word_ladder::generate("numbers", "truffle", english_lexicon);

		CHECK(ladders.empty() == true);
	}
}