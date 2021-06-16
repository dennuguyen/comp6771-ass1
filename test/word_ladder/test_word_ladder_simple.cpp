///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// This set of test cases are simple (considering only single word ladder solutions) and tests
// whether our generate() works for varying number of character differences and at various sections
// of the word.
//
// Explanation on the test design style. I aim to abstract test cases by property of the function
// generate(). Therefore each test case considers a particular property of generate() when given
// some particular input. Each test case is then broken into sections to test words that will give
// the property. Using test sections also allows me to use "english_lexicon" as a test fixture which
// overall looks cleaner. Then properties that are similar are encapsulated by test files.
//
// For context, a property is something we know about the output to be true.
//
// Also please read the TEST_CASE names for the description of what the test case is exactly for. I
// did not want to repeat myself in comments. These descriptions will typically follow the
// "something should something" format if the exact word ladder solution is not provided.
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