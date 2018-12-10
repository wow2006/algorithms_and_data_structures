/*
 * Find nth to last node in a linked list.
 */
#include <iostream>

struct ListNode {
	int val;
	ListNode *next;

	explicit ListNode(int v) : val{v}, next{nullptr} {
	}
};

ListNode *nthToLastNode(ListNode *head, int n);

void insert(ListNode *&head, int v);

void iterateList(ListNode *head);

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

ListNode *nthToLastNode(ListNode *head, int n) {
	auto ptr1 = head;
	auto ptr2 = head;

	int i = 1;
	while (ptr1 && i <= n) {
		ptr1 = ptr1->next;
		++i;
	}

	while (ptr1) {
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
	while (head) {
		std::cout << head->val << "-->";
		head = head->next;
	}

	std::cout << "NULL" << std::endl;
}
