// https://www.acmicpc.net/problem/5597

#include <iostream>

using namespace std;

int main() {
    bool arr[31] = {
        false,
    };

    for (int i = 0; i < 29; i++) {
        int n;
        cin >> n;

        arr[n] = true;
    }

    for (int j = 1; j < 31; j++) {
        if (arr[j] == false)
            cout << j << endl;
        else
            continue;
    }
}