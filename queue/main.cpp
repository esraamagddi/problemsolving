#include <iostream>

using namespace std;

class Queue {
private:
    int front;
    int rear;
    int size;
    int* arr;

public:
    Queue(int s) {
        size = s;
        front = rear = -1;
        arr = new int[size];
    }

    // insert at rear
    void enqueue(int data) {
        if (rear == size - 1) {
            cout << "Queue is full no other space " << data << endl;
        } else {
            arr[++rear] = data;
        }
    }

    // remove from front
    void dequeue() {
        if (front == rear) {
            cout << "queue is empty " << endl;
        } else {
            cout << "Dequeued element :" << arr[++front] << endl;
        }
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    Queue myQueue(5);

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

   // myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();

    return 0;
}
