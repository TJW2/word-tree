/// A non-balancing binary tree
/// TJW2

#ifndef WORD_TREE_H
#define WORD_TREE_H

#include <string>
#include <tuple>
#include "WordTreeNode.h"

class WordTree
{
  private:

    WordTreeNode* _root_node;
    WordTreeNode* _next_node;
    bool pass_word(std::string word, WordTreeNode*& current_node,
                   WordTreeNode::BRANCH_TYPE pass_direction);
    // Returns the leftmost leaf of the given node, and the node itself if it
    // has no left child
    WordTreeNode* leftmost_child(WordTreeNode* node);
    //Returns the first LEFT-type ancestor of the given node encountered when
    //traversing the tree from the given node to the root
    WordTreeNode* first_left_ancestor(WordTreeNode* node);
    // Returns the node that follows the given node in the tree
    WordTreeNode* find_next_node(WordTreeNode* node);
    // Deletes the given node from the tree, but not its children. Assumes that
    // the node is in the tree
    void delete_node(WordTreeNode* node);

  public:

    WordTree(void);

    virtual void add_word(std::string word);

    // Returns the next node in the current iteration
    virtual std::pair<std::string, int>* iter_next(void);
    //Resets the iteration to the first node in the tree
    virtual void iter_reset(void);

    bool is_word_in_tree(std::string word);
    // If the given word lies in the tree, deletes it and returns true. Returns
    // false otherwise.
    bool delete_word(std::string word);

    void write_data(std::ostream* data_stream_ptr);

    virtual ~WordTree(void);
};

#endif
