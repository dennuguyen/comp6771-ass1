///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// A property of word ladders is that there should not be any duplicates i.e. duplicate words within
// a word ladder or duplicate word ladders.
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

// I write this test case because I am paranoid about the correctness of the testing method for this
// test file. The below sections shows various ways we can use std::adjacent_find().
//
// std::adjacent_find() == it.end() means that the STL had duplicate elements.
// std::adjacent_find() != it.end() means that the STL did not have duplicate elements.
TEST_CASE("Test that testing method is correct") {
	// Gives us the expected output.
	SECTION("Two consecutive and identical words") {
		auto lexicon = std::vector<std::string>{"word", "word", "hello"};
		CHECK(std::adjacent_find(lexicon.begin(), lexicon.end()) != lexicon.end());
	}

	// Check that the output is unexpected.
	// This test shows us that we MUST sort before calling std::adjacent_find()
	SECTION("Two non-conseuctive and identical words without sort") {
		auto lexicon = std::vector<std::string>{"word", "hello", "word"};
		CHECK(std::adjacent_find(lexicon.begin(), lexicon.end()) == lexicon.end());
	}

	// Gives us the expected output.
	// This test shows us that we MUST sort before calling std::adjacent_find()
	SECTION("Two non-conseuctive and identical words with sort") {
		auto lexicon = std::vector<std::string>{"word", "hello", "word"};
		std::sort(lexicon.begin(), lexicon.end());
		CHECK(std::adjacent_find(lexicon.begin(), lexicon.end()) != lexicon.end());
	}

	// Gives us the expected output.
	SECTION("Three non-identical words") {
		auto lexicon = std::vector<std::string>{"word", "hello", "main"};
		std::sort(lexicon.begin(), lexicon.end());
		CHECK(std::adjacent_find(lexicon.begin(), lexicon.end()) == lexicon.end());
	}
}

TEST_CASE("A word ladder should not contain duplicate words") {
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");

	SECTION("tree -> roof") {
		auto ladders = word_ladder::generate("tree", "roof", english_lexicon);

		REQUIRE(ladders.size() == 1);
		auto ladder = ladders.front();

		std::sort(ladder.begin(), ladder.end()); // must sort() before adjacent_find()

		CHECK(std::adjacent_find(ladder.begin(), ladder.end()) == ladder.end());
	}

	SECTION("trout -> mound") {
		auto ladders = word_ladder::generate("too", "two", english_lexicon);

		REQUIRE(ladders.size() == 1);
		auto ladder = ladders.front();

		std::sort(ladder.begin(), ladder.end()); // must sort() before adjacent_find()

		CHECK(std::adjacent_find(ladder.begin(), ladder.end()) == ladder.end());
	}

	SECTION("when -> what") {
		auto ladders = word_ladder::generate("when", "what", english_lexicon);

		REQUIRE(ladders.size() == 1);
		auto ladder = ladders.front();

		std::sort(ladder.begin(), ladder.end()); // must sort() before adjacent_find()

		CHECK(std::adjacent_find(ladder.begin(), ladder.end()) == ladder.end());
	}
}

TEST_CASE("All returned word ladders should not contain duplicate words") {
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");

	SECTION("wear -> nice") {
		auto ladders = word_ladder::generate("wear", "nice", english_lexicon);

		REQUIRE(ladders.size() > 1);
		std::sort(ladders.begin(), ladders.end()); // must sort() before adjacent_find()

		for (auto& ladder : ladders) {
			CHECK(std::adjacent_find(ladder.begin(), ladder.end()) == ladder.end());
		}
	}
}

TEST_CASE("Word ladders should not contain duplicate word ladders") {
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");

	SECTION("cry -> ran") {
		auto ladders = word_ladder::generate("cry", "ran", english_lexicon);

		REQUIRE(ladders.size() > 1);
		std::sort(ladders.begin(), ladders.end()); // must sort() before adjacent_find()

		for (auto& ladder : ladders) {
			CHECK(std::adjacent_find(ladder.begin(), ladder.end()) == ladder.end());
		}
	}
}
