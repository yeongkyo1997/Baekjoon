// https://www.acmicpc.net/problem/10757

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main() {
    char a[100002];
    char b[100002];
    int result[100002] = { 0, };
    cin >> a >> b;

    int sizeA = strlen(a);
    int sizeB = strlen(b);

    while (sizeA != -1 && sizeB != -1) {
        if (strlen(a) > strlen(b)) {
            if (sizeA != 0)
                result[sizeA] += (int)(a[sizeA - 1] - '0');
            if (sizeB != 0)
                result[sizeA] += (int)(b[sizeB - 1] - '0');
            
            if (result[sizeA] >= 10) {
                result[sizeA - 1] += 1;
                result[sizeA] %= 10;
            }

            sizeA--;
            sizeB--;
        }
        else {
            if (sizeB != 0)
                result[sizeB] += (int)(b[sizeB - 1] - '0');
            
            if (sizeA != 0)
                result[sizeB] += (int)(a[sizeA - 1] - '0');

            if (result[sizeB] >= 10) {
                result[sizeB - 1] += 1;
                result[sizeB] %= 10;
            }

            sizeA--;
            sizeB--;
        }
    }
    // sizeA++;
    // sizeB++;

    if (sizeA > sizeB) {
        while (sizeA != 0) {
            result[sizeA + 1] += (int)(a[sizeA--] - '0');
            if (result[sizeA + 1] >= 10) {
                result[sizeA] += 1;
                result[sizeA + 1] %= 10;
            }
        }
    }

    if (sizeB > sizeA) {
        while (sizeB != 0) {
            result[sizeB + 1] += (int)(b[sizeB--] - '0');

            if (result[sizeB + 1] >= 10) {
                result[sizeB] += 1;
                result[sizeB + 1] %= 10;
            }
        }
    }

    if (result[1] >= 10) {
                result[0] = 1;
                result[1] %= 10;
    }

    if (sizeA > sizeB) {
        if (result[0] != 0) {
            for (int i = 0; i < strlen(a) + 1; i++) {
                printf("%d", result[i]);
            }
        }
        else {
            for (int i = 1; i < strlen(a) + 1; i++) {
                printf("%d", result[i]);
            }
        }
    }
    else {
        if (result[0] != 0) {
            for (int i = 0; i < strlen(b) + 1; i++) {
                printf("%d", result[i]);
            }
        }
        else {
            for (int i = 1; i < strlen(b) + 1; i++) {
                printf("%d", result[i]);
            }
        }
    }
}