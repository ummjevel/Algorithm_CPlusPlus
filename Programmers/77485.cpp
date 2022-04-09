#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> matrix(vector<int> query, vector<vector<int>> matrix) {
    int x1 = query[0];
    int y1 = query[1];
    int x2 = query[2];
    int y2 = query[3];
    int temp;
    int leftcornerup = matrix[x1][y1];
    int rightcornerup = matrix[x2][y1];
    int leftcornerdown = matrix[x1][y2];
    int rightcornerdown = matrix[x2][y2];

    for(int j = y2; j > y1; j--) {
        matrix[x1][j] = matrix[x1][j-1];
    }
    for(int j = y2; j > y1; j--) {
        matrix[x2][j] = matrix[x2][j-1];
    }
    for(int j = x2; j > x1; j--) {
        matrix[j][y1] = matrix[j-1][y1];
    }
    for(int j = x2; j > x1; j--) {
        matrix[j][y2] = matrix[j-1][y2];
    }

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
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            cout << temp[i][j] << endl;
        }
    }

    for(int i = 0; i < queries.size(); i++) {
        temp = matrix(queries[i], temp);
    }
    
    return answer;
    
}

int main() {
    vector<vector<int>> vec = {{2,2,5,4},{3,3,6,6},{5,1,6,3}};
    solution(6, 6, vec);
}