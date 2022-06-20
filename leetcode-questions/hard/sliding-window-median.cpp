class Solution {
public:
    set<pair<long long,int>> minh;
    set<pair<long long,int>, greater<pair<long long,int>>> maxh;
    double median=0.0;
    void addNum(long long num, int i) {
        if(maxh.size()==minh.size()) {
            if(num > median) {
                minh.insert({num,i});
                median = (*minh.begin()).first;
            } else {
                maxh.insert({num,i});
                median = (*maxh.begin()).first;
            }
        } else if(maxh.size() > minh.size()) {
            if(num > median) {
                minh.insert({num,i});
            } else {
                minh.insert(*maxh.begin());
                maxh.erase(maxh.begin());
                maxh.insert({num,i});
            }
            median = ((double)((*minh.begin()).first+(*maxh.begin()).first)/(2.0));
        } else {
            if(num > median) {
                maxh.insert(*minh.begin());
                minh.erase(minh.begin());
                minh.insert({num,i});
            } else {
                maxh.insert({num,i});
            }
            median = ((double)((*minh.begin()).first+(*maxh.begin()).first)/(2.0));
        }
    }
    double findMedian() {
        return median;
    }
    void removeElement(long long num, int i) {
        if(minh.find({num,i}) != minh.end()) {
            if(minh.size()>=maxh.size()) {
                minh.erase({num,i});
            } else {
                minh.erase({num,i});
                minh.insert(*maxh.begin());
                maxh.erase(maxh.begin());
            }
        }
        else {
            if(maxh.size()>=minh.size()) {
                maxh.erase({num,i});
            } else {
                maxh.erase({num,i});
                maxh.insert(*minh.begin());
                minh.erase(minh.begin());
            }
        }
        if(maxh.size()==minh.size()) {
            median = ((double)((*minh.begin()).first+(*maxh.begin()).first)/(2.0));
        } else if(maxh.size() > minh.size()) {
            median = (*maxh.begin()).first;
        } else {
            median = (*minh.begin()).first;
        }
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        maxh.clear();
        minh.clear();
        vector<double> ans;
        int n = nums.size();
        for(int i=0;i<k;i++) {
            addNum((long long)nums[i], i);
        }
        ans.push_back(findMedian());
        for(int i=k;i<n;i++) {
            removeElement((long long)nums[i-k], i-k);
            addNum((long long)nums[i], i);
            ans.push_back(findMedian());
        }
        return ans;
    }
};