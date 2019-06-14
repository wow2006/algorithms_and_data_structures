#include <gtest/gtest.h>

#include "SinglyLinkedList.hpp"

TEST(SinglyLinkedList, emptyListIsNull) {
  SinglyLinkedList list;

  ASSERT_TRUE(list.m_pRoot == nullptr);
}

TEST(SinglyLinkedList, initializeFromInitializationList) {
  SinglyLinkedList list{1};

  ASSERT_FALSE(list.m_pRoot == nullptr);
  EXPECT_EQ(1, list.m_pRoot->m_iValue);

  ASSERT_TRUE(list.m_pRoot->m_pNext == nullptr);
}

TEST(SinglyLinkedList, initializeFromInitializationList2) {
  SinglyLinkedList list{1, 2};

  ASSERT_FALSE(list.m_pRoot == nullptr);
  EXPECT_EQ(1, list.m_pRoot->m_iValue);

  ASSERT_FALSE(list.m_pRoot->m_pNext == nullptr);
  EXPECT_EQ(2, list.m_pRoot->m_pNext->m_iValue);
}

TEST(SinglyLinkedList, initializeFromInitializationList3) {
  SinglyLinkedList list{1, 2, 3};

  ASSERT_FALSE(list.m_pRoot == nullptr);
  EXPECT_EQ(1, list.m_pRoot->m_iValue);

  ASSERT_FALSE(list.m_pRoot->m_pNext == nullptr);
  EXPECT_EQ(2, list.m_pRoot->m_pNext->m_iValue);

  ASSERT_FALSE(list.m_pRoot->m_pNext->m_pNext == nullptr);
  EXPECT_EQ(3, list.m_pRoot->m_pNext->m_pNext->m_iValue);
}

TEST(SinglyLinkedList, addAValueToEmptyList) {
  SinglyLinkedList list;

  list.add(1);

  ASSERT_FALSE(list.m_pRoot == nullptr);
  EXPECT_EQ(1, list.m_pRoot->m_iValue);
}

TEST(SinglyLinkedList, addTwoValuesToEmptyList) {
  SinglyLinkedList list;

  list.add(1);
  list.add(2);

  ASSERT_FALSE(list.m_pRoot == nullptr);
  EXPECT_EQ(1, list.m_pRoot->m_iValue);
  
  ASSERT_FALSE(list.m_pRoot->m_pNext == nullptr);
  EXPECT_EQ(2, list.m_pRoot->m_pNext->m_iValue);
}

/*
TEST(SinglyLinkedList, addThreeValuesToEmptyList) {
  SinglyLinkedList list;

  list.add(1);
  list.add(2);
  list.add(3);

  ASSERT_FALSE(list.m_pRoot == nullptr);
  EXPECT_EQ(1, list.m_pRoot->m_iValue);
  
  ASSERT_FALSE(list.m_pRoot->m_pNext == nullptr);
  EXPECT_EQ(2, list.m_pRoot->m_pNext->m_iValue);
}
*/

TEST(SinglyLinkedList, getEnd) {
  SinglyLinkedList list;

  ASSERT_TRUE(list.getEnd() == nullptr);
}

TEST(SinglyLinkedList, getEndFromOneItemList) {
  SinglyLinkedList list{1};

  ASSERT_FALSE(list.getEnd() == nullptr);
  EXPECT_EQ(1, list.getEnd()->m_iValue);
}

TEST(SinglyLinkedList, getEndFromTwoItemList) {
  SinglyLinkedList list{1, 2};

  ASSERT_FALSE(list.getEnd() == nullptr);
  EXPECT_EQ(2, list.getEnd()->m_iValue);
}

TEST(SinglyLinkedList, getEndFromThreeItemList) {
  SinglyLinkedList list{1, 2, 3};

  ASSERT_FALSE(list.getEnd() == nullptr);
  EXPECT_EQ(3, list.getEnd()->m_iValue);
}
