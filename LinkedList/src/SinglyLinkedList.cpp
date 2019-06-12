#include "SinglyLinkedList.hpp"

LinkedList::LinkedList() = default;

LinkedList::LinkedList(const std::initializer_list<int> &l)
    : m_pRoot{new Node{*l.begin()}} {
  auto pNext = &m_pRoot->m_pNext;
  auto itr   = l.begin() + 1;

  for(;itr != l.end(); ++itr, pNext = &((*pNext)->m_pNext)) {
    (*pNext) = new Node{*itr};
  }
}

LinkedList::~LinkedList() {
  if(m_pRoot != nullptr) {
    delete m_pRoot->m_pNext;
    m_pRoot->m_pNext = nullptr;

    delete m_pRoot;
    m_pRoot = nullptr;
  }
}
