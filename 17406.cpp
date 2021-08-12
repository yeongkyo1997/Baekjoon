// https://www.acmicpc.net/problem/17406

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int ans;
int n, m, k;
bool check[6];

struct Info {
    int x;
    int y;
    int size;
    Info(int x, int y, int size) : x(x), y(y), size(size) {}
};

vector<Info> vt;

void move(int index, int map[50][50]) {
    int x = vt[index].x;
    int y = vt[index].y;
    int s = vt[index].size;

    while (s > 0) {

        int tmp = map[x - s][y - s];

        for (int i = x - s; i < x + s; i++) {
            map[i][y - s] = map[i + 1][y - s];
        }

        for (int j = y - s; j < y + s; j++) {
            map[x + s][j] = map[x + s][j + 1];
        }

        for (int i = x + s; i > x - s; i--) {
            map[i][y + s] = map[i - 1][y + s];
        }

        for (int j = y + s; j > y - s + 1; j--) {
            map[x - s][j] = map[x - s][j - 1];
        }

        map[x - s][y - s + 1] = tmp;
        s--;
    }
}

void mapcpy(int map[50][50], int newmap[50][50]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            newmap[i][j] = map[i][j];
        }
    }
}

void calc(int map[50][50]) {
    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = 0; j < m; j++) {
            sum += map[i][j];
        }
        if (ans > sum)
            ans = sum;
    }
}

void solve(int index, int map[50][50]) {
    if (index == k) {
        calc(map);
        return;
    }

    for (int i = 0; i < k; i++) {
        if (check[i])
            continue;

        int newmap[50][50];
        mapcpy(map, newmap);

        check[i] = true;
        move(i, newmap);

        solve(index + 1, newmap);

        check[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;

    ans = 10000;

    int map[50][50];

    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int r, c, s;

    for (int i = 0; i < k; i++) {
        cin >> r >> c >> s;
        r--;
        c--;
        vt.push_back(Info(r, c, s));
    }

    solve(0, map);

    cout << ans << '\n';
}