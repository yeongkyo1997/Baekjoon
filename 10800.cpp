// https://www.acmicpc.net/problem/10800

#include <cstdio>
#include <iostream>

using namespace std;

struct Ball {
    int color;
    int size;
};

bool compare(const Ball a, const Ball b) {
    if (a.size > b.size)
        return true;
    else
        return false;
}

int main() {
    Ball b[200000];
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d %d", &b[i].color, &b[i].size);

    sort(b, b + n, compare);

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i + 1; j < n; j++) {
            if (b[i].color != b[j].color)
                sum += b[j].size;
            else
                continue;
        }
        printf("%d\n", sum);
    }
}