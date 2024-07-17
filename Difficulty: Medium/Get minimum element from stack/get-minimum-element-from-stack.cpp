//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> st;
    stack<int> mst;
    public:
    
       /*returns min element from stack*/
       int getMin(){
        if(!mst.empty()){
            return mst.top();
        }
          return -1;
       }
       
       /*returns poped element from stack*/
       int pop(){
           if(!st.empty()){
               int val= st.top();
               st.pop();
               if(val== mst.top()){
                   mst.pop();
               }
               return val;
           }
           else{
               return -1;
           }
           
          
           
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           //Write your code here
          st.push(x);
          if(mst.empty() || x <= mst.top()){
              mst.push(x);
          }
          
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends