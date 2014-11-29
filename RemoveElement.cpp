// Source : https://oj.leetcode.com/problems/remove-element/
// Author : Cheng Chen
// Date   : 2014-11-29

/********************************************************************************** 
  * Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length. 
  *               
  **********************************************************************************/

#include<iostream>
#include<vector>
//#include<stack>

using namespace std;

 int removeElement(int A[], int n, int elem) {
        int i = 0, length = 0;
        for(i = 0; i < n; i++){
            if(A[i] != elem)
                A[length++] = A[i];
        }

        return length;
}

void printArr(int *arr, int len) {
	for(int i = 0; i < len; i++)
		cout<<arr[i]<<" "<<endl;
}

int main()
{
    int a[] = {1,2,3,4,5,0,6,0,0,7,8,9,0};
    int len = removeElement(a, 13, 0);
    printArr(a, len);
    return 0;
}
