#include <iostream>

using namespace std;

class Stack {
private:
    int top;
    int *arr;
    int size;

public:
    Stack(int s) {
        size = s;
        top = -1;
        arr = new int[size];
    }

    // push to stack
    void push(int data) {
        if (top < size - 1) {
            arr[++top] = data;
        } else {
            cout << "Stack is full no space to push " << data << endl;
        }
    }

    // pop --->display
    void pop() {
        if (top >= 0) {
            cout << "Popped element: " << arr[top--] << endl;
        } else {
            cout << "Stack is already empty " << endl;
        }
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack myStack(5);

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();

    return 0;
}
