#include <vector>

using namespace std;

int getLeftElementIndex(vector<int> array, int si, int mini) {
	for(int i=si+1;i<array.size();i++) {
		if(array[i]<array[si] and array[i]>=mini)
			return i;
	}
	return -1;
}

int getRightElementIndex(vector<int> array, int si, int maxi) {
	for(int i=si+1;i<array.size();i++) {
		if(array[i]>=array[si] and array[i]<maxi)
			return i;
	}
	return -1;
}

bool sameBstsUtil(vector<int> arrayOne, vector<int> arrayTwo, int rootOne, int rootTwo, int mini, int maxi) {
	if(rootOne==-1 or rootTwo==-1)
		return rootOne==rootTwo;
	if(arrayOne[rootOne] != arrayTwo[rootTwo])
		return false;
	int leftNodeOne = getLeftElementIndex(arrayOne, rootOne, mini);
	int leftNodeTwo = getLeftElementIndex(arrayTwo, rootTwo, mini);
	int rightNodeOne = getRightElementIndex(arrayOne, rootOne, maxi);
	int rightNodeTwo = getRightElementIndex(arrayTwo, rootTwo, maxi);
	int cv = arrayOne[rootOne];
	bool leftSame = sameBstsUtil(arrayOne, arrayTwo, leftNodeOne, leftNodeTwo, mini, cv);
	bool rigtSame = sameBstsUtil(arrayOne, arrayTwo, rightNodeOne, rightNodeTwo, cv, maxi);
	return (leftSame and rigtSame);
}

bool sameBsts(vector<int> arrayOne, vector<int> arrayTwo) {
	return sameBstsUtil(arrayOne, arrayTwo, 0, 0, INT_MIN, INT_MAX);
}
