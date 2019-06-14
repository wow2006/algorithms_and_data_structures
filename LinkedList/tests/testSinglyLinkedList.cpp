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

TEST(SinglyLinkedList, addAValueToAList) {
  SinglyLinkedList list{1};

  list.add(2);

  ASSERT_FALSE(list.m_pRoot == nullptr);
  EXPECT_EQ(1, list.m_pRoot->m_iValue);

  ASSERT_FALSE(list.m_pRoot->m_pNext == nullptr);
  EXPECT_EQ(2, list.m_pRoot->m_pNext->m_iValue);
}

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

TEST(SinglyLinkedList, removeEmpty) {
  SinglyLinkedList list;

  list.remove(nullptr);

  ASSERT_TRUE(list.m_pRoot == nullptr);
}

TEST(SinglyLinkedList, removeNullptrRoot) {
  SinglyLinkedList list{ 1 };

  list.remove(nullptr);

  ASSERT_FALSE(list.m_pRoot == nullptr);
}

TEST(SinglyLinkedList, removeRoot) {
  SinglyLinkedList list{ 1, 2, 3};

  auto pRoot = list.m_pRoot;
  list.remove(pRoot);
  delete pRoot;

  ASSERT_FALSE(list.m_pRoot == nullptr);
  EXPECT_EQ(2, list.m_pRoot->m_iValue);

  ASSERT_FALSE(list.m_pRoot->m_pNext == nullptr);
  EXPECT_EQ(3, list.m_pRoot->m_pNext->m_iValue);

  ASSERT_TRUE(list.m_pRoot->m_pNext->m_pNext == nullptr);
}

/*
TEST(SinglyLinkedList, removeEnd) {
  SinglyLinkedList list{1, 2, 3};

  auto pEnd = list.m_pRoot->m_pNext->m_pNext;
  list.remove(pEnd);
  delete pEnd;

  ASSERT_FALSE(list.m_pRoot == nullptr);
  EXPECT_EQ(1, list.m_pRoot->m_iValue);

  ASSERT_FALSE(list.m_pRoot->m_pNext == nullptr);
  EXPECT_EQ(2, list.m_pRoot->m_pNext->m_iValue);

  ASSERT_TRUE(list.m_pRoot->m_pNext->m_pNext == nullptr);
}
*/

TEST(SinglyLinkedList, removeRootFromEmptyList) {
  SinglyLinkedList list;

  list.remove(nullptr);

  ASSERT_TRUE(list.m_pRoot == nullptr);
}

TEST(SinglyLinkedList, findNodeEmptyList) {
  SinglyLinkedList list;

  auto pNode = list.find([](const SinglyLinkedList::Node* const p) {
      return p->m_iValue == 1;
      });

  ASSERT_TRUE(pNode == nullptr);
}

TEST(SinglyLinkedList, findNode) {
  SinglyLinkedList list{ 1, 2, 3};

  auto pNode = list.find([](const SinglyLinkedList::Node* const p) {
      return p->m_iValue == 1;
      });

  ASSERT_FALSE(pNode == nullptr);
}

TEST(SinglyLinkedList, findNode2) {
  SinglyLinkedList list{ 1, 2, 3};

  auto pNode = list.find([](const SinglyLinkedList::Node* const p) {
      return p->m_iValue == 2;
      });

  ASSERT_FALSE(pNode == nullptr);
  EXPECT_EQ(2, pNode->m_iValue);
}

TEST(SinglyLinkedList, findNode3) {
  SinglyLinkedList list{ 1, 2, 3};

  auto pNode = list.find([](const SinglyLinkedList::Node* const p) {
      return p->m_iValue == 3;
      });

  ASSERT_FALSE(pNode == nullptr);
  EXPECT_EQ(3, pNode->m_iValue);
}

TEST(SinglyLinkedList, findNodeCompare) {
  SinglyLinkedList list{ 1, 2, 3};

  auto pNode = list.find([&list](const SinglyLinkedList::Node* const p) {
      return p == list.m_pRoot;
      });

  ASSERT_FALSE(pNode == nullptr);
  EXPECT_EQ(1, pNode->m_iValue);
}
