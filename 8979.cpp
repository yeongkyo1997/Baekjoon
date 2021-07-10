#include <algorithm>
#include <iostream>

using namespace std;

struct Medal {
    int gold;
    int silver;
    int bronze;
};

bool compare(const int a[][4], const int b[][4]) {
    if (a[1] < b[1])
        return true;

    else if (a[1] > b[1])
        return false;

    else {
        if (a[2] < b[2])
            return true;

        else if (a[2] > b[2])
            return false;

        else {
            if (a[3] < b[3])
                return true;

            else if (a[3] > b[3])
                return false;
            else
                return true;
        }
    }
}

int main() {
    Medal m[1000];
    int n, k;
    int number;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> number >> m[i].gold >> m[i].silver >> m[i].bronze;
}