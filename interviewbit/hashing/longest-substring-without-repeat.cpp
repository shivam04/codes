int Solution::lengthOfLongestSubstring(string a) {
        unordered_map<char,int> visit;
	    visit[a[0]] = 0;
	    int cur_len = 1,max_len=1,p_i=-1;
	    for(int i=1;i<a.size();i++){
	        if(visit.find(a[i])!=visit.end())
	        p_i = visit[a[i]];
	        else
	        p_i = -1;
	        if(p_i==-1 || i-cur_len>p_i){
	            cur_len++;
	        }else{
	            max_len = max(max_len,cur_len);
	            cur_len = i-p_i;
	        }
	        visit[a[i]] = i;
	    }
	    return max(cur_len,max_len);
}
