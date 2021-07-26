// https://www.acmicpc.net/problem/1264

#include <iostream>
#include <string>

using namespace std;

int main() {

    while (true) {
        int cnt = 0;
        string str;

        getline(cin, str);

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == 'a' || str[i] == 'i' || str[i] == 'u' || str[i] == 'o' || str[i] == 'e' || str[i] == 'A' || str[i] == 'I' || str[i] == 'U' || str[i] == 'O' || str[i] == 'E')
                cnt++;
        }
        if (str == "#")
            break;
        cout << cnt << endl;
    }
}