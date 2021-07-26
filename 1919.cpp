// https://www.acmicpc.net/problem/1919

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string str1;
    int arr1['z' - 'a' + 1] = {
        0,
    };

    string str2;
    int arr2['z' - 'a' + 1] = {
        0,
    };

    cin >> str1 >> str2;

    for (int i = 0; i < str1.size(); i++) {
        arr1[str1[i] - 'a']++;
    }

    for (int i = 0; i < str2.size(); i++) {
        arr2[str2[i] - 'a']++;
    }

    int sum = 0;
    for (int i = 0; i < 'z' - 'a' + 1; i++) {
        sum += abs(arr1[i] - arr2[i]);
    }
    cout << sum << endl;
}