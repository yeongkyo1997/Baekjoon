// https://www.acmicpc.net/problem/17281

#include <iostream>
#include <vector>
using namespace std;

int info[51][10];
bool check[10];
int n;
int ans;
int location;

vector<int> order;

int go() {

    int point = 0;

    for (int i = 4; i < 7; i++) {
        if (location & (1 << i)) {
            point += 1;

            location = location & ~(1 << i);
        }
    }

    return point;
}

int start() {
    int out = 0;
    int point = 0;
    int first = 1;

    location = 0;

    for (int i = 1; i <= n; i++) {

        int j = first;
        while (true) {

            int result = info[i][order[j]];

            if (result == 1) {
                location += 1;
                location = location << 1;
                point += go();
            } else if (result == 2) {
                location += 1;
                location = location << 2;
                point += go();
            } else if (result == 3) {
                location += 1;
                location = location << 3;
                point += go();
            } else if (result == 4) {
                location += 1;
                for (int k = 0; k < 4; k++) {
                    if (location & (1 << k)) {
                        point += 1;
                    }
                }

                location = 0;
            } else if (result == 0) {
                out++;

                if (out == 3) {
                    out = 0;

                    first = j + 1;
                    if (first == 10)
                        first = 1;

                    location = 0;
                    break;
                }
            }

            j++;
            if (j == 10)
                j = 1;
        }
    }

    return point;
}

void select(int index) {
    if (index > 9) {
        int tmp = start();
        if (ans < tmp)
            ans = tmp;
        return;
    }

    if (index == 4) {
        order.push_back(1);
        check[1] = true;
        select(index + 1);
        order.pop_back();
    } else {
        for (int i = 2; i <= 9; i++) {
            if (check[i])
                continue;

            order.push_back(i);
            check[i] = true;
            select(index + 1);

            check[i] = false;
            order.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> info[i][j];
        }
    }

    order.push_back(0);

    select(1);

    cout << ans << '\n';

    return 0;
}
