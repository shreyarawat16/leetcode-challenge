//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->bottom;
    }
    printf("\n");
}

Node* createLinkedList(vector<Node*>& v) {
    Node* head = new Node(0);
    Node* temp = head;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        temp->next = v[i];
        temp = temp->next;
    }
    return head->next;
}


// } Driver Code Ends

/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
  Node* merge(Node* l1, Node* l2){
      if(l1==NULL && l2==NULL){
          return NULL;
      }
      if(l1==NULL){
          return l2;
      }
      if(l2==NULL){
          return l1;
      }
      Node* head=NULL, *tail=NULL;
      while(l1!=NULL && l2!=NULL){
          if(l1->data < l2->data){
              if(head==NULL){
                  head=tail=l1;
                  l1=l1->bottom;
              }
              else{
                  tail->bottom=l1;
                  l1=l1->bottom;
                  tail=tail->bottom;
              }
          }
          else{
               if(head==NULL){
                  head=tail=l2;
                  l2=l2->bottom;
              }
              else{
                  tail->bottom=l2;
                  l2=l2->bottom;
                  tail=tail->bottom;
              }
          }
      }
      while(l1!=NULL){
          tail->bottom= l1;
          l1=l1->bottom;
          tail= tail->bottom;
      }
      while(l2!=NULL){
          tail->bottom=l2;
          l2=l2->bottom;
          tail= tail->bottom;
      }
      return head;
  }
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        if(root==NULL || root->next==NULL){
            return root;
        }
        Node* down= root;
        Node* right= flatten(root->next);
        down->next=NULL;
        Node* ans= merge(down, right);
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->bottom = newNode;
                temp = temp->bottom;
            }
            v[i] = head->bottom;
        }

        Solution ob;
        Node* list = createLinkedList(v);
        Node* head = ob.flatten(list);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends