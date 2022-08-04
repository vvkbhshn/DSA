//problem link: https://practice.geeksforgeeks.org/problems/count-squares3649/1

class Solution {
  public:
    int countSquares(int N) {
        int cnt=0, i=1;
        while(i*i<N){
            cnt++;
            i++;
        }
        return cnt;
    }
};