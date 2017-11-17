int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string ans="";
	    while(n>0){
	        int k = n%26;
            if (k==0)
            {
                ans = "Z"+ans;
                n = (n/26)-1;
            }
            else
            {
                ans = (char)(64+k) + ans;
                n = n/26;
            }
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}