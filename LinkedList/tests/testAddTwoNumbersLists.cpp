#include <gtest/gtest.h>

#include "nthToLastNode.hpp"

bool add(const LinkedList::Node* const pA,
         const LinkedList::Node* const pB,
         int* const pResult,
         int* const pCarry) {
  if(pA == nullptr || pB == nullptr ||
     pResult == nullptr || pCarry == nullptr) {
    return false;
  }

  int value = pA->m_iValue + pB->m_iValue + *pCarry;
  if(value >= 10) {
    value -= 10;
    *pCarry = 1;
  }
  *pResult = value;

  return true;
}

TEST(AddTwoNodes, AddEmptyAndOne) {
  LinkedList::Node *pA = nullptr;
  LinkedList::Node b(1);

  int result = 0, carry = 0;
  ASSERT_FALSE(add(pA, &b, &result, &carry));
}

TEST(AddTwoNodes, AddOneAndEmpty) {
  LinkedList::Node a(1);
  LinkedList::Node *pB = nullptr;

  int result = 0, carry = 0;
  ASSERT_FALSE(add(&a, pB, &result, &carry));
}

TEST(AddTwoNodes, AddOneAndOne) {
  LinkedList::Node a(1);
  LinkedList::Node b(1);

  int result = 0, carry = 0;
  ASSERT_TRUE(add(&a, &b, &result, &carry));
  EXPECT_EQ(2, result);
}

TEST(AddTwoNodes, AddOneAndOneResultEmpty) {
  LinkedList::Node a(1);
  LinkedList::Node b(1);

  int carry = 0;
  ASSERT_FALSE(add(&a, &b, nullptr, &carry));
}

TEST(AddTwoNodes, AddOneAndOneCarryEmpty) {
  LinkedList::Node a(1);
  LinkedList::Node b(1);

  int result = 0;
  ASSERT_FALSE(add(&a, &b, &result, nullptr));
}

TEST(AddTwoNodes, AddOneAndNine) {
  LinkedList::Node a(1);
  LinkedList::Node b(9);

  int result = 0, carry = 0;
  ASSERT_TRUE(add(&a, &b, &result, &carry));
  ASSERT_EQ(0, result);
  ASSERT_EQ(1, carry);
}

TEST(AddTwoNodes, AddFiveAndFive) {
  LinkedList::Node a(5);
  LinkedList::Node b(5);

  int result = 0, carry = 0;
  ASSERT_TRUE(add(&a, &b, &result, &carry));
  ASSERT_EQ(0, result);
  ASSERT_EQ(1, carry);
}

TEST(AddTwoNodes, AddNineAndNine) {
  LinkedList::Node a(9);
  LinkedList::Node b(9);

  int result = 0, carry = 0;
  ASSERT_TRUE(add(&a, &b, &result, &carry));
  ASSERT_EQ(8, result);
  ASSERT_EQ(1, carry);
}

TEST(AddTwoNodes, AddNineAndNineWithCarryOne) {
  LinkedList::Node a(9);
  LinkedList::Node b(9);

  int result = 0, carry = 1;
  ASSERT_TRUE(add(&a, &b, &result, &carry));
  ASSERT_EQ(9, result);
  ASSERT_EQ(1, carry);
}

LinkedList operator+(LinkedList a, LinkedList b) {
  LinkedList c;

  auto pA = a.m_pHead;
  auto pB = b.m_pHead;
  if(pA == nullptr ||
     pB == nullptr) {
    return c;
  }

  int value = 0, carry = 0;
  while(add(pA, pB, &value, &carry)) {
    c.add(value);
    pA = pA->m_pNext;
    pB = pB->m_pNext;
  }

  if(pB == nullptr &&
     pA != nullptr) {
    value = pA->m_iValue + carry;
    c.add(value);
    carry = 0;

    auto pNode = pA->m_pNext;
    while(pNode != nullptr) {
      c.add(pNode->m_iValue);
      pNode = pNode->m_pNext;
    }
  }

  if(pA == nullptr &&
     pB != nullptr) {
    value = pB->m_iValue + carry;
    c.add(value);
    carry = 0;

    auto pNode = pB->m_pNext;
    while(pNode != nullptr) {
      c.add(pNode->m_iValue);
      pNode = pNode->m_pNext;
    }
  }

  if(carry > 0) {
    c.add(carry);
  }
  return c;
}

