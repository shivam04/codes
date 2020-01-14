string Solution::minWindow(string a, string b) {
    unordered_map<int,int> mpa,mpb;
	    int i;
	    for(i=0;i<b.length();i++){
	        mpb[b[i]]++;
	    }
	    int cnt = 0;
	    int start =0,sidx=-1,mini=INT_MAX;
	    for(i=0;i<a.length();i++){
	        mpa[a[i]]++;
	        if(mpb[a[i]]!=0 and mpa[a[i]]<=mpb[a[i]])
	        cnt++;
	        if(cnt==b.length()){
	            while(mpa[a[start]]>mpb[a[start]] || mpb[a[start]]==0){
	                if(mpa[a[start]]>mpb[a[start]])
	                mpa[a[start]]--;
	                start++;
	            }
	            int win_len = i-start+1;
	            if(win_len < mini){
	                mini = win_len;
	                sidx = start;
	            }
	        }
	    }
	    if(sidx==-1)
	    return "";
	    else{
	        return a.substr(sidx,mini);
	    }
}
