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
    vector<int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        if(root==NULL) return ans;
        queue<pair<Node*, int>> q;
        map<int, int> mp;
        q.push({root, 0});
        while(!q.empty()){
            Node* node= q.front().first;
            int v= q.front().second;
            q.pop();
            mp[v]= node->data;
            if(node->left) q.push({node->left, v-1});
            if(node->right) q.push({node->right, v+1});
        }
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};