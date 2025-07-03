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

Node* createlinked_list(int arr[],int index,int size){
    //Base case 
    if (index==size)
    return NULL;

    Node *temp;
    temp=new Node(arr[index]);
    temp->next=createlinked_list(arr,index+1,size);

    return temp;
}


int main(){
    Node *head;
    head=NULL;
    int arr[]={4,5,6,7,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    head=createlinked_list(arr,0,size);


    Node *temp;
    temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    return 0;
}