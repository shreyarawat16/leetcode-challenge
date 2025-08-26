/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
struct BSTPair{
      int size;
      int largest;
      int smallest;
 
  BSTPair(int s=0, int l=INT_MIN, int sm= INT_MAX){
      this->size= s;
      this->largest= l;
      this->smallest=sm;
  }
};
BSTPair solve(Node* root){
    if(root==NULL){
        return BSTPair(0, INT_MIN, INT_MAX);
    }
    BSTPair l= solve(root->left);
    BSTPair r= solve(root->right);
    BSTPair curr;
    if(root->data > l.largest && root->data < r.smallest){
        curr.size= l.size + r.size +1;
        curr.largest= max(root->data, r.largest);
        curr.smallest= min(root->data, l.smallest);
    }
    else{
        curr.size= max(l.size, r.size);
        curr.largest= INT_MAX;
        curr.smallest= INT_MIN;
    }
    return curr;
}
    int largestBst(Node *root) {
      BSTPair ans= solve(root);
      return ans.size;
        
    }
};