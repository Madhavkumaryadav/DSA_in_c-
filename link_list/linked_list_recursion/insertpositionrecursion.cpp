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
    //base case handle
    if (index==size){
        return NULL;
    }
    Node *temp=new Node(arr[index]);
    temp->next=createlinkedlist(arr,index+1,size);
    return temp;

}

//Insert the value at a Particular Location 
Node *insertatposition(Node *head,int val,int position){
    if (position==0){
        Node *newnode=new Node(val);
        newnode->next=head;
        return newnode;
    }
    head->next=insertatposition(head->next,val,position-1);
    return head;
}

// Node *insertatstart(Node *head,int val){
//     if(head==NULL){
//         head->next=val;
//     }
//     Node *temp=new Node(val);
//     head=temp->next;
//     head=temp;
// }

void print(Node *head){
    Node *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void option(){
    cout<<"1. View the linked list"<<endl;
    cout<<"2. Create the linked list"<<endl;
    cout<<"3. insert the value in linked list "<<endl;
    cout<<"4. Exit the program "<<endl;
}

int main(){

    while(true){
        option();
        cout<<"Enter the Option : ";
        int n;
        cin>>n;
        Node *head,*temp=NULL;
        if (n==1){
            print(head);
        }else if(n==2){
            int m;
            cout<<"Enter the size of array : ";
            cin>>m;
            int arr[1000];
            int index=0;
            for (int i=0;i<m;i++){
                cin>>arr[i];
            }
            int size=sizeof(arr)/sizeof(arr[0]);
            temp=createlinkedlist(arr,index,size);
            head->next=temp;
        }else if(n==3){
            int value,position;
            cout<<"Enter the value you want to insert : ";
            cin>>value;
            cout<<"Enter the position you want to add : ";
            cin>>position;
            head=insertatposition(head,value,position);
        }
        else if(n==4){
            break;
        }
        else{
            cout<<"Invalid Option..."<<endl;
        }
    }
    
    // head=createlinkedlist(arr,index,size);
    // head=insertatposition(head,90,3);
   

    // print(head);
    return 0;
}