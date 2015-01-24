/*
 * Source:https://oj.leetcode.com/problems/merge-intervals://oj.leetcode.com/problems/insert-interval/ 
 * Description:
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to their start times.
 *
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 *
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 *
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 */

#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>

struct Interval {
    int start;
    int end;
    Interval():start(0), end(0) {};
    Interval(int s, int e): start(s), end(e) {};
};

using namespace std;

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) 
{
    int i = 0;

    vector<Interval> res;
    if (intervals.size() == 0)
    {
        res.push_back(newInterval);
        return res;
    }

    while(i < intervals.size() && intervals[i].end < newInterval.start)
    {
        res.push_back(intervals[i]);
        i++;
    }

    if (i < intervals.size())
    {
        newInterval.start = min(intervals[i].start, newInterval.start);
    }

    res.push_back(newInterval);

    while(i < intervals.size() && intervals[i].start <= newInterval.end)
    {
        res.back().end = max(newInterval.end, intervals[i].end);
        i++;
    }

    while(i < intervals.size())
    {
        res.push_back(intervals[i]);
        i++;
    }

    return res;
}

void printIntervals(vector<Interval> intervals) {
    int i;

    for (i = 0; i < intervals.size(); ++i)
    {
        cout<<"start: "<<intervals[i].start<<" end:"<<intervals[i].end<<endl;
    }
}

int main(int argc, char *argv[]) {
    Interval i1(0, 5);
    Interval i2(8, 9);
    Interval newInterval(3, 4);
    vector<Interval> intervals;

    intervals.push_back(i1);
    intervals.push_back(i2);

    intervals = insert(intervals, newInterval);

    printIntervals(intervals);

    return 0;
}

