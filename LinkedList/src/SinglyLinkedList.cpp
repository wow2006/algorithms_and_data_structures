#include "SinglyLinkedList.hpp"
#include <cstdio>

SinglyLinkedList::SinglyLinkedList() = default;

SinglyLinkedList::SinglyLinkedList(const std::initializer_list<int> &l)
    : m_pRoot{new Node{*l.begin()}} {
  auto pNext = &m_pRoot->m_pNext;
  auto itr = l.begin() + 1;

  for (; itr != l.end(); ++itr, pNext = &((*pNext)->m_pNext)) {
    (*pNext) = new Node{*itr};
  }
}

SinglyLinkedList::~SinglyLinkedList() {
  if (m_pRoot != nullptr) {
    Node* pTemp = m_pRoot;
    while(pTemp != nullptr) {
      auto p = pTemp->m_pNext;
      delete pTemp;
      pTemp = p;
    }
  }
}
