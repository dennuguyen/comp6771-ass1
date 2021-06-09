#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <stdexcept>

#include "comp6771/word_ladder.hpp"

namespace word_ladder {

	// Filter lexicon for only words of the same length.
	static auto filter_lexicon(const std::unordered_set<std::string> lexicon,
	                           const size_t word_length) -> std::unordered_set<std::string> {
		auto filtered_lexicon = std::unordered_set<std::string>();
		std::copy_if(lexicon.begin(),
		             lexicon.end(),
		             std::inserter(filtered_lexicon, filtered_lexicon.begin()),
		             [word_length](std::string word) { return word.length() == word_length; });
		return filtered_lexicon;
	}

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

	// Builds a graph from an unordered set of words where edges are formed between words with one
	// differing character.
	static auto build_graph(const std::unordered_set<std::string> lexicon)
	   -> std::map<std::string, std::vector<std::string>> {
		auto graph = std::map<std::string, std::vector<std::string>>();
		for (const auto& base_word : lexicon) {
			auto adjacent_words = std::vector<std::string>();
			for (const auto& connecting_word : lexicon) {
				// Valid adjacent words have a single different character to the base word.
				const auto vectorised = compare_words(base_word, connecting_word);
				if (std::count(vectorised.begin(), vectorised.end(), false) == 1) {
					adjacent_words.push_back(connecting_word);
				}
			}
			graph[base_word] = adjacent_words;
		}
		return graph;
	}

	// Breadth-first search the graph and returns a vector of word ladders between "from" and "to".
	static auto breadth_first_search(const std::string from,
	                                 const std::string to,
	                                 const std::map<std::string, std::vector<std::string>> graph)
	   -> std::vector<std::vector<std::string>> {
		auto word_ladders = std::vector<std::vector<std::string>>();
		auto word_queue = std::deque<std::string>{from}; // words to check for edges
		while (word_queue.empty() == false) {
			const auto word = word_queue.front();
			word_queue.pop_front();
			if (word == to) {
				break;
			}
			for (const auto& adjacent_word : graph.at(word)) {
				word_queue.push_back(adjacent_word);
			}
		}
		return word_ladders;
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
		const auto filtered_lexicon = filter_lexicon(lexicon, from.length());
		const auto graph = build_graph(filtered_lexicon);
		const auto word_ladders = breadth_first_search(from, to, graph);
		return word_ladders;
	}
} // namespace word_ladder