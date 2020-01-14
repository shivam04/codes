#include<bits/stdc++.h>
using namespace std;
#define CToI(x) (x - '0') 
#define IToC(x) (x + '0') 
bool isPalindrome(string n) { 
    for (int i = 0; i < n.size() / 2; i++) 
        if (n[i] != n[n.size() - 1 - i]) 
            return false; 
    return true; 
} 
  
bool checkAll9(string n) {
    for(int i=0;i<n.length();i++) {
        if(n[i]!='9')
            return false;
    }
    return true;
}
string carryOperaion(string num, int carry, int size) { 
    if (carry == -1) { 
        int i = size - 1; 
        while (i >= 0 && num[i] == '0') 
            num[i--] = '9'; 
        if (i >= 0) 
            num[i] = IToC(CToI(num[i]) - 1); 
    } 
    else{ 
        for (int i = size - 1; i >= 0; i--) { 
            int digit = CToI(num[i]); 
            num[i] = IToC((digit + carry) % 10); 
            carry = (digit + carry) / 10; 
        }
        if(carry==1)
            num = "1" + num;
    } 
    return num; 
} 
bool powerOf10(long long n) {
    double p = log10(n);
    return (p == floor(p));
}
string MIN(long long int num, long long int num1, long long int num2, long long int num3) { 
  
    long long int Diff1 = abs(num - num1); 
    long long int Diff2 = abs(num - num2); 
    long long int Diff3 = abs(num3 - num); 
  
    if(Diff1<=Diff2 and Diff1<=Diff3) {
        return to_string(num1);
    }
    if(Diff2<=Diff1 and Diff2<=Diff3) {
        return to_string(num2);
    }
    if(Diff3<=Diff2 and Diff3<=Diff1) {
        return to_string(num3);
    }
    
} 
int main() {
    int t;
    cin>>t;
    while(t--) {
        string n;
        cin>>n;
        if(isPalindrome(n)) {
            cout<<n<<"\n";
        } else {
            int size = n.length();
            string FH = n.substr(0, size / 2); 
            string odd;
            if (size%2) 
                odd = n[size/2];
            string SH = FH; 
            reverse(SH.begin(), SH.end());
            string RPNUM = "", EPNUM = "", LPNUM = ""; 
            string tempFH = ""; 
            string tempSH = ""; 
            if(size%2) {
                EPNUM = FH + odd + SH;
                if (odd == "0") { 
                    tempFH = carryOperaion(FH, -1, FH.size()); 
                    tempSH = tempFH; 
                    reverse(tempSH.begin(), tempSH.end()); 
                    RPNUM = tempFH + "9" + tempSH; 
                } else {
                    RPNUM = FH + to_string(stoi(odd) - 1) + SH;
                }
                
                if(odd == "9") {
                    tempFH = carryOperaion(FH, 1, FH.size());
                    tempSH = tempFH; 
                    reverse(tempSH.begin(), tempSH.end());
                    LPNUM = tempFH + "0" + tempSH; 
                } else {
                    LPNUM = FH + to_string(stoi(odd) + 1) + SH;
                }
                
            } else {
                int n = FH.size(); 
                tempFH = FH; 
                EPNUM = FH + SH;
                if(FH[n-1]=='0') {
                    tempFH = carryOperaion(FH, -1, n);
                } else {
                    tempFH[n-1] = IToC(CToI(FH[n - 1]) - 1);
                }
                tempSH = tempFH; 
                reverse(tempSH.begin(), tempSH.end()); 
                RPNUM = tempFH + tempSH;
                tempFH = FH; 
                if(FH[n-1]=='9') {
                    tempFH = carryOperaion(FH, 1, n);
                } else {
                    tempFH[n-1] = IToC(CToI(FH[n - 1]) + 1);
                }
                tempSH = tempFH; 
                reverse(tempSH.begin(), tempSH.end()); 
                LPNUM = tempFH + tempSH;
            }
            long long int nums[3];
            nums[0] = stoll(EPNUM);
            nums[1] = stoll(RPNUM);
            nums[2] = stoll(LPNUM);
            sort(nums, nums+3);
            cout<<MIN(stoll(n), nums[0], nums[1], nums[2])<<"\n";
        }
        
    }
    return 0;
}