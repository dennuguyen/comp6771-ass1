#include "comp6771/word_ladder.hpp"
#include <iostream>

// Please note: it's not good practice to test your code via a main function that does
//  printing. Instead, you should be using your test folder. This file should only really
//  be used for more "primitive" debugging as we know that working solely with test
//  frameworks might be overwhelming for some.

auto main() -> int {
<<<<<<< HEAD
	auto const english_lexicon = word_ladder::read_lexicon("./english.txt");
=======
    auto const english_lexicon = word_ladder::read_lexicon("./test/word_ladder/english.txt");
>>>>>>> fb2f8b6db7ec71c77821355aec6e78a0d44d5eee
	auto const ladders = word_ladder::generate("fly", "sky", english_lexicon);
	// debug here
}
