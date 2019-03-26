#include <gtest/gtest.h>

#include "nthToLastNode.hpp"

void swapNodes(LinkedList::Node *pFirst, LinkedList::Node *pSecond) {
  auto pNode = pFirst->m_pNext;
  pFirst->m_pNext  = pSecond->m_pNext;
  pSecond->m_pNext = pNode;

  pNode = pSecond->m_pNext->m_pNext;
  pSecond->m_pNext->m_pNext = pFirst->m_pNext->m_pNext;
  pFirst->m_pNext->m_pNext = pNode;
}

bool swap(LinkedList &a, uint firstIndex, uint secondIndex) {
  if (a.m_pHead == nullptr) {
    return false;
  }

  LinkedList::Node *pNode  = a.m_pHead;
  LinkedList::Node *pFirst  = nullptr;
  LinkedList::Node *pSecond = nullptr;
  if(0 == firstIndex) {
    pFirst = pNode;
  } else if(0 == secondIndex) {
    pSecond = pNode;
  }

  unsigned int currentIndex = 1;
  while(pNode->m_pNext != nullptr) {
    if(currentIndex == firstIndex) {
      pFirst = pNode;
    } else if(currentIndex == secondIndex) {
      pSecond = pNode;
    }
    pNode = pNode->m_pNext;
    ++currentIndex;
  }

  if(0 == firstIndex) {
    a.m_pHead = pSecond->m_pNext;
    pSecond->m_pNext = pFirst;

    pNode = a.m_pHead->m_pNext;
    a.m_pHead->m_pNext = pFirst->m_pNext;
    pFirst->m_pNext = pNode;
  } else if(0 == secondIndex) {
    a.m_pHead = pFirst->m_pNext;
    pFirst->m_pNext = pSecond;

    pNode = a.m_pHead->m_pNext;
    a.m_pHead->m_pNext = pSecond->m_pNext;
    pSecond->m_pNext = pNode;
  } else {
    swapNodes(pFirst, pSecond);
  }

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

TEST(SwapNodes, LinkedListSwapSecondAndFourth) {
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

TEST(SwapNodes, LinkedListSwapFirstAndThird) {
  LinkedList data;
  data.add(0); // Swap with 3
  data.add(1);
  data.add(2);
  data.add(3); // Swap with 0
  data.add(4);
  data.add(5);

  EXPECT_TRUE(swap(data, 0, 3));
  EXPECT_EQ(3, data.find(0)->m_iValue);
  EXPECT_EQ(0, data.find(3)->m_iValue);
}

TEST(SwapNodes, LinkedListSwapFirstAndThird2) {
  LinkedList data;
  data.add(0); // Swap with 3
  data.add(1);
  data.add(2);
  data.add(3); // Swap with 0
  data.add(4);
  data.add(5);

  EXPECT_TRUE(swap(data, 3, 0));
  EXPECT_EQ(3, data.find(0)->m_iValue);
  EXPECT_EQ(0, data.find(3)->m_iValue);
}

TEST(SwapNodes, LinkedListSwapLastAndThird) {
  LinkedList data;
  data.add(0);
  data.add(1);
  data.add(2);
  data.add(3); // Swap with 5
  data.add(4);
  data.add(5); // Swap with 3

  EXPECT_TRUE(swap(data, 3, 5));
  EXPECT_EQ(3, data.find(5)->m_iValue);
  EXPECT_EQ(5, data.find(3)->m_iValue);
}
