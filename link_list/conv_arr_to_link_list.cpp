#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node (int value){
        data=value;
        next=NULL;
    }
};

int main(){
    int arr[]={1,2,3,4,5,6,7,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    Node *head;
    head=NULL;

    for (int i=0;i<size;i++){
        if (head ==NULL){
            head=new Node(arr[i]);
        }
        else{
            Node *temp;
            temp=new Node(arr[i]);
            temp->next=head;
            head=temp;
        }
    }
    Node *temp=head;

    while(temp!=NULL){
        cout<<temp->data <<" ";
        temp=temp->next;
    }
    cout<<endl;
    cout<<sizeof(head);
    // cout<<head->data<<endl;
    // cout<<head->next;
    return 0;
}