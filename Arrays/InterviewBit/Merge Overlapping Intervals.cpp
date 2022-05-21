//problem link: https://www.interviewbit.com/problems/merge-overlapping-intervals/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool myCmp(Interval &a, Interval &b){
    return a.start<b.start;
}

vector<Interval> Solution::merge(vector<Interval> &A) {
    int n=A.size();
    sort(A.begin(),A.end(),myCmp);
    vector<Interval> res;
    if(n==0) return res;
    res.push_back(A[0]);
    for(int i=1;i<n;i++){
        if(res.back().end>=A[i].start){
            res.back().end=max(res.back().end,A[i].end);
        }
        else res.push_back(A[i]);
    }
    return res;
}
