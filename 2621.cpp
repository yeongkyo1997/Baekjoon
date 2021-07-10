// https://www.acmicpc.net/problem/2621

#include <algorithm>
#include <iostream>

using namespace std;

struct Card {
    char color;
    int num;
};

int main() {
    int maximum = 0;
    int pair1 = 0;
    int pair2 = 0;
    int three = 0;
    int four = 0;

    int colorArr[4] = {
        0,
    };
    int digitsArr[10] = {
        0,
    };

    Card c[5];

    for (int i = 0; i < 5; i++) {
        cin >> c[i].color >> c[i].num;
        maximum = max(maximum, c[i].num);

        switch (c[i].color) {
        case 'R':
            colorArr[0]++;
            break;

        case 'G':
            colorArr[1]++;
            break;

        case 'B':
            colorArr[2]++;
            break;

        case 'Y':
            colorArr[3]++;
            break;
        }
        digitsArr[c[i].num]++;
    }

    bool isFulsh = false;
    if (colorArr[0] == 5 || colorArr[1] == 5 || colorArr[2] == 5 ||
        colorArr[3] == 5 || colorArr[4] == 5) {
        isFulsh = true;
    }

    bool isStraight = false;

    if (isStraight) {
        for (int i = 1; i <= 6; i++) {
            if (digitsArr[i] && digitsArr[i + 1] && digitsArr[i + 2] &&
                digitsArr[i + 3] && digitsArr[i + 4]) {
                isStraight = true;
            }
        }
    }
}