using namespace std;

string longestPalindromicSubstring(string str) {
	int n = str.length();
	if(n<2)
		return str;
	int maxLength = 1,start=0;
	
	int low, high;
	for (int i = 0; i < n; i++) {
		low = i - 1;
		high = i + 1;
		while(high < n and str[high] == str[i])
			high++;
		while ( low >= 0 && str[low] == str[i])
			low--;
		while (low >= 0 && high < n && str[low] == str[high]) {
			low--;
			high++;
		}
		int length = high - low - 1;
		if (maxLength < length) {
			maxLength = length;
			start=low+1;
		}
	}
  return str.substr(start, maxLength);
}
