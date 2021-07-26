// https://www.acmicpc.net/problem/6996

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {

        string str1;
        int arr1['z' - 'a' + 1] = {
            0,
        };

        string str2;
        int arr2['z' - 'a' + 1] = {
            0,
        };

        cin >> str1 >> str2;

        for (int j = 0; j < str1.size(); j++) {
            arr1[str1[j] - 'a']++;
        }

        for (int j = 0; j < str2.size(); j++) {
            arr2[str2[j] - 'a']++;
        }

        int sum = 0;
        for (int j = 0; j < 'z' - 'a' + 1; j++) {
            sum += abs(arr1[j] - arr2[j]);
        }

        if (sum == 0)
            cout << str1 << " & " << str2 << " are anagrams." << endl;
        else
            cout << str1 << " & " << str2 << " are NOT anagrams." << endl;
    }
}