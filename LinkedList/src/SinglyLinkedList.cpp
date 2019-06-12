#include "SinglyLinkedList.hpp"

LinkedList::LinkedList() = default;

LinkedList::LinkedList(const std::initializer_list<int> &l)
    : m_pRoot{new Node{*l.begin()}} {
  if (l.size() >= 2) {
    m_pRoot->m_pNext = new Node{*(l.begin() + 1)};
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
