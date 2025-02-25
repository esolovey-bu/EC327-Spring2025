#include <iostream>

#include "node.h"

// want to print Linked Lists Hello World!
int main()
{
    Node* head = NULL;
    Node** pointerToHead = &head;

    insertAtFront(pointerToHead, "World!");
    printList(head);

    insertAtFront(pointerToHead, "Hello");
    printList(head);
    //
    insertAtFront(pointerToHead, "Lists");
    printList(head);

    insertAtFront(pointerToHead, "Linked");
    printList(head);

    return 0;
}
