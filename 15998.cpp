// https://www.acmicpc.net/problem/15998

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 300000;
typedef long long ll;
int n;
ll arr[MAX][2];
vector<pair<int, ll>> vec;
vector<ll> measure;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int i, chk = 1;
    ll curMoney = 0;
    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
        if (arr[i][0] < 0 && -arr[i][0] > curMoney) {
            ll km = arr[i][1] - arr[i][0] - curMoney;

            vec.emplace_back(i, km);
        } else if (curMoney + arr[i][0] != arr[i][1]) {
            chk = 0;
        }
        curMoney = arr[i][1];
    }

    if (!chk) {
        cout << -1;
        return 0;
    }
    if (vec.size()) {

        ll tmp = vec[0].second;
        for (i = 1; i < vec.size(); i++) {
            if (tmp < vec[i].second)
                tmp = gcd(vec[i].second, tmp);
            else
                tmp = gcd(tmp, vec[i].second);
        }

        int chk = 1;
        for (auto it : vec) {
            int idx = it.first;
            ll prev = (idx == 0 ? 0 : arr[idx - 1][1]);
            if (it.second - tmp >= -(prev + arr[idx][0])) {
                chk = 0;
                break;
            }
        }
        if (chk) {
            cout << tmp;
            return 0;
        }
        cout << -1;
    } else
        cout << 1;
}