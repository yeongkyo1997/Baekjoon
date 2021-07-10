// https://www.acmicpc.net/problem/2621

#include <iostream>
#include <algorithm>

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
    int max = 0;
    bool check = true;
    for (int i = 0; i < 5; i++) {
        cin >> c[i].color >> c[i].num;
    }

    sort(c, c + 5, compare);

    // Rule 1
    
    for (int i = 0; i < 4; i++) {
        if (c[i].num + 1!= c[i + 1].num || c[i].color != c[i + 1].color) {
            check = false;
            break;
        }
    }
    if (check) {
        cout << 900 + c[4].num;
        return 0;
    }

    // Rule 2

    for (int i = 0; i < 2; i++) {
        check = true;
        for (int j = i; j < i + 3; j++) {
            if (c[j].num != c[j + 1].num){
                check = false;
            }
        }
        if (check) {
            cout << 800 + c[i].num;
            return 0;
        }   
    }

    // Rule 3

    int three;
    int two;

    // 3개가 같은 경우
    check = true;

    for (int i = 0; i < 3; i++) {
        for (int j = i; j < i + 2; j++) {
            if (c[j].num != c[j + 1].num) {
                check = false;
            }
        }

        if (check) {
            three = c[i].num;
            break;
        }
    }
    
    // 2개가 같은 경우
    if (check) {
        check = true;

        for (int i = 0; i < 4; i++) {
            if (c[i].num != c[i + 1].num || c[i].num == three) {
                check = false;
            }
            else {
                check = true;
            }

            if (check) {
                two = c[i].num;
                cout << three * 10 + two + 700;
                return 0;
            }
        }
    }

    // Rule 4
    check = true;

    for (int i = 0; i < 4; i++) {
        if (c[i].color != c[i + 1].color) {
            check = false;
        }
    }

    if (check) {
        cout << 600 + c[4].num;
        return 0;
    }

    // Rule 5

    check = true;
        
    for (int j = 0; j < 4; j++) {
        if (c[j].num + 1  != c[j + 1].num) {
            check = false;
        }
    }
    if (check) {
        cout << 500 + c[4].num;
        return 0;
    }

    // Rule 6

    for(int i = 0; i < 3; i ++) {
        check = true;
        for (int j = i; j < i + 2; j++) {
            if (c[j].num != c[j + 1].num) {
                check = false;
            }
        }
        if (check) {
            cout << 400 + c[i].num;
            return 0;
        }
    }

    // Rule 7
    int result = 300;
    int bigStart;
    
    for(int i = 0; i < 4; i ++) {
        if (c[i].num != c[i + 1].num) {
            check = false;
        }
        else {
            check = true;
        }
        if (check) {
            result += c[i].num;
            bigStart = i + 1;
            break;
        }
    }
    
    if (check) {
        for(int i = bigStart; i < 4; i ++) {

            if (c[i].num != c[i + 1].num) {
                check = false;
            }
            else {
                check = true;
            }
            if (check) {
                result += c[i].num * 10;
                cout << result;
                return 0;
            }
        }
    }

    // Rule 8

    for (int i = 0; i < 4; i ++) {
        if (c[i].num == c[i + 1].num) {
            cout << 200 + c[i].num;
            return 0;
        }
    }

    // Rule 9

    cout << 100 + c[4].num;
}