// This is an open source non-commercial project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
/*
 * Find nth to last node in a linked list.
 */
#include <iostream>
#include "nthToLastNode.hpp"


#ifndef TESTING
int main() {
	ListNode *head = nullptr;
	insert(head, 3);
	insert(head, 2);
	insert(head, 1);
	insert(head, 5);

	iterateList(head);

	const auto pNthNodeToLastNode = nthToLastNode(head, 2);
	std::cout << pNthNodeToLastNode->val << std::endl;

	return 0;
}
#endif //! TESTING

ListNode *nthToLastNode(ListNode *head, int n) {
	auto ptr1 = head;
	auto ptr2 = head;

	int i = 1;
	while(ptr1 != nullptr && i <= n) {
		ptr1 = ptr1->next;
		++i;
	}

	while (ptr1 != nullptr) {
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}

	return ptr2;
}

void insert(ListNode *&head, int v) {
	const auto newNode = new ListNode(v);

	if (head == nullptr) {
		head = newNode;
	} else {
		auto temp = head;

		while (temp->next != nullptr) {
			temp = temp->next;
		}

		temp->next = newNode;
	}
}

void iterateList(ListNode *head) {
	while (head != nullptr) {
		std::cout << head->val << "-->";
		head = head->next;
	}

	std::cout << "NULL" << std::endl;
}
