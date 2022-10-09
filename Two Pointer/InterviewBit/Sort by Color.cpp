//problem link: https://www.interviewbit.com/problems/sort-by-color/

void Solution::sortColors(vector<int> &A) {
    int n=A.size();
    int i=0;
    int red=0, blue=n-1;
    while(i<=blue){
        if(A[i]==0){
            swap(A[i],A[red]);
            red++;
        }
        if(A[i]==2){
            swap(A[i],A[blue]);
            blue--;
			continue;
        }
        i++;
    }  
}