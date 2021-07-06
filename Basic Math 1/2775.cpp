// https://www.acmicpc.net/problem/2775

#include <iostream>

using namespace std;

int getResult(int k, int n) {
    if (k == 0)
     return n;
    int res = 0;
    
    for (int i = 1; i <= n; i++) {
        res += getResult(k - 1, i);
    }

    return res;
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int k; 
        cin >> k;
        int n;
        cin >> n;
        printf("%d", getResult(k, n));
    }
}