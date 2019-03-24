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
    auto pNode = m_pHead;
    if(index < 0) {
      index *= -1;
      for (int i = 1; i < index && pNode != nullptr; ++i) {
        pNode = pNode->m_pNext;
      }

      if (pNode == nullptr) {
        return nullptr;
      }

      auto pCurrent = m_pHead;
      while (pNode->m_pNext != nullptr) {
        pNode = pNode->m_pNext;
        pCurrent = pCurrent->m_pNext;
      }
      return pCurrent;
    } else {
      int currentIndex = 0;
      while(pNode != nullptr && currentIndex != index) {
        pNode = pNode->m_pNext;
        ++currentIndex;
      }
      return pNode;
    }
  }

  Node *m_pHead = nullptr;
};
