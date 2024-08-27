/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool allSame(const vector<vector<int>>& grid, int r, int c, int w) {
        int k = grid[r][c];
        for (int i=r;i<r+w;i++) {
            for(int j=c;j<c+w;j++) {
                if (grid[i][j] != k) {
                    return false;
                }
            }
        }
        return true;
    }
    Node* helper(const vector<vector<int>> &grid, int i, int j, int w) {
        if (allSame(grid, i, j, w)) {
            return new Node(grid[i][j] == 1, true);
        }
        int half = w/2;
        return new Node(true, false, helper(grid, i, j, half), 
            helper(grid, i, j+half, half), helper(grid, i+half, j, half), 
            helper(grid, i+half, j+half, half));
    }
    Node* construct(vector<vector<int>>& grid) {
        return helper(grid, 0, 0, grid.size());
    }
};