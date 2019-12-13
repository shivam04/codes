#include <bits/stdc++.h>

using namespace std;

int block = 0;

struct Query { 
    int L, R, index, result; 
};

bool compare(Query x, Query y) 
{ 
    if (x.L / block != y.L / block) 
        return x.L / block < y.L / block; 
    return x.R < y.R; 
} 

bool compare1(Query x, Query y) 
{ 
    return x.index < y.index; 
} 
 

void queryResults(int a[], int n, Query q[], int m) {
    block = (int)sqrt(n);
    
    sort(q, q + m, compare); 
    
    int currL = 0, currR = 0;
    int curr_Diff_elements = 0; 
    map<int,int> freq;
    for (int i = 0; i < m; i++) { 
        int L = q[i].L, R = q[i].R; 
        while (currL < L) { 
            freq[a[currL]]--; 
            if (freq[a[currL]] == 0)  
                curr_Diff_elements--; 
              
            currL++; 
        }
        
        while (currL > L) { 
            freq[a[currL - 1]]++; 
            if (freq[a[currL - 1]] == 1)  
                curr_Diff_elements++; 
              
            currL--; 
        }
        while (currR <= R) { 
            freq[a[currR]]++; 
            if (freq[a[currR]] == 1)  
                curr_Diff_elements++; 
              
            currR++; 
        } 
        
        while (currR > R + 1) { 
            freq[a[currR - 1]]--; 
            if (freq[a[currR - 1]] == 0)  
                curr_Diff_elements--; 
              
            currR--; 
        }
        q[i].result = curr_Diff_elements;
    }
}

int main() {
	int n, m;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) {
	    cin>>arr[i];
	}
	int l,r;
	cin>>m;
	Query q[m+1];
	for(int i=0;i<m;i++) {
	    cin>>l>>r;
	    l--;
	    r--;
	    q[i] = {l,r,i,0};
	}
	queryResults(arr,n,q,m);
	sort(q, q + m, compare1); 
	for(int i=0;i<m;i++) {
	    cout<<q[i].result<<"\n";
	}
}
