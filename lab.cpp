#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};
Node *reverseList(Node *head)
{
    Node *prev = nullptr;
    Node *current = head;
    Node *nextNode = nullptr;

    while (current != nullptr)
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

void printList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    cout << "Original Linked List: ";
    printList(node1);

    Node *reversedHead = reverseList(node1);

    cout << "Reversed Linked List: ";
    printList(reversedHead);

    while (reversedHead != nullptr)
    {
        Node *temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }

    return 0;
}
