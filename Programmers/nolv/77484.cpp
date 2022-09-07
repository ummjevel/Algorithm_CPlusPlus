#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int zero_cnt = 0;
    int match_cnt = 0;
    int max_rank = 0;
    int min_rank = 0;

    for(vector<int>::iterator iter_lo = lottos.begin(); iter_lo != lottos.end(); iter_lo++) {
        if (*iter_lo == 0) {
            zero_cnt++;
            continue;       
        }
        for(vector<int>::iterator iter_win = win_nums.begin(); iter_win != win_nums.end(); iter_win++) {
            if(*iter_lo == *iter_win) {
                match_cnt++;
            }
        }
    }

    max_rank = 7 - (match_cnt + zero_cnt);
    min_rank = 7 - match_cnt;
    
    if(max_rank == 7)
        max_rank = 6;
    if(min_rank == 7)
        min_rank = 6;
    
    answer.push_back(max_rank);
    answer.push_back(min_rank);
    
    cout << "zero_cnt: " << zero_cnt << ", match_cnt: " << match_cnt << endl;
    cout << "max_rank: " << max_rank << ", min_rank: " << min_rank << endl;

    return answer;
}


int main() {


    vector<int> lottos; // [44, 1, 0, 0, 31, 25]
    vector<int> win_nums; // [31, 10, 45, 1, 6, 19] // [3, 5]

    lottos.push_back(44);
    lottos.push_back(1);
    lottos.push_back(0);
    lottos.push_back(0);
    lottos.push_back(31);
    lottos.push_back(25);

    win_nums.push_back(31);
    win_nums.push_back(10);
    win_nums.push_back(45);
    win_nums.push_back(1);
    win_nums.push_back(6);
    win_nums.push_back(19);

    solution(lottos, win_nums);
    return 0;
}