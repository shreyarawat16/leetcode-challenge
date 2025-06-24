/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */
void sortedInsert(stack<int>& st, int val){
    
    if(st.empty() || val>st.top()){
        st.push(val);
        return;
    }
    
    int x= st.top();
    st.pop();
    sortedInsert(st, val);
    st.push(x);
    
}
void SortedStack ::sort() {
    // Your code here
    if(!s.empty()){
    int val= s.top();
    s.pop();
    sort();
    sortedInsert(s, val);
    }
    
}