/// Unit Tests for WordTreeNode
/// TJW2

#include <string>
#include <iostream>
#include "WordTreeNode.h"

bool run_automated_tests(void);
void test_helper(bool test_result, std::string test_name, bool* tests_passed_ptr);
bool run_to_string_tests(void);
bool run_write_data_tests(void);

std::string main_test_node_name = "MainTestNode";
std::string main_test_node_name_change = "MainTestNodeChange";
std::string left_test_node_name = "LeftTestNode";
std::string right_test_node_name = "RightTestNode";
std::string destructor_test_node_name = "DestructorTestNode";
int default_count = 1;
int change_count = 2;
WordTreeNode* default_l_branch = NULL;
WordTreeNode* default_r_branch = NULL;

bool run_automated_tests(void)
{
  std::string pass_msg = "Test passed: ";
  std::string fail_msg = "Test failed: ";

  std::string test_name;

  bool tests_passed = true;
  try
  {
    //Constructor Tests
    WordTreeNode* main_test_node = new WordTreeNode(main_test_node_name,
                                                    WordTreeNode::LEFT,
                                                    NULL);
    test_helper(main_test_node->get_node_word() == main_test_node_name,
             "Constructor setting _node_word", &tests_passed);
    test_helper(main_test_node->get_count() == default_count,
             "Constructor setting _count", &tests_passed);
    test_helper(main_test_node->get_branch(WordTreeNode::LEFT) == default_l_branch,
             "Constructor setting _l_branch", &tests_passed);
    test_helper(main_test_node->get_branch(WordTreeNode::RIGHT) == default_r_branch,
             "Constructor setting _r_branch", &tests_passed);
    test_helper(main_test_node->get_branch_type() == WordTreeNode::LEFT,
             "Constructor setting _branch_type", &tests_passed);
    test_helper(!(main_test_node->get_parent_node()),
             "Constructor setting _parent_node", &tests_passed);

    //Basic Setter Tests
    main_test_node->set_node_word(main_test_node_name_change);
    test_helper(main_test_node->get_node_word() == main_test_node_name_change,
             "Setter for _node_word", &tests_passed);
    main_test_node->set_count(change_count);
    test_helper(main_test_node->get_count() == change_count,
             "Setter for _count", &tests_passed);
    main_test_node->increment_count();
    test_helper(main_test_node->get_count() == change_count + 1,
             "Incrementer for _count", &tests_passed);

    //Branch Setter Tests
    WordTreeNode* left_test_node = new WordTreeNode(left_test_node_name,
                                                    WordTreeNode::LEFT,
                                                    NULL);
    main_test_node->set_branch(WordTreeNode::LEFT, left_test_node);
    test_helper(main_test_node->get_branch(WordTreeNode::LEFT) == left_test_node,
             "Setter for _l_branch", &tests_passed);
    WordTreeNode* right_test_node = new WordTreeNode(right_test_node_name,
                                                     WordTreeNode::RIGHT,
                                                     main_test_node);
    main_test_node->set_branch(WordTreeNode::RIGHT, right_test_node);
    test_helper(main_test_node->get_branch(WordTreeNode::RIGHT) == right_test_node,
             "Setter for _r_branch", &tests_passed);

    //Branch Type and Parent Node Tests
    main_test_node->set_branch_type(WordTreeNode::RIGHT);
    test_helper(main_test_node->get_branch_type() == WordTreeNode::RIGHT,
             "Setter for _branch_type", &tests_passed);
    left_test_node->set_parent_node(main_test_node);
    test_helper(left_test_node->get_parent_node() == main_test_node,
              "Setter for _parent_node", &tests_passed);


    //Destructor Test
    delete main_test_node;
  }
  catch (const char* string_exception)
  {
    std::cout << string_exception << std::endl;
    tests_passed = false;
  }
  catch (...)
  {
    std::cout << "Exception caught." << std::endl;
    tests_passed = false;
  }
  return tests_passed;
}

void test_helper(bool test_result, std::string test_name, bool* tests_passed_ptr)
{
  std::cout << (test_result ? "Test passed: " : "Test failed: ");
  std::cout << test_name << std::endl;
  *tests_passed_ptr = *tests_passed_ptr && test_result;
}

