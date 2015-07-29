/* 
 * Author: cc
 * Date  : 2015-07-29
 * Source: https://leetcode.com/problems/implement-trie-prefix-tree/
 * Description:
 * Implement a trie with insert, search, and startsWith methods.
 *
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    unordered_map<char, TrieNode*> map_node;
    bool isNode;
    TrieNode() {
        isNode = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* visit = root;
        for (int i = 0; i < word.size(); i++) {
            if (visit->map_node.find(word[i]) != visit->map_node.end()) {
                //should mark the node is the insert node
                if (i == word.size() - 1) {
                   visit->map_node[word[i]]->isNode = true; 
                }
                visit = visit->map_node[word[i]];
            }else{
                TrieNode *node = new TrieNode();
                if (i == word.size() - 1) {
                    node->isNode = true;
                }
                visit->map_node.insert(make_pair(word[i], node));
                visit = node;
            }
        } 
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* visit = root;

        for (int i = 0; i < word.size(); ++i) {
            if (visit->map_node.find(word[i]) != visit->map_node.end()) {
                visit = visit->map_node[word[i]];
            }else{
                return false;
            }
        }

        if (visit->isNode) {
           return true;
        }
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* visit = root;

        for (int i = 0; i < prefix.size(); ++i) {
            if (visit->map_node.find(prefix[i]) != visit->map_node.end()) {
                visit = visit->map_node[prefix[i]];
            }else{
                return false;
            }
        }

        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");


int main(int argc, char *argv[]) {
    Trie trie;
    trie.insert("abc");
    cout<<trie.search("abc")<<endl;
    cout<<trie.search("ab")<<endl;
    trie.insert("ab");
    cout<<trie.search("ab")<<endl;
    cout<<trie.search("ab")<<endl;
    cout<<trie.search("ab")<<endl;

    cout<<trie.startsWith("a");
    return 0;
}

