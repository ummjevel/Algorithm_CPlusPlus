#include <iostream>
#include <string>

using namespace std;

int main() {

    int king, queen, look, bishop, knight, pone;
    int king1 = 1, queen1 = 1, look1 = 2, bishop1 = 2, knight1 = 2, pone1 = 8;
    cin >> king >> queen >> look >> bishop >> knight >> pone;
    cout << king1 - king << " " << queen1 - queen << " " << look1 - look << " " << bishop1 - bishop << " " << knight1 - knight << " " << pone1 - pone; 

}