bool run_to_string_tests()
{
  bool tests_passed = true;
  try
  {
    //Initialisation
    WordTreeNode* main_test_node = new WordTreeNode(main_test_node_name,
                                                    WordTreeNode::LEFT,
                                                    NULL);
    WordTreeNode* left_test_node = new WordTreeNode(left_test_node_name,
                                                    WordTreeNode::LEFT,
                                                    main_test_node);
    left_test_node->set_count(change_count);
    WordTreeNode* right_test_node = new WordTreeNode(right_test_node_name,
                                                     WordTreeNode::RIGHT,
                                                     main_test_node);
    right_test_node->set_count(change_count);
    right_test_node->increment_count();

    //Tests
    std::cout << "Testing to_string method, both branches null: ";
    std::cout << std::endl;
    std::cout << main_test_node->to_string() << std::endl;


    std::cout << "Testing to_string method, right branch null: ";
    std::cout << std::endl;
    main_test_node->set_branch(WordTreeNode::LEFT, left_test_node);
    std::cout << main_test_node->to_string() << std::endl;

    std::cout << "Testing to_string method, both branches not null: ";
    std::cout << std::endl;
    main_test_node->set_branch(WordTreeNode::RIGHT, right_test_node);
    std::cout << main_test_node->to_string() << std::endl;

    std::cout << "Testing to_string method, left branch null: ";
    std::cout << std::endl;
    main_test_node->set_branch(WordTreeNode::LEFT, NULL);
    std::cout << main_test_node->to_string() << std::endl;

    //Destruction
    delete main_test_node;
  }
  catch (const char* string_exception)
  {
    std::cout << string_exception << std::endl;
    tests_passed = false;
  }
  catch (...)
  {
    std::cout << "Exception caught." << std::endl;
    tests_passed = false;
  }
  return tests_passed;
}

bool run_write_data_tests()
{
  bool tests_passed = true;
  try
  {
    //Initialisation
    WordTreeNode* main_test_node = new WordTreeNode(main_test_node_name,
                                                    WordTreeNode::LEFT,
                                                    NULL);
    WordTreeNode* left_test_node = new WordTreeNode(left_test_node_name,
                                                    WordTreeNode::LEFT,
                                                    main_test_node);
    left_test_node->set_count(change_count);
    WordTreeNode* right_test_node = new WordTreeNode(right_test_node_name,
                                                     WordTreeNode::RIGHT,
                                                     main_test_node);
    right_test_node->set_count(change_count);
    right_test_node->increment_count();

    //Tests
    std::cout << "Testing write_data method, both branches null: ";
    std::cout << std::endl;
    main_test_node->write_data(&std::cout);

    std::cout << "Testing write_data method, right branch null: ";
    std::cout << std::endl;
    main_test_node->set_branch(WordTreeNode::LEFT, left_test_node);
    main_test_node->write_data(&std::cout);

    std::cout << "Testing write_data method, both branches not null: ";
    std::cout << std::endl;
    main_test_node->set_branch(WordTreeNode::RIGHT, right_test_node);
    main_test_node->write_data(&std::cout);

    std::cout << "Testing write_data method, left branch null: ";
    std::cout << std::endl;
    main_test_node->set_branch(WordTreeNode::LEFT, NULL);
    main_test_node->write_data(&std::cout);

    //Destruction
    delete main_test_node;
  }
  catch (const char* string_exception)
  {
    std::cout << string_exception << std::endl;
    tests_passed = false;
  }
  catch (...)
  {
    std::cout << "Exception caught." << std::endl;
    tests_passed = false;
  }
  return tests_passed;
}

int main(void)
{
  if (run_automated_tests())
  {
    std::cout << "Automated tests passed." << std::endl;
  }
  else
  {
    std::cout << "Automated tests failed." << std::endl;
  }

  if (run_to_string_tests())
  {
    std::cout << "to_string tests passed." << std::endl;
  }
  else
  {
    std::cout << "to_string tests failed." << std::endl;
  }

  if (run_write_data_tests())
  {
    std::cout << "write_data tests passed." << std::endl;
  }
  else
  {
    std::cout << "write_data tests failed." << std::endl;
  }

  return 0;
}
