#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    
    set<int> s;
    for(int i = 0; i < arr.size(); i++) {
        if (arr[i]%divisor == 0)
            s.insert(arr[i]);
    }
    if (s.size() == 0)
        s.insert(-1);
    vector<int> answer(s.begin(), s.end());
    
    return answer;
}