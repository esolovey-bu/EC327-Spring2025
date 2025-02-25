#ifndef NODE_H
#define NODE_H

#include <string>

struct Node {
    std::string value;
    Node* next;
};

void printList(Node* head);

void insertAtFront(Node** head, std::string value);

#endif //NODE_H
