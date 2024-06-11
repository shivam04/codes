#include <bits/stdc++.h>
using namespace std;

void rotateRow(vector<vector<int>> &mat, int r) {
	vector<int> oR = mat[r];
	rotate(oR.begin(), oR.begin()+oR.size()-1, oR.end());
	mat[r] = oR;
}

void rotateCol(vector<vector<int>> &mat, int c) {
	vector<int> oR;
	for(int i=0;i<mat.size();i++) {
		oR.push_back(mat[i][c]);
	}
	rotate(oR.begin(), oR.begin()+oR.size()-1, oR.end());
	for(int i=0;i<mat.size();i++) {
		mat[i][c] = oR[i];
	}
}

int main() {
	int n,r,c;
	cin>>n>>r>>c;
	vector<vector<int>> mat(n , vector<int> (n));
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>mat[i][j];
		}
	}
	int R;

	for(int i=0;i<r;i++) {
		cin>>R;
		R--;
		rotateRow(mat, R);
	}


	int C;

	for(int i=0;i<c;i++) {
		cin>>C;
		C--;
		rotateCol(mat, C);
	}

	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout<<mat[i][j]<<" ";
		}
		cout<<"\n";
	}

}