//(2^(n+m)) O(n+m)
using namespace std;

bool areInterWoven(string one, string two, string three, int i, int j) {
	int k = i+j;
	if(k==three.size())
		return true;
	if(i<one.size() and one[i]==three[k]) {
		if(areInterWoven(one, two, three, i+1, j))
			return true;
	}
	if(j<two.size() and two[j]==three[k]) {
		if(areInterWoven(one, two, three, i, j+1))
			return true;
	}
	return false;
}

bool interweavingStrings(string one, string two, string three) {
  if(three.size() != one.size() + two.size())
		return false;
  return areInterWoven(one, two, three, 0, 0);
}



//(2^(n+m)) O(n+m)
using namespace std;
map<int,map<int,bool>> mp;
bool areInterWoven(string one, string two, string three, int i, int j) {
	int k = i+j;
	if(k==three.size())
		return true;
	if(mp.find(i)!=mp.end() and mp[i].find(j)!=mp[i].end())
		return mp[i][j];
	if(i<one.size() and one[i]==three[k]) {
		if(areInterWoven(one, two, three, i+1, j))
			return mp[i][j]=true;
	}
	if(j<two.size() and two[j]==three[k]) {
		if(areInterWoven(one, two, three, i, j+1))
			return mp[i][j]=true;
	}
	return mp[i][j]=false;
}

bool interweavingStrings(string one, string two, string three) {
	mp.clear();
  if(three.size() != one.size() + two.size())
		return false;
  return areInterWoven(one, two, three, 0, 0);
}
