using namespace std;

int factorial(int n) {
	int ans = 1;
	for(int i=2;i<=n;i++) {
		ans*=i;
	}
	return ans;
}
int numberOfWaysToTraverseGraph(int width, int height) {
  width--;
	height--;
	return factorial(width+height)/(factorial(width)*factorial(height));
}
