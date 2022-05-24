vector<int> Solution::solve(vector<int> &arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end(), greater<int>());
 
	int freq[arr[0] + 1] = { 0 };
 
	// Count frequency of each element
	for (int i = 0; i < n; i++)
		freq[arr[i]]++;
 
	// Size of the resultant array
	int size = sqrt(n);
	vector<int> brr(size,0) ;
    int x, l = 0;
 
	for (int i = 0; i < n; i++) {
		if (freq[arr[i]] > 0) {
 
			// Store the highest element in
			// the resultant array
			brr[l] = arr[i];
 
			// Decrement the frequency of that element
			freq[brr[l]]--;
			l++;
			for (int j = 0; j < l; j++) {
				if (i != j) {
 
					// Compute GCD
					x = __gcd(arr[i], brr[j]);
 
					// Decrement GCD value by 2
					freq[x] -= 2;
				}
			}
		}
	}
    return brr;
}
