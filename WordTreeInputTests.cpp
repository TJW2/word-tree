/// WordTreeInput Tests using Google Test
/// TJW2

#include "WordTreeInput.h"
#include "MockWordTree.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
using ::testing::Return;

TEST(WordTreeInput, RealSingleInput)
{
  std::string file_path = "test-files/test-single-word.txt";
  EXPECT_EQ(most_common_word_from_file(file_path), "A");
  EXPECT_EQ(count_of_most_common_word_from_file(file_path), 1);
}

TEST(WordTreeInput, MockSingleInput)
{
  std::string file_path = "test-files/test-single-word.txt";
  std::pair<std::string, int> iter_result("M",2);
  MockWordTree mock_tree;

  EXPECT_CALL(mock_tree, add_word("A")).Times(1);
  add_to_tree_from_file(mock_tree, file_path);

  EXPECT_CALL(mock_tree, iter_reset()).Times(1);
  EXPECT_CALL(mock_tree,
              iter_next()).WillOnce(Return(&iter_result))
                          .WillOnce(Return(nullptr));
  EXPECT_EQ(most_common_word(mock_tree), iter_result.first);
}

TEST(WordTreeInput, RealBasicInput)
{
  std::string file_path = "test-files/test-1.txt";
  EXPECT_EQ(most_common_word_from_file(file_path), "C");
  EXPECT_EQ(count_of_most_common_word_from_file(file_path), 2);
}

TEST(WordTreeInput, RealRepeatedInput)
{
  std::string file_path = "test-files/test-2.txt";
  EXPECT_EQ(most_common_word_from_file(file_path), "A");
  EXPECT_EQ(count_of_most_common_word_from_file(file_path),2);
}

TEST(WordTreeInput, RealEmptyInput)
{
  std::string file_path = "test-files/test-3.txt";
  EXPECT_ANY_THROW(most_common_word_from_file(file_path));
  EXPECT_ANY_THROW(count_of_most_common_word_from_file(file_path));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}
