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
    current_node = current_node->get_branch(pass_direction);
    // If the new node should come next in the current iteration
    WordTreeNode* new_next_node = find_next_node(current_node);
    if(new_next_node && new_next_node == _next_node)
    {
      _next_node = current_node;
    }
    return true;
  }
}

WordTreeNode* WordTree::leftmost_child(WordTreeNode* node)
{
  WordTreeNode* current_node = node;
  while(current_node->get_branch(WordTreeNode::LEFT))
  {
    current_node = current_node->get_branch(WordTreeNode::LEFT);
  }
  return current_node;
}

WordTreeNode* WordTree::first_left_ancestor(WordTreeNode* node)
{
  WordTreeNode* current_node = node;
  while(current_node->get_branch_type() != WordTreeNode::LEFT)
  {
    current_node = current_node->get_parent_node();
  }
  return current_node;
}

void WordTree::delete_node(WordTreeNode* node)
{
  throw "delete_node not yet implemented.";
}

WordTree::WordTree(void):
  _root_node(nullptr)
{
}

void WordTree::add_word(std::string word)
{
  //If there is no root node yet
  if (!_root_node)
  {
    _root_node = new WordTreeNode(word, WordTreeNode::LEFT, nullptr);
    //LEFT required here for iterator
    _next_node = _root_node;
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

WordTreeNode* WordTree::find_next_node(WordTreeNode* node)
{
  WordTreeNode* next_node;
  if(node->get_branch(WordTreeNode::RIGHT))
  {
    next_node = leftmost_child(node->get_branch(WordTreeNode::RIGHT));
  }
  else
  {
    next_node = first_left_ancestor(node)->get_parent_node();
  }
  return next_node;
}

std::pair<std::string, int>*  WordTree::iter_next(void)
{
  WordTreeNode* current_node = _next_node;
  std::pair<std::string, int>* node_data = nullptr;
  if(current_node)
  {
    // If we have not reached the end of the tree
    _next_node = find_next_node(current_node);
    node_data = new std::pair<std::string, int>(current_node->get_node_word(),
                                                current_node->get_count());
  }
  return node_data;
}

void WordTree::iter_reset(void)
{
  if (_root_node)
  {
    _next_node = leftmost_child(_root_node);
  }
  else
  {
    _next_node = nullptr;
  }
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
