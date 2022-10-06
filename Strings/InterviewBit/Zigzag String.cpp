//problem link: https://www.interviewbit.com/problems/zigzag-string/

string Solution::convert(string A, int B) {
    int n=A.length();
	if(B==1 || B>=n) return A;
	vector<string> v(B);
    bool up=false;
    int row=0;
    for(auto c:A){
        v[row]+=c;
        if(row==0) up=false;
        else if(row==B-1) up=true;
        if(up) row--;
        else row++;
    }
    string res;
    for(auto &x:v) res+=x;
    return res;
}
