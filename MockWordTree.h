/// Mock WordTree Object
/// TJW2

#include "WordTree.h"
#include "gmock/gmock.h"

class MockWordTree : public WordTree
{
  public:
    MOCK_METHOD1(add_word, void(std::string word));
    MOCK_METHOD0(iter_next, std::pair<std::string, int>*());
    MOCK_METHOD0(iter_reset, void());
};
