/* 
 * Author: cc
 * Date  : 2015-04-06
 * Source: https://leetcode.com/problems/roman-to-integer/
 * Description:
 * Given a roman numeral, convert it to an integer.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

// 左减的数字必须只能是一位，从左只有进行遍历至左键的地方，之前的数字都可以加起来，并更新扫描的位置
int romanToInt(string s) {
    unordered_map<char, int> map;
    int result = 0;
    int prePos = 0;

    map.insert(make_pair('I', 1));
    map.insert(make_pair('V', 5));
    map.insert(make_pair('X', 10));
    map.insert(make_pair('L', 50));
    map.insert(make_pair('C', 100));
    map.insert(make_pair('D', 500));
    map.insert(make_pair('M', 1000));
    
    for (int i = 0; i < s.length() - 1; ++i)
    {
        if (map[s[i]] < map[s[i + 1]])
        {
            for(int j = prePos; j < i; j++)
            {
                result += map[s[j]];
            }

            result += map[s[i + 1]] - map[s[i]];
            prePos = i + 2;
        }
    }

    for (int i = prePos; i < s.length(); ++i)
    {
        result += map[s[i]];
    }
    return result;
}

int main(int argc, char *argv[]) {
    cout<<romanToInt("MCDXXXVII")<<endl;
    cout<<romanToInt("CXCIX")<<endl;
    cout<<romanToInt("MCDLXXVI")<<endl;
    return 0;
}

