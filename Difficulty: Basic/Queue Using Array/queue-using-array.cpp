/*

The structure of the class is
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};
 */

// Function to push an element x in a queue.
void MyQueue ::push(int x) {
    // Your Code
    if(rear== 100005 ){ //queue is full
        return;
    }
    else if(front== 0){
        arr[rear]= x;
        rear++;
    }
    else{
        arr[rear]= x;
        rear++;
    }
}

// Function to pop an element from queue and return that element.
int MyQueue ::pop() {
    // Your Code
    if(front== rear){
        return -1;
    }
   else{
    int ans=arr[front];
    //if single element is present in the queue
    if(front== rear){
        front=rear=0;
    }
    else{
    front++;
    }
    return ans;
   }
}
