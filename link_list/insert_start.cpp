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

    int arr[]={1,4,6,7};
    int size=sizeof(arr)/sizeof(arr[0]);

    for (int i=0;i<size;i++){
        if (head==NULL){
            head=new Node(arr[i]);
            tail=head;
        }else{
            tail->next=new Node(arr[i]);
            tail=tail->next;
        }
    }
    Node *temp;
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}