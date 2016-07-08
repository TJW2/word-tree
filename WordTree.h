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
    WordTreeNode* _next_node;
    bool pass_word(std::string word, WordTreeNode*& current_node,
                   WordTreeNode::BRANCH_TYPE pass_direction);
    // Deletes the given node from the tree, but not its children. Assumes that
    // the node is in the tree.
    void delete_node(WordTreeNode* node);

  public:

    WordTree(void);

    void add_word(std::string word);

    WordTreeNode* iter_next(void);
    void iter_reset(void);

    bool is_word_in_tree(std::string word);
    // If the given word lies in the tree, deletes it and returns true. Returns
    // false otherwise.
    bool delete_word(std::string word);

    void write_data(std::ostream* data_stream_ptr);

    ~WordTree(void);
};

#endif
