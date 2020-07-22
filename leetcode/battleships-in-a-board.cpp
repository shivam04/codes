class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int r = board.size();
        int c = 0;
        if(r>0) {
           c =  board[0].size();
        }
        int ans = 0;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if (board[i][j] == '.' || (i > 0 && board[i - 1][j] == 'X') || (j > 0 && board[i][j - 1] == 'X')) continue;
                ans++;
            }
        }
        return ans;
    }
};