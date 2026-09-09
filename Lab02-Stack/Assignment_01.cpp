#include <iostream>
using namespace std;

class Stack {
private:
    int arr[5];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top == 4) {
            cout << "Stack Overflow\n";
            return;
        }

        top++;
        arr[top] = value;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }

        cout << "Popped: " << arr[top] << endl;
        top--;
    }

    void peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Top: " << arr[top] << endl;
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.peek();

    s.pop();
    s.peek();

    return 0;
}
