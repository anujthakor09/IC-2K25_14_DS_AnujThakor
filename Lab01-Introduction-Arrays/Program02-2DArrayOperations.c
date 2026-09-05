#include <stdio.h>

#define MAX 10

void display(int a[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

void insertRow(int a[MAX][MAX], int *rows, int cols, int pos, int row[]) {
    if (*rows >= MAX || pos < 0 || pos > *rows) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = *rows; i > pos; i--)
        for (int j = 0; j < cols; j++)
            a[i][j] = a[i - 1][j];

    for (int j = 0; j < cols; j++)
        a[pos][j] = row[j];

    (*rows)++;
}

void deleteRow(int a[MAX][MAX], int *rows, int cols, int pos) {
    if (pos < 0 || pos >= *rows) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = pos; i < *rows - 1; i++)
        for (int j = 0; j < cols; j++)
            a[i][j] = a[i + 1][j];

    (*rows)--;
}

void search2D(int a[MAX][MAX], int rows, int cols, int value) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (a[i][j] == value) {
                printf("%d found at [%d][%d]\n", value, i, j);
                return;
            }
        }
    }

    printf("%d not found\n", value);
}

void rotate90(int a[MAX][MAX], int rows, int cols) {
    int temp[MAX][MAX];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            temp[j][rows - 1 - i] = a[i][j];

    printf("90-degree clockwise rotation:\n");
    display(temp, cols, rows);
}

int main() {
    int a[MAX][MAX] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int rows = 3, cols = 3;

    printf("Original matrix:\n");
    display(a, rows, cols);

    int newRow[] = {10, 11, 12};
    insertRow(a, &rows, cols, 1, newRow);

    printf("\nAfter row insertion:\n");
    display(a, rows, cols);

    deleteRow(a, &rows, cols, 2);

    printf("\nAfter row deletion:\n");
    display(a, rows, cols);

    printf("\nSearch result:\n");
    search2D(a, rows, cols, 8);

    printf("\n");
    rotate90(a, rows, cols);

    return 0;
}
