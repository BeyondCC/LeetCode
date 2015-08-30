/* 
 * Author: cc
 * Date  : 2015-08-30
 * Source: http://www.nowcoder.com/practice/445c44d982d04483b04a54f298796288?rp=3&ru=/ta/coding-interviews
 * Description:
 * 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
                queue<TreeNode*> q;
                vector<vector<int> > res;
                vector<int> tmp;
                TreeNode *pre = NULL;
                if (pRoot == NULL)
                    return res;
            
                q.push(pRoot);
                q.push(NULL);
            
                while(!q.empty())
                 {
                        TreeNode* front = q.front();
                        if(front == NULL) {
                            if (!tmp.empty()) {
                                res.push_back(tmp);
                            }
                            tmp.clear();
                            
                            if(pre != NULL)
                                q.push(NULL);
                            else
                                break;
                        }else{
                            tmp.push_back(front->val);
                            cout<<front->val<<endl; 
                            if(front->left) {
                                cout<<"hehe"<<endl;
                                   q.push(front->left);
                             }
                    
                            if(front->right) {
                              q.push(front->right);
                          }
                    
                        }
                    
                        pre = front;
                        q.pop();
                }   
                
                cout<<"size:"<<res.size()<<endl;
                for (int i = 0; i < res.size(); i++) {
                    vector<int> row = res[i];

                    for (int j = 0;  j < row.size(); j++) {
                        cout<<row[j]<<" "; 
                    }

                    cout<<endl;
                }         

                return res;
                 
        }
    
};

int main(int argc, char *argv[]) {
    TreeNode* root = new TreeNode(5);
    TreeNode* root1 = new TreeNode(3);
    TreeNode* root2 = new TreeNode(4);
    TreeNode* root3 = new TreeNode(5);
    TreeNode* root4 = new TreeNode(5);

    root->left = root1;
    root->right = root2;

    Solution s;
    s.Print(root); 
    return 0;
}

