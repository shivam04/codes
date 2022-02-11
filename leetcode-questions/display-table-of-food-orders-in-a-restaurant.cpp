class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int,map<string,int> > mp;
        set<string> foods;
        set<int> tables;
        int n = orders.size();
        for(int i=0;i<n;i++) {
            foods.insert(orders[i][2]);
            tables.insert(stoi(orders[i][1]));
        }
        for(auto t : tables) {
            for(auto f : foods) {
                mp[t][f] = 0;
            }
        }
        for(int i=0;i<n;i++) {
            mp[stoi(orders[i][1])][orders[i][2]] += 1;
        }
        
        vector<vector<string> > ans;
        vector<string> row;
        row.push_back("Table");
        for(auto order: foods) {
            row.push_back(order);
        }
        ans.push_back(row);
        row.clear();
        for(auto it: mp) {
            row.push_back(to_string(it.first));
            for(auto order: it.second) {
                row.push_back(to_string(order.second));
            }
            ans.push_back(row);
            row.clear();
        }
        return ans;
    }
};