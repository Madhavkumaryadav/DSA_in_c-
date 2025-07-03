
#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int val){
        data=val;
        next=NULL;
    }
};
Node *createlinkedlist(int arr[],int index,int size){
    if (index==size){
        return NULL;
    }
    Node *temp=new Node(arr[index]);
    temp->next=createlinkedlist(arr,index+1,size);
    return temp;
}
Node  *delete_at_start(Node *head){
    if(head!=NULL){
        Node *temp=head;
        head=head->next;
        delete temp;
    }
    return head;
}

int main(){
    int arr[]={2,3,4,5,6,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    int index=0;
    Node *head=NULL;
    head=createlinkedlist(arr,index,size);

    Node*temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    head=delete_at_start(head);
    // if (head!=NULL){
    //     Node *temp=head;
    //     head=head->next;
    //     delete temp;
    // }
    

    Node*temp1=head;
    while(temp1){
        cout<<temp1->data<<" ";
        temp1=temp1->next;
    }
    // cout<<"Hello wlrld";
    return 0;
}