// Source :  
// Author : Cheng Chen
// Date   : 2014-11-02

/********************************************************************************** 
  * 
  * Given a binary tree, return the preorder traversal of its nodes' values.
  * 
  * For example:
  * Given binary tree {1,#,2,3},
  * 
  *    1
  *     \
  *      2
  *     /
  *    3
  * i
  * return [1,2,3].
  * 
  * Note: Recursive solution is trivial, could you do it iteratively?
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
