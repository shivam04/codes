int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.size();
    int element1=INT_MAX,element2=INT_MAX;
    int count1=0,count2=0,i;
    for(i=0;i<n;i++){
    	if(count1>0 && A[i]==element1){
    		count1+=1;
    	}else if(count2>0 && A[i]==element2){
    		count2+=1;
    	}else if(count1==0){
    		element1=A[i];
    		count1=1;
    	}else if(count2==0){
    		element2=A[i];
    		count2=1;
    	}else{
    		count1--;
    		count2--;
    	}
    }
   int check,freq=0;
    if(count1==0 && count2==0)
    	return -1;
    else check=element1;
	for(i=0;i<n;i++){
    	if(A[i]==check)
    		freq++;
    }
    if(freq>n/3)
    	return check;
    check=element2;
    freq=0;
    for(i=0;i<n;i++){
    	if(A[i]==check)
    		freq++;
    }
    if(freq>n/3)
    	return check;
    return -1;
}
