// 신고 결고 받기
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    answer.assign(id_list.size(), 0);
    // stop_list : 신고당한 횟수
    vector<int> stop_list;
    stop_list.assign(id_list.size(), 0);

    // answer_list : 해당하는 유저 여부 (1: true, 0: false) -> 이걸로 더해줄 예정.
    vector<int> answer_list;
    answer_list.assign(id_list.size(), 0);

    // 유저 신고한 id 배열 만들기 report_list
    vector<vector<string> > report_list;
    report_list.resize(id_list.size());
    for(int i = 0; i < report.size(); i++) {
        vector<string> users;

        // split
        stringstream stringstreamvalue(report[i]);
        string st;
        char ch = ' ';
        while(getline(stringstreamvalue, st, ch)) {
            users.push_back(st);
        }
        vector<string>::iterator iter1 = find(id_list.begin(), id_list.end(), users.front());
        int idx = distance(id_list.begin(), iter1);
        report_list[idx].push_back(users.back());
        
        // 신고당한 횟수 저장
        vector<string>::iterator iter2 = find(id_list.begin(), id_list.end(), users.back());
        int idx2 = distance(id_list.begin(), iter2);
        stop_list[idx2]++;
    }

    // sort, remove duplicate
    for(int i; i < report_list.size(); i++) {
        sort(report_list[i].begin(), report_list[i].end());
        report_list[i].erase(unique(report_list[i].begin(), report_list[i].end()), report_list[i].end());
    }

    // stop_list 체크해서 k보다 큰 index에 해당하는 id가 들어있는 것 
    for(int i = 0; i < stop_list.size(); i++) {
        if (k <= stop_list[i]) {
            string stop_user = id_list[i];
            // report_list 돌아가면서 찾아서 찾으면 answer++ 해주기
            for(int j = 0; j < report_list.size(); j++) {
                for(int k = 0; k < report_list[j].size(); k++) {
                    // cout << report_list[j][k] << endl;
                    // cout << stop_user.compare(report_list[j][k]) << endl;
                    if (stop_user.compare(report_list[j][k]) == 0)
                        answer[j]++;
                }
            }
        }
    }

/*
    cout << "----------- report_list -----------" << endl;
    cout << report_list.size() << endl;
    for(int j = 0; j < report_list.size(); j++) {
        if (report_list.at(j).size() > 0)
            cout << report_list.at(j).front() << endl;
        else
            cout << endl;
    }
    
    cout << "----------- stop_list -----------" << endl;
    for(int j = 0; j < stop_list.size(); j++) {
        cout << stop_list.at(j) << endl;
    }
    */
    cout << "----------- answer -----------" << endl;
    for(int j = 0; j < answer.size(); j++) {
        cout << answer.at(j) << endl;
    }
    
    return answer;
}

int main() {

    vector<string> id_list;
    /*
    id_list.push_back("muzi");
    id_list.push_back("frodo");
    id_list.push_back("apeach");
    id_list.push_back("neo");
    */
    id_list.push_back("con");
    id_list.push_back("ryan");

    vector<string> report;
    /*
    report.push_back("muzi frodo");
    report.push_back("apeach frodo");
    report.push_back("frodo neo");
    report.push_back("muzi neo");
    report.push_back("apeach muzi");
    */
    report.push_back("ryan con");
    report.push_back("ryan con");
    report.push_back("ryan con");
    report.push_back("ryan con");
    int k = 3;

    solution(id_list, report, k);
    
    return 0;
}