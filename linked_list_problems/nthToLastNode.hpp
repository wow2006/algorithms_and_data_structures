#ifndef NTH_TO_LAST_NOTE_HPP
#define NTH_TO_LAST_NOTE_HPP

struct ListNode {
	int val;
	ListNode *next;

	explicit ListNode(int v) : val{v}, next{nullptr} {
	}
};

ListNode *nthToLastNode(ListNode *head, int n);

void insert(ListNode *&head, int v);

void iterateList(ListNode *head);

#endif //! NTH_TO_LAST_NOTE_HPP
