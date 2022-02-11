void getAllCombinations(string characters, int r, int idx, string data, int i, vector<string> &combinations) {
    if (idx == r) {
        combinations.push_back(data);
        return;
    }
    if (i >= characters.length())
      return;
    data[idx] = characters[i];
    getAllCombinations(characters, r, idx+1, data, i+1, combinations);
    getAllCombinations(characters, r, idx, data, i+1, combinations);
}
class CombinationIterator {
public:
    vector<string> combinations;
    int i = 0;
    int n;
    CombinationIterator(string characters, int combinationLength) {
        string data = "";
        for(int i=0;i<combinationLength;i++) {
            data += " ";
        }
        getAllCombinations(characters, combinationLength, 0, data, 0, combinations);
        n = combinations.size();
    }
    
    string next() {
        return combinations[i++];
    }
    
    bool hasNext() {
        return i<n;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */