/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/
/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
    stack<int> ts;
   while(!s.empty()){
       int x = s.top();
       s.pop();
       while(!ts.empty() and ts.top()>x){
           s.push(ts.top());
           ts.pop();
       }
       ts.push(x);
   }
   s = ts;
}