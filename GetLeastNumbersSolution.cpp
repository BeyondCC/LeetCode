/* 
 * Author: cc
 * Date  : 2015-08-23
 * Source: http://www.nowcoder.com/books/coding-interviews/6a296eb82cf844ca8539b57c23e6e9bf?rp=2
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
        vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
            vector<int> res;

            if (k > input.size()) {
                return res;
            }
            helper(input, 0, input.size() - 1, k);

            for (int i = 0; i < k; ++i) {
                res.push_back(input[i]);
            }

            return res;
        }

        void helper(vector<int> &input, int start, int end, int k) {
            if (start > end) {
                return;
            }

            int middle = partion(input, start, end);
            cout<<"middle:"<<middle<<endl;
            if (middle == k) {
                return;
            }

            if (middle > k) {
                helper(input, start, middle -1, k);
            }else{
                helper(input, middle + 1, end, k - middle - 1);
            }
            
        }

        int partion(vector<int> &input, int start, int end) {
            int index = start -1;
            int target = input[end];

            for (int i = start; i <= end; ++i) {
                if (input[i] < target) {
                    swap(input, index + 1, i);
                    index++;
                }
            }

            swap(input, index + 1, end);
            return index + 1;
        }
        
        void swap(vector<int> &input, int index1, int index2) {
            int tmp = input[index1];
            input[index1] = input[index2];
            input[index2] = tmp;
        }
};

int main(int argc, char *argv[]) {
    vector<int> v;

    v.push_back(4);
    v.push_back(5);
    v.push_back(1);
    v.push_back(6);
    v.push_back(2);
    v.push_back(7);
    v.push_back(3);
    v.push_back(8);

    Solution s;
    s.GetLeastNumbers_Solution(v, 4);
    return 0;
}

