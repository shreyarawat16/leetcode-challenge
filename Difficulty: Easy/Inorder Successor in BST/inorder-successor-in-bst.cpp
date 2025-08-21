/*The structure of Node

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    int inOrderSuccessor(Node *root, Node *x) {
        // Your code here
        int ans=-1;
        if(root==NULL){
            return ans;
        }
       
        
        if(x->data < root->data){
           ans= root->data;
           int left= inOrderSuccessor(root->left, x);
           if(left!= -1) ans= left;
        }
        else if(x->data> root->data){
            return inOrderSuccessor(root->right,x);
        }
        else{
           if(root->right){
            Node* temp= root->right;
            while(temp->left){
              temp=temp->left;
            }
            ans= temp->data;
           }
        }
        return ans;
    }
};