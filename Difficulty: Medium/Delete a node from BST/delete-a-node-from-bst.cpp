/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    Node *deleteNode(Node *root, int x) {
        // code here
        if(root==NULL){
            return NULL;
        }
        if(x> root->data){
          root->right=  deleteNode(root->right, x);
        }
        else if(x< root->data){
            root->left= deleteNode(root->left, x);
            
        }
        else{
            //leaf node
            if(root->left==NULL && root->right==NULL){
               Node* temp= root;
               delete temp;
                return NULL;
            }
            //has 1 children
            if(root->left==NULL){
                Node* temp= root->right;
                delete root;
                return temp;
            }
            if(root->right==NULL){
                Node* temp= root->left;
                delete root;
                return temp;
            }
            //has 2 children
            if(root->left && root->right){
                Node* temp= root->left;
                while(temp->right){
                    temp= temp->right;
                }
                root->data= temp->data;
                root->left=deleteNode(root->left, temp->data);
            }
        }
        return root;
    }
};