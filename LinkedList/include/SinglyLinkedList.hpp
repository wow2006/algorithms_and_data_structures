#pragma once
#include <list>

struct LinkedList {
  LinkedList();

  LinkedList(const std::initializer_list<int>& l);

  ~LinkedList();

  struct Node {
    Node(int value) : m_iValue{value} {}

    int m_iValue = 0;
    Node *m_pNext = nullptr;
  };

  Node *m_pRoot = nullptr;

};
