///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// This set of test cases are simple (considering only single word ladder solutions) and tests
// whether our generate() works for varying number of character differences and at various sections
// of the word. This test file is to build general confidence into our solution.
//
// TEST DESIGN RATIONALE
//
// The approach to testing design is property-based. The overall test design is done through
// abstraction of properties and conditions. A property is a particular characteristic of the output
// that is true e.g. a solution will always have same length words. A condition is a scenario/case
// where the property can be exhibited e.g. a solution will have the same length words for a single
// word ladder, or a solution will have the same length words for all word ladders.
//
// Hierarchy of the test design:
// 	- test file: collection of similar properties or a single property that we want to test
// 	- test case: a particular condition about the property that is true i.e. something should do
// something
// 	- test section: various words which will give an output to show the property to be true for a
// condition we are testing.
//
// I use this particular hierarchy because it neatly separates properties, conditions, and test
// sections. Using test sections also allows me to use "english_lexicon" as a test fixture which
// looks cleaner and requires less code (and is also recommended by authors of catch2)
//
// The TEST_CASE names are also descriptive to give an idea of what the test case is for and follows
// a "something should something" format. Therefore TEST_CASE is not commented as it will be
// redundant to rewrite what the test case is for. Comments will only be given at the top of the
// file to clarify why we are testing a particular property. The only time the "something should
// something" format is not followed is when exact word ladder solutions are given to be tested -
// this is for general confidence.
//
// Some test files will only have a single test case if the property to be tested is simple.
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

TEST_CASE("Words with single different character at beginning of word") {
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");

	SECTION("at -> it") {
		auto const ladders = word_ladder::generate("at", "it", english_lexicon);
		auto const answers = std::vector<std::vector<std::string>>{{"at", "it"}};

		CHECK(ladders == answers);
	}

	SECTION("ran -> tan") {
		auto const ladders = word_ladder::generate("ran", "tan", english_lexicon);
		auto const answers = std::vector<std::vector<std::string>>{{"ran", "tan"}};

		CHECK(ladders == answers);
	}
}

TEST_CASE("Words with single different character in middle of word") {
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");

	SECTION("too -> two") {
		auto const ladders = word_ladder::generate("too", "two", english_lexicon);
		auto const answers = std::vector<std::vector<std::string>>{{"too", "two"}};

		CHECK(ladders == answers);
	}

	SECTION("beer -> bear") {
		auto const ladders = word_ladder::generate("beer", "bear", english_lexicon);
		auto const answers = std::vector<std::vector<std::string>>{{"beer", "bear"}};

		CHECK(ladders == answers);
	}

	SECTION("litter -> latter") {
		auto const ladders = word_ladder::generate("litter", "latter", english_lexicon);
		auto const answers = std::vector<std::vector<std::string>>{{"litter", "latter"}};

		CHECK(ladders == answers);
	}
}

TEST_CASE("Words with single different character at end of word") {
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");

	SECTION("paw -> pal") {
		auto const ladders = word_ladder::generate("paw", "pal", english_lexicon);
		auto const answers = std::vector<std::vector<std::string>>{{"paw", "pal"}};

		CHECK(ladders == answers);
	}

	SECTION("boars -> boart") {
		auto const ladders = word_ladder::generate("boars", "boart", english_lexicon);
		auto const answers = std::vector<std::vector<std::string>>{{"boars", "boart"}};

		CHECK(ladders == answers);
	}
}

TEST_CASE("Words with a few different characters") {
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");

	SECTION("meek -> leak") {
		auto const ladders = word_ladder::generate("meek", "leak", english_lexicon);
		auto const answers = std::vector<std::vector<std::string>>{{"meek", "leek", "leak"}};

		CHECK(ladders == answers);
	}
}

TEST_CASE("Words that are entirely dissimilar") {
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");

	SECTION("feat -> wool") {
		auto const ladders = word_ladder::generate("feat", "wool", english_lexicon);
		auto const answers =
		   std::vector<std::vector<std::string>>{{"feat", "feal", "foal", "fool", "wool"}};

		CHECK(ladders == answers);
	}

	SECTION("lipid -> resow") {
		auto const ladders = word_ladder::generate("lipid", "resow", english_lexicon);
		auto const answers = std::vector<std::vector<std::string>>{
		   {"lipid", "livid", "lived", "rived", "rivet", "revet", "reset", "resew", "resow"}};

		CHECK(ladders == answers);
	}
}
