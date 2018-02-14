/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
int cmp(Interval a,Interval b){
    if(a.start==b.end){
        return a.end<b.end;
    }
    return a.start<b.start;
}
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin(),A.end(),cmp);
    int i;
    int n=A.size();
    
    vector<Interval> v;
    if(n==1){
        return A;
    }
    /*for(i=0;i<n;i++){
        cout<<A[i].start<<" "<<A[i].end<<"\n";
    }*/
    for(i=0;i<n;i++){
        int j = i;
        int m = A[i].end;
        while(m>=A[j+1].start and j<n-1){
            m = max(m,A[j+1].end);
            j++;
        }
        if(j>i){
            Interval temp;
            //cout<<A[i].start<<"\n";
            temp.start = A[i].start;
            temp.end = max(m,A[j].end);
            v.push_back(temp);
        }else{
            v.push_back(A[i]);
        }
        i=j;
    }
    return v;
}
