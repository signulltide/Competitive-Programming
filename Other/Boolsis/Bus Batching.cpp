#include <bits/stdc++.h>
using namespace std;

#define MAX 10000

int main() {
    string input;
    string arr[MAX];

    int i = 0;
    while (true) {
        cin >> input;

        if (input == "END") {
            break;
        }

        arr[i] = input;

        i++;
    }

    for (int j=0; j<i; j++) {
        if (j % 5 == 0) {
            if (j != 0) {
                cout << '\n';
            }
            cout << "Bus " << (j / 5) + 1 << ": ";
        }

        cout << arr[j] << " ";
    }
}