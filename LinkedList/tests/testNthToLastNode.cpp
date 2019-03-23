#include <array>

#include <gtest/gtest.h>
#include "nthToLastNode.hpp"
/*
 * Program:
 * -------
 *  Create Linked list store 1 -> 2 -> 3 -> 4
 *  get nth node from last node
 *
 */

TEST(LinkedListCreate, HeadIsNullptr) {
  LinkedList linkedList;

  ASSERT_EQ(nullptr, linkedList.m_pHead);
}

TEST(LinkedListCreate, CreateOneNodeWithOneValue) {
  constexpr int value = 1;
  LinkedList linkedList;
  linkedList.add(value);

  ASSERT_NE(nullptr, linkedList.m_pHead);
  EXPECT_EQ(value, linkedList.m_pHead->m_iValue);
}

TEST(LinkedListCreate, CreateOneNodeWithTwoValue) {
  constexpr int value = 2;
  LinkedList linkedList;
  linkedList.add(value);

  ASSERT_NE(nullptr, linkedList.m_pHead);
  EXPECT_EQ(value, linkedList.m_pHead->m_iValue);
}

TEST(LinkedListCreate, CreateOneNodeWithThreeValue) {
  constexpr int value = 3;
  LinkedList linkedList;
  linkedList.add(value);

  ASSERT_NE(nullptr, linkedList.m_pHead);
  EXPECT_EQ(value, linkedList.m_pHead->m_iValue);
}

TEST(LinkedListCreate, CreateOneNodeAndCheckNextPtr) {
  constexpr int value = 1;
  LinkedList linkedList;
  linkedList.add(value);

  ASSERT_NE(nullptr, linkedList.m_pHead);
  EXPECT_EQ(nullptr, linkedList.m_pHead->m_pNext);
}

TEST(LinkedListCreate, CreateTwoNodeWithOneValue) {
  constexpr int value = 1;
  LinkedList linkedList;
  linkedList.add(value);
  linkedList.add(value);

  ASSERT_NE(nullptr, linkedList.m_pHead);
  EXPECT_EQ(1, linkedList.m_pHead->m_iValue);
  ASSERT_NE(nullptr, linkedList.m_pHead->m_pNext);
  EXPECT_EQ(1, linkedList.m_pHead->m_pNext->m_iValue);
  ASSERT_EQ(nullptr, linkedList.m_pHead->m_pNext->m_pNext);
}

TEST(LinkedListCreate, CreateTwoNodeFromArray) {
  constexpr std::array<int, 2> aValues = {1, 2};
  LinkedList linkedList;
  for(int value : aValues) {
    linkedList.add(value);
  }

  ASSERT_NE(nullptr, linkedList.m_pHead);
  EXPECT_EQ(1, linkedList.m_pHead->m_iValue);
  ASSERT_NE(nullptr, linkedList.m_pHead->m_pNext);
  EXPECT_EQ(2, linkedList.m_pHead->m_pNext->m_iValue);
  ASSERT_EQ(nullptr, linkedList.m_pHead->m_pNext->m_pNext);
}

TEST(LinkedListCreate, CreateTwoNodeFromArray3) {
  constexpr std::array<int, 3> aValues = {1, 2, 3};
  LinkedList linkedList;
  for(int value : aValues) {
    linkedList.add(value);
  }

  ASSERT_NE(nullptr, linkedList.m_pHead);
  EXPECT_EQ(1, linkedList.m_pHead->m_iValue);
  ASSERT_NE(nullptr, linkedList.m_pHead->m_pNext);
  EXPECT_EQ(2, linkedList.m_pHead->m_pNext->m_iValue);
  ASSERT_NE(nullptr, linkedList.m_pHead->m_pNext->m_pNext);
  EXPECT_EQ(3, linkedList.m_pHead->m_pNext->m_pNext->m_iValue);
  ASSERT_EQ(nullptr, linkedList.m_pHead->m_pNext->m_pNext->m_pNext);
}

TEST(LinkedList, 2thToLastNode) {
  constexpr std::array<int, 3> aValues = {1, 2, 3};
  LinkedList linkedList;
  for(int value : aValues) {
    linkedList.add(value);
  }

  const auto pNode = linkedList.find(-2);
  ASSERT_NE(nullptr, pNode);
  EXPECT_EQ(2, pNode->m_iValue);
}

TEST(LinkedList, 3thToLastNode) {
  constexpr std::array<int, 3> aValues = {1, 2, 3};
  LinkedList linkedList;
  for(int value : aValues) {
    linkedList.add(value);
  }

  const auto pNode = linkedList.find(-3);
  ASSERT_NE(nullptr, pNode);
  EXPECT_EQ(1, pNode->m_iValue);
}

TEST(LinkedList, 4thToLastNodeOutside) {
  constexpr std::array<int, 3> aValues = {1, 2, 3};
  LinkedList linkedList;
  for(int value : aValues) {
    linkedList.add(value);
  }

  const auto pNode = linkedList.find(-4);
  ASSERT_EQ(nullptr, pNode);
}
