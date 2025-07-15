/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
  void addLeaf(Node* root, vector<int>& ans){
      if(root == NULL) return;
      // ✅ fix braces and return
      if(root->left == NULL && root->right == NULL){
          ans.push_back(root->data);
          return;
      }
      addLeaf(root->left, ans);
      addLeaf(root->right, ans);
  }
  
  vector<int> boundaryTraversal(Node *root) {
      vector<int> ans;
      if(root == NULL) return ans;
      
      // ✅ add root if it is not a leaf
      if(!(root->left == NULL && root->right == NULL)) {
          ans.push_back(root->data);
      }
      
      // ✅ add left boundary
      Node* curr = root->left;
      while(curr != NULL){
          if(!(curr->left == NULL && curr->right == NULL)) {
              ans.push_back(curr->data);
          }
          if(curr->left) curr = curr->left;
          else curr = curr->right;
      }
      
      // ✅ add leaves
      addLeaf(root, ans);
      
      // ✅ add right boundary
      curr = root->right;
      vector<int> temp;
      while(curr != NULL){
          if(!(curr->left == NULL && curr->right == NULL)) {
              temp.push_back(curr->data);
          }
          if(curr->right) curr = curr->right;
          else curr = curr->left;
      }
      for(int i = (int)temp.size() - 1; i >= 0; i--){
          ans.push_back(temp[i]);
      }
      
      return ans;
  }
};
