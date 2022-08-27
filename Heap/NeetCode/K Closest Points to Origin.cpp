//problem link: https://leetcode.com/problems/k-closest-points-to-origin/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        int n=points.size();
        int lo=0, hi=n-1;
        while(lo<=hi){
            int p=partition(points, lo, hi);
            if(p>k-1) hi=p-1;
            else if(p<k-1) lo=p+1;
            else break;
        }
        return vector<vector<int>>(points.begin(),points.begin()+k);
    }
    
    int partition(vector<vector<int>> &points, int lo, int hi){
        swap(points[hi],points[lo+rand()%(hi-lo+1)]);
        int index=lo, pivotDistance=getDistance(points[hi]);
        for(int i=lo;i<hi;i++){
            if(getDistance(points[i])<=pivotDistance){
                swap(points[i],points[index++]);
            }
        }
        swap(points[index],points[hi]);
        return index;
    }
    
    int getDistance(vector<int> &v){
        return v[0]*v[0]+v[1]*v[1];
    }    
};