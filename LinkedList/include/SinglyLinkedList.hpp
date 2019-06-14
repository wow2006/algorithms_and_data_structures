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

  void add(int value);

  void remove(const Node* const pNode);

  const Node* getEnd() const;

  Node *m_pRoot = nullptr;
};
