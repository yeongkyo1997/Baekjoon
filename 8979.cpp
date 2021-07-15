#include <algorithm>
#include <iostream>

using namespace std;

struct Medal {
    int gold;
    int silver;
    int bronze;
};

bool compare(const Medal a, const Medal b) {
    if (a.gold < b.gold)
        return false;
    else if (a.gold > b.gold)
        return true;
    else {
        if (a.silver < b.silver)
            return false;
        else if (a.silver > b.silver)
            return true;
        else {
            if (a.bronze < b.bronze)
                return false;
            else if (a.bronze > b.bronze)
                return true;
            else
                return true;
        }
    }
}

bool sameRank(Medal a, Medal b) {
    if (a.gold == b.gold && a.silver == b.silver && a.bronze == b.bronze)
        return true;
    else
        return false;
}

int main() {
    Medal m[1000];
    int n, k;
    int number;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> number >> m[i].gold >> m[i].silver >> m[i].bronze;

    sort(m, m + n, compare);
}