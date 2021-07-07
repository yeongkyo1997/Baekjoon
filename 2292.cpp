// https://www.acmicpc.net/problem/2292

#include <iostream>

using namespace std;

int main() {
    int n;
    int last = 1;
    int level = 1;
    int result;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        if (n <= last) {
            result = i;
            break;
        }
        else {
            last += i * 6;
            level += i;
        }
    }

    printf("%d\n", result);
}
