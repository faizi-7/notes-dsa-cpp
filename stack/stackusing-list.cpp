#include<iostream>
using namespace std;
template <typename T>

class Node{
    public:
    T data;
    Node<T> *next;
    Node(T data){
        this-> data= data;
        next= NULL;
    }
};

template <typename T>

class stackusinglist{
    Node<T> *head;
    int size;

    public: 

    stackusinglist(){
        head= NULL;
        size= 0;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    void push(T element){
        Node<T> *newNode= new Node<T>(element);
        newNode-> next= head;
        head= newNode;
        size++;
        return;
    }

    T pop(){
        if(isEmpty()){
            cout<<"Stack is Empty!!"<<endl;
            return 0;
        }
        T ans= head-> data;
        Node<T> *temp= head;
        head= head-> next;
        delete temp;
        size--;
        return ans;
    }

    T top(){
        if(isEmpty()){
            cout<<"Stack is Empty!!"<<endl;
            return 0;
        }
        return head-> data;
    }

};

int main(){
    stackusinglist<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    int top= s.top();
    cout<<"Top element is: "<<top<<endl;
    return 0;
}