#include <bits/stdc++.h>
using namespace std;

#define MAX 10000

int main() {

    // input

    string input;
    string queue[MAX];

    int count = 0;
    while (true) {
        cin >> input;

        if (input == "END") {
            break;
        }

        queue[count] = input;

        count++;
    }

    // get customers into counters + get last counter used

    int current_customer = 0;
    int final_call, total_time;
    for (int time = 1; time < MAX; time++) {

        if ( (time - 1) % 5 == 0 ) {
            cout << time << " counterA : " << queue[current_customer] << '\n';
            current_customer++;
        }
        if (current_customer >= count) {
            final_call = time;
            total_time = final_call + 4;
            break;
        }


        if ( (time - 1) % 8 == 0 ) {
            cout << time << " counterB : " << queue[current_customer] << '\n';
            current_customer++;
        }
        if (current_customer >= count) {
            final_call = time;
            total_time = final_call + 7;
            break;
        }

    }

    // output

    cout << "Final Called " << final_call << '\n';
    cout << "Total Time " << total_time << '\n';
}