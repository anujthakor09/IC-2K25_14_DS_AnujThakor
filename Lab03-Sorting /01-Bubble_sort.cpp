#include <iostream>
#include <vector>
using namespace std;

class BubbleSort {
private:
    vector<int> arr;

public:
    void input() {
        int n;

        cout << "Enter number of elements: ";
        cin >> n;

        cout << "Enter elements: ";

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            arr.push_back(x);
        }
    }

    void sortArray() {
        int n = arr.size();

        for (int i = 0; i < n - 1; i++) {

            for (int j = 0; j < n - i - 1; j++) {

                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    void display() {
        cout << "Sorted array: ";

        for (int x : arr) {
            cout << x << " ";
        }
    }
};

int main() {

    BubbleSort obj;

    obj.input();
    obj.sortArray();
    obj.display();

    return 0;
}
