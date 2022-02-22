using namespace std;

// Do not edit the class below except for
// the insert method. Feel free to add new
// properties and methods to the class.
class ContinuousMedianHandler {
public:
  double median;
	priority_queue <double> maxH;
	priority_queue<double,vector<double>,greater<double> > minH;
  void insert(int number) {
		if(maxH.size()==0 and minH.size()==0) {
			maxH.push((double)number);
			median = (double)number;
		} else {
			double x = (double) number;
			if(maxH.size() > minH.size()) {
				if(x < median) {
					minH.push(maxH.top());
					maxH.pop();
					maxH.push(x);
				} else {
					minH.push(x);
				}
				median = (minH.top() + maxH.top())/2.0;
			} else if(minH.size() == maxH.size()) {
				if(x < median) {
					maxH.push(x);
					median = maxH.top();
				} else {
					minH.push(x);
					median = minH.top();
				}
			} else {
				if(x > median) {
					maxH.push(minH.top());
					minH.pop();
					minH.push(x);
				} else {
					maxH.push(x);
				}
				median = (minH.top() + maxH.top())/2.0;
			}
		}
  }

  double getMedian() { return median; }
};
