configure_file("english.txt" ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

cxx_test(
   TARGET test_read_lexicon
   FILENAME test_read_lexicon.cpp
   LINK word_ladder lexicon Catch2::Catch2 test_main
)

cxx_test(
   TARGET test_word_ladder_benchmark
   FILENAME test_word_ladder_benchmark.cpp
   LINK word_ladder lexicon Catch2::Catch2 test_main
)

cxx_test(
   TARGET test_word_ladder_duplicate
   FILENAME test_word_ladder_duplicate.cpp
   LINK word_ladder lexicon Catch2::Catch2 test_main
)

cxx_test(
   TARGET test_word_ladder_multiple
   FILENAME test_word_ladder_multiple.cpp
   LINK word_ladder lexicon Catch2::Catch2 test_main
)

cxx_test(
   TARGET test_word_ladder_null
   FILENAME test_word_ladder_null.cpp
   LINK word_ladder lexicon Catch2::Catch2 test_main
)

cxx_test(
   TARGET test_word_ladder_reverse
   FILENAME test_word_ladder_reverse.cpp
   LINK word_ladder lexicon Catch2::Catch2 test_main
)

cxx_test(
   TARGET test_word_ladder_simple
   FILENAME test_word_ladder_simple.cpp
   LINK word_ladder lexicon Catch2::Catch2 test_main
)

cxx_test(
   TARGET test_word_ladder_sorted
   FILENAME test_word_ladder_sorted.cpp
   LINK word_ladder lexicon Catch2::Catch2 test_main
)
