/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        if(root==NULL) return ans;
       queue<pair<Node*, int>> q;
       q.push({root, 0});
       map<int, int> mp;  //vertical distance and node value
       while(!q.empty()){
           Node* node= q.front().first;
           int v= q.front().second;
           q.pop();
           if(mp.find(v)== mp.end()){
                mp[v]= node->data;
           }
          
           if(node->left) q.push({node->left, v-1});
           if(node->right) q.push({node->right, v+1});
       }
       for(auto it: mp){
           ans.push_back(it.second);
       }
       return ans;
    }
};