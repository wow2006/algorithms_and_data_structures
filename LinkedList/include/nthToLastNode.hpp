#pragma once

struct LinkedList {
  struct Node {
    int m_iValue;
    Node *m_pNext= nullptr;

    explicit Node(int value) : m_iValue(value) {}
  };

  void add(int value) {
    if(m_pHead == nullptr) {
      m_pHead = new Node(value);
    } else {
      auto pLastNode = m_pHead;
      while(pLastNode->m_pNext != nullptr) {
        pLastNode = pLastNode->m_pNext;
      }

      pLastNode->m_pNext = new Node(value);
    }
  }

  Node *m_pHead = nullptr;
};

