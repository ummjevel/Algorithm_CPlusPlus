#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector< vector<int> > board, vector<int> moves) {
    int answer = 0;
    
    stack<int> ppopgi;

    for (int i = 0; i < moves.size(); i++) {
        // moves 값 가지고 (i, moves 값) 에서 가장 위에 있는 값 찾기
        int j = 0;
        // 0 이거나 끝까지 가되 j 가 나중에 쓰이므로 -1 한 데까지만 가기.
        while(board[j][moves[i] - 1] == 0 && j < board[0].size() - 1) {
            j++;
        }
        cout << "current moves: " << moves[i] << ", j : " << j << ", board[j][moves[i] - 1] : " << board[j][moves[i] - 1] << endl;
        // 없으면 말고, 있으면 stack 에 넣고.
        if (board[j][moves[i] - 1] == 0 || j == board[0].size()) { // 여기 때문에 테스트 1,2 통과 못했었음.. 질문 101의 반례로 다 1일 때 해보라길래도 되서 다 0으로 바꿔서 테스트 해봤더니 문제점 발견함.
            // 비어있는 곳임
            continue;
        } else {
            // 안 비어있음
            if (!ppopgi.empty()) {
                // 넣을 때 이전 값과 같으면 넣지말고 하나 빼고, +2 시키고
                if (board[j][moves[i] - 1] == ppopgi.top()) {
                    cout << "ppopgi count : " << ppopgi.size() << endl;
                    cout << "board[j][moves[i] - 1]: " << board[j][moves[i] - 1] << ", ppopgi.top(): " << ppopgi.top() << endl;
                    ppopgi.pop();
                    cout << "ppopgi count : " << ppopgi.size() << endl;
                    answer += 2;
                    cout << "pop()!! answer : " << answer << endl;
                } else {
                    // 이전 값과 안 같으면 넣기

                    cout << "ppopgi count : " << ppopgi.size() << endl;
                    ppopgi.push(board[j][moves[i] - 1]);
                    cout << "push()!! " << board[j][moves[i] - 1] << endl;
                    cout << "ppopgi count : " << ppopgi.size() << endl;
                }
            } else {
                // 아무것도 없는 상태이므로 넣기!
                cout << "ppopgi count : " << ppopgi.size() << endl;
                ppopgi.push(board[j][moves[i] - 1]);
                cout << "push()!! " << board[j][moves[i] - 1] << endl;
                cout << "ppopgi count : " << ppopgi.size() << endl;
            }
            board[j][moves[i] - 1] = 0;
            cout << "-- result answer: " << answer << endl;
        }
    }
    cout << "result answer: " << answer << endl;
    return answer;
}

int main() {
    vector< vector<int> > board = 
    
   {
        {0,0,0,0,0},
        {0,0,1,1,1},
        {0,0,1,1,1},
        {0,0,1,1,1},
        {0,0,1,1,1}
    };
    /*
    {
        {0,0,0,0,0},
        {0,0,1,0,3},
        {0,2,5,0,1},
        {4,2,4,4,2},
        {3,5,1,3,1}
    };
*/
    // vector<int> vec1 = {-1,-1,-1,-1,-1,-1};
    /*
    {
        {0,0,0,0,0},
        {0,0,1,0,3},
        {0,2,5,0,1},
        {4,2,4,4,2},
        {3,5,1,3,1}
    };
*/
    // board.push_back(vec1);
    vector<int> moves = {1,1,1,1}; // {1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4,5,5,5,5,5};

    solution(board, moves);
    return 0;
}