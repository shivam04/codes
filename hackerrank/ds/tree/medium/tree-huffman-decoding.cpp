/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/


void decode_huff(node * root,string s)
{
    //cout<<s<<"\n";
    node *temp = root;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0'){
            if(temp->left==NULL){
                i--;
                cout<<temp->data;
                temp=root;
            }else{
                temp = temp->left;
            }
        }else{
            if(temp->right==NULL){
                i--;
                cout<<temp->data;
                temp=root;
            }else{
                temp = temp->right;
            }
        }
    }
    cout<<temp->data;
}
