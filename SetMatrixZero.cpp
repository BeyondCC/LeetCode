/*
 * Source: https://oj.leetcode.com/problems/set-matrix-zeroes/
 * Description: 
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>

using namespace std;

void printVector(vector<vector<int> > matrix) {
    
    for (int i = 0; i < matrix.size(); i++) {
        vector<int> row = matrix[i];
        for (int j = 0; j < row.size(); j++) {
            cout<<" "<<row[j];
        }
        cout<<endl;
    }
}

void setRowZero(vector<vector<int> > &matrix, int index) {
    vector<int> row = matrix[index];

    for (int i = 0; i < row.size(); i++) {
        matrix[index][i] = 0;
    }
}

void setColZero(vector<vector<int> > &matrix, int index) {
    
    for (int i = 0; i < matrix.size(); i++) {
        matrix[i][index] = 0;
    }
}


void setRowAndColZero(vector<vector<int> > &matrix, bool *rowInfo, bool *colInfo) {
    
    for (int i = 0; i < matrix.size(); i++) {
        vector<int> row = matrix[i];
        if (rowInfo[i]) {
            setRowZero(matrix, i);
        }
        
        for (int j = 0; j < row.size(); j++) {
            if (colInfo[j]) {
                setColZero(matrix, j);
            }
        }
    }
}

// space: O(1), 每行每列是否要被置0的信息全部存放在第0行和第0列，第0行和列是否被置0由两个标记位
// 记录，这两个实在扫第0行和第0列时记录
void setZerosSpace(vector<vector<int> > &matrix) {
    if (matrix.size() == 0) {
        return;
    }

    int rowSize = matrix.size();
    int colSize = matrix[0].size();
    
    bool rowFlag = false;
    bool colFlag = false;

    for (int i = 0; i < rowSize; i++) {
        vector<int> row = matrix[i];
        for (int j = 0; j < colSize; j++) {
            if (matrix[i][j] == 0) {
                if (i == 0) {
                    rowFlag = true;
                }

                if (j == 0) {
                    colFlag = true;
                }
                if (matrix[i][0]) {
                    matrix[i][0] = 0;
                }

                if (matrix[0][j]) {
                    matrix[0][j] = 0;
                }
            }
        }
    }

    for (int i = 1; i < colSize; i++) {
        if (!matrix[0][i]) {
            setColZero(matrix, i);
        }
    }


    for (int i = 1; i < rowSize; i++) {
        if (!matrix[i][0]) {
            setRowZero(matrix, i);
        }
    }
    //use flag to judge whether the 0 row and 0 col should be setted zero
    
    if (rowFlag) {
        setRowZero(matrix, 0);
    }

    if (colFlag) {
        setColZero(matrix, 0);
    }
    printVector(matrix);
}  
// time: o(m * n) space: o(m + n)
void setZeros(vector<vector<int> > &matrix) {
    if (matrix.size() == 0) {
        return;
    }

    int rowSize = matrix.size();
    int colSize = matrix[0].size();

    bool *rowInfo = new bool[rowSize];
    bool *colInfo = new bool[colSize];

    for (int i = 0; i < rowSize; i++) {
        rowInfo[i] = false;
    }

    for (int j = 0; j < colSize; j++) {
        colInfo[j] = false;
    }

    for (int i = 0; i < rowSize; i++) {
        vector<int> row = matrix[i];
        for (int j = 0; j < colSize; j++) {
            if (matrix[i][j] == 0) {
                if (!rowInfo[i]) {
                    rowInfo[i] = true;
                }

                if (!colInfo[j]) {
                    colInfo[j] = true;
                }
            }
        }
    }
    
    setRowAndColZero(matrix, rowInfo, colInfo);
}


int main(int argc, char *argv[]) {
    vector<vector<int> > matrix;

    for (int i = 1; i < 4; i++) {
        vector<int> row;

        row.push_back(-1);

        row.clear();

        row.push_back(0);

        matrix.push_back(row);
   }

    setZerosSpace(matrix);
    
    printVector(matrix);

    return 0;
}

