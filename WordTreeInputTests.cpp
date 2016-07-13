/// WordTreeInput Tests using Google Test
/// TJW2

#include "WordTreeInput.h"
#include "gtest/gtest.h"

TEST(WordTreeInput, BasicInput)
{
  std::string file_path = "test-files/test-1.txt";
  EXPECT_EQ(most_common_word_from_file(file_path), "C");
  EXPECT_EQ(count_of_most_common_word_from_file(file_path), 2);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
