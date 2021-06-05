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

	[[nodiscard]] auto read_lexicon(std::string const& path) -> std::unordered_set<std::string> {}

	// Given a start word and destination word, returns all the shortest possible paths from the
	// start word to the destination, where each word in an individual path is a valid word per the
	// provided lexicon. Pre: ranges::size(from) == ranges::size(to) Pre: valid_words.contains(from)
	// and valid_words.contains(to)
	[[nodiscard]] auto generate(std::string const& from,
	                            std::string const& to,
	                            std::unordered_set<std::string> const& lexicon)
	   -> std::vector<std::vector<std::string>> {
		// Which letters of the word are already the same.

		// Filter lexicon for only words of the same length.

		// BFS
	}
} // namespace word_ladder