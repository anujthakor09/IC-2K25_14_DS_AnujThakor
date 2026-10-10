#include <iostream>
using namespace std;

class StaticQueue {
    int arr[5];
    int front, rear;

public:
    StaticQueue() {
        front = rear = -1;
    }

    void enqueue(int x) {
        if (rear == 4) {
            cout << "Queue Overflow\n";
            return;
        }

        if (front == -1)
            front = 0;

        arr[++rear] = x;
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue Underflow\n";
            return;
        }

        cout << "Deleted: " << arr[front] << endl;

        if (front == rear)
            front = rear = -1;
        else
            front++;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return;
        }

        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main() {
    StaticQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();
    q.dequeue();
    q.display();

    return 0;
}
