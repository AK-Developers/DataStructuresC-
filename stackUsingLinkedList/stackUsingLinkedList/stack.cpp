//Implementing Stack using Linked List
#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

void printStack(Node* head) {
	cout << endl << "Stack : ";
	while (head != nullptr) {
		cout << head->data << " ";
		head = head->next;
	}
}
void push(Node** head) {
	Node* newNode = new Node();
	cout << endl << "Enter the value of the Node: ";
	cin >> newNode->data;
	if (*head == nullptr) {
		newNode->next = nullptr;
		*head = newNode;
	}
	else {
		newNode->next = *head;
		*head = newNode;
	}
}
void pop(Node** head) {
	if (*head == nullptr) {
		cout << "List is empty. Cannot pop.\n";
		return;
	}

	Node* temp = *head;
	*head = (*head)->next;
	delete temp;
	cout << "Succefully Popped an Item!\n";
}
void main() {
	Node* head = nullptr;
	int choice;
	do {
		cout << "\n___Stack Menu___\n1.Push\n2.Pop\n3.Print\nEnter your Choice : ";
		cin >> choice;
		switch (choice) {
		case 1:
			push(&head);
			break;
		case 2:
			pop(&head);
			break;
		case 3:
			printStack(head);
			break;
		default:
			cout << "Enter a Valid Option!!";
		}
	} while (choice != 1000);
}