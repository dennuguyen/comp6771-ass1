///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// Test solutions with multiple word ladders are correct.
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

TEST_CASE("Words with a few word ladder solutions") {
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");

	SECTION("sour -> vise") {
		auto const ladders = word_ladder::generate("sour", "vise", english_lexicon);
		auto const answers = std::vector<std::vector<std::string>>{
		   {"sour", "soup", "roup", "roue", "rose", "rise", "vise"},
		   {"sour", "soup", "sols", "sole", "vole", "vile", "vise"},
		};

		CHECK(ladders == answers);
	}

	SECTION("awake -> sleep") {
		auto const ladders = word_ladder::generate("apple", "peach", english_lexicon);
		auto const answers = std::vector<std::vector<std::string>>{
		   {"awake", "aware", "sware", "share", "sharn", "shawn", "shewn", "sheen", "sheep", "sleep"},
		   {"awake", "aware", "sware", "share", "shire", "shirr", "shier", "sheer", "sheep", "sleep"},
		};

		CHECK(ladders == answers);
	}
}

TEST_CASE("Words with many word ladder solutions") {
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");

	SECTION("try -> rat") {
		auto const ladders = word_ladder::generate("try", "rat", english_lexicon);
		auto const answers = std::vector<std::vector<std::string>>{
		   {"try", "cry", "cay", "cat", "rat"},
		   {"try", "cry", "cay", "ray", "rat"},
		   {"try", "dry", "day", "ray", "rat"},
		   {"try", "fry", "fay", "fat", "rat"},
		   {"try", "fry", "fay", "ray", "rat"},
		   {"try", "pry", "pay", "pat", "rat"},
		   {"try", "pry", "pay", "ray", "rat"},
		   {"try", "toy", "tot", "rot", "rat"},
		   {"try", "toy", "tot", "tat", "rat"},
		   {"try", "wry", "way", "ray", "rat"},
		   {"try", "wry", "wau", "wat", "rat"},
		};

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
		   {"work", "wort", "wert", "pert", "peat", "plat", "play"},
		};

		CHECK(ladders == answers);
	}
}
