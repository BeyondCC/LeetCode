/*
 * Source: https://oj.leetcode.com/problems/merge-intervals/
 * Description:
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
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

void printIntervals(vector<Interval> intervals);

//what the fucking static 
static bool compare(Interval a, Interval b) {
    return a.start < b.start;
}

//归并排序
vector<Interval> merge(vector<Interval> &intervals) {
    if (intervals.size() == 0)
    {
        return intervals;
    }

    cout<<"============"<<endl;
    sort(intervals.begin(), intervals.end(), compare);
    printIntervals(intervals);

    cout<<"============"<<endl;
    vector<Interval> res;

    res.push_back(intervals[0]);
    int i;
    for (i = 1; i < intervals.size(); ++i)
    {
        if (intervals[i].start <= res[res.size() - 1].end && res[res.size() - 1].end < intervals[i].end)
        {
            res[res.size() - 1].end = intervals[i].end;
        }else if (intervals[i].start > res[res.size() - 1] .end)
        {
            res.push_back(intervals[i]);
        }
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
    Interval i4(1, 4);
    Interval i5(1, 5);

    vector<Interval> intervals;
    intervals.push_back(i4);
    intervals.push_back(i5);

    vector<Interval> res = merge(intervals);

    printIntervals(res);
    return 0;
}

