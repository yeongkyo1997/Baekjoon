// https://www.acmicpc.net/problem/12865

#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;

int n, k;
int d[100001];
int w[101];
int v[101];

void dp() {
    for (int i = 1; i <= n; i++) {
        for (int j = k; j >= 1; j--) {
            if (w[i] <= j) {
                d[j] = max(d[j], d[j - w[i]] + v[i]);
            }
        }
    }

    cout << d[k] << "\n";
}

int main(int argc, const char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    dp();
}