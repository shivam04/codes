class Solution {
public:
    bool binarySearch(vector<vector<int>>& matrix, int r, int jl, int jh, int target) {
        while(jl<=jh) {
            int mid = (jl+jh)/2;
            if(matrix[r][mid] == target)
                return true;
            if(matrix[r][mid] > target) {
                jh = mid-1;
            } else {
                jl = mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n==0)
            return false;
        int m = matrix[0].size();
        if(m==0)
            return false;
        if(n==1)
            return binarySearch(matrix, 0, 0, m-1, target);
        int il = 0;
        int ih = n-1;
        int jmid = m/2;
        while(il<=ih) {
            int imid = (il + ih) / 2;
            if(matrix[imid][jmid] == target) {
                return true;
            }
            else if(matrix[imid][jmid] > target) {
                ih = imid-1;
            } else {
                il = imid +1;
            }
        }
                cout<<il<<" "<<ih<<" "<<jmid<<"\n";
        if(matrix[il][jmid]==target) {
            return true;
        }
        else if(il+1< n and matrix[il+1][jmid]==target) {
            return true;
        }
        else if(jmid > 0 and target<=matrix[il][jmid-1]) {
            return binarySearch(matrix, il, 0, jmid-1, target); 
        } else if(jmid+1 < m and target>=matrix[il][jmid+1] and target<=matrix[il][m-1]) {
            return binarySearch(matrix, il, jmid+1, m-1, target); 
        } else if(jmid > 0 and il+1<n and target<=matrix[il+1][jmid-1]) {
            return binarySearch(matrix, il+1, 0, jmid-1, target); 
        } else if(jmid+1<m and il+1 < n){
            return binarySearch(matrix, il+1, jmid+1, m-1, target); 
        }
        return false;
    }
};