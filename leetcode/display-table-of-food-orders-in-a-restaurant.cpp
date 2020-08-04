class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int,map<string,int> > mp;
        set<string> s;
        set<int> tables;
        int n = orders.size();
        for(int i=0;i<n;i++) {
            s.insert(orders[i][2]);
            tables.insert(stoi(orders[i][1]));
        }
        for(auto it1 = tables.begin(); it1 != tables.end(); ++it1) {
            int table = *it1;
            for(auto it2 = s.begin(); it2 != s.end(); ++it2) {
                string order = *it2;
                mp[table][order] = 0;
            }
        }
        
        for(int i=0;i<n;i++) {
            mp[stoi(orders[i][1])][orders[i][2]] += 1;
        }
        
        vector<vector<string> > ans;
        vector<string> row;
        row.push_back("Table");
        for(auto it2 = s.begin(); it2 != s.end(); ++it2) {
            string order = *it2;
            row.push_back(order);
        }
        ans.push_back(row);
        row.clear();
        for(auto it1 = tables.begin(); it1 != tables.end(); ++it1) {
            int table = *it1;
            row.push_back(to_string(table));
            for(auto it2 = s.begin(); it2 != s.end(); ++it2) {
                string order = *it2;
                row.push_back(to_string(mp[table][order]));
            }
            ans.push_back(row);
            row.clear();
        }
        return ans;
    }
};