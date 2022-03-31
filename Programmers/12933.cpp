#include <string>
#include <vector>
#include <algorithm>

using namespace std;


long long solution(long long n) {
    long long answer = 0;
    vector<int> vec;
    string temp = to_string(n);
    for(int i = 0; i < temp.length(); i++) {
        vec.push_back(temp[i] - '0');
    }
    
    sort(vec.begin(), vec.end());
    
    int i = 1;
    int idx = 0;
    while(idx < vec.size()) {
        answer += i * vec[idx];
        idx++;
        i *= 10;
    }
    
    return answer;
}

 // 변환이 비슷한 문제 있었는데 거기서도 다른 사람 풀이에서 string 그대로를 정렬하는 것 있었음..
    // string str = to_string(n);
    // sort(str.begin(), str.end(), greater<char>());
    // answer = stoll(str);