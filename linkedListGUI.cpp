#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QInputDialog>
#include <stdexcept>
#include <iostream>

class Node
{
public:
    int data;
    Node *next;
};
class LinkedListApp : public QWidget
{
    Q_OBJECT

public:
    LinkedListApp(QWidget *parent = nullptr) : QWidget(parent)
    {
        QVBoxLayout *layout = new QVBoxLayout(this);

        QLabel *titleLabel = new QLabel("Linked List Operations", this);
        layout->addWidget(titleLabel);

        listLabel = new QLabel("Linked List: nullptr", this);
        layout->addWidget(listLabel);

        QPushButton *insertFrontButton = new QPushButton("Insert at Front", this);
        layout->addWidget(insertFrontButton);
        connect(insertFrontButton, SIGNAL(clicked()), this, SLOT(insertFront()));

        QPushButton *insertEndButton = new QPushButton("Insert at End", this);
        layout->addWidget(insertEndButton);
        connect(insertEndButton, SIGNAL(clicked()), this, SLOT(insertEnd()));

        QPushButton *insertAfterButton = new QPushButton("Insert After Element", this);
        layout->addWidget(insertAfterButton);
        connect(insertAfterButton, SIGNAL(clicked()), this, SLOT(insertAfter()));

        QPushButton *printButton = new QPushButton("Print List", this);
        layout->addWidget(printButton);
        connect(printButton, SIGNAL(clicked()), this, SLOT(printList()));

        setLayout(layout);
    }

public slots:
    void insertFront()
    {
        bool ok;
        int value = QInputDialog::getInt(this, "Insert at Front", "Enter the value:", 0, -2147483647, 2147483647, 1, &ok);
        if (ok)
        {
            insertAtFront(value);
        }
    }

    void insertEnd()
    {
        bool ok;
        int value = QInputDialog::getInt(this, "Insert at End", "Enter the value:", 0, -2147483647, 2147483647, 1, &ok);
        if (ok)
        {
            insertAtEnd(value);
        }
    }

    void insertAfter()
    {
        bool ok;
        int target = QInputDialog::getInt(this, "Insert After Element", "Enter the target element:", 0, -2147483647, 2147483647, 1, &ok);
        if (ok)
        {
            int value = QInputDialog::getInt(this, "Insert After Element", "Enter the value to insert:", 0, -2147483647, 2147483647, 1, &ok);
            if (ok)
            {
                insertAfter(target, value);
            }
        }
    }

    void printList()
    {
        printListGUI();
    }

private:
    Node *head = nullptr;
    QLabel *listLabel;

    void insertAtFront(int newValue)
    {
        try
        {
            Node *newNode = new Node();
            newNode->data = newValue;
            newNode->next = head;
            head = newNode;
            updateListLabel();
        }
        catch (const std::bad_alloc &e)
        {
            showError("Memory allocation failed.");
        }
    }

    void insertAtEnd(int newValue)
    {
        try
        {
            Node *newNode = new Node();
            newNode->data = newValue;
            newNode->next = nullptr;

            if (head == nullptr)
            {
                head = newNode;
                updateListLabel();
                return;
            }

            Node *last = head;
            while (last->next != nullptr)
            {
                last = last->next;
            }
            last->next = newNode;
            updateListLabel();
        }
        catch (const std::bad_alloc &e)
        {
            showError("Memory allocation failed.");
        }
    }

    void insertAfter(int targetValue, int newValue)
    {
        try
        {
            Node *newNode = new Node();
            newNode->data = newValue;

            Node *current = head;
            while (current != nullptr && current->data != targetValue)
            {
                current = current->next;
            }

            if (current == nullptr)
            {
                showError("Target element not found.");
                return;
            }

            newNode->next = current->next;
            current->next = newNode;
            updateListLabel();
        }
        catch (const std::bad_alloc &e)
        {
            showError("Memory allocation failed.");
        }
    }

    void printListGUI()
    {
        QString listText = "Linked List: ";
        Node *current = head;
        while (current != nullptr)
        {
            listText += QString::number(current->data) + " -> ";
            current = current->next;
        }
        listText += "nullptr";
        listLabel->setText(listText);
    }

    void showError(const QString &message)
    {
        QMessageBox::critical(this, "Error", message);
    }

    void updateListLabel()
    {
        printListGUI();
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    LinkedListApp window;
    window.setWindowTitle("Linked List Application");
    window.resize(400, 200);
    window.show();

    return app.exec();
}

#include "main.moc"