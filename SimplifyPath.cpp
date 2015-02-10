/* 
 * Author: cc
 * Date  : 2015-02-09
 * Source: https://oj.leetcode.com/problems/simplify-path/
 * Description:
 * Given an absolute path for a file (Unix-style), simplify it.
 *
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 * click to show corner cases.
 *
 * Corner Cases:
 * Did you consider the case where path = "/../"?
 * In this case, you should return "/".
 * Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
 * In this case, you should ignore redundant slashes and return "/home/foo".
 *
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//目录进栈，遇到..出栈
//time O(n), space O(n)
string simplifyPath(string path) {

    stack<string> s;
    bool hasSlashFlag = false;
    int  preIndex = 0;

    for (int i = 0; i < path.length(); ++i)
    {
        if (!hasSlashFlag && path[i] == '/') 
        {
            hasSlashFlag = true;
            preIndex = i + 1;
        }else if (hasSlashFlag && path[i] == '/'){
            if (preIndex < i)
            {
                //the parameter of substr is (index, length)
                string str = path.substr(preIndex, i - preIndex);
                
                cout<<"cut str is"<<str<<endl;
                if (str == "..")
                {
                    if (!s.empty()) // when the stack is not empty, pop the top element
                    {
                        s.pop();
                    }
                }else if(str != "."){
                    s.push(str);
                }
            }
                
            hasSlashFlag = true;
            preIndex = i + 1;
        }
    }

    if (preIndex < path.length())
    {
        string str = path.substr(preIndex, path.length());
        if (str != "." && str != "..")
            s.push(str);

        if (str == "..")
        {
            if (!s.empty())
            {
                s.pop();
            }
        }
    }

    vector<string> filteredVector;

    //convert the stack to vector to compose the final result
    while(!s.empty())
    {
        filteredVector.insert(filteredVector.begin(), s.top());
        s.pop();
    }

    string res("/");

    cout<<"here"<<endl;

    if (filteredVector.size() > 0)
    {
        for (int i = 0; i < filteredVector.size() - 1; ++i)
        {
            res.append(filteredVector[i]);
            res.append("/");
        }

        if (filteredVector.size() > 0)
        {
           res.append(filteredVector[filteredVector.size() - 1]);
        }
    }

    return res;
}

int main(int argc, char *argv[]) {

//    cout<<simplifyPath("/aa/bb/cc/dd//ee")<<endl;
    cout<<simplifyPath("/a/./b///../c/../././../d/..//../e/./f/./g/././//.//h///././/..///")<<endl;
  //  cout<<simplifyPath("/../")<<endl;
   // cout<<simplifyPath("/a/../b/c")<<endl;
    return 0;
}

