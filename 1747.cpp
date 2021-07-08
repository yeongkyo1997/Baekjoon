// https://www.acmicpc.net/problem/1747

#include <iostream>
#include <cstdio>

using namespace std;

bool isReversed(int num) {
    int reverse = 0;
    int temp = num;

    while (true) {
        reverse += temp % 10;
        temp /= 10;

        if (temp == 0) {
            break;
        }
        reverse *= 10;
    }

    if (reverse == num) {
        return true;
    }

    else {
        return false;
    }
}

void eratos(bool arr[]) {
	for (int i = 2; i <= 1003001; i++)
	    arr[i] = true;

	for (int i = 2; i <= 1003001; i++)
	{
		if (arr[i])
			for (int j = i * 2; j <= 1003001; j += i)
			    arr[j] = false;
	}

}

int main() {
    int n;
    bool arr[1003001];

    cin >> n;

    eratos(arr);

    for (int i = n; i <= 1003001; i++) {
        if (arr[i] == true && isReversed(i)) {
            printf("%d\n", i);
            break;
        }
    }
}