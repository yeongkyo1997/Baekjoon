// https://www.acmicpc.net/problem/2953

#include <iostream>

using namespace std;

int main() {
    pair<int, int> p;
    p.first = 0;
    p.second = 0;

    for (int i = 1; i <= 5; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int sum = a + b + c + d;
 
        if (p.second < sum) {
            p.first = i;
            p.second = sum;
        }
    }

    cout << p.first << " " << p.second << endl;
}