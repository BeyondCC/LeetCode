/* 
 * Author: cc
 * Date  : 2015-09-02
 * Source: http://www.nowcoder.com/practice/cf7e25aa97c04cc1a68c8f040e71fb84?rp=4&ru=/ta/coding-interviews
 * Description:
 * 请实现两个函数，分别用来序列化和反序列化二叉树
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
    char ser[4096];
    public:
    char* Serialize(TreeNode *root) {    
static int i=0;
         
        if(root == NULL){
            ser[i++] = 255;
            return  (char *)ser;
        }
         
        ser[i++] = (unsigned char)root->val;
        Serialize(root->left);
        Serialize(root->right);
      
        return (char *)ser;
    }
    
    TreeNode* Deserialize(char *str) {
         static int i=0;
        unsigned char *s = (unsigned char *)str;
        
        if(s[i] == 255){
            i++;
            return NULL;
        }
           
        TreeNode* r = new TreeNode((int)s[i++]);
         
        r->left = Deserialize(str);
        r->right = Deserialize(str);
         
        return r;
    }
};

int main(int argc, char *argv[]) {
    return 0;
}

