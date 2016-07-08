/// WordTreeNode Header File
/// A non-balancing binary tree
/// Note that WordTreeNodes should be created on the heap
/// TJW2

#ifndef WORD_TREE_NODE_H
#define WORD_TREE_NODE_H

class WordTreeNode;

#include <string>

class WordTreeNode
{
  private:

    std::string _node_word;
    int _count;

    //Pointer to the WordTreeNode on the left branch of this one
    WordTreeNode* _l_branch;
    //Pointer to the WordTreeNode on the right branch of this one
    WordTreeNode* _r_branch;

  public:

    enum BRANCH_TYPE {LEFT, RIGHT};

    WordTreeNode(std::string node_word);

    std::string get_node_word(void);
    void set_node_word(std::string node_word);

    int get_count(void);
    void set_count(int count);
    void increment_count(void);

    WordTreeNode* get_branch(BRANCH_TYPE branch);
    void set_branch(BRANCH_TYPE branch, WordTreeNode* node);

    std::string to_string(void);

    //Recursively writes _node_word and _count to the given stream
    void write_data(std::ostream* data_stream_ptr);

    //Recursively destroys the children of this WordTreeNode
    ~WordTreeNode(void);
};

#endif
