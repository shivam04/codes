using namespace std;

vector<int> spiralTraverse(vector<vector<int>> array) {
	int startRow = 0;
  int endRow = array.size()-1;
	int startCol = 0;
	int endCol = array[0].size()-1;
	vector<int> ans;
	while(startRow<=endRow && startCol<=endCol) {
		for(int col=startCol;col<=endCol;col++) {
			ans.push_back(array[startRow][col]);
		}
		for(int row=startRow+1;row<=endRow;row++) {
			ans.push_back(array[row][endCol]);
		}
		for(int col=endCol-1;col>=startCol;col--) {
			if(startRow==endRow)
				break;
			ans.push_back(array[endRow][col]);
		}
		
		for(int row=endRow-1;row>startRow;row--) {
			if(startCol==endCol)
				break;
			ans.push_back(array[row][startCol]);
		}
		startRow++;
		endRow--;
		startCol++;
		endCol--;
	}
	return ans;
}
