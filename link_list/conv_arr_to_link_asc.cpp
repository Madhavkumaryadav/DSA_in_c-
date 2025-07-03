#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int val){
        data=val;
        next=NULL;
    }
};

int main(){
    Node *head,*tail;
    head=tail=NULL;

    int arr[]={1,4,6,8,6,4,2,46,7,87,8};
    int n=sizeof(arr)/sizeof(arr[0]);

    for (int i=0;i<n;i++){
        if(head==NULL){
            head=new Node(arr[i]);
            tail=head;
        }else{
            tail->next=new Node(arr[i]);
            tail=tail->next;
        }
    }
    Node *temp;
    temp=head;
    while(temp){
        cout<<temp->data<< " ";
        temp=temp->next;
    }

    
    // Node *head;
    // head=new Node(99);
    // cout<<head->data<<endl;
    // cout<<head->next;

    return 0;
}