TEST(AddTwoNumbersLists, AddEmptyAndOne) {
  LinkedList firstNumber;

  LinkedList secondNumber;
  secondNumber.add(1);

  auto result = firstNumber + secondNumber;

  ASSERT_EQ(nullptr, result.m_pHead);
}

TEST(AddTwoNumbersLists, AddOneAndEmpty) {
  LinkedList firstNumber;
  firstNumber.add(1);

  LinkedList secondNumber;

  auto result = firstNumber + secondNumber;

  ASSERT_EQ(nullptr, result.m_pHead);
}

TEST(AddTwoNumbersLists, AddOneAndOne) {
  LinkedList firstNumber;
  firstNumber.add(1);

  LinkedList secondNumber;
  secondNumber.add(1);

  auto result = firstNumber + secondNumber;

  ASSERT_NE(nullptr, result.m_pHead);
  EXPECT_EQ(2, result.m_pHead->m_iValue);
}

TEST(AddTwoNumbersLists, AddOneAndTwo) {
  LinkedList firstNumber;
  firstNumber.add(1);

  LinkedList secondNumber;
  secondNumber.add(2);

  auto result = firstNumber + secondNumber;

  ASSERT_NE(nullptr, result.m_pHead);
  EXPECT_EQ(3, result.m_pHead->m_iValue);
}

TEST(AddTwoNumbersLists, AddOneAndNine) {
  LinkedList firstNumber;
  firstNumber.add(1);

  LinkedList secondNumber;
  secondNumber.add(9);

  auto result = firstNumber + secondNumber;

  ASSERT_NE(nullptr, result.m_pHead);
  EXPECT_EQ(0, result.m_pHead->m_iValue);
  ASSERT_NE(nullptr, result.m_pHead->m_pNext);
  EXPECT_EQ(1, result.m_pHead->m_pNext->m_iValue);
}

TEST(AddTwoNumbersLists, AddElevenAndEleven) {
  LinkedList firstNumber;
  firstNumber.add(1);
  firstNumber.add(1);

  LinkedList secondNumber;
  secondNumber.add(1);
  secondNumber.add(1);

  auto result = firstNumber + secondNumber;

  ASSERT_NE(nullptr, result.m_pHead);
  EXPECT_EQ(2, result.m_pHead->m_iValue);
  ASSERT_NE(nullptr, result.m_pHead->m_pNext);
  EXPECT_EQ(2, result.m_pHead->m_pNext->m_iValue);
}

TEST(AddTwoNumbersLists, AddElevenAndTwelve) {
  LinkedList firstNumber;
  firstNumber.add(1);
  firstNumber.add(1);

  LinkedList secondNumber;
  secondNumber.add(1);
  secondNumber.add(2);

  auto result = firstNumber + secondNumber;

  ASSERT_NE(nullptr, result.m_pHead);
  EXPECT_EQ(2, result.m_pHead->m_iValue);
  ASSERT_NE(nullptr, result.m_pHead->m_pNext);
  EXPECT_EQ(3, result.m_pHead->m_pNext->m_iValue);
}

TEST(AddTwoNumbersLists, AddElevenAndOne) {
  LinkedList firstNumber;
  firstNumber.add(1);
  firstNumber.add(1);

  LinkedList secondNumber;
  secondNumber.add(1);

  auto result = firstNumber + secondNumber;

  ASSERT_NE(nullptr, result.m_pHead);
  EXPECT_EQ(2, result.m_pHead->m_iValue);
  ASSERT_NE(nullptr, result.m_pHead->m_pNext);
  EXPECT_EQ(1, result.m_pHead->m_pNext->m_iValue);
}

TEST(AddTwoNumbersLists, AddOneAndEleven) {
  LinkedList firstNumber;
  firstNumber.add(1);

  LinkedList secondNumber;
  secondNumber.add(1);
  secondNumber.add(1);

  auto result = firstNumber + secondNumber;

  ASSERT_NE(nullptr, result.m_pHead);
  EXPECT_EQ(2, result.m_pHead->m_iValue);
  ASSERT_NE(nullptr, result.m_pHead->m_pNext);
  EXPECT_EQ(1, result.m_pHead->m_pNext->m_iValue);
}

