// https://www.acmicpc.net/problem/10987

#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;
    int cnt = 0;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'a' || str[i] == 'i' || str[i] == 'u' || str[i] == 'o' || str[i] == 'e')
            cnt++;
    }

    cout << cnt;
}