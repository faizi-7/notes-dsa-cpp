#include<iostream>
using namespace std;
template <typename T>

class stackusingarray{
    T *data;
    int nextIndex;
    int capacity;
    public:
    stackusingarray(){
        data= new T[4];
        nextIndex= 0;
        capacity= 4;
    }
    int size(){
        return nextIndex;
    }
    bool isEmpty(){
        return nextIndex == 0;
    }
    void push(T element){
        if(nextIndex == capacity){
            T *newData= new T[2*capacity];
            for(int i=0; i<nextIndex; i++){
                newData[i]= data[i];
            }
            capacity*= 2;
            delete []data;
            newData= data;
        }
        data[nextIndex]= element;
        nextIndex++;
    }
    T pop(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }
    T top(){
        if(isEmpty()){
            cout<<"Stack is Empty "<<endl;
            return INT16_MIN;
        }
        return data[nextIndex-1];
    }
};
int main(){
    stackusingarray<int> s;
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
