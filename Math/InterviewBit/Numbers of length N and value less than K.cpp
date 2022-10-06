//problem link: https://www.interviewbit.com/problems/numbers-of-length-n-and-value-less-than-k/

int Solution::solve(vector<int> &A, int B, int C) {
    if(A.size()==0) return 0;
    int n=A.size(), m=log10(C)+1;
    int res=0;
    if(B>m) return 0;
    else if(B<m){
        if(A[0]==0) res=(n-1)*pow(n,B-1);
        else res=pow(n,B);
        if(B==1 && A[0]==0) res++;
    }
    else{
        if(B==1){
            for(auto x:A) if(x<C) res++;
        }
        else{
            vector<int> dig(m);
            int temp=C;
            for(int i=m-1;i>=0;i--){
                dig[i]=temp%10;
                temp/=10;
            }
            int count=0;
            for(auto x:A){
                if(x>0 && x<=dig[0]) count++;
            }
            res=count*pow(n,B-1);     
            //remove numbers greater than or equal to C       
            bool flag=0;
            for(auto x:A) if(x==dig[0]) flag=1;
            int j=1;
            while(flag && j<B){
                flag=0;
                count=0;
                for(int i=0;i<n;i++){
                    if(A[i]==dig[j]) flag=1;
                    else if(A[i]>dig[j]) count++;
                }
                res-=count*pow(n,B-j-1);
                j++;
            }
            if(j==B && flag==1) res--;
        }
    }
    return res;
}