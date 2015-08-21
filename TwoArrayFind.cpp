/* 
 * Author: cc
 * Date  : 2015-08-21
 * Source: 
 * Description:
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool Find(vector<vector<int> > array,int target) {
        int row = array.size();

        for (int i = 0; i < row; i++) {
            //array[i].size() > 0
            if(array[i][0] == target)
                return true;
            else if(array[i][0] < target) {
                bool flag = helper(array, i, target);
                if  (flag)
                    return true;
            }else{
                return false;   
            }
        }
        
        return false;
    }
    
    bool helper(vector<vector<int> > array, int row, int target) {
            vector<int> vec = array[row];
        
            int start = 0;
            int end = vec.size() - 1;
        
            while(start <= end) 
            {
                    int middle = (start + end) / 2;
                
                    if  (target == vec[middle])
                        return true;
                    else if(target < vec[middle]) {
                        end = middle -1;
                    }else{
                        start = middle + 1;
                    }
            }
    
            return false;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    vector<vector<int> > res;
    res.push_back(vec);

    cout<<s.Find(res, 2)<<endl;
    return 0;
}

