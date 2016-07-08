/// WordTree Source File
/// A non-balancing binary tree
/// TJW2

#include <string>
#include <sstream>
#include <iostream>
#include "WordTreeNode.h"
#include "WordTree.h"

/// Passes the word from the current node to the node in the given direction,
/// and updates the current node value, if such a node exists. Otherwise,
/// creates a new node in that direction. Returns true if we are in the second
/// case.
bool WordTree::pass_word(std::string word, WordTreeNode*& current_node,
                         WordTreeNode::BRANCH_TYPE pass_direction)
{
  if (current_node->get_branch(pass_direction))
  {
    current_node = current_node->get_branch(pass_direction);
    return false;
  }
  else
  {
    current_node->set_branch(pass_direction,
                             new WordTreeNode(word, pass_direction, current_node));
    return true;
  }
}

void delete_node(WordTreeNode* node)
{
  throw "delete_node not yet implemented.";
}

WordTree::WordTree(void):
  _root_node(NULL)
{
}

void WordTree::add_word(std::string word)
{
  //If there is no root node yet
  if (!_root_node)
  {
    _root_node = new WordTreeNode(word, WordTreeNode::LEFT, NULL);
    //Arbitrary choice of left - perhaps use a ROOT enum value?
  }
  else
  {
    //If there is a root node
    bool word_placed = false;
    WordTreeNode* current_node = _root_node;
    while(!word_placed)
    {
      if (word < current_node->get_node_word())
      {
        word_placed = pass_word(word, current_node, WordTreeNode::LEFT);
      }
      else if (word > current_node->get_node_word())
      {
        word_placed = pass_word(word, current_node, WordTreeNode::RIGHT);
      }
      else // If the given word is equal to the word on the current node
      {
        current_node->increment_count();
        word_placed = true;
      }
    }
  }
}

WordTreeNode* WordTree::iter_next(void)
{
  throw "iter_next not yet implemented.";
}

void WordTree::iter_reset(void)
{
  throw "iter_reset not yet implemented.";
}

bool WordTree::is_word_in_tree(std::string word)
{
  throw "is_word_in_tree not yet implemented.";
}

bool WordTree::delete_word(std::string word)
{
  throw "delete_word not yet implemented.";
}

void WordTree::write_data(std::ostream* data_stream_ptr)
{
  if (_root_node)
  {
    _root_node->write_data(data_stream_ptr);
  }
  else
  {
    *data_stream_ptr << "NO DATA" << std::endl;
  }
}

WordTree::~WordTree(void)
{
  if (_root_node)
  {
    delete _root_node;
  }
}
