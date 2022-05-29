//problem link: https://www.interviewbit.com/problems/hotel-bookings-possible/

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int C) {
    //Greedy Solution
    int n=arrive.size();
    sort(arrive.begin(),arrive.end());
    sort(depart.begin(),depart.end());
    int count=1;
    int i=1, j=0;
    while(i<n && j<n){
        if(arrive[i]<=depart[j]){
            count++;
            i++;
        }
        else{
            count--;
            j++;
        }
        if(count>C) return false;
    }
    return true;
}
