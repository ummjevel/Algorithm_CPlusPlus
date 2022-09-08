#include <iostream>
using namespace std;

int N;
int operands[11]; // 수열 
int operators[4]; // 연산자의 개수
int mymin = 1000000001;
int mymax = -1000000001;
void getanswer(int result, int idx)
{
    if(idx == N)
    {
        if(result > mymax)
            mymax = result;
        if(result < mymin)
            mymin = result;
        return;
    }
    for(int i = 0; i < 4; i++)
    {
        if(operators[i] > 0)
        {
            operators[i]--; // 연산자 하나 사용했으므로 1개 줄여줌
            if(i == 0)
                getanswer(result + operands[idx], idx+1);
            else if(i == 1)
                getanswer(result - operands[idx], idx+1);
            else if(i == 2)
                getanswer(result * operands[idx], idx+1);
            else
                getanswer(result / operands[idx], idx+1);
            operators[i]++; // 다른 연산자를 사용할 것이므로 아까 줄였던 연산자 개수 늘려줌
        }
    }
    return;
}
int main() {
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> operands[i];
    for(int i = 0; i < 4; i++)
        cin >> operators[i];
    getanswer(operands[0],1);
    cout << mymax << '\n';
    cout << mymin;
}

// #include <iostream>
// #include <vector>
// #include <sstream>
// #include <string>

// using namespace std;

// vector<int> arr, arr2;
// vector<bool> visited;
// int num;
// long minNum = 10000000001, maxNum = -10000000001;

// void DFS(int number, int idx) {
    
//     if (idx == num) {
//         minNum = minNum < number ? minNum : number;
//         maxNum = maxNum < number ? number : maxNum;
//         return;
//     }

//     for(int i = 0; i < 4; i++) {
//         if(arr2[i] > 0) {
//             // 연산자 개수가 있을 때
//             arr2[i]--;
//             if (i == 0) DFS(number + arr[idx], idx + 1); 
//             else if (i == 1) DFS(number - arr[idx], idx + 1);
//             else if (i == 2) DFS(number * arr[idx], idx + 1);
//             else if (i == 3) DFS(number / arr[idx], idx + 1);

//             arr2[i]++;
//         }
//     }
// }


// int main() {

//     string cnt;
//     string str, temp;
//     int tempCnt = 0;

//     // input
//     getline(cin, cnt);
//     getline(cin, str);
    
//     num = stoi(cnt);
//     stringstream ss(str);

//     while(tempCnt < num) {
//         ss >> str;
//         arr.push_back(stoi(str));
//         cout << str << endl;
//         tempCnt++;
//     }
//     tempCnt = 0;
//     getline(cin, str);
//     stringstream ss2(str);
//     while(tempCnt < 4) {
//         ss2 >> str;
//         arr2.push_back(stoi(str));
//         visited.push_back(false);
//         tempCnt++;
//     }

//     // 가능한 모든 것 찾기
//     DFS(arr[0], 1);

//     cout << maxNum << endl << minNum << endl;

//     return 0;
// }