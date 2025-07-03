#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int val){
        data=val;
        next =NULL;
    }
};

Node *createlinkedlist(int arr[],int index,int size){
    if (index==size){
        return NULL;
    }else{
        Node *temp=new Node(arr[index]);
        temp->next=createlinkedlist(arr,index+1,size);
        return temp;
    }
}
Node *delete_at_start(Node *head){
    if (head!=NULL){
        Node *temp=head;
        head=head->next;
        delete temp;
        return head;
    }else{
        cout<<"Head is Null . Linked list is not exist...";
    }
    return head;
}

Node *delete_at_end(Node *head){
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
            return head;
        }

    }
    else{
        cout<<"Linked List is not Exist... ";
    }
    return head;

}

Node *delete_at_particular(Node *head,int position){
    if (head!=NULL){
        if(position==1){
            Node *temp=head;
            delete temp;
            head=NULL;
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
    else{
        cout<<"Linked List is Not exist ..."<<endl;
    }
    return head;
}

Node *print(Node *head){
    Node *temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return head;
}

void option(){
    cout<<"You want to select the 1-5 option . Option is given below..."<<endl;
    
    cout<<"1. view Linked list "<<endl;
    cout<<"2. Delete Node at start "<<endl;
    cout<<"3. Delete Node at end "<<endl;
    cout<<"4. Delete Node at a particulart position "<<endl;
    cout<<"5. Exit the program ..."<<endl;
}

int main(){
    while(true){
        option();
        int input;
        cout<<"Chooise the Option : ";
        cin>>input;
        
        cout<<"\n";
        Node *head=new Node(0);
        int arr[]={1,2,3,4,5,6,7,8,9,10};
        int size=sizeof(arr)/sizeof(arr[0]);
        int index=0;
        head=createlinkedlist(arr,index,size);

        if  (input==1){
            print(head);
        }
        else if(input==2){
            head=delete_at_start(head);
            print(head);
        }else if(input==3){
            head=delete_at_end(head);
            print(head);
        }else if(input==4){
            int position;
            cout<<"Enter The position you want to delete : ";
            cin>>position;

            head=delete_at_particular(head,position);
            print(head);

        }else if(input==5){
            cout<<"Thanks for Terminating the program .... "<<endl;
            break;
        }else{
            cout<<"Please Enter the valid input ??????  "<<endl;
        }
        cout<<"\n"<<endl;
    }
    return 0;
}