using namespace std;

// Feel free to add new properties and methods to the class.
class MinMaxStack {
public:
	vector<int> stack;
	vector<unordered_map<string,int>> minMaxStack;
  int peek() {
    return stack.back();
  }

  int pop() {
    minMaxStack.pop_back();
		int res = stack.back();
		stack.pop_back();
    return res;
  }

  void push(int number) {
    unordered_map<string,int> nmm = {{"min", number}, {"max", number}};
		if(minMaxStack.size() > 0) {
			unordered_map<string,int> lmm = minMaxStack.back();
			nmm["min"] = min(number, lmm["min"]);
			nmm["max"] = max(number, lmm["max"]);
		}
		minMaxStack.push_back(nmm);
		stack.push_back(number);
  }

  int getMin() {
    return minMaxStack.back()["min"];
  }

  int getMax() {
    return minMaxStack.back()["max"];
  }
};
