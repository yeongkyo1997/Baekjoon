// https://www.acmicpc.net/problem/17413

#include <iostream>
#include <stack>

using namespace std;

int main() {
    char *str;
    str = new char[100001];

    scanf("%[^\n]s", str);

    stack<char> s;

    while (*str != NULL) {
        if (*str != '<') {
            while (*str != ' ' &&
                   *str != NULL && *str != '<')
                s.push(*(str++));

            while (!s.empty()) {
                cout << s.top();
                s.pop();
            }
            if (*str == ' ') {
                cout << " ";
                str++;
            }

        } else {
            while (*str != '>')
                cout << *(str++);
            cout << ">";
            str++;
        }
    }
}