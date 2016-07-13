/// Input/Output for WordTree
/// TJW2

#ifndef WORD_TREE_INPUT_H
#define WORD_TREE_INPUT_H

#include <string>
#include <iostream>
#include "WordTree.h"

// Reads a list of words, one per line, from the chosen input
WordTree* create_tree_from_console(std::string exit_string);
WordTree* create_tree_from_file(std::string file_path);

// Writes a list of word, count pairs to the chosen output in alphabetical order
void output_tree_to_console(WordTree* word_tree);
void output_tree_to_file(WordTree* word_tree, std::string file_path);

#endif
