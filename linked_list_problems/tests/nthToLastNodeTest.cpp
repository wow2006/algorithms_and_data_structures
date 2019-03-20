#include <gtest/gtest.h>
#include "../nthToLastNode.hpp"

TEST(a, b) {
	std::cout << "Get the last element from linked list" << '\n';
  ListNode *pHead = nullptr;
  insert(pHead, 3);
  insert(pHead, 2);
  insert(pHead, 1);
  insert(pHead, 5);

	ListNode *pNode = nthToLastNode(pHead, 1);
	EXPECT_EQ(5, pNode->val);// << "get value of 4th element from linked list \"5\"";

	pNode = nthToLastNode(pHead, 2);
	EXPECT_EQ(1, pNode->val);// << "get value of 3rd element from linked list \"1\"";

	pNode = nthToLastNode(pHead, 3);
	EXPECT_EQ(2, pNode->val);// << "get value of 2nd element from linked list \"2\"";

	pNode = nthToLastNode(pHead, 4);
	EXPECT_EQ(3, pNode->val);// << "get value of 1st element from linked list \"3\"";

  auto coutBuffer = std::cout.rdbuf();

  std::stringstream buffer;
  std::cout.rdbuf(buffer.rdbuf());
  iterateList(pHead);
  std::cout.rdbuf(coutBuffer);

	EXPECT_EQ("3-->2-->1-->5-->NULL\n", buffer.str());// << "get print of linked list";
}

TEST(c, d) {
  ListNode *pHead = nullptr;
  insert(pHead, 3);
  insert(pHead, 2);
  insert(pHead, 1);
  insert(pHead, 5);

	ListNode *pNode = nthToLastNode(pHead, 5);

	EXPECT_EQ(nullptr, pNode) << "return null if index = 5";
  if(pNode != nullptr) {
    std::cout << "Value : " << pNode->val << '\n';
  }

	pNode = nthToLastNode(pHead, 0);

	EXPECT_EQ(nullptr, pNode) << "return null if index = 0";
}
