// https://www.acmicpc.net/problem/2580

#include <iostream>

using namespace std;

int arr[9][9];

struct Point {
    int row;
    int col;
};

Point p[81];

int pCount = 0;

bool check(int num, int row, int col) {
    for (int i = 0; i < 9; i++) {
        if (arr[i][col] == num || arr[row][i] == num)
            return false;
    }

    for (int i = (row / 3) * 3; i < (row / 3) * 3 + 3; i++) {
        for (int j = (col / 3) * 3; j < (col / 3) * 3 + 3; j++) {
            if (arr[i][j] == num)
                return false;
        }
    }
    return true;
}

void sudoku(int n) {
    if (n < pCount) {
        for (int i = 1; i <= 9; i++) {
            if (check(i, p[n].row, p[n].col) == true) {
                arr[p[n].row][p[n].col] = i;
                sudoku(n + 1);
                arr[p[n].row][p[n].col] = 0;
            } else {
                arr[p[n].row][p[n].col] = 0;
                continue;
            }
        }
    } else {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0)
                p[pCount++].row = i;
                p[pCount++].col = j;
        }
    }

    sudoku(0);
}