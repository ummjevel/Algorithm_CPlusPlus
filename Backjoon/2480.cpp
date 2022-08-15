#include <iostream>
#include <set>

using namespace std;

int main() {
    int dice[7] = {0, 0, 0, 0, 0, 0, 0};
    int a, b, c, max = -1;
    bool isDone;
    cin >> a >> b >> c;
    dice[a]++;
    dice[b]++;
    dice[c]++;

    for(int i = 1; i < 7; i++) {
        if (dice[i] == 3) {
            cout << 10000 + i * 1000;
            isDone = true;
            break;
        } else if (dice[i] == 2) {
            cout << 1000 + i * 100;
            isDone = true;
            break;
        }
    }

    if (!isDone) {
        max = a > b ? a : b > c ? b : c;
        cout << max * 100;
    }


    return 0;
}