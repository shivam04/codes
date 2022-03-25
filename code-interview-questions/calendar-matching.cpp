#include <vector>

using namespace std;

struct StringMeeting {
  string start;
  string end;
};


struct Meeting {
  int start;
  int end;
};

int timeInMin(string time) {
	int delim = time.find(":");
	int h = stoi(time.substr(0,delim));
	int m = stoi(time.substr(delim+1,time.length()));
	return h*60 + m;
}

string minToTime(int min) {
	int h = min/60;
	int m = min%60;
	string hs = to_string(h);
	string ms = m < 10 ? "0" + to_string(m) : to_string(m);
	return hs + ":" + ms;
}

vector<Meeting> getUpdatedCal(vector<StringMeeting> calendar, StringMeeting dailyBounds) {
	vector<StringMeeting> uc;
	uc.push_back({"0:00", dailyBounds.start});
	uc.insert(uc.end(), calendar.begin(), calendar.end());
	uc.push_back({dailyBounds.end, "23:59"});
	vector<Meeting> calInMin;
	for(int i=0;i<uc.size();i++) {
		calInMin.push_back({timeInMin(uc[i].start), timeInMin(uc[i].end)});
	}
	return calInMin;
}
vector<Meeting> merge(vector<Meeting> c1, vector<Meeting>c2) {
	vector<Meeting> merged;
	int i=0;
	int j=0;
	while(i<c1.size() and j<c2.size()) {
		Meeting m1 = c1[i];
		Meeting m2 = c2[j];
		if(m1.start < m2.start) {
			merged.push_back(m1);
			i++;
		} else {
			merged.push_back(m2);
			j++;
		}
	}
	while(i<c1.size()) {
		merged.push_back(c1[i]);
		i++;
	}
	while(j<c2.size()) {
		merged.push_back(c2[j]);
		j++;
	}
	return merged;
}

vector<Meeting> flat(vector<Meeting> calendar) {
	vector<Meeting> fc = {calendar[0]};
	for(int i=1;i<calendar.size();i++) {
		Meeting cm = calendar[i];
		Meeting pm = fc[fc.size()-1];
		if(pm.end >= cm.start) {
			Meeting nm = {pm.start, max(pm.end, cm.end)};
			fc[fc.size()-1] = nm;
		} else {
			fc.push_back(cm);
		}
	}
	return fc;
}

vector<StringMeeting> getAvailableTimeSlots(vector<Meeting> calendar, int mD) {
	vector<Meeting> ansInMin;
	for(int i=1;i<calendar.size();i++) {
		int s = calendar[i-1].end;
		int e = calendar[i].start;
		int aD = e - s;
		if(aD >= mD) {
			ansInMin.push_back({s,e});
		}
	}
	vector<StringMeeting> ans;
	for(int i=0;i<ansInMin.size();i++) {
		ans.push_back({minToTime(ansInMin[i].start), minToTime(ansInMin[i].end)});
	}
	return ans;
}

vector<StringMeeting> calendarMatching(vector<StringMeeting> calendar1,
                                       StringMeeting dailyBounds1,
                                       vector<StringMeeting> calendar2,
                                       StringMeeting dailyBounds2,
                                       int meetingDuration) {
  vector<Meeting> uc1 = getUpdatedCal(calendar1, dailyBounds1);
	vector<Meeting> uc2 = getUpdatedCal(calendar2, dailyBounds2);
	vector<Meeting> merged = merge(uc1, uc2);
	vector<Meeting> fc = flat(merged);
  return getAvailableTimeSlots(fc, meetingDuration);
}
