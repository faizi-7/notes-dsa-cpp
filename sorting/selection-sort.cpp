#include<iostream>
#include<vector>
using namespace std;
void selectionSort(vector<int> &arr, int n){
    for(int i=0; i<n; i++){
        int min= INT32_MAX;
        int k= 0;
        for(int j=i; j<n; j++){
            if(arr[j] < min){
                min= arr[j];
                k = j;
            }
        }
        int m= arr[i];
        arr[i] = arr[k];
        arr[k] = m;
    }
}
int main(){
    vector<int> arr= {5, 8, 1, 2, 0, 11};
    selectionSort(arr, 6);
    for(int x: arr){
        cout<<x<<", ";
    }
    cout<<endl;
    return 0;

}