#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, int> map;

    for (int i = 0; i < words.size(); i++) {
        map[words[i]]++;
        if (words[i].size() == 1 || 
        (i != 0 && words[i].substr(0, 1) != words[i-1].substr(words[i-1].size() - 1, 1)) ||
        (map[words[i]] != 1)) {
            answer.push_back(i%n + 1 == 0 ? n : (i%n + 1));
            answer.push_back(i/n + 1);
            break;
        }
    }

    if (answer.size() == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}

int main() {
    vector<string> words = {"qwe", "eqwe", "eqwe"};
    solution(2, words);

    return 0;
}