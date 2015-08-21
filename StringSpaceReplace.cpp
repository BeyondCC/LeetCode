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
        void replaceSpace(char *str,int length) {
            int count = 0;
            int len = 0;
            char *visit = str;
            
            while(*visit != '\0')
            {
                if (*visit == ' ') {
                    count++;
                }
                visit++;
                len++;
            }

            int totalLength= len + 2 * count;
            int end = totalLength;
            printf("len:%d  length:%d count:%d\n", len, totalLength, count);
            end--;
            len--;
            while(len >= 0)
            {
                if (str[len] == ' ') {
                    printf("end:%d\n", end);
                    str[end--] = '0';
                    str[end--] = '2';
                    str[end--] = '%';
                    printf("end:%d\n", end);
                }else{
                    printf("end:%d\n", end);
                    printf("end:%c\n", str[len]);
                    str[end--] = str[len];
                    printf("end:%d\n", end);
                }

                len--;
            }

            str[totalLength ] = '\0';
           
            printf("%s\n", str);
        }

};
int main(int argc, char *argv[]) {
    Solution s;
    char str[100] = "hello world";
    s.replaceSpace(str, 100);
    return 0;
}

