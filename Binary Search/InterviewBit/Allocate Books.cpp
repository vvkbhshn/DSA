//problem link: https://www.interviewbit.com/problems/allocate-books/

int countStudents(vector<int> &A, int pages){
    int cnt=1, curr=0;
    for(auto x:A){
        curr+=x;
        if(curr>pages){
            curr=x;
            cnt++;
        }
    }
    return cnt;
}


int Solution::books(vector<int> &A, int B) {
    int n=A.size();
    if(B>n) return -1;
    int res=0;
    int l=0, mid;
    long long r=0;
    for(auto x:A){
        l=max(l,x);
        r+=x;
    }
    while(l<=r){
        mid=l+(r-l)/2;
        int cnt=countStudents(A,mid);
        if(cnt>B) l=mid+1;
        else{
            res=mid;
            r=mid-1;
        }
    }
    return res;
}
