/* 
 * Author: cc
 * Date  : 2015-02-25
 * Source: https://oj.leetcode.com/problems/repeated-dna-sequences/
 * Description:
 *
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
 *
 * Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
 *
 * For example,
 *
 * Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
 *
 * Return:
 * ["AAAAACCCCC", "CCCCCAAAAA"].
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;

//因为只有ACGT4个数字进行00,01,10,11编码，那么10位字符串就是20位,所有编码个数是2^20就是1024 * 1024
//每次只用左移2位，低两位补上下一个字符的编码，21,22位置0，如果有相同的编码值则出现多次
//time o(n) space 2^20 bit
vector<string> findRepeatedDnaSequencesPre(string s) {
    bool hashMap[1024 * 1024];
    vector<string> result;

    unsigned char convertTable[26];
    convertTable[0] = 0; // A - A
    convertTable[2] = 1; // C - A
    convertTable[6] = 2; // G - A
    convertTable[19] = 3; // T - A

    memset(hashMap, false, sizeof(hashMap));

    if (s.length() < 10)
    {
        return result;
    }

    int hashValue = 0;
    for (int i = 0; i < 10; ++i)
    {
        hashValue <<= 2;
        hashValue |= convertTable[s[i] - 'A'];
    }

    hashMap[hashValue] = true;

    unordered_set<int> set; // to store the responding hashValue
    for (int i = 10; i < s.length(); ++i)
    {
        hashValue <<= 2;
        hashValue |= convertTable[s[i] - 'A'];
        hashValue &= ~(0x300000);

        cout<<"hash value is "<<hashValue<<endl;
        if (hashMap[hashValue])
        {
            if (set.find(hashValue) == set.end())
            {
                string subStr = s.substr(i - 10 + 1, 10);

                cout<<"pre:"<<subStr<<endl;
                result.push_back(subStr);
                set.insert(hashValue);
            }
        }else{
            hashMap[hashValue] = true;   
        }
    }
    return result;
}

//space O(mn), the size of hashmap
vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<string, int> countMap;
    vector<string> result;

    cout<<"length:"<<s.length()<<endl;
    cout<<"size:"<<s.size()<<endl;
    if (s.length() <= 10)
    {
       return result; 
    }

    for (int i = 0; i < (s.length() - 10); ++i)
    {
        string subString = s.substr(i, 10);

        cout<<"sub:"<<subString<<endl;

        unordered_map<string, int>::const_iterator iter = countMap.find(subString);
        
        if (iter == countMap.end())
        {
            countMap.insert(make_pair(subString, 1));
        }else{
            int count = iter->second;
            count++;

            countMap[subString] = count;
        }
    }

    cout<<"here"<<endl;

    for (unordered_map<string, int>::iterator iter = countMap.begin(); iter != countMap.end(); iter++)
    {
        int count = iter->second;

        if (count > 1)
        {
            cout<<iter->first<<endl;
            result.push_back(iter->first);        
        }
    }

    return result;
}

int main(int argc, char *argv[]) {
    string s("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");

//    findRepeatedDnaSequences(s);
    findRepeatedDnaSequencesPre(s);
    return 0;
}

