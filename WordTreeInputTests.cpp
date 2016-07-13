/// WordTreeInput Tests using Google Test
/// TJW2

#include "WordTreeInput.h"
#include "MockWordTree.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(WordTreeInput, RealSingleInput)
{
  std::string file_path = "test-files/test-0.txt";
  EXPECT_EQ(most_common_word_from_file(file_path), "A");
  EXPECT_EQ(count_of_most_common_word_from_file(file_path), 1);
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
