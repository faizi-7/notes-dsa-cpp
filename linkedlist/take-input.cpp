#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node(int data){
        this->data= data;
        this->next= NULL;
    }
};

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head= head->next;
    }
    cout<<endl;
}

// time-complexity: O(N^2)
Node* takeInput1(){
    int data;
    cin>>data;
    Node* head= NULL;
    while(data!=-1){
        Node* newNode= new Node(data);
        if(head==NULL){
            head= newNode;
        }
        else {
            Node* temp= head;
            while (temp->next!=NULL)
            {
                temp= temp->next;
            }
            temp->next= newNode;
        }
        cin>>data;
    }
    return head;
}

// time-complexity: O(N)
Node* takeInput2(){
    int data;
    cin>>data;
    Node* head= NULL;
    Node* tail= NULL;
    while(data!=-1){
        Node* newNode= new Node(data);
        if(head==NULL){
            head= newNode;
            tail= newNode;
        }
        else {
            tail->next= newNode;
            tail= tail->next;
        }
        cin>>data;
    }
    return head;
}


