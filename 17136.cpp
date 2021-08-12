// https://www.acmicpc.net/problem/17136

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> P;
bool arr[10][10];
int paper[6], res = 25;

int measure(int x, int y) {
    int tmp = 5;

    for (int i = x; i < 10; i++) {
        for (int j = y; j < 10; j++) {
            if (!arr[i][j]) {
                tmp = min(tmp, max(i - x, j - y));
                break;
            }
        }
    }

    tmp = min(tmp, 10 - x);
    tmp = min(tmp, 10 - y);
    return tmp;
}

void chk(int x, int y, int len, bool t) {
    for (int i = x; i < x + len; i++) {
        for (int j = y; j < y + len; j++) {
            arr[i][j] = t;
        }
    }
}
void func(int cnt) {
    if (cnt >= res)
        return;

    P one = make_pair(10, 10);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (arr[i][j]) {
                one = make_pair(i, j);
                break;
            }
        }

        if (one.first != 10)
            break;
    }

    if (one.first != 10) {
        int t = measure(one.first, one.second);
        bool frag = false;

        for (int k = t; k >= 1; k--) {
            if (paper[k] == 5)
                continue;
            else {
                frag = true;
                chk(one.first, one.second, k, false);
                paper[k]++;
                func(cnt + 1);
                chk(one.first, one.second, k, true);
                paper[k]--;
            }
        }
        if (!frag)
            return;
    } else
        res = min(res, cnt);
}
int main() {
    int cnt = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> arr[i][j];

            if (arr[i][j])
                cnt++;
        }
    }
    func(0);

    if (res == 25)
        cout << "-1\n";
    else
        cout << res << '\n';
    return 0;
}