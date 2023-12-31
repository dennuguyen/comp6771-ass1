///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// Benchmark to ensure solution is not too slow. Modified to fail if the test case times out.
//
// Please refer to test_word_ladder_simple.cpp for the test design rationale.
//
///////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Copyright UNSW Sydney School of Computer Science and Engineering
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

#include <chrono>
#include <string>
#include <vector>

#include "catch2/catch.hpp"

TEST_CASE("Solutions should not take any longer than this test") {
	auto const english_lexicon = ::word_ladder::read_lexicon("./english.txt");

	SECTION("atlases -> cabaret") {
		Catch::Timer timer;
		timer.start();
		auto const ladders = ::word_ladder::generate("atlases", "cabaret", english_lexicon);

		CHECK(timer.getElapsedSeconds() <= 15.0);
		CHECK(std::size(ladders) != 0);
	}
}
