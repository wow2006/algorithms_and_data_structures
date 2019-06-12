#include <gtest/gtest.h>

#include "SinglyLinkedList.hpp"

TEST(SinglyLinkedList, emptyListIsNull) {
  LinkedList list;

  EXPECT_TRUE(list.m_pRoot == nullptr);
}

TEST(SinglyLinkedList, initializeFromInitializationList) {
  LinkedList list{1};

  EXPECT_FALSE(list.m_pRoot == nullptr);
  EXPECT_EQ(1, list.m_pRoot->m_iValue);

  EXPECT_TRUE(list.m_pRoot->m_pNext == nullptr);
}

TEST(SinglyLinkedList, initializeFromInitializationList2) {
  LinkedList list{1, 2};

  EXPECT_FALSE(list.m_pRoot == nullptr);
  EXPECT_EQ(1, list.m_pRoot->m_iValue);

  EXPECT_FALSE(list.m_pRoot->m_pNext == nullptr);
}

