#include<iostream>
#include<vector>

using namespace std;


  int lengthOfLastWord(const char *s) {
        int count = 0;
        char preChar = NULL;

        while(*s != '\0')
        {
            if(*s == ' ')
            {
                preChar = ' ';
            }else{
                if(preChar == ' '){ //"hello " should return 5
                    count= 1;
                    preChar = *s;
                }
                else
                    count++;
            }
            s++;
        }
        return count;
 }

int main(int argc, char*argv[])
{
	return 1;
}
