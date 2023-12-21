//Implementing Queue using Array
#include<iostream>
using namespace std;

const int max_size = 5;

class Queue {
private:
	int front, rear, size;
	int myQueue[max_size];
public:
    Queue() : front(-1), rear(-1), size(0) {}

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == max_size;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % max_size; // Circular queue
        }

        myQueue[rear] = item;
        size++;
        cout << item << " enqueued to the queue." << endl;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        do {
            cout << myQueue[i] << " ";
            i = (i + 1) % max_size;
        } while (i != (rear + 1) % max_size);

        cout << endl;
    }
};

int main() {
    Queue myQueue;
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    myQueue.enqueue(40);
    myQueue.enqueue(50);
    myQueue.enqueue(60);
    myQueue.enqueue(70);
    myQueue.display();
}