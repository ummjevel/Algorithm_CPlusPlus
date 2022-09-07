#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    // 1 - 실패 74.0, 성공 -> 0 으로 나누게 되는 경우 처리
    vector<pair<int, int> > vec;  // 각 스테이지별 개수 (stage, 개수)
    vector<pair<int, float> > fvec;   // 스테이지별 실패 수 (stage, 실패율)

    for(int i = 1; i <= N + 1; i++) {
        vec.push_back(make_pair(i, 0));
        fvec.push_back(make_pair(i, 0.0f));
    }
    
    // stages 돌리면서 해당되는 숫자에 넣어주고
    for(int i = 0; i < stages.size(); i++) {
        int j = stages[i];
        auto it = find_if(vec.begin(), vec.end(), [&j](const std::pair<int,int> &p) {
            return j == p.first;
        });
        it->second++;
    }
 
    // stage 현 상태가 아니라, 지나간 사람들까지 더해놓아서 총 통과한 사람을 표시하도록 하기
    for(int i = 0; i < vec.size(); i++) {
        float size = stages.size();

        // 자기 이전의 개수를 뺀다.
        for(int j = 0; j < i; j++) {
            size -= vec[j].second;
        }
        
        // 0 으로 나누게 되는 경우 처리
        if (vec[i].second == 0)
            continue;

        fvec[i].second = static_cast< float >(vec[i].second/size) * 1000;
    }

    cout << " vec -----------------" << endl;
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i].first << ", " << vec[i].second << endl;
    }
    cout << " fvec -----------------" << endl;
    for(int i = 0; i < fvec.size(); i++) {
        cout << fvec[i].first << ", " << fvec[i].second << endl;
    }

    // sort, 높은 순으로, 같은 값일 경우 작은 번호의 스테이지로 정렬.
    std::sort(fvec.begin(), fvec.end(), [](const std::pair<int,float> &left, const std::pair<int,float> &right) {

        if (left.second == right.second) {
            return left.first < right.first;
        }
        return left.second > right.second;
    });


    for(int i = 0; i < fvec.size(); i++) {
        if (fvec[i].first == N + 1)
            continue;
        answer.push_back(fvec[i].first);
    }

    cout << " answer -----------------" << endl;
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }

    return answer;
}


int main() {

    int N = 5;
    vector<int> stages = {2,1,2,4,2,4,3,3};
    // 3,4,2,1,5
    vector<int> answer = solution(N, stages);
    
    for(int i = 0 ; i < answer.size(); i++) 
        cout << answer[i] << " ";
    cout << endl;
/*
    vector<pair<int, int>>v;

    v.push_back({2, -2});
	v.push_back({1, 1});
	v.push_back({1, -1});
	v.push_back({2, 2});
	v.push_back({3, -2});

    std::sort(v.begin(), v.end(), [](const std::pair<int,int> &left, const std::pair<int,int> &right) {

        if (left.second == right.second) {
            return left.first == right.first;
        }
        return left.second < right.second;
    });

	for(auto i : v){
		cout<<i.first<<" "<<i.second<<endl;
	}
    */
    return 0;
}