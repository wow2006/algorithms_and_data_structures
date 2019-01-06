// This is an open source non-commercial project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
/*
 * We have two numbers represented by a linked list,
 * where each node contains a single digit. The digits are stored in reverse
 * order, such that the 1's digit is at the head of the list. Write a function
 * that adds the two numbers and returns the sum as a linked list.
 *
 * Example
 * Given 7->1->6 + 5->9->2. That is, 617 + 295.
 *
 * Return 2->1->9. That is 912.
 *
 * Given 3->1->5 and 5->9->2, return 8->0->8.
 */

#include <iostream>

#include "addTwoNumbersLists.hpp"


#ifndef TESTING
int main() {
  auto pList1 = new ListNode(9);
  pList1->m_pNext = new ListNode(9);

  auto pList2 = new ListNode(5);
  pList2->m_pNext = new ListNode(9);
  pList2->m_pNext->m_pNext = new ListNode(2);

  iterate(pList1);
  iterate(pList2);

  auto pList3 = addLists(pList1, pList2);
  iterate(pList3);

  return 0;
}
#endif //! TESTING

ListNode *addLists(ListNode *list1, ListNode *list2) {
  ListNode *list3 = nullptr;
  ListNode *curr = nullptr;
  int carry = 0;

  // both list1 and list2 are not null
  while (list1 && list2) {
    int x = list1->m_iValue + list2->m_iValue + carry;
    if (x > 9) {
      carry = 1;
      x -= 10;
    } else {
      carry = 0;
    }
    if (list3 == nullptr) {
      list3 = new ListNode(x);
      curr = list3;
    } else {
      curr->m_pNext = new ListNode(x);
      curr = curr->m_pNext;
    }
    list1 = list1->m_pNext;
    list2 = list2->m_pNext;
  }

  // list2 is null
  while (list1) {
    int x = list1->m_iValue + carry;
    if (x > 9) {
      carry = 1;
      x -= 10;
    } else {
      carry = 0;
    }
    curr->m_pNext = new ListNode(x);
    curr = curr->m_pNext;
    list1 = list1->m_pNext;
  }

  // list1 is null
  while (list2) {
    int x = list2->m_iValue + carry;
    if (x > 9) {
      carry = 1;
      x -= 10;
    } else {
      carry = 0;
    }
    curr->m_pNext = new ListNode(x);
    curr = curr->m_pNext;
    list2 = list2->m_pNext;
  }
  if (carry > 0) {
    curr->m_pNext = new ListNode(carry);
    curr = curr->m_pNext;
  }
  return list3;
}

void iterate(ListNode *node) {
  while (node) {
    std::cout << node->m_iValue << " ";
    node = node->m_pNext;
  }
  std::cout << std::endl;
}

bool equal(const ListNode* pNode1, const ListNode* pNode2) {
  bool result = false;
  if(pNode1 == nullptr && pNode2 == nullptr) {
    result = true;
  }

  if(pNode1 != nullptr && pNode2 != nullptr) {
    result = equal(pNode1->m_pNext, pNode2->m_pNext);
    return result && (pNode1->m_iValue == pNode2->m_iValue);
  }

  return result;
}
