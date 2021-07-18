// https://www.acmicpc.net/problem/15649

#include <iostream>

using namespace std;

int n; // 숫자 범위
int m; // 배열크기
int arr[8];

bool check(int data, int num) {
    for (int i = 0; i < num; i++) {
        if (arr[i] == data)
            return false;
    }
    return true;
}

void print(int num) {
    if (num < m)
        for (int i = 1; i <= n; i++) {
            if (check(i, num) == true) {
                arr[num] = i;
                print(num + 1);
                arr[num] = 0;
            } else
                continue;
        }
    else {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    cin >> n >> m;

    print(0);
}