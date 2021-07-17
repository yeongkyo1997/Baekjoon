// https://www.acmicpc.net/problem/9613

#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    int size;
    int n;
    int arr[100];

    cin >> n;

    while (n-- != 0) {
        cin >> size;

        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }

        int sum = 0;

        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                sum += gcd(arr[i], arr[j]);
            }
        }
        printf("%d\n", sum);
    }
}