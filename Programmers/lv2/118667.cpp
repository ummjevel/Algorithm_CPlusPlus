
// 테스트 케이스는 다 풀었는데 제출 시 시간초과 나옴. DFS
// 시간초과가 덜 뜨고 실패없음. DFS2, 11,12, 15, 19~28,30
// dfs3 deque 사용 시에도 dfs2 와 결과 같음.
// 시간 초과 하나도 안 뜨고 실패많이 뜸.

#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <queue>
#include <deque>

using namespace std;

long long MakeSum(vector<int> queue1) {
    long long sum1 = 0;
    for(int i = 0; i < queue1.size(); i++) {
        sum1 += queue1[i];
    }
    return sum1;
}

int DFS(vector<int> queue1, vector<int> queue2, int cnt, int initSize) {

    if (cnt > pow(initSize, 2)) {
        return -1;
    }

    // 만약 합이 같으면,
    long sum1 = MakeSum(queue1);
    long sum2 = MakeSum(queue2);
    if (sum1 == sum2) {
        return cnt;
    } else if (sum1 > sum2) {
        int num1 = queue1[0];
        queue1.erase(queue1.begin());
        queue2.push_back(num1);
    } else {
        int num2 = queue2[0];
        queue2.erase(queue2.begin());
        queue1.push_back(num2);
    }

    return DFS(queue1, queue2, cnt+1, initSize);

}

int DFS2(queue<int> queue1, queue<int> queue2, int cnt, int sum1, int sum2, int initSize) {

    if (cnt > 9 * pow(10, 10)) {
        return -1;
    }

    if (sum1 == sum2) {
        return cnt;
    } else if (sum1 > sum2) {
        int num1 = queue1.front();
        queue1.pop();
        queue2.push(num1);
        sum1 -= num1;
        sum2 += num1;
    } else {
        int num2 = queue2.front();
        queue2.pop();
        queue1.push(num2);
        sum1 += num2;
        sum2 -= num2;
    }

    return DFS2(queue1, queue2, cnt+1, sum1, sum2, initSize);

}


int DFS3(deque<int> queue1, deque<int> queue2, int cnt, int sum1, int sum2, int initSize) {

    if (cnt > 9 * pow(10, 10)) {
        return -1;
    }

    if (sum1 == sum2) {
        return cnt;
    } else if (sum1 > sum2) {
        int num1 = queue1.front();
        queue1.pop_front();
        queue2.push_back(num1);
        sum1 -= num1;
        sum2 += num1;
    } else {
        int num2 = queue2.front();
        queue2.pop_front();
        queue1.push_back(num2);
        sum1 += num2;
        sum2 -= num2;
    }

    return DFS3(queue1, queue2, cnt+1, sum1, sum2, initSize);

}

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    // return DFS(queue1, queue2, 0, queue1.size());

    /*
    queue<int> queue3, queue4;
    for(int num : queue1) queue3.push(num);
    for(int num : queue2) queue4.push(num);

    long long sum1 = MakeSum(queue1);
    long long sum2 = MakeSum(queue2);

    return DFS2(queue3, queue4, 0, sum1, sum2, queue1.size());
    */
   
    /*
    deque<int> queue3, queue4;
    for(int num : queue1) queue3.push_back(num);
    for(int num : queue2) queue4.push_back(num);

    long long sum1 = MakeSum(queue1);
    long long sum2 = MakeSum(queue2);

    return DFS3(queue3, queue4, 0, sum1, sum2, queue1.size());
    */

    //vector 그대로 해봅시다.
    int cnt = 0;
    long long limitSize = queue1.size() * 2 + 2; // pow(queue1.size(), 2);
    long long sum1 = MakeSum(queue1);
    long long sum2 = MakeSum(queue2);
    int index1 = 0, index2 = 0;

    while(cnt <= limitSize) {

        if (sum1 == sum2) {
            return cnt;
        } else if (sum1 > sum2) {
            sum1 -= queue1[index1];
            sum2 += queue1[index1];
            queue2.push_back(queue1[index1++]);
        } else {
            sum1 += queue2[index2];
            sum2 -= queue2[index2];
            queue1.push_back(queue2[index2++]);
        }
        cnt++;
    }

    return -1;

}

int main() {
    vector<int> queue1 = {1, 1};
    vector<int> queue2 = {1, 5};
    cout << solution(queue1, queue2);
    return 0;
}