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

void SinglyLinkedList::add(int value) {
  if(m_pRoot == nullptr) {
    m_pRoot = new Node{value};
    return;
  }

  auto** p = &m_pRoot->m_pNext;
  while(*p != nullptr) {
    p = &(*p)->m_pNext;
  }
  (*p) = new Node{value};
}

const SinglyLinkedList::Node* SinglyLinkedList::getEnd() const {
  if(m_pRoot == nullptr) {
    return nullptr;
  }

  auto p = m_pRoot;
  while(p->m_pNext != nullptr) {
    p = p->m_pNext;
  }
  return p;
}

void SinglyLinkedList::remove(const SinglyLinkedList::Node* const pNode) {
  if(m_pRoot == nullptr || pNode == nullptr) {
    return;
  }

  if(m_pRoot == pNode) {
    m_pRoot = pNode->m_pNext;
  } else {
    auto pTemp = m_pRoot;
    while(pTemp->m_pNext != nullptr && pTemp->m_pNext != pNode) {
      pTemp = pTemp->m_pNext;
    }
    pTemp->m_pNext = pTemp->m_pNext->m_pNext;
  }
}

const SinglyLinkedList::Node* SinglyLinkedList::find(std::function<bool(const Node* const)> compare) const {
  if(m_pRoot == nullptr) {
    return nullptr;
  }

  auto p = m_pRoot;
  while(p != nullptr && !compare(p)) {
    p = p->m_pNext;
  }

  return p;
}
