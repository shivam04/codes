class Solution {
public:
    int traverse(string tiles, map<int,int> cc) {
        int sum = 0;
        for (int i = 0; i < 26; i++) {
            if(cc[i]==0) continue;
            sum++;
            cc[i]--;
            sum += traverse(tiles, cc);
            cc[i]++;
        }
        return sum;
    }
    int numTilePossibilities(string tiles) {
        map<int,int> cc;
        sort(tiles.begin(), tiles.end());
        for(char c: tiles) {
            cc[c-'A'] += 1;
        }
        return traverse(tiles, cc);
    }
};