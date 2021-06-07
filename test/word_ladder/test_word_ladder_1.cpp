// Test cases generated using https://datagenetics.com/blog/april22019/solve.php
//
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

TEST_CASE("Word ladders when reversed should be the same") {
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");

	SECTION("war -> bro") {
		auto const ladders1 = word_ladder::generate("war", "bro", english_lexicon);
		auto const ladders2 = word_ladder::generate("bro", "war", english_lexicon);

		CHECK(ladders1 == ladders2);
	}

	SECTION("menu -> trap") {
		auto const ladders1 = word_ladder::generate("menu", "trap", english_lexicon);
		auto const ladders2 = word_ladder::generate("trap", "menu", english_lexicon);

		CHECK(ladders1 == ladders2);
	}
}

TEST_CASE("Words with a few indifferent characters") {
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");

	SECTION("sour -> vise") {
		auto const ladders = word_ladder::generate("sour", "vise", english_lexicon);
		auto const answers = std::vector<std::vector<std::string>>{
		   {"sour", "soup", "roup", "roue", "rose", "rise", "vise"}};

		CHECK(ladders == answers);
	}

	SECTION("mister -> ladder") {
		auto const ladders = word_ladder::generate("mister", "ladder", english_lexicon);
		auto const answers = std::vector<std::vector<std::string>>{
		   {"mister", "minter", "minder", "binder", "bidder", "badder", "ladder"}};

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

	SECTION("cry -> lea") {
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

TEST_CASE("Words with multiple word ladder solutions") {
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");

	SECTION("aal -> log") {
		auto const ladders = word_ladder::generate("aal", "log", english_lexicon);
		auto const answers = std::vector<std::vector<std::string>>{{"aal", "bal", "bag", "bog", "log"},
		                                                           {"aal", "bal", "bag", "lag", "log"}};

		CHECK(ladders == answers);
	}

	SECTION("log -> aal") {
		auto const ladders = word_ladder::generate("aal", "log", english_lexicon);
		auto const answers = std::vector<std::vector<std::string>>{{"log", "bog", "bag", "bal", "aal"},
		                                                           {"log", "lag", "bag", "bal", "aal"}};

		CHECK(ladders == answers);
	}

	SECTION("awake -> sleep") {
		auto const ladders = word_ladder::generate("apple", "peach", english_lexicon);
		auto const answers = std::vector<std::vector<std::string>>{
		   {"awake", "aware", "sware", "share", "sharn", "shawn", "shewn", "sheen", "sheep", "sleep"},
		   {"awake", "aware", "sware", "share", "shire", "shirr", "shier", "sheer", "sheep", "sleep"}};

		CHECK(ladders == answers);
	}

	SECTION("work -> play") {
		auto const ladders = word_ladder::generate("apple", "peach", english_lexicon);
		auto const answers = std::vector<std::vector<std::string>>{
		   {"work", "fork", "form", "foam", "flam", "flay", "play"},
		   {"work", "pork", "perk", "peak", "pean", "plan", "play"},
		   {"work", "pork", "perk", "peak", "peat", "plat", "play"},
		   {"work", "pork", "perk", "pert", "peat", "plat", "play"},
		   {"work", "pork", "porn", "pirn", "pian", "plan", "play"},
		   {"work", "pork", "port", "pert", "peat", "plat", "play"},
		   {"work", "word", "wood", "pood", "plod", "ploy", "play"},
		   {"work", "worm", "form", "foam", "flam", "flay", "play"},
		   {"work", "worn", "porn", "pirn", "pian", "plan", "play"},
		   {"work", "wort", "bort", "boat", "blat", "plat", "play"},
		   {"work", "wort", "port", "pert", "peat", "plat", "play"},
		   {"work", "wort", "wert", "pert", "peat", "plat", "play"}};

		CHECK(ladders == answers);
	}
}

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