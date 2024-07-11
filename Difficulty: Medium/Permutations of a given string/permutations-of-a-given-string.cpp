//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void solve(string input, int i, set<string>& st){
	    if(i== input.size()){
	        st.insert(input);
	        return;
	    }
	    for(int j=i; j< input.size(); j++){
	        
	           
	        swap(input[i], input[j]);
	        solve(input,  i+1, st);
	        swap(input[i], input[j]);
	    
	    }
	
}
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    set<string> st;
		    vector<string> ans;
		   
		    solve(S,  0, st);
		   for(auto it:st){
		       ans.push_back(it);
		   }
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends