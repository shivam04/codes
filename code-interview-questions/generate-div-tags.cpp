#include <vector>
using namespace std;
void generateDivTagsUtil(vector<string> &ans, int s, int n, string &p) {
	if(s>0) {
		string np = p + "<div>";
		generateDivTagsUtil(ans, s-1, n, np);
	}
	if(s<n) {
		string np = p + "</div>";
		generateDivTagsUtil(ans, s, n-1, np);
	}
	if(n==0)
		ans.push_back(p);
}
vector<string> generateDivTags(int numberOfTags) {
	vector<string> ans;
	string w = "";
	generateDivTagsUtil(ans, numberOfTags, numberOfTags, w);
  return ans;
}
