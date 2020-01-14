/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The function should return the modified array
as specified in the problem statement */
vector<int> threeWayPartition(vector<int> A, int lowVal, int highVal)
{
    int n = A.size();
     int start = 0, end = n-1;
    for (int i=0; i<=end;)
    {
        if (A[i] < lowVal)
            swap(A[i++], A[start++]);
        else if (A[i] > highVal)
            swap(A[i], A[end--]);
        else
            i++;
    }
    return A;
}
