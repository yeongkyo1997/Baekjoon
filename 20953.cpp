#include <cstdio>

using namespace std;

long long int dolmen(int a, int b) {
    return (a + b) * (((a + b) * (a + b - 1)) / 2);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%lld\n", dolmen(a, b));
    }
}