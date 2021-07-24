#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<string, int> mp;

typedef struct game {
    int x, y;
    double win, draw, lose;
} Game;

Game gameArr[6];
double ret[6];
int score[6];
vector<pair<int, int>> finalScore(4);
void func(int idx, double proc) {
    if (idx == 6) {
        if (proc == 0)
            return;
        for (int i = 0; i < 4; i++) {
            finalScore[i] = {score[i], i};
        }
        sort(finalScore.begin(), finalScore.end());
        int aScore = finalScore[0].first,
            bScore = finalScore[1].first,
            cScore = finalScore[2].first,
            dScore = finalScore[3].first;

        int a = finalScore[0].second,
            b = finalScore[1].second,
            c = finalScore[2].second,
            d = finalScore[3].second;

        if (bScore != cScore) {
            ret[c] += proc;
            ret[d] += proc;
        } else if (aScore == bScore && cScore == dScore) {
            ret[a] += proc / 2;
            ret[b] += proc / 2;
            ret[c] += proc / 2;
            ret[d] += proc / 2;
        } else if (aScore == bScore) {
            ret[a] += proc / 3;
            ret[b] += proc / 3;
            ret[c] += proc / 3;
            ret[d] += proc;
        } else if (cScore == dScore) {
            ret[b] += proc * 2 / 3;
            ret[c] += proc * 2 / 3;
            ret[d] += proc * 2 / 3;
        } else {
            ret[b] += proc / 2;
            ret[c] += proc / 2;
            ret[d] += proc;
        }
        return;
    }

    Game g = gameArr[idx];
    score[g.x] += 3;
    func(idx + 1, proc * g.win);
    score[g.x] -= 3;

    score[g.x]++;
    score[g.y]++;
    func(idx + 1, proc * g.draw);
    score[g.x]--;
    score[g.y]--;

    score[g.y] += 3;
    func(idx + 1, proc * g.lose);
    score[g.y] -= 3;
}
int main() {
    int i;
    string a, b;
    double p, q, r;
    for (i = 0; i < 4; i++) {
        cin >> a;
        mp[a] = i;
    }

    for (i = 0; i < 6; i++) {
        cin >> a >> b >> p >> q >> r;
        gameArr[i] = { mp[a], mp[b], p, q, r };
    }

    func(0, 1.0);

    cout << fixed;
    cout.precision(10);
    for (i = 0; i < 4; i++) {
        cout << ret[i] << endl;
    }
}