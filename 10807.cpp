// https://www.acmicpc.net/problem/10807

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
 
    int findNum;
    cin >> findNum;

    cout << count(v.begin(), v.end(), findNum) << endl;
}