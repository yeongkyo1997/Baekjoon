// https://www.acmicpc.net/problem/16000

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };
const int n_ = 2000+2, nm_ = 4000000+1;

char a[n_][n_];
int n, m, cnt, num, vst[n_][n_], chk[nm_], con[nm_], isSum[nm_];
vector<int> stk, gph[nm_];

void go(int x, int y, int num) {
    vst[x][y] = num;
    for (int i = 0; i < 4; i++) {
        int nx = x+dx[i], ny = y+dy[i];
        if (a[x][y] == a[nx][ny] && !vst[nx][ny]) {
            go(nx, ny, num);
        }
        else if (a[x][y] != a[nx][ny] && vst[nx][ny]) {
            if (con[vst[nx][ny]] == num) continue;
            gph[num].push_back(vst[nx][ny]);
            gph[vst[nx][ny]].push_back(num);
            con[num] = num;
            con[vst[nx][ny]] = num;
        }
    }
}

void buildGraph() {
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
        if (!vst[i][j]) go(i, j, ++num);
}

void init() {
    fill(con, con+num+1, 0);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
        if (a[i][j] == '#') isSum[vst[i][j]] = 1;
}

void gogo(int now) {
    int mn = num;
    chk[now] = ++cnt;
    stk.push_back(now);
    for (auto nxt : gph[now]) {
        if (!chk[nxt]) {
            gogo(nxt);
            if (isSum[now] && chk[nxt] == chk[now]) {
                while (!stk.empty() && stk.back() != now) {
                    con[stk.back()] = 1;
                    stk.pop_back();
                }
            }
            stk.push_back(now);
        }
        mn = min(mn, chk[nxt]);
    }
    chk[now] = mn;
    return;
}

void input() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", a[i]+1);
    stk.reserve(nm_);
}

void process() {
    buildGraph();
    init();
    gogo(1);
}

void output() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '.') {
                printf(".");
                continue;
            }
            int num = vst[i][j];
            printf("%c", con[num] && chk[num] != 1 ? 'X' : 'O');
        }
        puts("");
    }
}

int main() {
    input();
    process();
    output();
    return 0;
}