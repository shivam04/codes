class Solution:
    def maxDepthAfterSplit(self, seq):
        n = len(seq)
        res = [0] *n
        c1,c2= 0,0
        for i in range(n):
            if seq[i] == '(':
                if c1<c2:
                    c1+=1
                else:
                    c2+=1
                    res[i]=1
            else:
                if c1>c2:
                    c1-=1
                else:
                    c2-=1
                    res[i]=1
        return res
        