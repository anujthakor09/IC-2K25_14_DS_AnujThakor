#include <iostream>
using namespace std;

class DynamicQueue {
    int *arr;
    int capacity, count;

    void resize() {
        int *temp = new int[capacity * 2];

        for (int i = 0; i < count; i++)
            temp[i] = arr[i];

        delete[] arr;
        arr = temp;
        capacity *= 2;
    }

public:
    DynamicQueue() {
        capacity = 2;
        count = 0;
        arr = new int[capacity];
    }

    ~DynamicQueue() {
        delete[] arr;
    }

    void enqueue(int x) {
        if (count == capacity)
            resize();

        arr[count++] = x;
    }

    void dequeue() {
        if (count == 0) {
            cout << "Queue Underflow\n";
            return;
        }

        cout << "Deleted: " << arr[0] << endl;

        for (int i = 1; i < count; i++)
            arr[i - 1] = arr[i];

        count--;
    }

    void display() {
        if (count == 0) {
            cout << "Queue is empty\n";
            return;
        }

        for (int i = 0; i < count; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main() {
    DynamicQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();
    q.dequeue();
    q.display();

    return 0;
}