TEST(AddTwoNumbersLists, AddNineAndEleven) {
  LinkedList firstNumber;
  firstNumber.add(9);

  LinkedList secondNumber;
  secondNumber.add(1);
  secondNumber.add(1);

  auto result = firstNumber + secondNumber;

  ASSERT_NE(nullptr, result.m_pHead);
  EXPECT_EQ(0, result.m_pHead->m_iValue);
  ASSERT_NE(nullptr, result.m_pHead->m_pNext);
  EXPECT_EQ(2, result.m_pHead->m_pNext->m_iValue);
  ASSERT_EQ(nullptr, result.m_pHead->m_pNext->m_pNext);
}

TEST(AddTwoNumbersLists, AddElevenAndNine) {
  LinkedList firstNumber;
  firstNumber.add(1);
  firstNumber.add(1);

  LinkedList secondNumber;
  secondNumber.add(9);

  auto result = firstNumber + secondNumber;

  ASSERT_NE(nullptr, result.m_pHead);
  EXPECT_EQ(0, result.m_pHead->m_iValue);
  ASSERT_NE(nullptr, result.m_pHead->m_pNext);
  EXPECT_EQ(2, result.m_pHead->m_pNext->m_iValue);
  ASSERT_EQ(nullptr, result.m_pHead->m_pNext->m_pNext);
}

TEST(AddTwoNumbersLists, AddOneAnd111) {
  LinkedList firstNumber;
  firstNumber.add(1);

  LinkedList secondNumber;
  secondNumber.add(1);
  secondNumber.add(1);
  secondNumber.add(1);

  auto result = firstNumber + secondNumber;

  ASSERT_NE(nullptr, result.m_pHead);
  EXPECT_EQ(2,       result.m_pHead->m_iValue);
  ASSERT_NE(nullptr, result.m_pHead->m_pNext);
  EXPECT_EQ(1,       result.m_pHead->m_pNext->m_iValue);
  ASSERT_NE(nullptr, result.m_pHead->m_pNext->m_pNext);
  EXPECT_EQ(1,       result.m_pHead->m_pNext->m_pNext->m_iValue);
  ASSERT_EQ(nullptr, result.m_pHead->m_pNext->m_pNext->m_pNext);
}

TEST(AddTwoNumbersLists, Add111AndOne) {
  LinkedList firstNumber;
  firstNumber.add(1);
  firstNumber.add(1);
  firstNumber.add(1);

  LinkedList secondNumber;
  secondNumber.add(1);

  auto result = firstNumber + secondNumber;

  ASSERT_NE(nullptr, result.m_pHead);
  EXPECT_EQ(2,       result.m_pHead->m_iValue);
  ASSERT_NE(nullptr, result.m_pHead->m_pNext);
  EXPECT_EQ(1,       result.m_pHead->m_pNext->m_iValue);
  ASSERT_NE(nullptr, result.m_pHead->m_pNext->m_pNext);
  EXPECT_EQ(1,       result.m_pHead->m_pNext->m_pNext->m_iValue);
  ASSERT_EQ(nullptr, result.m_pHead->m_pNext->m_pNext->m_pNext);
}

TEST(AddTwoNumbersLists, AddNineAnd111) {
  LinkedList firstNumber;
  firstNumber.add(9);

  LinkedList secondNumber;
  secondNumber.add(1);
  secondNumber.add(1);
  secondNumber.add(1);

  auto result = firstNumber + secondNumber;

  ASSERT_NE(nullptr, result.m_pHead);
  EXPECT_EQ(0,       result.m_pHead->m_iValue);
  ASSERT_NE(nullptr, result.m_pHead->m_pNext);
  EXPECT_EQ(2,       result.m_pHead->m_pNext->m_iValue);
  ASSERT_NE(nullptr, result.m_pHead->m_pNext->m_pNext);
  EXPECT_EQ(1,       result.m_pHead->m_pNext->m_pNext->m_iValue);
  ASSERT_EQ(nullptr, result.m_pHead->m_pNext->m_pNext->m_pNext);
}

