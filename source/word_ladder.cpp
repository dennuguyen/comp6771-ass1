#include <algorithm>
#include <queue>
#include <stdexcept>

#include "comp6771/word_ladder.hpp"

namespace word_ladder {

	struct Graph {
		// std::vector < std::pair <
	};

	// Returns a vector of which characters are already matching between "from" and "to".
	static auto compare_words(std::string const& from, std::string const& to) -> std::vector<bool> {
		if (from.length() != to.length()) {
			throw std::runtime_error("Start and finishing words have different length.");
		}

		std::vector<bool> vec;
		for (unsigned int i = 0; i < from.length(); i++) {
			if (from[i] == to[i]) {
				vec.push_back(true);
			}
			else {
				vec.push_back(false);
			}
		}
		return vec;
	}

	static auto breadth_first_search() -> void {
		std::queue<int> q;

		while (q.empty() == false) {
			int v = q[0];
			q.pop();

			if (9) {
			}

			for (auto& n : q) {
				q.push(n);
			}
		}
	}

	// Get the lexicon as an unordered set of strings from the file specified by the path.
	[[nodiscard]] auto read_lexicon(std::string const& path) -> std::unordered_set<std::string> {}

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
		// Which letters of the word are already the same.

		// Filter lexicon for only words of the same length.

		// BFS
	}
} // namespace word_ladder