// https://www.acmicpc.net/problem/2621

#include <iostream>

using namespace std;

struct Card {
    char color;
    int num;
};

bool compare(const Card c1, const Card c2) {
    if (c1.num < c2.num) {
        return true;
    }
    else if (c1.num == c2.num) {
        return c1.color <= c2.color;
    }
    else {
        return false;
    }
}

int main() {
    Card c[5];
    
    for (int i = 0; i < 5; i++) {
        cin >> c[i].color >> c[i].num;
    }

    sort(c, c + 5, compare);

    if (c[0].color == c[1].color && c[1].color == c[2].color && c[2].color == c[3].color && c[4].color == c[5].color) {
        if (c[0].num + 4 == c[1].num + 3 && c[1].num + 3 == c[2].num + 2 && c[3].num + 2 == c[4].num + 1 && c[4].num + 1 == c[5].num) {
            cout << 900 + c[5].num;
            return;
        }
    }
    
    for (int i = 0; i < 5; i++) {
        int cnt = 0;
        int start;
        for (int j = i; j < 4; j++) {
            if (c[j].num == c[j + 1].num) {
                start = c[j].num;
                cnt++;
            }
        }

        if (cnt >= 4) {
            cout << 800 + start;
            return;
        }
    }

    
}