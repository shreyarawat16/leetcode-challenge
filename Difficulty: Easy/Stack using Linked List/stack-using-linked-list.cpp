class MyStack {
  private:
    StackNode *top;
   
  public:
    void push(int x) {
        // code here
        
        StackNode* newnode= new StackNode(x);
        newnode->next= top;
        top= newnode;
    }

    int pop() {
        
        // code here
       if(top == NULL){
           return -1;
       }
       int ans = top->data;
       top=top->next;
       return ans;
    }

    MyStack() { 
        top = NULL; 
        
    }
};