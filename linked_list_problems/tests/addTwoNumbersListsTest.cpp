#include <GUnit.h>

#include "../addTwoNumbersLists.hpp"


GTEST("equal") {
  ListNode* pNode1 = nullptr;
  ListNode* pNode2 = nullptr;

  SHOULD("two null equal") {
    EXPECT_TRUE(equal(pNode1, pNode2));
  }

  pNode1 = new ListNode(1);
  SHOULD("\"1\" node and null node not equal") {
    EXPECT_FALSE(equal(pNode1, pNode2));
  }
  delete pNode1;
  pNode1 = nullptr;

  pNode2 = new ListNode(1);
  SHOULD("null node and \"1\" not equal") {
    EXPECT_FALSE(equal(pNode1, pNode2));
  }

  pNode1 = new ListNode(1);
  SHOULD("\"1\" node and \"1\" are equal") {
    EXPECT_TRUE(equal(pNode1, pNode2));
  }

  pNode2->m_iValue = 2;
  SHOULD("\"1\" and \"2\" not equal") {
    EXPECT_FALSE(equal(pNode1, pNode2));
  }

  pNode1->m_iValue = 2;
  SHOULD("\"2\" and \"2\" are equal") {
    EXPECT_TRUE(equal(pNode1, pNode2));
  }

  pNode1->m_pNext = new ListNode(2);
  SHOULD("\"2\" and \"22\" are equal") {
    EXPECT_FALSE(equal(pNode1, pNode2));
  }

  pNode2->m_pNext = new ListNode(2);
  SHOULD("\"22\" and \"22\" are equal") {
    EXPECT_TRUE(equal(pNode1, pNode2));
  }

  pNode1->m_pNext->m_iValue = 3;
  SHOULD("\"23\" and \"22\" are equal") {
    EXPECT_FALSE(equal(pNode1, pNode2));
  }

  delete pNode1;
  delete pNode2;
}

GTEST("99 + 295 = 394") {
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

