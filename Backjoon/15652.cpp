#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> arr, vec;
vector<bool> visited;

void DFS(int cnt, int num) {
    if (cnt == M) {
        for(int i = 0; i < vec.size(); i++) {
            cout << vec[i] << ' ';
        }
        cout << endl;
        return;
    }

    for(int i = num; i < N; i++) {
        vec.push_back(arr[i]);
        DFS(cnt+1, i);
        vec.pop_back();
    }
}


int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        arr.push_back(i+1);
        visited.push_back(false);
    }
    DFS(0, 0);
}