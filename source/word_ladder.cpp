#include <algorithm>
#include <deque>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <stack>

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
					adjacent_words.emplace_back(leaf_word);
				}
			}
			graph[base_word] = adjacent_words;
			graph[base_word].shrink_to_fit();
		}
		return graph;
	}

	// Traverse the graph with a breadth first search to build a directed graph.
	static auto bfs(std::string const& from,
	                std::string const& to,
	                std::map<std::string, std::vector<std::string>> const& graph)
	   -> std::map<std::string, int> {
		// Initialise directed graph.
		auto directed_graph = std::map<std::string, int>();
		for (const auto& node : graph) {
			directed_graph[node.first] = -1;
		}
		directed_graph.at(from) = 0;

		// Initialise word queue.
		auto word_queue = std::queue<std::string>();
		word_queue.push(from);

		while (word_queue.empty() == false) {
			const auto current_word = word_queue.front();
			word_queue.pop();

			// Found the destination.
			if (current_word == to) {
				break;
			}

			for (const auto& adjacent_word : graph.at(current_word)) {
				// Give unvisited words a distance from source.
				if (directed_graph.at(adjacent_word) == -1) {
					directed_graph.at(adjacent_word) = directed_graph.at(current_word) + 1;
					word_queue.push(adjacent_word);
				}
			}
		}
		return directed_graph;
	}

	// Traverse the graph and check for direction to build the word ladder.
	static auto dfs(std::string const& from,
	                std::string const& to,
	                std::map<std::string, std::vector<std::string>> const& graph,
	                std::map<std::string, int> const& directed_graph)
	   -> std::vector<std::vector<std::string>> {
		// Initialise word ladders.
		auto word_ladders = std::vector<std::vector<std::string>>();

		// Initialise word ladder.
		auto word_ladder = std::vector<std::string>();
		word_ladder.emplace_back(from);

		// Initialise word stack.
		auto word_stack = std::stack<std::pair<std::string, std::vector<std::string>>>();
		word_stack.push(std::make_pair(from, word_ladder));

		while (word_stack.empty() == false) {
			const auto [current_word, word_ladder] = word_stack.top();
			word_stack.pop();

			// Found the destination.
			if (current_word == to) {
				word_ladders.push_back(word_ladder);
			}

			// Trace back directed graph.
			for (const auto& adjacent_word : graph.at(current_word)) {
				if (directed_graph.at(adjacent_word) > directed_graph.at(current_word)) {
					auto new_ladder = std::vector<std::string>(word_ladder);
					new_ladder.emplace_back(adjacent_word);
					word_stack.push(std::make_pair(adjacent_word, new_ladder));
				}
			}
		}
		std::sort(word_ladders.begin(), word_ladders.end());
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
		const auto& filtered_lexicon = filter_lexicon(lexicon, from.length());
		const auto& graph = build_graph(filtered_lexicon);
		const auto& directed_graph = bfs(from, to, graph);
		const auto& word_ladders = dfs(from, to, graph, directed_graph);
		return word_ladders;
	}
} // namespace word_ladder