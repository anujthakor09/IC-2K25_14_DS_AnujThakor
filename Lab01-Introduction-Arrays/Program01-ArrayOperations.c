#include <stdio.h>

#define MAX 100

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insert(int arr[], int *n, int pos, int value) {
    if (*n >= MAX || pos < 0 || pos > *n) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = *n; i > pos; i--)
        arr[i] = arr[i - 1];

    arr[pos] = value;
    (*n)++;
}

void delete(int arr[], int *n, int pos) {
    if (pos < 0 || pos >= *n) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = pos; i < *n - 1; i++)
        arr[i] = arr[i + 1];

    (*n)--;
}

int search(int arr[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

void rotateRight(int arr[], int n, int k) {
    if (n == 0) return;

    k %= n;

    for (int r = 0; r < k; r++) {
        int last = arr[n - 1];

        for (int i = n - 1; i > 0; i--)
            arr[i] = arr[i - 1];

        arr[0] = last;
    }
}

int main() {
    int arr[MAX] = {10, 20, 30, 40, 50};
    int n = 5;

    printf("Original array: ");
    display(arr, n);

    insert(arr, &n, 2, 25);
    printf("After insertion: ");
    display(arr, n);

    delete(arr, &n, 3);
    printf("After deletion: ");
    display(arr, n);

    int pos = search(arr, n, 40);
    printf("40 found at index: %d\n", pos);

    rotateRight(arr, n, 2);
    printf("After right rotation: ");
    display(arr, n);

    return 0;
}
