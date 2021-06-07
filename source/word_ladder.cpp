#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <stdexcept>

#include "comp6771/word_ladder.hpp"

namespace word_ladder {
	// Returns a vector of which characters are already matching between "a" and "b".
	static auto compare_words(std::string a, std::string b) -> std::vector<bool> {
		auto vec = std::vector<bool>();
		for (unsigned int i = 0; i < a.length(); i++) {
			if (a[i] == b[i]) {
				vec.push_back(true);
			}
			else {
				vec.push_back(false);
			}
		}
		return vec;
	}

	// Returns a vector of vectors of strings. Inner vector is a word ladder where each word in
	// the ladder is a valid word from the lexicon. Outer vector contains other possible word
	// ladders.
	//
	// Word ladders must contain "from" and "to" at the beginning and end of the word ladder
	// respectively.
	//
	// The size of "from" and size of "to" are the same.
	//
	// As the shortest possible path is returned, the size of all returned word ladders are the
	// same.
	[[nodiscard]] auto generate(std::string const& from,
	                            std::string const& to,
	                            std::unordered_set<std::string> const& lexicon)
	   -> std::vector<std::vector<std::string>> {
		// Filter lexicon for only words of the same length.
		auto filtered_lexicon = std::unordered_set<std::string>();
		std::copy_if(lexicon.begin(),
		             lexicon.end(),
		             std::inserter(filtered_lexicon, filtered_lexicon.begin()),
		             [from](std::string word) { return word.length() == from.length(); });

		// Build the graph.
		auto graph = std::map<std::string, std::vector<std::string>>();
		for (const auto& base_word : filtered_lexicon) {
			auto vec = std::vector<std::string>();
			for (const auto& connecting_word : filtered_lexicon) {
				const auto b = compare_words(base_word, connecting_word);
				if (std::count(b.begin(), b.end(), false) == 1) {
					vec.push_back(connecting_word);
				}
			}
			graph[base_word] = vec;
		}

		// Debugging purposes
		// for (const auto& i : graph) {
		// 	std::cout << i.first << ": ";
		// 	for (const auto& j : i.second) {
		// 		std::cout << j << " ";
		// 	}
		// 	std::cout << std::endl;
		// }

		// Breadth-first search the graph.
		auto word_ladders = std::vector<std::vector<std::string>>();
		// auto word_queue = std::deque<std::string>(); // words to check for edges

		// while (word_queue.empty() == false) {
		// 	const auto word = word_queue.front();
		// 	word_queue.pop_front();

		// 	if (word == to) {
		// 	}

		// 	for (const auto& next_word : word_queue) {
		// 		auto vectorised = compare_words(word, next_word);
		// 		if (std::count(vectorised.begin(), vectorised.end(), false) == 1) {
		// 			word_queue.push_back(next_word);
		// 		}
		// 	}
		// }
		(void)to;
		return word_ladders;
	}
} // namespace word_ladder