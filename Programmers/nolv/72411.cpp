#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

map<string, int> m;

void combination(vector<char> orders, string order, int index, int select) {
    if (select == 0) {
        if (m.find(order) == m.end())
            m.insert({order, 1});
        else
            m[order]++;
        return;
    }
    for(int i = index; i < orders.size(); i++) {
        combination(orders, order + orders[i], i + 1, select - 1);
    }
    return;
}

vector<string> solution(vector<string> orders, vector<int> course) {

    vector<string> answers;
    map<int, int> courseMax;    // key : course[i], value : max counter
    map<int, vector<string> > courseResult; // key : course[i], value : (max menus){, , }
    // map<int, map<string, vector<string> > > courseA;

    for(int i = 0; i < course.size(); i++) {
        vector<string> strings;
        courseMax.insert({course[i], 0});
        courseResult.insert({course[i], strings});
    }

    for(int i = 0; i < orders.size(); i++) {
        vector<char> order;
        for(int j = 0; j < orders[i].length(); j++) {
            order.push_back(orders[i][j]);
        }
        sort(order.begin(), order.end());
        for(int j = 0; j < course.size(); j++)
             combination(order, "", 0, course[j]);
    }

    // 2번 이상인 것만 남기기
    for(map<string, int>::iterator it = m.begin(); it != m.end(); ) {
        if (it->second < 2) {
            it++;
            continue; // m.erase(it++);
        }
        else {
            if (courseMax[it->first.length()] < it->second) {
                courseMax[it->first.length()] = it->second;
                courseResult[it->first.length()].clear();
                courseResult[it->first.length()].push_back(it->first);
            } else if (courseMax[it->first.length()] == it->second) {
                courseResult[it->first.length()].push_back(it->first);
            }
            it++;
        }
    }

    for(map<int, vector<string> >::iterator it = courseResult.begin(); it != courseResult.end(); it++) {
        answers.insert(answers.end(), it->second.begin(), it->second.end());
    }


    sort(answers.begin(), answers.end());
    return answers;
}

// vector<string> solution(vector<string> orders, vector<int> course) {
//     vector<string> answer;
    
//     sort(orders.begin(), orders.end());
    
//     map<string, int> m;
    
//     for(int i = 0; i < course.size(); i++) {
//         for(int j = 0; j < orders.size(); j++) {
//             if (orders[j].size() == course[i])
//                 m.insert({orders[j], 0});
//         }
//     }
//     map<string, int >::iterator iter;
//     for(iter = m.begin(); iter != m.end(); iter++) {
//         for(int j = 0; j < orders.size(); j++) {
//             if(orders[j].find(iter->first) != std::string::npos) {
//                 iter->second++;
//             }
//         }
//         if (iter->second >= 2) {
//             answer.push_back(iter->first);
//         }
//     }

//     sort(answer.begin(), answer.end());
    
//     return answer;
// }

int main() {
    vector<string> orders = {"XYZ", "XWY", "WXA"};
    vector<int> course = {2, 3, 4};
    solution(orders, course);
    return 0;
}