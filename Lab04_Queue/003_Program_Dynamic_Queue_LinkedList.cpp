#include <iostream>
using namespace std;

class DynamicQueue {
    struct Node {
        int data;
        Node *next;

        Node(int x) {
            data = x;
            next = nullptr;
        }
    };

    Node *front, *rear;

public:
    DynamicQueue() {
        front = rear = nullptr;
    }

    ~DynamicQueue() {
        while (front != nullptr) {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }

    void enqueue(int x) {
        Node *temp = new Node(x);

        if (rear == nullptr) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue Underflow\n";
            return;
        }

        Node *temp = front;
        cout << "Deleted: " << temp->data << endl;

        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
    }

    void display() {
        Node *temp = front;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    DynamicQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();
    q.dequeue();
    q.display();

    return 0;
}
