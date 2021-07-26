// https://www.acmicpc.net/problem/10820

#include <iostream>
#include <string>

using namespace std;

int main() {
    for (int i = 0; i < 100; i++) {
        string str;
        getline(cin, str);

        if (str.length() == 0)
            break;

        int upper = 0, lower = 0, number = 0, space = 0;
        for (int j = 0; j < str.length(); j++)
            if (str[j] >= 'A' && str[j] <= 'Z')
                upper++;
            else if (str[j] >= 'a' && str[j] <= 'z')
                lower++;
            else if (str[j] >= '0' && str[j] <= '9')
                number++;
            else if (str[j] == ' ')
                space++;

        cout << lower << " " << upper << " " << number << " " << space << "\n";
    }
    return 0;
}
