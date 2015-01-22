/*
 * Source: https://oj.leetcode.com/problems/largest-number/
 * Description:
 * Given a list of non negative integers, arrange them such that they form the largest number.
 *
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 *
 * Note: The result may be very large, so you need to return a string instead of an integer.
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

bool aLessB(int a, int b) {
    stack<int> stackA;
    stack<int> stackB;

    int remainder;
    if (a)
    {   
        while(a)
        {
            remainder = a % 10;
            stackA.push(remainder);
        
            a = a / 10;
        }
    }else{
        stackA.push(0);
    } 

    if (b)
    {
         while(b)
        {
            remainder = b % 10;
            stackB.push(remainder);

            b = b / 10;
        }
    }else{
        stackB.push(0);
    }

    stack<int> backupA = stackA;
    stack<int> backupB = stackB;

    int depth = 0;
    while(!stackA.empty() && !stackB.empty())
    {
        int topA = stackA.top();
        stackA.pop();

        int topB = stackB.top();
        stackB.pop();

        if (topA < topB){
        
            return true;
        }else if (topA > topB)
            return false;
        else
            depth++;
    }

    //A 和B的前缀相同，如何判断AB大还是BA大
    //保留初始栈，弹出不为空的栈顶元素，跟初始栈的每个数进行比较，如在该元素之前并且大于该元素，则A < B,若在该元素之后则A>b
    if(!stackA.empty())
    {
        int visit = stackA.top();
        while(!backupA.empty())
        {
            int current = backupA.top();
            backupA.pop();
            depth--;

            if (current > visit && depth >= 0)
            {
                return true;
            }else if (current < visit && depth >= 0)
            {
                return false;
            }else if(current > visit && depth < 0){
                return false;
            }else if (current < visit && depth < 0)
            {
                return true;
            }
        }
    }

    if (!stackB.empty())
    {
        int visit = stackB.top();
        while(!backupB.empty())
        {
            int current = backupB.top();
            backupB.pop();
            depth--;

            if (current > visit && depth >= 0)
            {
                return false;
            }else if (current < visit && depth >= 0)
            {
                return true;
            }else if(current > visit && depth < 0){
                return true;
            }else if (current < visit && depth < 0)
            {
                return false;
            }

        }
    }

    return true;
}

int partion(vector<int> &num, int start, int end) {
    
    int pre = start - 1;
   
    for (int i = start; i < end; ++i)
    {
        if (!aLessB(num[i], num[end]))
        {
            pre++;
            swap(&num[pre], &num[i]);
        }
    }

    pre++;
    swap(&num[pre], &num[end]); 

    return pre;
}

void quickSort(vector<int> &num, int start, int end) {

    if(start >= end)
        return;

    int middle = partion(num, start, end);

    quickSort(num, start, middle - 1);
    quickSort(num, middle + 1, end);
}

void printArr(vector<int> &num) {
    for (int i = 0; i < num.size(); ++i)
    {
        cout<<num[i]<<" ";
    }

    cout<<endl;
}

string largestNumber(vector<int> &num) {

    quickSort(num, 0, num.size() - 1);

    printArr(num);
    string res;

    if (num[0] == 0)
    {
        return "0";  
    }

    for(int i = 0; i < num.size(); i++) {

        std::string s = std::to_string(num[i]);
        res.append(s);
    }

    return res;
}

int main(int argc, char *argv[]) {

    vector<int> ve;

    ve.push_back(1);
    ve.push_back(2);
    ve.push_back(3);
    ve.push_back(4);
    ve.push_back(0);

    cout<<"res:"<<largestNumber(ve)<<endl;
    printArr(ve);
    return 0;

}

