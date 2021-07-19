// https://www.acmicpc.net/problem/14002

#include <stdio.h>
int dp[1001];
int num[1001];
int v[1001];
int max = -2147000000;
void go(int p) {
    if (p == 0)
        return;
    go(v[p]);
    printf("%d ", num[p]);
}

int main() {

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
    }
    for (int i = 1; i <= n; i++) {

        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (num[i] > num[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                v[i] = j;
            }
        }
    }
    int p = 0;
    for (int i = 1; i <= n; i++) {
        if (max < dp[i]) {
            max = dp[i];
            p = i;
        }
    }
    printf("%d\n", max);
    go(p);
    printf("\n");
    return 0;
}