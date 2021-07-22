// https://www.acmicpc.net/problem/1676

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector< pair<int, int> > v;

void count(int n) {
    while (n % 2 == 0) {
        n /= 2;
        v[0].first++;
    }

    while (n % 5 == 0) {
        n /= 5;
        v[0].second++;
    }
}

int main() {
    int n;
    int cnt = 0;

    v.push_back(pair<int, int>(0, 0));

    cin >> n;

    for (int i = 1; i <= n; i++) {
        count(i);
    }

    cout << min(v[0].first, v[0].second);
}