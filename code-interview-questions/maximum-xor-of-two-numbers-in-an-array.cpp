class Node {
    public:
        Node *left; 
        Node *right;
};

class Solution
{
    
    public:
    void insert(Node *head, int x) {
        Node* curr = head;
        for(int i=30;i>=0;i--) {
            int bit = (x>>i)&1;
            if(bit==0) {
                if(!curr->left) {
                    curr->left = new Node();
                }
                curr = curr->left;
            } else {
                if(!curr->right) {
                    curr->right = new Node();
                }
                curr = curr->right;
            }
        }
    }
    int max_xor(int arr[] , int n) {
        int ans = 0;
        Node* head = new Node();
        for(int i=0;i<n;i++) {
            insert(head, arr[i]);
        }
        int res = 0;
        for(int i=0;i<n;i++) {
            int x = arr[i];
            int ans = 0;
            Node* curr = head;
            for(int j=30;j>=0;j--) {
                int bit = (x>>j)&1;
                if(bit==0) {
                    if(curr->right) {
                        ans += (1<<j);
                        curr = curr->right;
                    } else {
                        curr = curr->left;
                    }
                } else {
                    if(curr->left) {
                        ans += (1<<j);
                        curr = curr->left;
                    } else {
                        curr = curr->right;
                    }
                }
            }
            res = max(res,ans);
        }
        
        return res;
    }
    
};