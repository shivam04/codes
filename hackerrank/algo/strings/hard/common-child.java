import java.io.*;
import java.util.*;

public class Solution {
    public int child(String str1, String str2){
        int L[][] = new int[str1.length()+1][str2.length()+1];
        for(int i=0;i<=str1.length();i++){
            for(int j=0;j<=str2.length();j++){
                if(i==0 || j==0)
                    L[i][j]=0;
                else if(str1.charAt(i-1)==str2.charAt(j-1)){
                    L[i][j] = L[i-1][j-1]+1;
                }
                else{
                    L[i][j] = Math.max(L[i-1][j],L[i][j-1]);
                }
            }
        }
        return L[str1.length()][str2.length()];
    }
    public static void main(String[] args){
        Solution ob = new Solution();
        Scanner sc = new Scanner(System.in);
        String str1 = sc.nextLine();
        String str2 = sc.nextLine();
        int ans = ob.child(str1,str2);
        System.out.println(ans);
       
    }
}