// https://www.acmicpc.net/problem/1260

#include <iostream>
#include <queue>

using namespace std;

bool arr[1001][1001];
bool visit1[1000];
bool visit2[1000];

void insert(int start, int end) {
    arr[start][end] = true;
    arr[end][start] = true;
}

void dfs(int n, int v) {
    visit1[v] = true;

    cout << v << " ";

    for (int i = 1; i <= n; i++) {
        if (arr[v][i] == true && visit1[i] != true) {
            dfs(n, i);
        }
    }
}

void bfs(int n, int v) {
    queue<int> q;
    visit2[v] = true;
    cout << v << ' ';

    q.push(v);

    while (q.empty() == false) {
        v = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (arr[v][i] == true && visit2[i] == false) {
                visit2[i] = true;
                cout << i << ' ';
                q.push(i);
            }
        }
    }
}

int main() {
    int n, v, startNum;

    cin >> n >> v >> startNum;

    for (int i = 1; i <= v; i++) {
        int start, end;

        cin >> start >> end;
        insert(start, end);
    }

    dfs(n, startNum);
    cout << endl;
    bfs(n, startNum);
}