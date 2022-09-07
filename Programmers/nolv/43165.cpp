#include <string>
#include <vector>

using namespace std;

int cnt;

void dfs(int x, int sum, int idx, vector<int> numbers, int target) {    // void 로 해줘야 채점에서 abort ~ 안난다.

    sum += x;

    if (idx == numbers.size() - 1) {
        if(sum == target)
            cnt++;
        return;
    }
    idx++;
    dfs(numbers[idx], sum, idx, numbers, target);
    dfs(numbers[idx] * -1, sum, idx, numbers, target);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int start = numbers[0]; 
    dfs(start, 0, 0, numbers, target);
    dfs(start * -1, 0, 0, numbers, target);

    return answer;
}

// 가닥은 잡았는데 모르겠어서 찾아봄.


// #include <string>
// #include <vector>
// #include <iostream>

// using namespace std;


// int sum;

// // 일단 dfs 순회하는 것부터 만들어 보자.
// int dfs(int idx, int idx2, vector<int> numbers[], vector<bool> visited[], int visit[]) {
//     if (visited[idx][idx2])
//         return 0;
    

//     for(int i = idx2; i < numbers[idx].size(); i++) {
//        int temp = numbers[idx][i];
       
//         visited[idx][idx2] = true;
//        cout << "visited: numbers[" << idx << "][" << i << "] : " << numbers[idx][i] << endl;
//        if(!visited[idx][i]) {
//            dfs(idx, i, numbers, visited, visit);
//        }
//     }
    
//     visit[idx] = true;
//     return 0;
// }

// int solution(vector<int> numbers, int target) {
//     int answer = 0;
//     vector<int> number[numbers.size()];
//     vector<bool> visited[numbers.size()];
//     int visit[numbers.size()];
    
//     for(int i = 0; i < numbers.size(); i++) {
//         number[i].push_back(numbers[i]);
//         number[i].push_back(numbers[i]*-1);
//         visited[i].push_back(false);
//         visited[i].push_back(false);
//         visit[i] = false;
//     }
    
//     dfs(0, 0, number, visited, visit);
    
//     return answer;
// }

// int main() {
//     vector<int> vect = {1, 1, 1, 1, 1};
//     cout << solution(vect, 3) << endl;
    
// }