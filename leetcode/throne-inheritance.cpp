class ThroneInheritance {
private:
    unordered_map<string, vector<string>> family;
    unordered_set<string> dead;
    string kingName;
    void dfs(string name, vector<string> &ans) {
        if(!dead.count(name))
            ans.push_back(name);
        if (!family.count(name))
            return;
        for (string child : family[name]) {
            dfs(child, ans);
        }
    }
public:
    ThroneInheritance(string kingName) : kingName(kingName) {}
    
    void birth(string parentName, string childName) {
        family[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(kingName, ans);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */