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


int main(){
    Node *head;
    head=new Node(23);
    cout<<head->data<<endl;
    cout<<head->next<<endl;
    return 0;
}