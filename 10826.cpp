// https://www.acmicpc.net/problem/2747

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    unsigned long long  arr[100001];

    scanf("%d", &n);

    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    printf("%llu\n", arr[n]);
}