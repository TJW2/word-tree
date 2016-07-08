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
  public:

    enum BRANCH_TYPE {LEFT, RIGHT};

  private:

    std::string _node_word;
    BRANCH_TYPE _branch_type;
    WordTreeNode* _parent_node;

    int _count;

    //Pointer to the WordTreeNode on the left branch of this one
    WordTreeNode* _l_branch;
    //Pointer to the WordTreeNode on the right branch of this one
    WordTreeNode* _r_branch;

  public:

    WordTreeNode(std::string node_word, BRANCH_TYPE branch_type,
                 WordTreeNode* parent_node);

    std::string get_node_word(void);
    void set_node_word(std::string node_word);

    int get_count(void);
    void set_count(int count);
    void increment_count(void);

    BRANCH_TYPE get_branch_type(void);
    void set_branch_type(BRANCH_TYPE branch_type);

    WordTreeNode* get_parent_node(void);
    void set_parent_node(WordTreeNode* parent_node);

    WordTreeNode* get_branch(BRANCH_TYPE branch);
    void set_branch(BRANCH_TYPE branch, WordTreeNode* node);

    std::string to_string(void);

    //Recursively writes _node_word and _count to the given stream
    void write_data(std::ostream* data_stream_ptr);

    //Recursively destroys the children of this WordTreeNode
    ~WordTreeNode(void);
};

#endif
