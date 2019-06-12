#include "SinglyLinkedList.hpp"

LinkedList::LinkedList() = default;

LinkedList::LinkedList(const std::initializer_list<int>& l)
  : m_pRoot{new Node{*l.begin()}} {}
  
LinkedList::~LinkedList() {
  delete m_pRoot;
  m_pRoot = nullptr;
}

