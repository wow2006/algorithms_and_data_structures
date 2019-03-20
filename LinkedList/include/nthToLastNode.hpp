#pragma once

struct LinkedList {
  struct Node {
    int m_iValue;
    Node *m_pNext = nullptr;

    explicit Node(int value) : m_iValue(value) {}
  };

  /**
   * @brief Add new Node to Linked list
   *
   * @param value value of new Node
   */
  void add(int value) {
    if (m_pHead == nullptr) {
      m_pHead = new Node(value);
    } else {
      auto pLastNode = m_pHead;
      while (pLastNode->m_pNext != nullptr) {
        pLastNode = pLastNode->m_pNext;
      }

      pLastNode->m_pNext = new Node(value);
    }
  }

  /**
   * @brief Get node of input index
   * use positive value to find node of index from start
   * use negative value to find node of index from back
   *
   * @param index value of index
   *
   * @return node of index
   */
  Node *find(int index) {
    index *= -1;
    auto m_pNode = m_pHead;
    for (int i = 1; i < index && m_pNode != nullptr; ++i) {
      m_pNode = m_pNode->m_pNext;
    }

    if (m_pNode == nullptr) {
      return nullptr;
    }

    auto m_pCurrent = m_pHead;
    while (m_pNode->m_pNext != nullptr) {
      m_pNode = m_pNode->m_pNext;
      m_pCurrent = m_pCurrent->m_pNext;
    }
    return m_pCurrent;
  }

  Node *m_pHead = nullptr;
};
