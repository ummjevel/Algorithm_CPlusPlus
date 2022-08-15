#include <iostream>

using namespace std;

int main() {

    int h, m, add;
    cin >> h >> m;
    cin >> add;

    if (m + add >= 60) {
        h = (h + (m + add)/60)%24;
        m = (m + add)%60;
    } else {
        m = m + add;
    }

    cout << h << " " << m;

    return 0;
}