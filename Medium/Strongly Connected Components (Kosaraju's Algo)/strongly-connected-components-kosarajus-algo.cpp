//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void  dfs(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int> & st){
        vis[node]=1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,vis, adj, st);
            }
        }
        st.push(node);
    }
    void dfs1(int node, vector<vector<int>>& radj, vector<int>& vis, vector<int>& comp){
        vis[node]=1;
        comp.push_back(node);
        for(auto it: radj[node]){
            if(!vis[it]){
                dfs1(it, radj, vis, comp);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        
        vector<vector<int>> scss;
        vector<int> component;
        stack<int> st;
        vector<int> vis(V,0);
        for(int i=0; i<V;i++){
            if(!vis[i]){
                  dfs(i, vis, adj, st);
            }
        }
       
        vector<vector<int>> radj(V);
        for(int i=0;i<V;i++){
            vis[i]=0;
        for(auto it: adj[i]){
            radj[it].push_back(i);
        }
    }
        while(!st.empty()){
            int x= st.top();
            st.pop();
            component.clear();
            if(!vis[x]){
            dfs1(x, radj, vis, component);
            scss.push_back(component);
           }
        }
        int ans= scss.size();
        return ans;
    }
    
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends