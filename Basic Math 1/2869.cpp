// https://www.acmicpc.net/problem/2869

#include <stdio.h>

int main() {
	int a, b, v;
	int day;
	scanf("%d %d %d", &a, &b, &v);
	day = (v - b - 1) / (a - b) + 1;
	printf("%d", day);
}