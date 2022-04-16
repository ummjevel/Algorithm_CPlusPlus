#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    sort(orders.begin(), orders.end());
    
    map<string, int> m;
    
    for(int i = 0; i < course.size(); i++) {
        for(int j = 0; j < orders.size(); j++) {
            if (orders[j].size() == course[i])
                m.insert({orders[j], 0});
        }
    }
    map<string, int >::iterator iter;
    for(iter = m.begin(); iter != m.end(); iter++) {
        for(int j = 0; j < orders.size(); j++) {
            if(orders[j].find(iter->first) != std::string::npos) {
                iter->second++;
            }
        }
        if (iter->second >= 2) {
            answer.push_back(iter->first);
        }
    }

    sort(answer.begin(), answer.end());
    
    return answer;
}

int main() {
    vector<string> orders = {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
    vector<int> course = {2, 3, 4};
    solution(orders, course);
    return 0;
}