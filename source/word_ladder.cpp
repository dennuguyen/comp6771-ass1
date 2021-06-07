#include <algorithm>
#include <fstream>
#include <queue>
#include <stdexcept>

#include "comp6771/word_ladder.hpp"

namespace word_ladder {

	class Graph {
	public:
		Graph(std::string from, std::string to, std::unordered_set<std::string> lexicon)
		: from(from)
		, to(to) {
			// Filter lexicon for only words of the same length.
			std::copy_if(lexicon.begin(),
			             lexicon.end(),
			             std::inserter(this->lexicon, this->lexicon.begin()),
			             [from](std::string word) { return word.length() == from.length(); });

			// Build a graph from the lexicon where adjacent edges represent one change in character
			// between valid words.
		}

		auto get_word_ladders() -> std::vector<std::vector<std::string>> {}

	private:
		auto breadth_first_search() -> void {
			std::deque<int> q; // we use a deque to get that sweet iterator

			while (q.empty() == false) {
				int v = q.front();
				q.pop_front();

				if (v == 0) {
				}

				for (const auto& n : q) {
					q.push_back(n);
				}
			}
		}

		// Returns a vector of which characters are already matching between "from" and "to".
		// auto compare_words() -> std::vector<bool> {
		// 	std::vector<bool> vec;
		// 	for (unsigned int i = 0; i < from.length(); i++) {
		// 		if (from[i] == to[i]) {
		// 			vec.push_back(true);
		// 		}
		// 		else {
		// 			vec.push_back(false);
		// 		}
		// 	}
		// 	return vec;
		// }

	private:
		const std::string from;
		const std::string to;
		std::vector<std::string> lexicon;
	};

	// Returns a vector of vectors of strings. Inner vector is a word ladder where each word in the
	// ladder is a valid word from the lexicon. Outer vector contains other possible word ladders.
	//
	// Word ladders must contain "from" and "to" at the beginning and end of the word ladder
	// respectively.
	//
	// The size of "from" and size of "to" are the same.
	//
	// As the shortest possible path is returned, the size of all returned word ladders are the same.
	[[nodiscard]] auto generate(std::string const& from,
	                            std::string const& to,
	                            std::unordered_set<std::string> const& lexicon)
	   -> std::vector<std::vector<std::string>> {
		auto graph = Graph(from, to, lexicon);

		// BFS
		auto word_ladders = std::vector<std::vector<std::string>>();

		return graph.get_word_ladders();
	}
} // namespace word_ladder