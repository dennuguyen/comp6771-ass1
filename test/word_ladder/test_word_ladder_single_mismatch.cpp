///////////////////////////////////////////////////////////////////////////////////////////////////
//
// TESTING RATIONALE
//
// A property of word ladders is that words in a word ladder have a single mismatch to
// their neighbouring words.
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
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "catch2/catch.hpp"

static auto is_single_mismatch(std::string const& a, std::string const& b) -> bool {
	auto mismatch_count = 0;
	for (unsigned int i = 0; i < a.length(); i++) {
		if (a[i] != b[i]) {
			mismatch_count++;
		}

		if (mismatch_count > 1) {
			break;
		}
	}
	return (mismatch_count == 1) ? true : false;
}

static auto single_mismatch = [](auto const& a, auto const& b) {
	return is_single_mismatch(a, b) == true;
};

// Implement my own template function because standard library doesn't have what I'm looking for
// which is a count_if() but with BinaryPredicate.
//
// Implementation inspired by second version of count_if()
// https://en.cppreference.com/w/cpp/algorithm/count
//
// I also implemented this because I have too much time on my hands.
template<typename InputIt, typename BinaryPredicate = std::equal_to<>>
auto count_adjacent_if(InputIt first, InputIt last, BinaryPredicate p) ->
   typename std::iterator_traits<InputIt>::difference_type {
	auto ret = typename std::iterator_traits<InputIt>::difference_type(0);
	for (InputIt next(first); ++next != last; ++first) {
		if (p(*first, *next)) {
			++ret;
		}
	}
	return ret;
}

// I write this test case because I am paranoid about the correctness of the testing method for
// this test file.
TEST_CASE("Test that testing method is correct") {
	SECTION("Three single-mismatched words should have two mismatches") {
		auto lexicon = std::vector<std::string>{"word", "ward", "ware"};

		CHECK(count_adjacent_if(lexicon.cbegin(), lexicon.cend(), single_mismatch) == 2);
	}

	SECTION("No single-mismatch pattern") {
		auto lexicon = std::vector<std::string>{"word", "hello", "ware"};

		CHECK(count_adjacent_if(lexicon.cbegin(), lexicon.cend(), single_mismatch) == 0);
	}

	SECTION("Three identical words") {
		auto lexicon = std::vector<std::string>{"word", "word", "word"};

		CHECK(count_adjacent_if(lexicon.cbegin(), lexicon.cend(), single_mismatch) == 0);
	}

	SECTION("Two separate single-mismatch patterns") {
		auto lexicon = std::vector<std::string>{"ward", "word", "hare", "hard"};

		CHECK(count_adjacent_if(lexicon.cbegin(), lexicon.cend(), single_mismatch) == 2);
	}
}

TEST_CASE("Word ladders should have consecutive single-mismatches") {
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");

	SECTION("feat -> wool") {
		auto const ladders = word_ladder::generate("feat", "wool", english_lexicon);

		REQUIRE(ladders.empty() == false);
		auto const& ladder = ladders.front();

		CHECK(count_adjacent_if(ladder.begin(), ladder.end(), single_mismatch)
		      == static_cast<int>(ladder.size() - 1));
	}

	SECTION("pie -> tar") {
		auto const ladders = word_ladder::generate("pie", "tar", english_lexicon);

		REQUIRE(ladders.empty() == false);
		for (auto const& ladder : ladders) {
			CHECK(count_adjacent_if(ladder.begin(), ladder.end(), single_mismatch)
			      == static_cast<int>(ladder.size() - 1));
		}
	}

	SECTION("tan -> put") {
		auto const ladders = word_ladder::generate("tan", "put", english_lexicon);

		REQUIRE(ladders.empty() == false);
		for (auto const& ladder : ladders) {
			CHECK(count_adjacent_if(ladder.begin(), ladder.end(), single_mismatch)
			      == static_cast<int>(ladder.size() - 1));
		}
	}

	SECTION("crack -> trick") {
		auto const ladders = word_ladder::generate("crack", "trick", english_lexicon);

		REQUIRE(ladders.empty() == false);
		for (auto const& ladder : ladders) {
			CHECK(count_adjacent_if(ladder.begin(), ladder.end(), single_mismatch)
			      == static_cast<int>(ladder.size() - 1));
		}
	}
}
