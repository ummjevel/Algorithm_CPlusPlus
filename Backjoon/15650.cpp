#include <iostream>
#include <vector>
using namespace std;

vector<int> arr, vec;
vector<bool> visited;
int N, M;

void DFS(int cnt, int num) {
    if (cnt == M) {
        for(int i = 0; i < vec.size(); i++) {
            cout << vec[i] << ' ';
        }
        cout << endl;
        return;
    }

    for(int i = num; i < N; i++) {
        if (visited[i]) continue;
        vec.push_back(arr[i]); 
        visited[i] = true;
        DFS(cnt+1, i+1);
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
    DFS(0, 0);

    return 0;
}