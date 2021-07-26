// https://www.acmicpc.net/problem/1259

#include <iostream>

using namespace std;

int reverse(int n) {
    int ret = 0;
    while (true) {
        ret += n % 10;
        n /= 10;

        if (n == 0)
            break;

        ret *= 10;
    }
    return ret;
}

int main() {
    while (true) {
        int n;
        cin >> n;

        if (n == 0)
            break;
        else {
            if (reverse(n) == n)
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
    }
}