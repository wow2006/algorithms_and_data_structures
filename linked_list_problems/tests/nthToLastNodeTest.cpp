#include <GUnit.h>
#include "../nthToLastNode.hpp"

GTEST("Get the last element from linked list") {
  ListNode *pHead = nullptr;
  insert(pHead, 3);
  insert(pHead, 2);
  insert(pHead, 1);
  insert(pHead, 5);

  SHOULD("get value of 4th element from linked list \"5\"") {
    const auto pNode = nthToLastNode(pHead, 1);
    EXPECT_EQ(5, pNode->val);
  }

  SHOULD("get value of 3rd element from linked list \"1\"") {
    const auto pNode = nthToLastNode(pHead, 2);
    EXPECT_EQ(1, pNode->val);
  }

  SHOULD("get value of 2nd element from linked list \"2\"") {
    const auto pNode = nthToLastNode(pHead, 3);
    EXPECT_EQ(2, pNode->val);
  }

  SHOULD("get value of 1st element from linked list \"3\"") {
    const auto pNode = nthToLastNode(pHead, 4);
    EXPECT_EQ(3, pNode->val);
  }

  SHOULD("get print of linked list") {
    auto coutBuffer = std::cout.rdbuf();

    std::stringstream buffer;
    std::cout.rdbuf(buffer.rdbuf());
    iterateList(pHead);
    std::cout.rdbuf(coutBuffer);

    EXPECT_EQ("3-->2-->1-->5-->NULL\n", buffer.str());
  }
}

GTEST("Check boundery") {
  ListNode *pHead = nullptr;
  insert(pHead, 3);
  insert(pHead, 2);
  insert(pHead, 1);
  insert(pHead, 5);

  SHOULD("return null if index = 5") {
    const auto pNode = nthToLastNode(pHead, 5);

    EXPECT_EQ(nullptr, pNode);
    if(pNode != nullptr) {
      std::cout << "Value : " << pNode->val << '\n';
    }
  }

  SHOULD("return null if index = 0") {
    const auto pNode = nthToLastNode(pHead, 0);

    EXPECT_EQ(nullptr, pNode);
  }
}
