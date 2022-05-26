//problem link: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#
    
static bool myCmp(pair<int,int> &a, pair<int,int> &b){
    return a.second<b.second;
}

//Function to find the maximum number of meetings that can
//be performed in a meeting room.
int maxMeetings(int start[], int end[], int n)
{
    // Your code here
    vector<pair<int,int>> A(n);
    for(int i=0;i<n;i++) A[i]={start[i],end[i]};
    sort(A.begin(),A.end(),myCmp);
    int res=1, prev=0;
    for(int i=0;i<n;i++){
        if(A[i].first>A[prev].second){
            res++;
            prev=i;
        }
    }
    return res;
}