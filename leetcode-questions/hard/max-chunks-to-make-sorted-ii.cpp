class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> tempA = arr;
        sort(tempA.begin(), tempA.end());

        unordered_map<int, int> setA, setB;
        int i = 0;
        while(i<n and arr[i]==tempA[i]) {
            i++;
        }
        if(i==n)
            return n;
        setA[arr[i]]++;
        setB[tempA[i]]++;
        int ans = i==0 ? 0 : i;
        i++;

        for(;i<n;i++) {
            if(arr[i]==tempA[i])
                continue;
            if(setA.find(tempA[i]) != setA.end() and setA[tempA[i]] > 0) {
                    setA[tempA[i]]--;
                    if(setA[tempA[i]]==0)
                        setA.erase(tempA[i]);
            } else {
                setB[tempA[i]]++;
            }
            if(setB.find(arr[i]) != setB.end() and setB[arr[i]] > 0) {
                setB[arr[i]]--;
                if(setB[arr[i]]==0)
                    setB.erase(arr[i]);
            } else {
                setA[arr[i]]++;
            }
            
            if(setA.size()==0 and setB.size()==0) {
                ans++;
                int j = i;
                i++;
                while(i<n and arr[i]==tempA[i]) {
                    i++;
                }
                if(i>j+1)
                    ans += (i-j-1);
                if(i>=n)
                    break;
                setA[arr[i]]++;
                setB[tempA[i]]++;
            }
        }
        return ans;
    }
};