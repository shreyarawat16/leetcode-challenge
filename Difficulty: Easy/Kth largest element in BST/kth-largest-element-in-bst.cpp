/*The Node structure is defined as
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

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:
  void inorder(Node* root, int k, int& ans, int& cnt){
      if(root==NULL){
          return;
      }
      inorder(root->right, k, ans, cnt);
      cnt++;
      if(cnt==k){
          ans= root->data;
          return;
      }
      inorder(root->left, k, ans, cnt);
  }
    int kthLargest(Node *root, int k) {
        // Your code here
        int ans, cnt=0;
        inorder(root, k, ans, cnt);
        return ans;
    }
};