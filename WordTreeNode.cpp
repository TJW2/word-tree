/// WordTreeNode Source File
/// A non-balancing binary tree
/// TJW2

#include <string>
#include <sstream>
#include "WordTreeNode.h"

WordTreeNode::WordTreeNode(std::string node_word, BRANCH_TYPE branch_type,
                           WordTreeNode* parent_node):
  _node_word(node_word),
  _branch_type(branch_type),
  _parent_node(parent_node),
  _count(0),
  _l_branch(NULL),
  _r_branch(NULL)
{
  increment_count();
}

std::string WordTreeNode::get_node_word(void)
{
  return _node_word;
}

void WordTreeNode::set_node_word(std::string node_word)
{
  _node_word = node_word;
}

int WordTreeNode::get_count(void)
{
  return _count;
}

void WordTreeNode::set_count(int count)
{
  _count = count;
}

void WordTreeNode::increment_count(void)
{
  set_count(get_count() + 1);
}

WordTreeNode::BRANCH_TYPE WordTreeNode::get_branch_type(void)
{
  return _branch_type;
}

void WordTreeNode::set_branch_type(BRANCH_TYPE branch_type)
{
  _branch_type = branch_type;
}

WordTreeNode* WordTreeNode::get_parent_node(void)
{
  return _parent_node;
}

void WordTreeNode::set_parent_node(WordTreeNode* parent_node)
{
  _parent_node = parent_node;
}

WordTreeNode* WordTreeNode::get_branch(BRANCH_TYPE branch)
{
  switch(branch)
  {
    case LEFT:
      return _l_branch;
    case RIGHT:
      return _r_branch;
    default:
      throw "Unexpected branch type";
  }
}

void WordTreeNode::set_branch(BRANCH_TYPE branch, WordTreeNode* node)
{
  switch(branch)
  {
    case LEFT:
      _l_branch = node;
      break;
    case RIGHT:
      _r_branch = node;
      break;
    default:
      throw "Unexpected branch type";
  }

}

///Creates a string representation of the WordTreeNode in the following form:
/// "_node_word: <_node_word>
///  _count: <_count>
///  _l_branch: <_l_branch>
///  _r_branch: <_r_branch>"
std::string WordTreeNode::to_string(void)
{
  std::ostringstream os;
  os << "_node_word: " << get_node_word() << std::endl;
  os << "_count: " << get_count() << std::endl;
  os << "_branch_type: " << get_branch_type() << std::endl;
  os << "_l_branch: " << (get_branch(LEFT) ?
                          get_branch(LEFT)->get_node_word() :
                          "NULL ")
     << std::endl;
  os << "_r_branch: " << (get_branch(RIGHT) ?
                          get_branch(RIGHT)->get_node_word() :
                          "NULL ")
     << std::endl;
  os << "_parent_node: " << (get_parent_node() ?
                             get_parent_node()->get_node_word() :
                             "NULL ")
     << std::endl;
  return os.str();
}

///Writes _node_word and _count to the given stream
void WordTreeNode::write_data(std::ostream* data_stream_ptr)
{
  if (get_branch(LEFT))
  {
    get_branch(LEFT)->write_data(data_stream_ptr);
  }
  *data_stream_ptr << get_node_word() << ", " << get_count() << std::endl;
  if (get_branch(RIGHT))
  {
    get_branch(RIGHT)->write_data(data_stream_ptr);
  }
}

///Recursively destroys the children of the WordTreeNode
WordTreeNode::~WordTreeNode()
{
  delete _l_branch;
  delete _r_branch;
}
