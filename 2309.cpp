// https://www.acmicpc.net/problem/2309

#include <algorithm>
#include <iostream>

using namespace std;

int arr[10];

int sum = 0;

int list[8];
int index = 0;
int count = 0;

void print() {
    sort(list, list + 8);

    for (int i = 1; i < 8; i++)
        cout << list[i] << "\n";
}

void dfs(int n) {
    if (index < 8) {
        for (int i = n; i < 10; i++) {
            sum += arr[i];
            list[index++] = arr[i];
            dfs(i + 1);
            index--;
            sum -= arr[i];
        }
    } else {
        if (sum == 100) {
            print();
            exit(0);
        }
    }
}

int main() {
    for (int i = 1; i < 10; i++)
        cin >> arr[i];

    dfs(0);
}