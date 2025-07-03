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
    //base case handling 
    if (index==size){
        return NULL;
    }
    Node *temp=new Node(arr[index]);
    temp->next=createlinkedlist(arr,index+1,size);
    return temp;
}
Node *delete_at_position(Node *head,int position){
    if (head!=NULL){
        if(head->next==NULL){
            Node *temp=head;
            head=head->next;
            delete temp;
            return head;
        }else{
            Node *curr=head;
            Node *prev=NULL;

            position--;
            while(position--){
                prev=curr;
                curr=curr->next;
            }
            prev->next=curr->next;
            delete curr;
            return head;
        }
    }
    return head;
}

int main(){
    int arr[]={3,4,5,6,7,8,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    int index=0;

    Node *head=NULL;
    head=createlinkedlist(arr,index,size);

    int position=3;
    head=delete_at_position(head,position);
    // if (head!=NULL){
    //     if(head->next==NULL){
    //         Node *temp=head;
    //         head=head->next;
    //         delete temp;

    //     }else{
    //         Node *curr=head;
    //         Node *prev=NULL;
    //         position--;
    //         while(position--){
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