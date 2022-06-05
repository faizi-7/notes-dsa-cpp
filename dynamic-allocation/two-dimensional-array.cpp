#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter no. of rows: ";
    cin>>n;
    int m;
    cout<<"Enter no. of columns: ";
    cin>>m;

    int* *p1= new int*[n];
    for (int i = 0; i < n; i++)
    {
        *(p1+i)= new int[m];
        for(int j=0; j<m; j++){
            cout<< "Enter data of "<<i<<"th row and "<<j<<"th column :";
            cin>>*(*(p1+i)+j);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<p1[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
    
}