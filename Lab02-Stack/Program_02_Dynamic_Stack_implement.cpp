#include <iostream>
using namespace std;

class Stack {
private:

    struct Node {
        int data;
        Node* next;

        Node(int value) {
            data = value;
            next = nullptr;
        }
    };

    Node* top;

public:

    Stack() {
        top = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value);

        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow\n";
            return;
        }

        Node* temp = top;

        cout << "Popped: " << top->data << endl;

        top = top->next;

        delete temp;
    }

    void peek() {
        if (top == nullptr) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Top: " << top->data << endl;
    }

    bool isEmpty() {
        return top == nullptr;
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
