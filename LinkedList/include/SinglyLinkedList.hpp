#pragma once
#include <list>

struct SinglyLinkedList {
  SinglyLinkedList();

  SinglyLinkedList(const std::initializer_list<int> &l);

  ~SinglyLinkedList();

  struct Node {
    explicit Node(int value) : m_iValue{value} {}

    int m_iValue = 0;
    Node *m_pNext = nullptr;
  };

  Node *m_pRoot = nullptr;
};
