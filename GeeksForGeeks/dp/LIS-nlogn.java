/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	static int ceilIndex(int a[], int l, int r,int k){
		int m;
		while(r-l>1){
			m = l + (r-l)/2;
			if(a[m]>=k){
				r = m;
			}else{
				l = m;
			}
		}
		return r;
	}
	static int lis(int n, int a[]){
		int t[] = new int[n+1];
		t[0] = a[0];
		int i;
		int l = 1;
		for(i=1;i<n;i++){
			if(a[i]<t[0]){
				t[0] = a[i];
			}else if(a[i]>t[l-1]){
				t[l] = a[i];
				l+=1;
			}else{
				t[ceilIndex(a,-1,l-1,a[i])] = a[i];
			}
		}
		return l;
	}
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int n  = sc.nextInt();
		int a[] = new int[n+1];
		int i;
		for(i=0;i<n;i++){
			a[i] = sc.nextInt();
		}
		int ans = lis(n,a);
		System.out.println(ans);
	}
}