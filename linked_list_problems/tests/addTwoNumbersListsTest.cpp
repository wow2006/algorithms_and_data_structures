#include <gtest/gtest.h>

#include "../addTwoNumbersLists.hpp"


TEST(addTwoNumbersLists, equal) {
  ListNode* pNode1 = nullptr;
  ListNode* pNode2 = nullptr;

	EXPECT_TRUE(equal(pNode1, pNode2)) << "two null equal";

  pNode1 = new ListNode(1);
	EXPECT_FALSE(equal(pNode1, pNode2)) << "\"1\" node and null node not equal";
  delete pNode1;
  pNode1 = nullptr;

  pNode2 = new ListNode(1);
	EXPECT_FALSE(equal(pNode1, pNode2)) << "null node and \"1\" not equal";

  pNode1 = new ListNode(1);
	EXPECT_TRUE(equal(pNode1, pNode2)) << "\"1\" node and \"1\" are equal";

  pNode2->m_iValue = 2;
	EXPECT_FALSE(equal(pNode1, pNode2)) << "\"1\" and \"2\" not equal";

  pNode1->m_iValue = 2;
	EXPECT_TRUE(equal(pNode1, pNode2)) << "\"2\" and \"2\" are equal";

  pNode1->m_pNext = new ListNode(2);
	EXPECT_FALSE(equal(pNode1, pNode2)) << "\"2\" and \"22\" are equal";

  pNode2->m_pNext = new ListNode(2);
	EXPECT_TRUE(equal(pNode1, pNode2)) << "\"22\" and \"22\" are equal";

  pNode1->m_pNext->m_iValue = 3;
	EXPECT_FALSE(equal(pNode1, pNode2)) << "\"23\" and \"22\" are equal";

  delete pNode1;
  delete pNode2;
}

TEST(addTwoNumberListsTest, largeNumber) {
	std::cout << "99+295=394" << '\n';
  auto pList1 = new ListNode(9);
  pList1->m_pNext = new ListNode(9);

  auto pList2 = new ListNode(5);
  pList2->m_pNext = new ListNode(9);
  pList2->m_pNext->m_pNext = new ListNode(2);

  iterate(pList1);
  iterate(pList2);

  auto pList3 = addLists(pList1, pList2);
  iterate(pList3);
}
