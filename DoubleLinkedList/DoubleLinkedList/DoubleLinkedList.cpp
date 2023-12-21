#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Insert at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Delete a node by value
    void deleteNode(int value) {
        Node* current = head;

        while (current != nullptr) {
            if (current->data == value) {
                if (current->prev) {
                    current->prev->next = current->next;
                }
                else {
                    head = current->next;
                }

                if (current->next) {
                    current->next->prev = current->prev;
                }
                else {
                    tail = current->prev;
                }

                delete current;
                return; // Found and deleted
            }

            current = current->next;
        }
    }

    // Display the list from head to tail
    void displayForward() {
        Node* current = head;

        while (current != nullptr) {
            cout << current->data << " <-> ";
            current = current->next;
        }

        cout << "nullptr" << endl;
    }

    // Display the list from tail to head
    void displayBackward() {
        Node* current = tail;

        while (current != nullptr) {
            cout << current->data << " <-> ";
            current = current->prev;
        }

        cout << "nullptr" << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, value;

    do {
        cout << "\nDoubly Linked List Menu:\n";
        cout << "1. Insert at the Beginning\n";
        cout << "2. Insert at the End\n";
        cout << "3. Delete Node by Value\n";
        cout << "4. Display Forward\n";
        cout << "5. Display Backward\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value to insert at the beginning: ";
            cin >> value;
            dll.insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter the value to insert at the end: ";
            cin >> value;
            dll.insertAtEnd(value);
            break;
        case 3:
            cout << "Enter the value to delete: ";
            cin >> value;
            dll.deleteNode(value);
            break;
        case 4:
            cout << "Doubly Linked List (Forward):" << endl;
            dll.displayForward();
            break;
        case 5:
            cout << "Doubly Linked List (Backward):" << endl;
            dll.displayBackward();
            break;
        case 6:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
