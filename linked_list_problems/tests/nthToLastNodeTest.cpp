#include <GUnit.h>
#include "../nthToLastNode.hpp"


GTEST("Get the last element from linked list") {
	ListNode *head = nullptr;
	insert(head, 3);
	insert(head, 2);
	insert(head, 1);
	insert(head, 5);

  SHOULD("get value of last element from linked list \"1\"") {
    const auto pNthNodeToLastNode = nthToLastNode(head, 2);
    EXPECT_EQ(1, pNthNodeToLastNode->val);
  }

  SHOULD("get print of linked list") {
    auto coutBuffer = std::cout.rdbuf();

    std::stringstream buffer;
    std::cout.rdbuf(buffer.rdbuf());
    iterateList(head);
    std::cout.rdbuf(coutBuffer);

    EXPECT_EQ("3-->2-->1-->5-->NULL\n", buffer.str());
  }
}
