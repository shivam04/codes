class Solution:
    def longestDecomposition(self, text: str) -> int:
        start = 0
        end = len(text)-1
        temp1 = ""
        temp2 = ""
        ans = 1 if len(text) & 1 else 0
        while start<end:
            temp1+=text[start]
            temp2 = text[end]+temp2
            if temp1 == temp2:
                temp1 = temp2 = ""
                ans+=2
            start+=1
            end-=1
        if len(text)%2 == 0 and (temp1 or temp2):
            ans += 1
        return ans