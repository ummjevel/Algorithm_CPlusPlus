#include <iostream>
#include <vector>

using namespace std;

int N;
int gap = 100000000;
vector<bool> visited;
vector<vector<int>> vec;

void DFS(int cnt, int position) {
    if (cnt == N/2) {
        // 능력치 계산
        int start = 0, link = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(visited[i] && visited[j]) start += vec[i][j];
                if(!visited[i] && !visited[j]) link += vec[i][j];
            }
        }
        int temp = abs(start - link);
        if (gap > temp) gap = temp;

        return ;
    }

    for(int i = position; i < N; i++) {
        visited[i] = true;
        DFS(cnt + 1, i + 1);
        visited[i] = false;
    }
}


int main() {

    // 입력 받기
    int temp;

    cin >> N;
    for(int i = 0; i < N; i++) {
        vector<int> v;
        for(int j = 0; j < N; j++) {
            cin >> temp;
            v.push_back(temp);
            visited.push_back(false);
        }
        vec.push_back(v);
    }
    DFS(0, 1);

    cout << gap;

    return 0;
}