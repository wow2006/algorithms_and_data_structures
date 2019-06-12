#include <gtest/gtest.h>

#include "SinglyLinkedList.hpp"

TEST(SinglyLinkedList, emptyListIsNull) {
  LinkedList list;

  ASSERT_TRUE(list.m_pRoot == nullptr);
}

TEST(SinglyLinkedList, initializeFromInitializationList) {
  LinkedList list{1};

  ASSERT_FALSE(list.m_pRoot == nullptr);
  EXPECT_EQ(1, list.m_pRoot->m_iValue);

  ASSERT_TRUE(list.m_pRoot->m_pNext == nullptr);
}

TEST(SinglyLinkedList, initializeFromInitializationList2) {
  LinkedList list{1, 2};

  ASSERT_FALSE(list.m_pRoot == nullptr);
  EXPECT_EQ(1, list.m_pRoot->m_iValue);

  ASSERT_FALSE(list.m_pRoot->m_pNext == nullptr);
  EXPECT_EQ(2, list.m_pRoot->m_pNext->m_iValue);
}

TEST(SinglyLinkedList, initializeFromInitializationList3) {
  LinkedList list{1, 2, 3};

  EXPECT_FALSE(list.m_pRoot == nullptr);
  EXPECT_EQ(1, list.m_pRoot->m_iValue);

  EXPECT_FALSE(list.m_pRoot->m_pNext == nullptr);
  EXPECT_EQ(2, list.m_pRoot->m_pNext->m_iValue);

  EXPECT_FALSE(list.m_pRoot->m_pNext->m_pNext == nullptr);
  //EXPECT_EQ(3, list.m_pRoot->m_pNext->m_pNext->m_iValue);
}
