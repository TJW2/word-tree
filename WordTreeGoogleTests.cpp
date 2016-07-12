/// WordTree and WordTreeNode Tests using Google Test
/// TJW2

#include "WordTree.h"
#include "gtest/gtest.h"

std::string main_test_node_name = "MainTestNode";
std::string main_test_node_name_change = "MainTestNodeChange";
std::string left_test_node_name = "LeftTestNode";
std::string right_test_node_name = "RightTestNode";

int default_count = 1;
int change_count = 2;

WordTreeNode* default_l_branch = NULL;
WordTreeNode* default_r_branch = NULL;

class WordTreeNodeTest : public ::testing::Test
{
  public:
    WordTreeNode* main_test_node;
    WordTreeNode* left_test_node;
    WordTreeNode* right_test_node;

    WordTreeNodeTest()
    {
      main_test_node = new WordTreeNode(main_test_node_name,
                                        WordTreeNode::LEFT, NULL);
      left_test_node = new WordTreeNode(left_test_node_name,
                                        WordTreeNode::LEFT, NULL);
      right_test_node = new WordTreeNode(right_test_node_name,
                                         WordTreeNode::RIGHT, NULL);
    }
};

TEST(WordTreeNode, Constructor) {
  WordTreeNode* main_test_node =
    new WordTreeNode(main_test_node_name, WordTreeNode::LEFT, NULL);
  EXPECT_EQ(main_test_node->get_node_word(), main_test_node_name);
  EXPECT_EQ(main_test_node->get_count(), default_count);
  EXPECT_EQ(main_test_node->get_branch(WordTreeNode::LEFT), default_l_branch);
  EXPECT_EQ(main_test_node->get_branch(WordTreeNode::RIGHT), default_r_branch);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
