/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
int solve(Node* root, int& ans){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL){
            return root->data;
        }
        
        
        int left= solve(root->left, ans);
        int right= solve(root->right, ans);
        if(root->data != left + right){
            ans=0;
            
        }
        return root->data;
}
    int isSumProperty(Node *root) {
        // Add your code here
         if(root==NULL) return 0;
         int ans=1;
         solve(root, ans);
         return ans;
        
    }
};