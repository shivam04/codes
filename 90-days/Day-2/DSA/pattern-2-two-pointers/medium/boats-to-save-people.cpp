class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int totalBoats = 0;
        int l = 0;
        int r = people.size()-1;
        while(l<=r) {
            if (people[l] + people[r] <= limit) {
                totalBoats++;
                l++;
                r--;
            } else {
                totalBoats++;
                r--;
            }
        }
        return totalBoats;
    }
};