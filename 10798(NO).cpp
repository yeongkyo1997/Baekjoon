// https://www.acmicpc.net/problem/10798

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string str[5];

    for (int i = 0; i < 5; i++)
        cin >> str[i];

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 5; j++) {
            char ch = str[j][i];
            if (str[j][i] == NULL)
                continue;
            cout << str[j][i];
        }
    }
}