#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int max_width = 0;
    int max_height = 0;

    for(int i = 0 ; i < sizes.size(); i++) {
        vector<int> vec = sizes[i];

        sort(vec.begin(), vec.end());

        if (max_width < vec[0])
            max_width = vec[0];
        if (max_height < vec[1])
            max_height = vec[1];

    }
    cout << "min_width, min_height : " << max_width << ", " << max_height << endl;
    answer = max_width * max_height;
    return answer;
}

int main() {
    vector<vector<int>> sizes = {
        {60, 50}, {30, 70}, {60, 30}, {80, 40}
    };
    cout << solution(sizes) << endl;
    return 0;
}

// 다른 사람 풀이에서는 좌는 min, 우는 max 로 하고 겉은 각각 max로 감싸서 깔끔하게 품.