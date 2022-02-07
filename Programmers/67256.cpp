#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int prev_left = -1, prev_right = -1;
    // ------------ 2 ----------------

    // 배열에 집어넣기
    // index 찾아서 
    for(int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            // 1, 4, 7 은 왼손
            // 넣은 게 L, R 여부에 따라 이전 것 변경해서 넣어주기
            answer += "L";
            prev_left = numbers[i];
        } else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            // 3, 6, 9 는 오른손
            // 넣은 게 L, R 여부에 따라 이전 것 변경해서 넣어주기
            answer += "R";
            prev_right = numbers[i];
        } else {
            // 2, 5, 8, 0
            int dis_left, dis_right;
        }
    }


    /*
    // ------------ 1 -----------------
    int prev_left = -1, prev_right = -1;
    vector<int> prime3;
    vector<int> prime4;
    vector<int> prime24;
    prime3.push_back(1); prime3.push_back(3);
    prime4.push_back(1); prime4.push_back(4);
    prime24.push_back(2); prime24.push_back(4);
    
    for(int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            // 1, 4, 7 은 왼손
            // 넣은 게 L, R 여부에 따라 이전 것 변경해서 넣어주기
            answer += "L";
            prev_left = numbers[i];
        } else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            // 3, 6, 9 는 오른손
            // 넣은 게 L, R 여부에 따라 이전 것 변경해서 넣어주기
            answer += "R";
            prev_right = numbers[i];
        } else {
            // 2, 5, 8, 0
            int dis_left, dis_right;
            // 현재 키패드의 위치에서 엄지 거리 확인

            if(prev_left == 0)
                prev_left = 11;
            if (prev_right == 0)
                prev_right = 11;

            if (prev_left == -1)
                prev_left = 10;
            if (prev_right == -1)
                prev_right = 12;

            if (numbers[i] == 0) {
                numbers[i] = 11;
            }

            dis_left = numbers[i] - prev_left;
            dis_right = numbers[i] - prev_right;
            cout << "prev_left : " << prev_left << ", prev_right : " << prev_right << ", current num : " << numbers[i] << endl;
            cout << "dis_left : " << dis_left << ", dis_right : " << dis_right << endl;

            // 1, 3
            if (find(prime3.begin(), prime3.end(), dis_left) != prime3.end()
            && find(prime3.begin(), prime3.end(), dis_right) != prime3.end()) {
                dis_left = 0; dis_right = 0;
            }
            // 1, 2, 4
            else if (find(prime4.begin(), prime4.end(), dis_left) != prime4.end()
            && find(prime4.begin(), prime4.end(), dis_right) != prime4.end()) {
                dis_left = 0; dis_right = 0;
            }
            else if (find(prime24.begin(), prime24.end(), dis_left) != prime24.end()
            && find(prime24.begin(), prime24.end(), dis_right) != prime24.end()) {
                dis_left = 0; dis_right = 0;
            }
            dis_left = abs(dis_left);
            dis_right = abs(dis_right);
            cout << "dis_left : " << dis_left << ", dis_right : " << dis_right << endl;
            // 거리가 같은 경우 hand 검사, 더 가까운 엄지 사용
            if((dis_left == dis_right && hand == "left") || 
                dis_left < dis_right) {
                answer += "L";
                prev_left = numbers[i];
            } else if ((dis_left == dis_right && hand == "right") || 
                dis_left > dis_right) {
                answer += "R";
                prev_right = numbers[i];
            }
            cout << "current answer: " << answer << endl;
            cout << "------------------------------------------" << endl;
        }
    }
    */
    return answer;
}

int main() {

    string hand = "right";
    vector<int> numbers;    
    // [1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5]
    /*
    numbers.push_back(1);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(5);
    numbers.push_back(8);
    numbers.push_back(2);
    numbers.push_back(1);
    numbers.push_back(4);
    numbers.push_back(5);
    numbers.push_back(9);
    numbers.push_back(5);

    // [7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2]
    numbers.push_back(7);
    numbers.push_back(0);
    numbers.push_back(8);
    numbers.push_back(2);
    numbers.push_back(8);
    numbers.push_back(3);
    numbers.push_back(1);
    numbers.push_back(5);
    numbers.push_back(7);
    numbers.push_back(6);
    numbers.push_back(2);
*/
    // [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(5);
    numbers.push_back(6);
    numbers.push_back(7);
    numbers.push_back(8);
    numbers.push_back(9);
    numbers.push_back(0);

    solution(numbers, hand);
    
    return 0;
}
/*
LRLLLRLLRRL
LRLLRLLLLRL
*/