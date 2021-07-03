// https://www.acmicpc.net/problem/1712


#include <cstdio>
using namespace std;

int main() {

    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if (b >= c) printf("-1\n");
    else printf("%d\n", a/(c-b) + 1);
    return 0;
}