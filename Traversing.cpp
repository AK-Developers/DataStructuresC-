#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *node;
};

void traverseList(Node *head)
{
    Node *current = head;
    int count = 0;
    while (current != nullptr)
    {
        cout << "Traversed Node: " << ++count << endl;
    }
}

int main()
{
    Node node1, node2, node3;
    Node *head;
    node1.data = 10;
    node2.data = 20;
    node3.data = 30;
    head->node = &node1;
    node1.node = &node2;
    node2.node = &node3;
    node3.node = nullptr;
    traverseList(head);
}