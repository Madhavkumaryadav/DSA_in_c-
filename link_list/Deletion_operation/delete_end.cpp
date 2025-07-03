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

Node *createlinkedlist(int arr[],int index,int size){
    //base Case handle
    if (index==size)
    return NULL;

    Node *temp=new Node(arr[index]);
    temp->next=createlinkedlist(arr,index+1,size);
    return temp;
}

Node *delete_at_end(Node *head){
    
    
    // base case
    if (head!=NULL){
        if (head->next==NULL){
            Node *temp=head;
            delete temp;
            head=NULL;
        }else{
            Node *curr=head;
            Node *prev=NULL;
            
            while(curr->next!=NULL){
                prev=curr;
                curr=curr->next;

            }
            prev->next=curr->next;
            delete curr;
        }
    }
    return head;
}

int main(){
    int arr[]={2,4,5,9,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    int index=0;
    
    Node *head=NULL;
    head=createlinkedlist(arr,index,size);

    head=delete_at_end(head);

    //Delete Node at End 
    // if (head!=NULL){
    //     if (head->next==NULL){
    //         Node *temp=head;
    //         delete temp;
    //         head=NULL;
    //     }
    //     else{
    //         Node *curr=head;
    //         Node *prev=NULL;

    //         while(curr->next!=NULL){
    //             prev=curr;
    //             curr=curr->next;
    //         }
    //         prev->next=curr->next;
    //         delete curr;
    //     }
    // }


    Node *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}