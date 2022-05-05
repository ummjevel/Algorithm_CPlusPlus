#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int compare(string a, string b) {
    return stoi(a + b) > stoi(b + a); 
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> sNumbers;
    for(int i = 0 ; i < numbers.size(); i++) {
        sNumbers.push_back(to_string(numbers[i]));
    }

    sort(sNumbers.begin(), sNumbers.end(), compare);

    for(vector<string>::iterator it = sNumbers.begin(); it != sNumbers.end(); it++) {
        answer += *it;
    }

    if (answer[0] == '0')
        answer = "0";

    return answer;
}

int main() {
    vector<int> numbers = {3, 30, 34, 5, 9};
    solution(numbers);
    return 0;
}