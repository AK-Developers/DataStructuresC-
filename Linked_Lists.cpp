#include <iostream>
#include <stdexcept> // Include the header for exception handling

class Node
{
public:
    int data;
    Node* next;
};

// Function to print the linked list
void printList(Node* head)
{
    Node* current = head;
    while (current != nullptr)
    {
        std::cout << current->data << current->next << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Function to insert a new node at the front of the linked list
void insertAtFront(Node** head, int newValue)
{
    try
    {
        Node* newNode = new Node();
        newNode->data = newValue;
        newNode->next = *head;
        *head = newNode;
    }
    catch (const std::bad_alloc& e)
    {
        throw std::runtime_error("Memory allocation failed.");
    }
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(Node** head, int newValue)
{
    try
    {
        Node* newNode = new Node();
        newNode->data = newValue;
        newNode->next = nullptr;

        if (*head == nullptr)
        {
            *head = newNode;
            return;
        }

        Node* last = *head;
        while (last->next != nullptr)
        {
            last = last->next;
        }
        last->next = newNode;
    }
    catch (const std::bad_alloc& e)
    {
        throw std::runtime_error("Memory allocation failed.");
    }
}

// Function to insert a new node after a specific element
void insertAfter(Node* head, int newValue, int targetValue)
{
    try
    {
        Node* newNode = new Node();
        newNode->data = newValue;

        Node* current = head;
        while (current != nullptr && current->data != targetValue)
        {
            current = current->next;
        }

        if (current == nullptr)
        {
            throw std::runtime_error("Target element not found.");
        }

        newNode->next = current->next;
        current->next = newNode;
    }
    catch (const std::bad_alloc& e)
    {
        throw std::runtime_error("Memory allocation failed.");
    }
}

int main()
{
    Node* head = nullptr;
    int choice;

    do
    {
        std::cout << "\nLinked List Menu:\n";
        std::cout << "1. Insert at Front\n";
        std::cout << "2. Insert at End\n";
        std::cout << "3. Insert After Element\n";
        std::cout << "4. Print List\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        try
        {
            switch (choice)
            {
            case 1:
            case 2:
            case 3:
                int value, target;
                std::cout << "Enter the value: ";
                std::cin >> value;
                if (choice == 3)
                {
                    std::cout << "Enter the target element: ";
                    std::cin >> target;
                    insertAfter(head, value, target);
                }
                else if (choice == 1)
                {
                    insertAtFront(&head, value);
                }
                else
                {
                    insertAtEnd(&head, value);
                }
                break;

            case 4:
                std::cout << "Linked List:" << std::endl;
                printList(head);
                break;

            case 5:
                std::cout << "Exiting program." << std::endl;
                break;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    } while (choice != 5);

    return 0;
}
