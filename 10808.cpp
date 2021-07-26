// https://www.acmicpc.net/problem/10808

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int size = 'z' - 'a' + 1;
    string str;
    int arr['z' - 'a' + 1] = {
        0,
    };
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        arr[str[i] - 'a']++;
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}