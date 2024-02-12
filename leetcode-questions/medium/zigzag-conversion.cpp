class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) {
            return s;
        }
        string arr[numRows];
        for(int i=0;i<numRows;i++) {
            arr[i] = "";
        }
        int i=0, row = 0;
        bool down = true;
        for(i = 0; i < s.size(); i++){
            arr[row] += s[i];
            if (row==0) {
                down = true;
            }
            if (row==numRows-1) {
                down = false;
            }
            down ? row++ : row--;
        }
        string answer = "";
        for(i = 0; i < numRows; i++){
            answer += arr[i];
        }
        return answer;
    }
};