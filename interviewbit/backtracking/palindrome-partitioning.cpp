bool isPalindrome(string str, int low, int high)
{
    while (low < high)
    {
        if (str[low] != str[high])
            return false;
        low++;
        high--;
    }
    return true;
}
void ans(vector<vector<string> > &v, string A,int s,int e,vector<string>p){
    if (s >= e)
    {
        v.push_back(p);
        return;
    }
    for(int i=s;i<e;i++){
        if(isPalindrome(A,s,i)){
            p.push_back(A.substr(s,i-s+1));
            ans(v,A,i+1,e,p);
            p.pop_back();
        }
    }
}
vector<vector<string> > Solution::partition(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<string> > v;
    vector<string> p;
    ans(v,A,0,A.length(),p);
    return v;
}
