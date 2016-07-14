/// Input/Output for WordTree
/// TJW2

#include <string>
#include <iostream>
#include <fstream>
#include "WordTreeInput.h"

std::string exit_string = "exit";

void add_to_tree_from_console(WordTree &word_tree, std::string exit_string)
{
  std::string word_string;

  while(true)
  {
    std::cout << "Type '" << exit_string << "' to exit." << std::endl;
    std::cout << "Input word: ";
    std::getline(std::cin, word_string);

    if (word_string == exit_string)
    {
      break;
    }

    word_tree.add_word(word_string);
  }
}

void add_to_tree_from_file(WordTree &word_tree, std::string file_path)
{
  std::string line;
  int line_count = 0;
  std::ifstream file;
  file.open(file_path.c_str());

  if (!file.is_open())
  {
    throw "Unable to open file.";
  }

  while(std::getline(file, line))
  {
    word_tree.add_word(line);
    line_count++;
  }

  file.close();
}

void add_to_tree_from_vector(WordTree &word_tree, std::vector<std::string> &word_vector)
{
  std::vector<std::string>::iterator v = word_vector.begin();
  while (v != word_vector.end())
  {
    word_tree.add_word(*v);
  }
}

std::pair<std::string, int>* find_highest_count_node(WordTree &word_tree)
{
  word_tree.iter_reset();
  std::pair<std::string, int>* current_node = word_tree.iter_next();
  if (!current_node)
  {
    throw "Tree is empty!";
  }
  std::pair<std::string, int>*  max_node = current_node;
  while(current_node)
  {
    if (current_node->second > max_node->second)
    {
      max_node = current_node;
    }
    current_node = word_tree.iter_next();
  }
  return max_node;
}

std::string most_common_word(WordTree &word_tree)
{
  std::pair<std::string, int>* highest_count_node = find_highest_count_node(word_tree);
  return highest_count_node->first;
}

int count_of_most_common_word(WordTree &word_tree)
{
  std::pair<std::string, int>* highest_count_node = find_highest_count_node(word_tree);
  return highest_count_node->second;
}

std::string most_common_word_from_file(std::string file_path)
{
  WordTree word_tree;
  add_to_tree_from_file(word_tree, file_path);
  std::string word = most_common_word(word_tree);
  return word;
}

int count_of_most_common_word_from_file(std::string file_path)
{
  WordTree word_tree;
  add_to_tree_from_file(word_tree, file_path);
  int word_count = count_of_most_common_word(word_tree);
  return word_count;
}

void output_tree_to_console(WordTree &word_tree)
{
  word_tree.write_data(&std::cout);
}

void output_tree_to_file(WordTree &word_tree, std::string file_path)
{
  std::ofstream file;
  file.open(file_path.c_str(), std::ofstream::trunc);

  if (!file.is_open())
  {
    throw "Unable to open file.";
  }

  word_tree.write_data(&file);
  file.close();
}
/*
int main(int argc, char *argv[])
{
  WordTree* word_tree;
  if (argc == 1)
  {
    //Add words from the console one-by-one, and output the finished tree to the
    //console
    std::cout << "Console-to-Console mode." << std::endl;
    word_tree = create_tree_from_console("exit");
    output_tree_to_console(word_tree);
  }
  else if (argc == 2)
  {
    //Add words from the given file, and output the finished tree to the console
    std::cout << "File-to-Console mode." << std::endl;
    word_tree = create_tree_from_file(argv[1]);
    output_tree_to_console(word_tree);
  }
  else if (argc == 3)
  {
    //Add words from the first given file, and output the finished tree to the
    //second given file
    std::cout << "File-to-File Mode." << std::endl;
    word_tree = create_tree_from_file(argv[1]);
    output_tree_to_file(word_tree, argv[2]);
  }
  else
  {
    //Incorrect usage - prints an error message
    std::cout << "Incorrect Usage. Use as follows: " << std::endl;
    std::cout << "'" << argv[0] << "'"
              << " for Console-to-Console mode;" << std::endl;
    std::cout << "'" << argv[0] << " <input_file>'"
              << " for File-to-Console mode;" << std::endl;
    std::cout << "'" << argv[0] << " <input_file> <output_file>'"
              << " for File-to-File mode;" << std::endl;
  }
  if (!word_tree)
  {
    delete word_tree;
  }
}
*/
