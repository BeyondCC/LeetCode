/* 
 * Author: cc
 * Date  : 2015-03-06
 * Source: https://oj.leetcode.com/problems/copy-list-with-random-pointer/
 * Description:
 *
 * A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 * Return a deep copy of the list.
 *
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>

using namespace std;

struct RandomListNode{
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x): label(x), next(NULL), random(NULL) {}
};

//跟复制单独节点一样, 复制每个节点都要考虑每个节点random节点
//把每个random节点跟原链表中的节点做个映射
RandomListNode *copyRandomList(RandomListNode *head) {
    unordered_map<RandomListNode*, RandomListNode*> nodeMap;

    if (head == NULL)
    {
        return NULL;
    }

    RandomListNode *result = new RandomListNode(head->label);
    
    if (head->random != NULL)
    {
        RandomListNode *randomNode = new RandomListNode(head->random->label);
        result->random = randomNode;
        //add random node to hashmap
        nodeMap.insert(make_pair(head->random, randomNode));
        nodeMap.insert(make_pair(head, result));
    }

    RandomListNode *visitNode = result;

    while (head->next)
    {
        RandomListNode *currentNode = head->next;
        
        if (nodeMap.find(currentNode) == nodeMap.end())
        {
            RandomListNode *newNode = new RandomListNode(currentNode->label);

            //judge the node status to add the random node to the hashmap
            if (currentNode->random && nodeMap.find(currentNode->random) == nodeMap.end())
            {
                RandomListNode *newRandomNode = new RandomListNode(currentNode->random->label);
                newNode->random = newRandomNode;

                nodeMap.insert(make_pair(currentNode->random, newRandomNode));
            }else{
                newNode->random = nodeMap[currentNode->random];
            }

            nodeMap.insert(make_pair(currentNode, newNode));
            visitNode->next = newNode;
        }else{
            RandomListNode *nextNode = nodeMap[currentNode];

            //the nextNode may not contain random node 
            if (currentNode->random && !nextNode->random)
            {
                if (nodeMap.find(currentNode->random) == nodeMap.end())
                {
                    RandomListNode *randomNode = new RandomListNode(currentNode->random->label);

                    nodeMap.insert(make_pair(currentNode->random, randomNode));
                    nextNode->random = randomNode;
                }else{
                    nextNode->random = nodeMap[currentNode->random];
                }

                nodeMap[currentNode] = nextNode;
            }

            visitNode->next = nextNode;
        }

        head = head->next;
        visitNode = visitNode->next;
    }

    return result;
}

int main(int argc, char *argv[]) {
    RandomListNode *node1 = new RandomListNode(3);
    RandomListNode *node2 = new RandomListNode(4);
    RandomListNode *node3 = new RandomListNode(5);
    RandomListNode *node4 = new RandomListNode(6);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    node1->random = node3;
    node2->random = node1;

    copyRandomList(node1); 
    return 0;
}

