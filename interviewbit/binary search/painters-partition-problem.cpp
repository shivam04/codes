int getMax(vector<int>arr, int n)
{
  int max = INT_MIN;
  for (int i = 0; i < n; i++) 
    if (arr[i] > max)
      max = arr[i]; 
  return max;
}
int getSum(vector<int>arr, int n)
{
  int total = 0;
  for (int i = 0; i < n; i++)
    total += arr[i];
  return total;
}
int numberOfPainters(vector<int>arr, int n, int maxLen)
{
  int total = 0, numPainters = 1;

  for (int i = 0; i < n; i++) {
    total += arr[i];

    if (total > maxLen) {
      total = arr[i];
      numPainters++;
    }
  }

  return numPainters;
}

int Solution::paint(int A, int B, vector<int> &C) {
    int n=C.size();
    int l = getMax(C, n);
  int r = getSum(C, n);
    int i;
    if(C.size()==0){
        return 0;
    }
    while(l<r){
        int mid = l+(r-l)/2;
        int reqPainters = numberOfPainters(C, n, mid);
        if(reqPainters<=A){
            r = mid;
        }else{
            l = mid+1;
        }
    }
    return ((long long)l%10000003*B%10000003)%10000003;
}
