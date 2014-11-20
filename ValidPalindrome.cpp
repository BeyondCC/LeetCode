#include<iostream>
#include<string>
using namespace std;

/*
 * Given a string, determine if it is a palindrome, considering only alphanumeri *  c characters and ignoring cases.
 *
 *  For example,
 *  "A man, a plan, a canal: Panama" is a palindrome.
 *  "race a car" is not a palindrome.
 *
 */

bool isCharacterNumberic(char c);
bool charEqual(char a, char b);

 bool isPalindrome(string s) {
        int i,j;
        
        for(i = 0, j = s.length() - 1; i <= j;)
        {
            while(!isCharacterNumberic(s[i]) && s[i] != '\0')
	            i++;
      
            if(i >= j)
                return 1;
                
           while(!isCharacterNumberic(s[j]) && j >= 0)
            	j--;

           if(!charEqual(s[i], s[j]))
            	return 0;
      
           i++;
           j--;
      }

        return 1;
    }
    
    bool isCharacterNumberic(char c)
    {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            return 1;
        
        return 0;
    }
    
    bool charEqual(char a, char b)
    {
        if(a == b || a + 32 == b || a - 32 == b)
            return 1;
            
        return 0;
    }

int main()
{
  string s = " ";
  cout<<s.length()<<endl;
  cout<<isPalindrome(s)<<endl;
  return 0;
}
