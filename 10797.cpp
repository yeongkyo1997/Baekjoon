// https://www.acmicpc.net/problem/10797

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;

    for (int i = 0; i < 5; i++) {
        int num;
        cin >> num;

        v.push_back(num);
    }

    cout << count(v.begin(), v.end(), n);
}