///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// Because I'm paranoid.
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

#include <string>
#include <vector>

#include "catch2/catch.hpp"

TEST_CASE("All words are read from file") {
	auto const english_lexicon = ::word_ladder::read_lexicon("./english.txt");

	CHECK(english_lexicon.size() == 127142);
}
