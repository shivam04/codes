class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(tasks.empty()) return 0;
        vector<int> f(26);
        for(auto task : tasks)
            ++f[task - 'A'];
        sort(f.begin(), f.end(), greater<int>());
        int fe = f[0], i = 1;
        while(i < 26 && f[i] == fe) ++i;
        int frame_size = max(i, n + 1) * (fe - 1) + i;
        int num = tasks.size();
        return max(num, frame_size);
    }
};