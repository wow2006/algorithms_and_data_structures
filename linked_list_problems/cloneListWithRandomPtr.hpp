#pragma once

struct Node {
    int data;
    Node *next;
    Node *random;
    Node(int d) : data{d}, next{nullptr}, random{nullptr} {}
};

void printList(Node *head);

Node *clone(Node *head);

bool verifyClone(Node *list1, Node *list2);
