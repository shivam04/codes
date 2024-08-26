/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dimension = binaryMatrix.dimensions();
        int r = dimension[0];
        int c = dimension[1];
        vector<int> allRowWithLastColumnOne;
        for (int i=0;i<r;i++) {
            if (binaryMatrix.get(i, c-1) == 1) {
                allRowWithLastColumnOne.push_back(i);
            }
        }
        int miniIndex = c;
        if (allRowWithLastColumnOne.size() == 0) {
            return -1;
        }
        for(int row: allRowWithLastColumnOne) {
            int findIndex = lowerBound(binaryMatrix, row, c);
            miniIndex = min(miniIndex, findIndex);
        }
        return miniIndex;
    }

    int lowerBound(BinaryMatrix &binaryMatrix, int r, int c) {
        int mid;
        int low = 0;
        int high = c;
        int X = 1;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (X <= binaryMatrix.get(r, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        if(low < c && binaryMatrix.get(r,low) < X) {
            low++;
        }
        return low;
    }
};