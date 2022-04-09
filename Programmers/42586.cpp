#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> vec; // 각 프로세스마다 걸리는 기한을 넣어둘 벡터
    vector<pair<int, int> > pairs;  // 기한과 해당 갯수를 pair로 넣어둘 벡터
    
    // 각 프로세스마다 걸리는 기한 넣기
    for(int i = 0; i < progresses.size(); i++) {
        int progress = progresses[i];
        int speed = speeds[i];
        int cnt = 0;
        while(progress < 100) {
            progress += speed;
            cnt++;
        }
        vec.push_back(cnt);
    }
    
    
    // 넣어둔 기한으로 배포 작업 횟수 확인, 앞이 처리가 될 경우에만 뒤에 것이 처리가능.
    for(int i = 0 ; i < vec.size(); i++) {
        if(i == 0) {
            // 첫번째는 무조건 넣어준다.
            pairs.push_back(make_pair(vec[i], 1));
            continue;
        }
        // 5, 10 인 경우 10을 넣어준다.
        if(pairs.back().first < vec[i]) {
            pairs.push_back(make_pair(vec[i], 1));
        } else {
            // 10, 1인 경우 10에 갯수를 추가한다.
            pairs.back().second++;
        }
    }
    
    for(int i = 0; i < pairs.size(); i++) {
        answer.push_back(pairs[i].second);
    }
    
    
    return answer;
}

// 2번째 풀이.
// #include <string>
// #include <vector>
// #include <cmath>

// using namespace std;

// vector<int> solution(vector<int> progresses, vector<int> speeds) {
//     vector<int> answer;
    
//     // 각자 필요한 날 수 계산
//     int i = 0;
//     int pdays;
//     while(i < progresses.size()) {
        
//         int days = ceil((double)(100 - progresses[i])/speeds[i]);
//         // (100 - progresses[i])/speeds[i] 로 할 경우 테스트11 통과못함
//         // (99 - progresses[i])/speeds[i] + 1
//         // ceil 도 실패. ? 형변환..
//         // 자기 앞의 날과만 비교해서 더하면 되는 거니까.
//         if (i == 0) {
//             pdays = days;
//             answer.push_back(1);
//         } else if (pdays < days) {
//             answer.push_back(1);
//             pdays = days;
//         } else if (pdays >= days) {
//             answer.back()++;
//         }
//         i++;
//     }
    
    
//     return answer;
// }