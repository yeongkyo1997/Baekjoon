// https://www.acmicpc.net/problem/2178

#include <cstdio>
#include <queue>

using namespace std;

int N, M;
int arr[100][100] = { 0, };
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };


void bfs(int x, int y) {
	queue<pair<int, int> > q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1) continue;
			if (arr[nx][ny] == 1) {
				q.push(make_pair(nx, ny));
				arr[nx][ny] = arr[x][y] + 1;
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	arr[0][0] = 2;
	bfs(0, 0);

	printf("%d\n", arr[N - 1][M - 1] - 1);

	return 0;
}