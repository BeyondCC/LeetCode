/* 
 * Author: cc
 * Date  : 2015-02-25
 * Source: https://oj.leetcode.com/problems/max-points-on-a-line/
 * Description:
 * Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<float.h>
using namespace std;

struct Point{
    int x;
    int y;
    Point(): x(0), y(0) {}
    Point(int a, int b): x(a), y(b) {}
};
//time O(n^2), space O(n):the space of the hashmap
int maxPoints(vector<Point> &points) {

    if (points.size() == 0)
    {
        return 0;
    }

    int result = 0;

    for (int i = 0; i < points.size(); ++i)
    {
        Point point = points[i];
        unordered_map<double, int> hashMap;
        int numOfSame = 0;
        int localMax  = 1; //each loop contain one point at least

        for (int j = i + 1; j < points.size(); ++j)
        {
            double ratio = 0;
            
            if (points[i].x == points[j].x && points[i].y == points[j].y)
            {
                numOfSame++;
                continue;
            }

            if (points[i].x == points[j].x)
            {
                ratio = 0;
            }else if (points[i].y == points[j].y)
            {
                ratio = INT_MAX; 
            }else{
                ratio = (double)(points[i].y - points[j].y) / (points[i].x - points[j].x);
            }

            if (hashMap.find(ratio) == hashMap.end())
            {//two point compose one line
                hashMap.insert(make_pair(ratio, 2));
            }else{
                int count = hashMap[ratio];
                count++;

                hashMap[ratio] = count;
            }
        }

        for (unordered_map<double, int>::iterator iter = hashMap.begin(); iter != hashMap.end(); iter++)
        {
            localMax = max(iter->second, localMax);
        }
        //plus the same point
        localMax = localMax + numOfSame;

        result = max(localMax, result);
    }
   

    return result;
}

int main(int argc, char *argv[]) {
    Point p(0, 0), p1(-1, -1), p2(0, 0);

    vector<Point> v;
    v.push_back(p);
    v.push_back(p1);
    v.push_back(p2);

    cout<<maxPoints(v)<<endl;
    return 0;
}

