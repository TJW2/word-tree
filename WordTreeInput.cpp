/// Input/Output for WordTree
/// TJW2

#include <string>
#include <iostream>
#include <fstream>
#include "WordTreeInput.h"

std::string exit_string = "exit";

WordTree* create_tree_from_console(std::string exit_string)
{
  std::string word_string;
  WordTree* word_tree = new WordTree();

  while(true)
  {
    std::cout << "Type '" << exit_string << "' to exit." << std::endl;
    std::cout << "Input word: ";
    std::getline(std::cin, word_string);

    if (word_string == exit_string)
    {
      break;
    }

    word_tree->add_word(word_string);
  }
  return word_tree;
}

WordTree* create_tree_from_file(std::string file_path)
{
  std::string line;
  int line_count = 0;
  std::ifstream file;
  file.open(file_path.c_str());

  if (!file.is_open())
  {
    throw "Unable to open file.";
  }

  WordTree* word_tree = new WordTree();

  while(std::getline(file, line))
  {
    word_tree->add_word(line);
    line_count++;
  }

  file.close();
  std::cout << "Read " << line_count << " lines from file: " << file_path;
  std::cout << std::endl;

  return word_tree;
}

WordTreeNode* find_highest_count_node(WordTree* word_tree)
{
  word_tree->iter_reset();
  WordTreeNode* current_node = word_tree->iter_next();
  WordTreeNode* max_node = NULL;
  while(current_node)
  {
    if (!max_node || current_node->get_count() > max_node->get_count())
    {
      max_node = current_node;
    }
    current_node = word_tree->iter_next();
  }
  return max_node;
}

void output_tree_to_console(WordTree* word_tree)
{
  word_tree->write_data(&std::cout);
}

void output_tree_to_file(WordTree* word_tree, std::string file_path)
{
  std::ofstream file;
  file.open(file_path.c_str(), std::ofstream::trunc);

  if (!file.is_open())
  {
    throw "Unable to open file.";
  }

  word_tree->write_data(&file);
  file.close();
  std::cout << "Data written to file: " << file_path << std::endl;
}

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
