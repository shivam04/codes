using namespace std;

class OrgChart {
public:
  char name;
  vector<OrgChart *> directReports;

  OrgChart(char name) {
    this->name = name;
    this->directReports = {};
  }

  void addDirectReports(vector<OrgChart *> directReports);
};
OrgChart* getLowestCommonManagerUtil(OrgChart *topManager, OrgChart *reportOne,
                                 OrgChart *reportTwo, bool &v1, bool &v2) {
	if(topManager==nullptr)
		return nullptr;
	if(topManager==reportOne) {
		v1 = true;
		return topManager;
	}
	if(topManager==reportTwo) {
		v2 = true;
		return topManager;
	}
	OrgChart* nodes[topManager->directReports.size()];
	int c = 0;
	OrgChart* ans = nullptr;
	for(int i=0;i<topManager->directReports.size();i++) {
		nodes[i] = getLowestCommonManagerUtil(topManager->directReports[i], reportOne, reportTwo, v1, v2);
		if(nodes[i]!=nullptr) {
			ans = nodes[i];
			c++;
		}
	}
	if(c>=2) {
		return topManager;
	}
	return ans;
}

bool find(OrgChart* root, OrgChart* findNode) {
	if(root == nullptr)
		return root;
	if(root==findNode)
		return true;
	for(OrgChart* c: root->directReports) {
		if(find(c, findNode))
			return true;
	}
	return false;
}


OrgChart *getLowestCommonManager(OrgChart *topManager, OrgChart *reportOne,
                                 OrgChart *reportTwo) {
  bool v1 = false, v2 = false;
	OrgChart* node = getLowestCommonManagerUtil(topManager, reportOne, reportTwo, v1, v2);
  if((v1 and v2) || (v1 and find(node, reportTwo)) || (v2 and find(node, reportOne)))
		return node;
	return nullptr;
}
