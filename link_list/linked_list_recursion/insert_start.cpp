#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node (int val){
        data=val;
        next=NULL;
    }
};

Node * create_linked_list(int arr[],int index,int size,Node *prev){
    //Base Case 
    if (index==size){
        return prev;
    }
    Node *temp;
    temp=new Node(arr[index]);
    temp->next=prev;

    return create_linked_list(arr,index+1,size,temp);
}



int main(){

    Node *head=NULL;
    int arr[]={1,4,6,7,9};
    int size=sizeof(arr)/sizeof(arr[0]);

    head=create_linked_list(arr,0,size,head);

    Node *temp;
    temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}