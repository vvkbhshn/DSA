//problem link: https://www.interviewbit.com/problems/serialize/

string Solution::serialize(vector<string> &A) {
    string res;
    for(auto &str:A){
        res+=str+to_string(str.length())+'~';
    }
    return res;
}
