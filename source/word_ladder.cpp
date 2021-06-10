#include <algorithm>
#include <fstream>
#include <map>
#include <queue>

#include "comp6771/word_ladder.hpp"

namespace word_ladder {

	// Filter lexicon for only words of the same length.
	static auto filter_lexicon(std::unordered_set<std::string> const& lexicon,
	                           std::size_t const& word_length) -> std::unordered_set<std::string> {
		auto filtered_lexicon = std::unordered_set<std::string>();
		std::copy_if(lexicon.begin(),
		             lexicon.end(),
		             std::inserter(filtered_lexicon, filtered_lexicon.begin()),
		             [word_length](std::string word) { return word.length() == word_length; });
		return filtered_lexicon;
	}

	// Returns true if there is exactly one mismatching character between "a" and "b".
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

	// Builds a graph from an unordered set of words. Condition of our graph is that valid leaf words
	// have a single different character to the base word.
	static auto build_graph(std::unordered_set<std::string> const& lexicon)
	   -> std::map<std::string, std::vector<std::string>> {
		auto graph = std::map<std::string, std::vector<std::string>>();

		for (const auto& base_word : lexicon) {
			auto adjacent_words = std::vector<std::string>();

			for (const auto& leaf_word : lexicon) {
				if (is_single_mismatch(base_word, leaf_word)) {
					adjacent_words.push_back(leaf_word);
				}
			}
			graph[base_word] = adjacent_words;
		}
		return graph;
	}

	// Search the graph for shortest paths between "from" and "to" using a modified BFS algorithm.
	static auto breadth_first_search(std::string const& from,
	                                 std::string const& to,
	                                 std::map<std::string, std::vector<std::string>> const& graph)
	   -> std::vector<std::vector<std::string>> {
		auto word_ladders = std::vector<std::vector<std::string>>();
		auto word_distance = std::map<std::string, int>();
		auto current_ladder = std::vector<std::string>();
		auto ladder_queue = std::deque<std::vector<std::string>>();

		// Initialise.
		constexpr auto unvisited = -1;
		for (const auto& word : graph) {
			word_distance[word.first] = unvisited;
		}
		word_distance[from] = 1;
		current_ladder.push_back(from);
		ladder_queue.push_back(current_ladder);

		while (ladder_queue.empty() == false) {
			current_ladder = ladder_queue.front();
			ladder_queue.pop_front();
			const auto current_word = current_ladder.back();

			// Found the destination.
			if (current_word == to) {
				word_ladders.push_back(current_ladder);
			}

			for (const auto& adjacent_word : graph.at(current_word)) {
				if (word_distance.at(adjacent_word) == unvisited) {
					word_distance.at(adjacent_word) = word_distance.at(current_word) + 1;
					auto new_word_ladder = std::vector<std::string>(current_ladder);
					new_word_ladder.push_back(adjacent_word);
					ladder_queue.push_back(new_word_ladder);
				}
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