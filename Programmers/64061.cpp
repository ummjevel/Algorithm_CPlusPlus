#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector< vector<int> > board, vector<int> moves) {
    int answer = 0;
    
    stack<int> ppopgi;

    for (int i = 0; i <3 ; i++)
    {
        for (int j = 0; j < 4; j++) {
            cout << board[i].at(j) << ", ";
        }
        cout << endl;
    }
   
    
    return answer;
}

int main() {
    cout << "hell worod...!!!!!" << endl;
    vector< vector<int> > board = {
        {0,0,0,0,0},
        {0,0,1,0,3},
        {0,2,5,0,1},
        {4,2,4,4,2},
        {3,5,1,3,1}
    };

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
    vector<int> moves; // {1,5,3,5,1,2,1,4};

    solution(board, moves);
    return 0;
}