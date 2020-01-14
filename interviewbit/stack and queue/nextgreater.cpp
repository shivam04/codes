vector<int> Solution::nextGreater(vector<int> &a) {
    stack<int> s;
	    s.push(0);
	    int i;
	    
	    int n = a.size();
	    vector<int> ans(n);
	    for(i=1;i<n;i++){
	        int x = a[i];
	        if(s.empty()==false){
	            int e = s.top();
	            s.pop();
	            while(a[e]<x){
	                //cout<<e<<"\n";
	                ans[e] = x;
	                if(s.empty()==true)
	                break;
	                e = s.top();
	                s.pop();
	            }
	            if(a[e]>=x)
	            s.push(e);
	        }
	        s.push(i);
	    }
	    while (s.empty() == false)
        {
          //  cout<<"p "<<s.top()<<"\n";
            ans[s.top()] = -1;
            s.pop();
        }
        return ans;
}
