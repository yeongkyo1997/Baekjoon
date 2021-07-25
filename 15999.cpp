// https://www.acmicpc.net/problem/15999

#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;
int nxt[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char board[2000][2000];

long long func(int num) {
    if (num == 1)
        return 2;
    long long tmp;
    if (num % 2) {
        tmp = func(num - 1);
        return (2 * tmp) % MOD;
    } else {
        tmp = func(num / 2);
        return (tmp * tmp) % MOD;
    }
}

int main() {
    int i, j, k, n, m;
    cin >> n >> m;
    for (i = 0; i < n; i++) {
        cin >> board[i];
    }

    int num = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            char here = board[i][j];

            for (k = 0; k < 4; k++) {
                int nxtX = i + nxt[k][0], nxtY = j + nxt[k][1];
                if (nxtX < 0 || nxtX >= n || nxtY < 0 || nxtY >= m)
                    continue;
                if (board[nxtX][nxtY] != here)
                    break;
            }
            if (k == 4) {
                num++;
            }
        }
    }
    cout << func(num) << endl;
}