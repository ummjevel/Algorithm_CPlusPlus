#include <iostream>
#include <vector>

using namespace std;

int N, M; // 1부터 N까지 한줄 출력 시 M개의 숫자 수열
vector<int> vec, arr;
vector<bool> visited;

void DFS(int cnt) {

    if (cnt == M) {
        for(int i = 0; i < vec.size(); i++) {
            cout << vec[i] << ' ';
        }
        cout << endl;
        return;
    }

    for(int i = 0; i < N; i++) {
        if (visited[i]) continue;
        vec.push_back(arr[i]);
        visited[i] = true;
        DFS(cnt+1);
        vec.pop_back();
        visited[i] = false;
    }
}


int main() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        arr.push_back(i+1);
        visited.push_back(false);
    }
    DFS(0);
}