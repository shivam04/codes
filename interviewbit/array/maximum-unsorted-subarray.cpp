vector<int> Solution::subUnsort(vector<int> &arr) {
    int n =arr.size();
    int s = 0, e = n-1, i, max, min;
    
    for (s = 0; s < n-1; s++)
    {
        if (arr[s] > arr[s+1])
            break;
    }
    vector<int> v;
    if(s==n-1){
        v.push_back(-1);
        return v;
    }
    for(e = n - 1; e > 0; e--)
    {
        if(arr[e] < arr[e-1])
            break;
    }
    max = arr[s]; min = arr[s];
    for(i = s + 1; i <= e; i++)
    {
        if(arr[i] > max)
            max = arr[i];
        if(arr[i] < min)
            min = arr[i];
    }
    for( i = 0; i < s; i++)
    {
        if(arr[i] > min)
        {  
            s = i;
            break;
        }      
    }
    for( i = n -1; i >= e+1; i--)
    {
        if(arr[i] < max)
        {
            e = i;
            break;
        } 
    }
    v.push_back(s);
    v.push_back(e);
    return v;
}
