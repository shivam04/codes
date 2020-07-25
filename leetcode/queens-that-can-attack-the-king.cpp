class Solution {
public:
    bool isValid(vector<int> pos) {
        return ((pos[0] > -1) && (pos[0] < 8) && (pos[1] > -1) && (pos[1] < 8));
    }
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        map<pair<int,int>, int> q;
        for(int i= 0;i<queens.size();i++) {
            q[{queens[i][0], queens[i][1]}] = 1;
        }
        vector<vector<int>> res;
        int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
        int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
        for(int i=0;i<8;i++) {
            int x = dx[i];
            int y = dy[i];
            vector<int> pos = king;
            while(isValid(pos)) {
                if(q[{pos[0], pos[1]}] == 1) {
                    res.push_back(pos);
                    break;
                }
                pos[0] += x;
                pos[1] += y;
            }
        }
        return res;
    }
};