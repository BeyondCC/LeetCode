/*
 * Source:https://oj.leetcode.com/problems/unique-paths-ii/ 
 * Follow up for "Unique Paths":

 Now consider if some obstacles are added to the grids. How many unique paths would there be?

 An obstacle and empty space is marked as 1 and 0 respectively in the grid.

 For example,
 There is one obstacle in the middle of a 3x3 grid as illustrated below.
 * use dp to calculate the result
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>

using namespace std;
void printArr(vector<vector<int> > v);

int uniquePathsWithobstaclesDP(vector<vector<int> > &obstacleGrid) { 
    if(obstacleGrid.size() == 0)
        return 0;

    int* result  = new int[obstacleGrid[0].size()];

    for(int i = 0; i < obstacleGrid[0].size(); i++) {
        result[i] = 0;
    }
    result[0] = 1;
    for(int i = 0; i < obstacleGrid.size(); i++) {
        for(int j = 0; j < obstacleGrid[i].size(); j++) {
            if(obstacleGrid[i][j] == 1)
                result[j] = 0;
            else{
                if(j > 0){
                    result[j] += result[j - 1];
                }
            }
        }
    }

    return result[obstacleGrid[0].size() - 1];
}

int uniquePathsWithobstacles(vector<vector<int> > &obstacleGrid) { 
    vector<vector<int> > result;
    int flag = 0;
    for(int i = 0; i < obstacleGrid.size(); i++) {
        vector<int> visit = obstacleGrid[i];
        vector<int> rowResult;
        if(i == 0) {
            for(int i = 0; i < visit.size(); i++) {
                if(visit[i] == 1){
                    for(int j = i; j < visit.size(); j++) {
                        rowResult.push_back(0);
                    }
                    break;
                 }else{
                    rowResult.push_back(1);
                }
            }
            result.push_back(rowResult);
            rowResult.clear();
        }else{
            for(int j = 0; j < visit.size(); j++) {
            
                if(j == 0) {
                    //pre row is obstacle or the current row is obstacle
                    if(obstacleGrid[i - 1][j] == 1 || visit[j] == 1){
                        flag = 1;
                        rowResult.push_back(0);
                    }else if (flag)
                    {
                        rowResult.push_back(0);
                    }else{
                        rowResult.push_back(1);
                    }
                }else
                    rowResult.push_back(0);
            }

            result.push_back(rowResult);
            rowResult.clear();
        }
    }
    
    printArr(result);

    for(int i = 1; i < obstacleGrid.size(); i++) {
        vector<int> visit = obstacleGrid[i];
        for(int j = 1; j < visit.size(); j++){
            printArr(result);
            if(visit[j] != 1) {
                if(obstacleGrid[i - 1][j] == 0) {
                   result[i][j] += result[i - 1][j];
                    cout<<"row "<< i <<" "<<j<<" "<<result[i][j]<<endl;
                }
            
                if(obstacleGrid[i][j - 1] == 0){
                    result[i][j] += result[i][j - 1];
                    cout<<"row "<< i <<" "<<j<<" "<<result[i][j]<<endl;
                }
            }
        }
    }

    printArr(result);
    vector<int> row = result[0];

    return result[result.size() - 1][row.size() -1];
}

void printArr(vector<vector<int> > v) {
    for(int i = 0; i < v.size(); i++) {
        vector<int> tmp = v[i];

        for(int j = 0; j < tmp.size(); j++) {
             cout<<tmp[j]<<" ";
        }

        cout<<endl;
    }
}

int main(int argc, char *argv[]) {
    vector<vector<int> > v;

    vector<int> row;
    row.push_back(0);
    row.push_back(0);


    v.push_back(row);
    row.clear();


    row.push_back(0);
    row.push_back(0);

    v.push_back(row);
    row.clear();

    cout<<uniquePathsWithobstacles(v)<<endl;
    cout<<uniquePathsWithobstaclesDP(v);
    return 0;
}

