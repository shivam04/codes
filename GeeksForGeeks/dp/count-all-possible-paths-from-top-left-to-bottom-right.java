import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    
	public static void main (String[] args) {
		int t;
		int mo = 1000000007;
		Scanner sc = new Scanner(System.in);
		t = sc.nextInt();
		while(t>0){
		    t-=1;
		    int m = sc.nextInt();
		    int n = sc.nextInt();
		    int dp[][] = new int[m+1][n+1];
		    int i,j;
		    for(i=1;i<=n;i++)
		    dp[1][i] = 1;
		    for(i=1;i<=m;i++)
		    dp[i][1] = 1;
		    for(i=2;i<=m;i++){
		        for(j=2;j<=n;j++){
		            dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mo;
		        }
		    }
		    System.out.println(dp[m][n]);
		}
	}
}