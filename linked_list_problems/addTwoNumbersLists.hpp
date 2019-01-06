#pragma once


struct ListNode {
  int m_iValue;

  ListNode *m_pNext;

  ListNode(int value) : m_iValue(value), m_pNext(nullptr) {}

};

ListNode *addLists(ListNode *list1, ListNode *list2);

void iterate(ListNode *node);

bool equal(const ListNode* pNode1, const ListNode* pNode2);

