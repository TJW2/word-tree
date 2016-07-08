/// A non-balancing binary tree
/// TJW2

#ifndef WORD_TREE_H
#define WORD_TREE_H

#include <string>
#include "WordTreeNode.h"

class WordTree
{
  private:

    WordTreeNode* _root_node;
    bool pass_word(std::string word, WordTreeNode*& current_node,
                   WordTreeNode::BRANCH_TYPE pass_direction);

  public:

    WordTree(void);
    void add_word(std::string word);
    void write_data(std::ostream* data_stream_ptr);
    ~WordTree(void);
};

#endif
