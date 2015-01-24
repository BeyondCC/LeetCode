/*
 * Source: https://oj.leetcode.com/problems/maximum-gap/ 
 * Description:
 * Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
 *
 * Try to solve it in linear time/space.
 *
 * Return 0 if the array contains less than 2 elements.
 *
 * You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>


using namespace std;

struct Bucket{
    int min;
    int max;
    int volumn;

    Bucket():volumn(0){};
};

int maximumGap(vector<int> &num) {
    if (num.size() < 2)
    {
        return 0;
    }

    if (num.size() == 2)
    {
        return num[0] > num[1] ? num[0] - num[1] : num[1] - num[0];
    }

    int i;

    int maxInt = INT_MIN;
    int minInt = INT_MAX;
    for (i = 0; i < num.size(); ++i)
    {
            if (num[i] > maxInt)
            {
                maxInt = num[i];
            }

            if (num[i] < minInt)
            {
                minInt = num[i];
            }
    }

    //每个桶的大小取上整
    int maxGap =  (maxInt - minInt) / num.size() + 1;
    int bucketCount = (maxInt - minInt) / maxGap + 1;

    cout<<"maxGap is "<<maxGap<<" bucket count is "<<bucketCount<<endl;
    vector<Bucket> buckets(bucketCount, Bucket());

    //分桶的同时，记录每个桶的最大值和最小值
    for (i = 0; i < num.size(); ++i)
    {
        int bucketIndex = (num[i] - minInt) / maxGap;
       
        if (buckets[bucketIndex].volumn == 0) // 记录最大值
        {
            buckets[bucketIndex].min = buckets[bucketIndex].max = num[i];
        }else if (num[i] > buckets[bucketIndex].max)
        {
            buckets[bucketIndex].max = num[i];
        }else if (num[i] < buckets[bucketIndex].min)
        {
            buckets[bucketIndex].min = num[i];
        }

        buckets[bucketIndex].volumn++;
    }

    int res = INT_MIN;

    int preBucketIndex = 0;

    for (i = 0; i < bucketCount; ++i)
    {
        cout<<"bucket["<<i<<"]:"<<"min:"<<buckets[i].min<<" max:"<<buckets[i].max<<" volumn:"<<buckets[i].volumn<<endl;
    }

    //当前桶的最小值 - 之前桶的最大值 取最大即为最终的结果, 第0个桶肯定不是空桶
    for (i = 1; i < bucketCount; ++i)
    {
        if (buckets[i].volumn == 0) continue;

        if (buckets[i].min - buckets[preBucketIndex].max > res)
        {
                res = buckets[i].min - buckets[preBucketIndex].max;
        }

       preBucketIndex = i;
    }

    return res;
}

void intToVector(vector<int> &ve, int A[], int n) {
    
    int i;

    for (i = 0; i < n; ++i)
    {
        ve.push_back(A[i]);
    }
}

int main(int argc, char *argv[]) {

    int a[] = {15252,16764,27963,7817,26155,20757,3478,22602,20404,6739,16790,10588,16521,6644,20880,15632,27078,25463,20124,15728,30042,16604,17223,4388,23646,32683,23688,12439,30630,3895,7926,22101,32406,21540,31799,3768,26679,21799,23740};
    vector<int> ve;

    intToVector(ve, a, 39);

    cout<<"max gap is "<<maximumGap(ve);
    return 0;
}

