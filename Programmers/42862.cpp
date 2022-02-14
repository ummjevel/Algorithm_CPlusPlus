#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    int lost_cnt = lost.size();
    // 3 
    /*
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for(int i = 0 ; i < reserve.size(); i++) {
        if (find(lost.begin(), lost.end(), reserve[i]) != lost.end()) {
            reserve.erase(remove(reserve.begin(), reserve.end(), reserve[i]), reserve.end());
            lost.erase(remove(lost.begin(), lost.end(), reserve[i]), lost.end());
        }
    }

    for(int i = 0; i < reserve.size(); i++) {
        for(int j = 0; j < lost.size(); j++) {
            if (reserve[i] - 1 == lost[j] || reserve[i] + 1 == lost[j]) {
                lost.erase(remove(lost.begin(), lost.end(), lost[i]), lost.end());
                break;
            }
        }
    }

    answer = n - lost.size();
*/
    // 2. hash 로도 풀어봄. 85%. 1, 6, 7
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    unordered_map<int, int> hash;

    for(int i = reserve.size() - 1 ; i >= 0; i--) {
        hash.insert(make_pair(reserve[i], 1));
    }
    for(auto it = hash.begin() ; it != hash.end(); it++) {
        cout << it->first << ", " << it->second << endl;
    }
    cout << "------------------------" << endl;

    // 자기 자신이 잃어버린 경우
    for(int i = 0; i < lost.size(); i++) {
        auto it = hash.find(lost[i]);
        if (it != hash.end()) {
            it->second -= 1;
            /*
            if (it->second == 0) {
                lost.erase(remove(lost.begin(), lost.end(), lost[i]), lost.end());
                reserve.erase(remove(reserve.begin(), reserve.end(), lost[i]), reserve.end());
            }
            */
        }
    }
    for(auto it = hash.begin() ; it != hash.end(); it++) {
        cout << it->first << ", " << it->second << endl;
    }
    cout << "------------------------" << endl;

    for(auto it = hash.begin() ; it != hash.end(); it++) {
        cout << it->first << ", " << it->second << endl;
    } 
    cout << "------------------------" << endl;


    // 앞 뒤 빌려받는 경우
    for(int i = 0; i < lost.size(); i++) {
        auto it = hash.find(lost[i] - 1);
        if (it != hash.end() && it->second > 0) {
            it->second -= 1;
            cout << "it->first : " << it->first << ", " << it->second << endl;
        
            lost_cnt--;
        } else {
            auto it2 = hash.find(lost[i] + 1);
            if (it2 != hash.end() && it2->second > 0) {
                it2->second -= 1;
                cout << "it2->first : " << it2->first << ", " << it2->second << endl;

                lost_cnt--;
            } else {
                // 둘 다 없음!
                cout << "can't find ..." << endl;
            }
        }
    }
    
     for(auto it = hash.begin() ; it != hash.end(); it++) {
        cout << it->first << ", " << it->second << endl;
    } 
    cout << "------------------------" << endl;
    answer = n - lost_cnt;

    /*
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    // lost 에도 있고 reserve 에도 있는 경우
    // lost 에도 있고 reserve 에 +1, -1 있는 경우
    // lost 에도 있고 reserve 에 없는 경우 answer--

    while(!lost.empty()) {
        if (auto it = find(reserve.begin(), reserve.end(), lost[lost.size() - 1]) != reserve.end()) {
            // 중복된 경우 그냥 제외..

        } else if (auto it = find(reserve.begin(), reserve.end(), lost[lost.size() - 1] - 1) != reserve.end()) {

        } else if (auto it = find(reserve.begin(), reserve.end(), lost[lost.size() - 1] + 1) != reserve.end()) {

        } else {
            answer--;
        }
        lost.pop_back();
    }*/

    // 1 --------------
    /*
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    while(!lost.empty()) {
        auto it = lost.end();
        auto it1 = find(reserve.begin(), reserve.end(), *(it)-1);
        auto it2 = find(reserve.begin(), reserve.end(), *(it)+1);
        auto it3 = find(reserve.begin(), reserve.end(), *(it));
        if (it3 != reserve.end()) {
            reserve.erase(reserve.begin() + distance(reserve.begin(), it));
            continue;
        }
        if (it1 != reserve.end()) {
            reserve.erase(reserve.begin() + distance(reserve.begin(), it1));
        } else if (it2 != reserve.end()) {
            reserve.erase(reserve.begin() + distance(reserve.begin(), it2));
        } else {
            answer--;
        }
        lost.pop_back();
    }
    */
    return answer;
}

int main() {
    int n = 3; // 5;
    vector<int> lost = {1,2,3}; // {2, 4}; // {2, 4};
    vector<int> reserve = {1,2,3};// {3}; // {1, 3, 5};

    // 6 [2,3,5] [1,2,4,6] 5
    // 9, [5,6,8,1,2], [2,3,1,4,8,9 ]
    // 7, [2,3,4,6], [1,2,3]
    int result = solution(n, lost, reserve);
    cout << "result is ... " << result << " ";
    cout << endl;
    return 0;
}