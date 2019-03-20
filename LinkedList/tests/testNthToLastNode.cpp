#include <gtest/gtest.h>
/*
 * Program:
 * -------
 *  Create Linked list store 1 -> 2 -> 3 -> 4
 *  get nth node from last node
 *
 */

struct LinkedList {
    struct Node {};

    void add(int value) {
        m_pHead = new Node;
    }

    Node *m_pHead = nullptr;
};

TEST(LinkedListCreate, HeadIsNullptr) {
    LinkedList linkedList;

    EXPECT_EQ(nullptr, linkedList.m_pHead);
}

TEST(LinkedListCreate, CreateOneNode) {
    LinkedList linkedList;
    linkedList.add(1);

    EXPECT_NE(nullptr, linkedList.m_pHead);
}

