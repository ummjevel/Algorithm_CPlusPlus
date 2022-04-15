#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

set<int> sAll;

vector<vector<int>> matrix(vector<int> query, vector<vector<int>> matrix) {

    sAll.clear();

    int x1 = query[0]-1;
    int y1 = query[1]-1;
    int x2 = query[2]-1;
    int y2 = query[3]-1;
    int temp;
    int leftcornerup = matrix[x1][y1];
    int rightcornerup = matrix[x1][y2];
    int leftcornerdown = matrix[x2][y1];
    int rightcornerdown = matrix[x2][y2];

    matrix[x1][y1] = matrix[x1+1][y1];
    sAll.insert(matrix[x1+1][y1]);
    //cout << "matrix[" << x1 << "][" << y1 << "] = matrix[" << x1+1 << "][" << y1 << "]" << endl;

    for(int i = x1 + 1; i < x2; i++) {
        //cout << "matrix[" << i << "][" << y1 << "] = matrix[" << i+1 << "][" << y1 << "]" << endl;
        matrix[i][y1] = matrix[i+1][y1];
        sAll.insert(matrix[i+1][y1]);
    }

    matrix[x2][y1] = matrix[x2][y1+1];
    sAll.insert(matrix[x2][y1+1]);
    //cout << "matrix[" << x2 << "][" << y1 << "] = matrix[" << x2 << "][" << y1+1 << "]" << endl;

    for(int i = y1 + 1; i < y2; i++) {
        //cout << "matrix[" << x2 << "][" << i << "] = matrix[" << x2 << "][" << i+1 << "]" << endl;
        matrix[x2][i] = matrix[x2][i+1];
        sAll.insert(matrix[x2][i+1]);
    }

    matrix[x2][y2] = matrix[x2-1][y2];
    sAll.insert(matrix[x2-1][y2]);
    //cout << "matrix[" << x2 << "][" << y2 << "] = matrix[" << x2-1 << "][" << y2 << "]" << endl;

    for(int i = x2 - 1; i > x1; i--) {
        //cout << "matrix[" << i << "][" << y2 << "] = matrix[" << i-1 << "][" << y2 << "]" << endl;
        matrix[i][y2] = matrix[i-1][y2];
        sAll.insert(matrix[i-1][y2]);
    }

    matrix[x1][y2] = matrix[x1][y2-1];
    sAll.insert(matrix[x1][y2-1]);
    //cout << "matrix[" << x1 << "][" << y2 << "] = matrix[" << x1 << "][" << y2-1 << "]" << endl;

    for(int i = y2 - 1; i > y1; i--) {
        //cout << "matrix[" << x1 << "][" << i << "] = matrix[" << x1 << "][" << i-1 << "]" << endl;
        matrix[x1][i] = matrix[x1][i-1];
        sAll.insert(matrix[x1][i-1]);
    }

    matrix[x1][y1+1] = leftcornerup;
    sAll.insert(leftcornerup);


    // for(int i = 0; i < 6; i++) {
    //     for(int j = 0; j < 6; j++)
    //         cout << matrix[i][j] << " ";
    //     cout << endl;
    // }

    return matrix;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    vector<vector<int>> temp;
    
    int itemp = 1;
    for(int i = 0; i < rows; i++) {
        vector<int> vec;
        for(int j = 0; j < columns; j++) {
            vec.push_back(itemp);
            itemp++;
        }
        temp.push_back(vec);
    }

    for(int i = 0; i < queries.size(); i++) {
        temp = matrix(queries[i], temp);
        answer.push_back(*(sAll.begin()));
    }

    return answer;
    
}

int main() {
    vector<vector<int>> vec = {{2,2,5,4},{3,3,6,6},{5,1,6,3}};
    solution(6, 6, vec);
}