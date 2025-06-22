/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

//Function to push an element into the queue.
void MyQueue:: push(int x)
{
        // Your Code
        QueueNode* newnode= new QueueNode(x);
        if(front==NULL){
            front=rear=newnode;
        }
        else{
            rear->next= newnode;
            rear= newnode;
        }
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
        // Your Code  
        if(front==NULL){
            return -1;
        }
        int ans= front->data;
        front= front->next;
        return ans;
}
