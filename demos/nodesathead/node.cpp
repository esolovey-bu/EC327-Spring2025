#include "node.h"

#include <iostream>
#include <stdio.h>

void printList(Node* head){
    std::cout << "Printing List:" << std::endl;
    while (head != NULL) {
        std::cout << " -> " << head->value;
        head = head->next;
    }
    std::cout << "\n" << std::endl;
}

void insertAtFront(Node** head, std::string value) {
    std::cout << "Pointer to head node is stored at location: " << head << std::endl;
    std::cout << "Head node is stored at location: " << *head << std::endl;

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = *head;

    *head = newNode;
}