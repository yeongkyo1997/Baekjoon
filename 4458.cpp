// https://www.acmicpc.net/problem/4458

#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;

    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str);

        if ('a' <= str[0] && str[0] <= 'z')
            str[0] -= 32;
            
        cout << str << endl;
    }
}