//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        unordered_set<string> s(wordList.begin(), wordList.end());
        s.erase(startWord);
        while(!q.empty()){
           string temp= q.front().first;
           int n= q.front().second;
           q.pop();
           if(temp== targetWord){
               return n;
           }
           for(int i=0; i< temp.size(); i++){
               char original= temp[i];
               for(char ch='a'; ch<= 'z'; ch++){
                   temp[i]= ch;
                   if( s.find(temp)!= s.end()){
                       q.push({temp, n+1});
                       s.erase(temp);
                   }
               }
               temp[i]= original;
           }
        }
        return 0;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends