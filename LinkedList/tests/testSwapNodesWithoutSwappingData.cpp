#include <gtest/gtest.h>

#include "nthToLastNode.hpp"


bool swap(LinkedList &a, uint firstIndex, uint secondIndex) {
  if (a.m_pHead == nullptr) {
    return false;
  }

  unsigned int currentIndex = 1;
  LinkedList::Node *pNode  = a.m_pHead;
  LinkedList::Node *pFirst  = nullptr;
  LinkedList::Node *pSecond = nullptr;
  while(pNode->m_pNext != nullptr) {
    if(currentIndex == firstIndex) {
      pFirst = pNode;
    } else if(currentIndex == secondIndex) {
      pSecond = pNode;
    }
    pNode = pNode->m_pNext;
    ++currentIndex;
  }

  pNode = pFirst->m_pNext;
  pFirst->m_pNext  = pSecond->m_pNext;
  pSecond->m_pNext = pNode;

  pNode = pSecond->m_pNext->m_pNext;
  pSecond->m_pNext->m_pNext = pFirst->m_pNext->m_pNext;
  pFirst->m_pNext->m_pNext = pNode;

  return true;
}

TEST(SwapNodes, LinkedListIsEmpty) {
  LinkedList data;

  EXPECT_FALSE(swap(data, 1, 3));
}

// TEST(SwapNodes, LinkedListSwapFirstAndSecond) {
//  LinkedList data;
//  data.add(1);
//  data.add(2);
//  data.add(3);
//
//  EXPECT_TRUE(swap(data, 0, 1));
//  EXPECT_EQ(2, data.m_pHead->m_iValue);
//  EXPECT_EQ(1, data.m_pHead->m_pNext->m_iValue);
//}

TEST(SwapNodes, LinkedListSwapSecondAndThird) {
  LinkedList data;
  data.add(0);
  data.add(1);
  data.add(2); // Swap with 4
  data.add(3);
  data.add(4); // Swap with 2
  data.add(5);

  EXPECT_TRUE(swap(data, 2, 4));
  EXPECT_EQ(1, data.find(1)->m_iValue);
  EXPECT_EQ(4, data.find(2)->m_iValue);
  EXPECT_EQ(3, data.find(3)->m_iValue);
  EXPECT_EQ(2, data.find(4)->m_iValue);
  EXPECT_EQ(5, data.find(5)->m_iValue);
}
