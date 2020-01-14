/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The function returns a vector containing the 
increasing sub-sequence of length 3 if present
else returns an empty vector */
vector<int> find3Numbers(vector<int> A, int N)
{
    int smaller[N+1];
    int greater[N+1];
    int i;
    smaller[0] = -1;
    int mini=0;
    for(i=1;i<N;i++){
        if(A[i]<=A[mini]){
            mini = i;
            smaller[i] = -1;
        }else{
            smaller[i] = mini;
        }
    }
    int maxi = N-1;
    greater[N-1] = -1;
    for(i=N-2;i>=0;i--){
        if(A[i]>=A[maxi]){
            maxi = i;
            greater[i]=-1;
        }else{
            greater[i] = maxi;
        }
    }
    /*for(i=0;i<N;i++){
        cout<<smaller[i]<<" "<<greater[i]<<"\n";
    }*/
    vector<int> v;
    for(int i=0;i<N;i++){
        if(smaller[i]!=-1 and greater[i]!=-1){
            //cout<<smaller[i]<<" "<<i<<" "<<greater[i]<<"\n";
            v.push_back(A[smaller[i]]);
            v.push_back(A[i]);
            v.push_back(A[greater[i]]);
            //cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<"\n";
            return v;
        }
    }
    return v;
}