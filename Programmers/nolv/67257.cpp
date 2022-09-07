#include <string>
#include <vector>
#include <stack>
#include <cctype>
#include <set>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;


long long solution(string expression) {
    long long answer = 0;
    vector<long long> sNumbers;
    set<char> setOper;
    vector<char> sOpers;

    // string에서 분리하여 queue 에 넣어놓기
    string s;
    for(int i = 0; i < expression.length(); i++) {
        if(!isdigit(expression[i])) {
            sNumbers.push_back(stoi(s));
            s.clear();
            sOpers.push_back(expression[i]);
            setOper.insert(expression[i]);
        } else {
            s += expression[i];
        }
    }
    sNumbers.push_back(stoi(s));
    
    vector<char> sOpers2(setOper.begin(), setOper.end());

    do {
        vector<long long> sNumbers2(sNumbers.begin(), sNumbers.end());
        vector<long long> sOpers3(sOpers.begin(), sOpers.end());
        
        cout << "sOpers2 : ";
        for(int i = 0; i < sOpers2.size(); i++) {
            cout << sOpers2[i] << " ";
        }
        cout << "sOpers : ";
        for(int i = 0; i < sOpers.size(); i++) {
            cout << sOpers[i] << " ";
        }
        cout << endl;

        for(int i = 0; i < sOpers2.size(); i++) {
            
            for(int j = 0; j < sOpers3.size() ; j++) {

                if (sOpers2[i] == sOpers3[j]) {
                    cout << "sOpers2[i] == sOpers[j]: " << sOpers2[i] << " == " << sOpers[j] << endl;
                    cout << "come on in : " << j << endl;
                    
                    switch(sOpers3[j]) {
                        case '*':
                            cout << sNumbers2[j] << " * " << sNumbers[j+1] << "=";
                            sNumbers2[j] = sNumbers2[j] * sNumbers2[j+1];
                            break;
                        case '+':
                            cout << sNumbers2[j] << " + " << sNumbers[j+1] << "=";
                            sNumbers2[j] = sNumbers2[j] + sNumbers2[j+1];
                            break;
                        case '-':
                            cout << sNumbers2[j] << " = " << sNumbers[j+1] << "=";
                            sNumbers2[j] = sNumbers2[j] - sNumbers2[j+1];
                            break;
                    }
                    
                    cout << sNumbers2[j] << endl;
                    sNumbers2.erase(sNumbers2.begin() + j + 1);
                    sOpers3.erase(sOpers3.begin() + j);
                    j--;
                }
            }
        }
        
        answer = answer < abs(sNumbers2[0]) ? abs(sNumbers2[0]) : answer;
        
    } while(next_permutation(sOpers2.begin(), sOpers2.end()));

    
    return answer;

}

int main() {
    solution("100-200*300-500+20");
    return 0;
}


// void permutation(set<char> setOper, vector<int> orders, int select) {
//     if (select == 0) {
//         operResult.push_back(orders);

//         return;
//     }
//     for(int i = 0; i < setOper.size(); i++) {
//         if (find(orders.begin(), orders.end(), i) != orders.end())
//             continue;

//         orders.push_back(i);
//         vector<int> secondOrder;
//         // vector<int> secondOrder(orders.size());
//         // copy(orders.begin(), orders.end(), secondOrder.begin());
//         for(int j = 0; j < orders.size(); j++) {
//             secondOrder.push_back(orders[j]);
//         }

//         permutation(setOper, secondOrder, select - 1);
//     }
//     return;
// }

// long long solution(string expression) {
//     long long answer = 0;
//     vector<long long> answers;
//     stack<long long> sNumbers;
//     stack<char> sOper;
//     vector<string> q;
//     set<char> setOper;
//     vector<int> vecOperNumber;
//     map<char, int> m; 

//     // string에서 분리하여 queue 에 넣어놓기
//     string s;
//     for(int i = 0; i < expression.length(); i++) {
//         if(!isdigit(expression[i])) {
//             q.push_back(s);
//             s.clear();
//             string sO;
//             sO += expression[i];
//             q.push_back(sO);
//             setOper.insert(expression[i]);
//             m.insert({expression[i], 0});
//         } else {
//             s += expression[i];
//         }
//     }
//     q.push_back(s);

