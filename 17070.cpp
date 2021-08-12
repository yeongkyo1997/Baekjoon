// https://www.acmicpc.net/problem/17070

#include <iostream>
#include <queue>

#define endl "\n"
#define MAX 16
using namespace std;

int N, Answer;
int MAP[MAX][MAX];
queue<pair<pair<int, int>, int>> Q;

int dx[] = {0, 1, 1};
int dy[] = {1, 0, 1};

void Input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> MAP[i][j];
        }
    }
}

void BFS() {
    while (Q.empty() == 0) {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int Dir = Q.front().second;
        Q.pop();

        if (x == N - 1 && y == N - 1) {
            Answer++;
            continue;
        }

        if (Dir == 0) // 동쪽으로 향할때
        {
            int nx = x + dx[Dir];
            int ny = y + dy[Dir];
            if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                if (MAP[nx][ny] == 0) {
                    Q.push(make_pair(make_pair(nx, ny), Dir));
                }
            }

            nx = x + dx[2];
            ny = y + dy[2];
            if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                if (MAP[nx][ny] == 0 && MAP[x + 1][y] == 0 && MAP[x][y + 1] == 0) {
                    Q.push(make_pair(make_pair(nx, ny), 2));
                }
            }
        } else if (Dir == 1) {
            int nx = x + dx[Dir];
            int ny = y + dy[Dir];
            if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                if (MAP[nx][ny] == 0) {
                    Q.push(make_pair(make_pair(nx, ny), Dir));
                }
            }

            nx = x + dx[2];
            ny = y + dy[2];
            if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                if (MAP[nx][ny] == 0 && MAP[x + 1][y] == 0 && MAP[x][y + 1] == 0) {
                    Q.push(make_pair(make_pair(nx, ny), 2));
                }
            }
        } else if (Dir == 2) {
            int nx = x + dx[Dir];
            int ny = y + dy[Dir];
            if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                if (MAP[nx][ny] == 0 && MAP[x + 1][y] == 0 && MAP[x][y + 1] == 0) {
                    Q.push(make_pair(make_pair(nx, ny), Dir));
                }
            }

            for (int i = 0; i < 2; i++) {
                nx = x + dx[i];
                ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
                    if (MAP[nx][ny] == 0) {
                        Q.push(make_pair(make_pair(nx, ny), i));
                    }
                }
            }
        }
    }
}

void Solution() {
    Q.push(make_pair(make_pair(0, 1), 0));
    BFS();
    cout << Answer << endl;
}

void Solve() {
    Input();
    Solution();
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Solve();

    return 0;
}