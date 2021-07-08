// https://www.acmicpc.net/problem/10828

#include <iostream>

#include <stack>

using namespace std;

int main() {
    int n;
    stack<int> s;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int num;
            cin >> num;

            s.push(num);
        }

        else if (cmd == "pop") {
            if (s.empty()) {
                cout << "-1" << endl;
            }
            else {
                cout << s.top() << endl;
                s.pop();
            }
        }

        else if (cmd == "size") {
            cout << s.size() << endl;
        }

        else if (cmd == "empty") {
            if (s.empty()) {
                cout << "1" << endl;
            }
            else {
                cout << "0" << endl;

            }
        }

        else if (cmd == "top") {
            if (s.empty()) {
                cout << "-1" << endl;
            }
            else{
                cout << s.top() << endl;
            }
        }
   }
}