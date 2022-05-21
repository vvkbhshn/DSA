// problem link: https://www.interviewbit.com/problems/merge-intervals/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

// bool myCmp(Interval &a, Interval &b){
//     return a.start<b.start;
// }

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    int n=intervals.size();
    if(newInterval.start>newInterval.end) swap(newInterval.start,newInterval.end);
    bool merged=false;
    vector<Interval> res;
    for(int i=0;i<n;i++){
        Interval temp=intervals[i];
        if(!merged && temp.start>newInterval.end){
            res.push_back(newInterval);
            merged=true;
        }
        if(!merged && max(intervals[i].start,newInterval.start)<=min(intervals[i].end,newInterval.end)){
            // overlapping occurs 
            temp.start=min(temp.start,newInterval.start);
            temp.end=max(temp.end,newInterval.end);
            merged=true;
        }
        if(!res.empty() && merged && res.back().end>=temp.start){
            res.back().end=max(res.back().end,temp.end);
        }
        else res.push_back(temp);
    }
    if(n==0 || newInterval.start>res.back().end) res.push_back(newInterval);
    return res;
    
    // Method-2: (less efficient)
    // if(newInterval.start>newInterval.end) swap(newInterval.start,newInterval.end);
    // intervals.push_back(newInterval);
    // sort(intervals.begin(),intervals.end(),myCmp);
    // vector<Interval> res;
    // res.push_back(intervals[0]);
    // for(int i=1;i<intervals.size();i++){
    //     int sz=res.size();
    //     if(!res.empty() && res[sz-1].end>=intervals[i].start){
    //         res[sz-1].end=max(res[sz-1].end,intervals[i].end);
    //     }
    //     else res.push_back(intervals[i]);
    // }
    // return res;
}
