/* Source:https://oj.leetcode.com/problems/maximal-rectangle/
 * Descriptions: Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
 *
 *
 */

#include<iostream>
#include<vector>

using namespce std;

int maxRectangle(vector<vector<char> > &matrix) {
    if(matrix.size() == 0)
        return 0;

    int row = matrix[0];

    int *dp = new int[row.size()];

    for(int i = 0; i < matrix.size(); i++) {
        vector<char>  row = matrix[i];
        for(int j = 0; j < row.size(); j++) {
            if(row[j] == 1) {
                dp[j + 1] = l
            }
        }
    }
}


int main(int argc, char *argv[]) {
    return 0;
} 
