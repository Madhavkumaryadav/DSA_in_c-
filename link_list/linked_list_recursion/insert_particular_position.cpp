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
    //base case 
    if (index==size){
        return NULL;
    }
    Node *temp=new Node(arr[index]);
    temp->next=createlinkedlist(arr,index+1,size);
    return temp;
}

int main(){
    int arr[]={4,6,7,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    int index=0;

    Node *head=NULL;
    head=createlinkedlist(arr,index,size);

    int position=2; //insert position 
    int value=11; // insert the value

    Node *temp1=head;

    position--;
    while(position--){
        temp1=temp1->next;
    }
    Node *temp2=new Node(value);

    temp2->next=temp1->next;
    temp1->next=temp2;



    Node *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        
        temp=temp->next;
    }
    return 0;
}