//     // 연산자 우선순위 조합 만들어놓고, 

//     // vector<int> orders;
//     // permutation(setOper, orders, setOper.size());

//     for(int i = 0; i < setOper.size(); i++) {
//         vecOperNumber.push_back(i);
//     }

//     std::vector<char> vec(setOper.begin(), setOper.end());

//     // 넣어놓은 queue에서 뽑으면서, 
//     do {
//         for(int i = 0; i < vecOperNumber.size(); i++) {
//             m.find(vec[i])->second = vecOperNumber[i];
//         }

//         for(int i = 0; i < q.size(); i++) {
//             if (atoi(q[i].c_str()) != 0) {
//                 // if(sNumbers.empty())
//                 sNumbers.push(stoi(q[i]));
                
//             } else {
//                 // 넣기 전에 우선순위 확인.
//                 if (sOper.empty() || sNumbers.size() == 1) {
//                     // 넣기
//                     sOper.push(q[i][0]);
//                 } else {
//                     if(m[sOper.top()] < m[q[i][0]]) {
//                         long long i2 = sNumbers.top();
//                         sNumbers.pop();
//                         long long i1 = sNumbers.top();
//                         sNumbers.pop();
//                         int result = 0;
//                         if (sOper.top() == '*') {
//                             result = i1 * i2;
//                         } else if (sOper.top() == '+') {
//                             result = i1 + i2;
//                         } else if (sOper.top() == '-') {
//                             result = i1 - i2;
//                         }
//                         sOper.pop();
//                         sNumbers.push(result);
//                         sOper.push(q[i][0]);
//                     } else {
//                         sOper.push(q[i][0]);
//                     }
//                 }
//             }
//         }

//         if (sOper.size() > 1) {
//             char top = sOper.top();
//             if(m[sOper.top()] < m[top]) {
//                 long long i2 = sNumbers.top();
//                 sNumbers.pop();
//                 long long i1 = sNumbers.top();
//                 sNumbers.pop();
//                 int result = 0;
//                 if (sOper.top() == '*') {
//                     result = i1 * i2;
//                 } else if (sOper.top() == '+') {
//                     result = i1 + i2;
//                 } else if (sOper.top() == '-') {
//                     result = i1 - i2;
//                 }
//                 sOper.pop();
//                 sNumbers.push(result);
//             } else {
//                 long long i3 = sNumbers.top();
//                 sNumbers.pop();
                
//             }
//         }

//         stack<long long> sTemp;
//         while(!sNumbers.empty()) {
//             sTemp.push(sNumbers.top());
//             sNumbers.pop();
//         }
//         while(!sTemp.empty()) {
//             sNumbers.push(sTemp.top());
//             sTemp.pop();
//         }
//         while(!sOper.empty()) {
//             sTemp.push(sOper.top());
//             sOper.pop();
//         }
//         while(!sTemp.empty()) {
//             sOper.push(sTemp.top());
//             sTemp.pop();
//         }
//         // 남은 친구들에 대한 결과값 취하기.
//         while(sNumbers.size() != 1) {
//             int i2 = sNumbers.top();
//             sNumbers.pop();
//             int i1 = sNumbers.top();
//             sNumbers.pop();
//             int result = 0;
//             if (sOper.top() == '*') {
//                 result = i1 * i2;
//             } else if (sOper.top() == '+') {
//                 result = i1 + i2;
//             } else if (sOper.top() == '-') {
//                 result = i1 - i2;
//             }
//             sOper.pop();
//             sNumbers.push(result);
//         }
//         answers.push_back(abs(sNumbers.top()));
//         if (abs(sNumbers.top()) > answer) {
//             answer = abs(sNumbers.top());
//         }
//         sNumbers.pop();

//     } while(next_permutation(vecOperNumber.begin(), vecOperNumber.end()));

//     // 만들어놓은 조합 우선순위 적용해서 계산, 절대값 적용

//     // 결과 절대값 중 가장 큰 것 반환

//     return answer;
// }