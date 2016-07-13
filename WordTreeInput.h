/// Input/Output for WordTree
/// TJW2

#ifndef WORD_TREE_INPUT_H
#define WORD_TREE_INPUT_H

#include <string>
#include <tuple>
#include <iostream>
#include <vector>
#include "WordTree.h"

// Reads a list of words, one per line, from the chosen input
WordTree* create_tree_from_console(std::string exit_string);
WordTree* create_tree_from_file(std::string file_path);

WordTree* create_tree_from_vector(std::vector<std::string> &word_vector);

std::pair<std::string, int>*  find_highest_count_node(WordTree* word_tree);

std::string most_common_word(WordTree* word_tree);
int count_of_most_common_word(WordTree* word_tree);

std::string most_common_word_from_file(std::string file_path);
int count_of_most_common_word_from_file(std::string file_path);

// Writes a list of word, count pairs to the chosen output in alphabetical order
void output_tree_to_console(WordTree* word_tree);
void output_tree_to_file(WordTree* word_tree, std::string file_path);

#endif
