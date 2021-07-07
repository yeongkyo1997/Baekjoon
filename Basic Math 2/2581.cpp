// https://www.acmicpc.net/problem/2581

#include <iostream>

using namespace std;

bool isPrime(int n) { 

    if (n == 1)
        return false;

    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int a, b;
    int cnt = 0;
    int min;
    int sum = 0;

    cin >> a >> b;
    
    for (int i = a; i <= b; i++) {
        if (isPrime(i)) {
            cnt++;
            if (cnt== 1) {
                min = i;
            }
            sum += i;
        }
    }
    if (cnt == 0) {
        printf("-1");
    }
    else
        cout << sum << endl << min;
}