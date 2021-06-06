configure_file("english.txt" ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

cxx_test(
   TARGET test_read_lexicon
   FILENAME test_read_lexicon.cpp
   LINK word_ladder lexicon Catch2::Catch2 test_main
)

cxx_test(
   TARGET test_word_ladder_1
   FILENAME test_word_ladder_1.cpp
   LINK word_ladder lexicon Catch2::Catch2 test_main
)

cxx_test(
   TARGET test_word_ladder_benchmark
   FILENAME test_word_ladder_benchmark.cpp
   LINK word_ladder lexicon Catch2::Catch2 test_main
)
