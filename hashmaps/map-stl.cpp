#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    
    //creation
    unordered_map<string, int> m;

    //Insertion

    //1. 
    pair<string, int> pair1 = make_pair("Faiz", 1);
    m.insert(pair1);

    //2.
    pair<string, int> pair2("Humaira", 1);
    m.insert(pair2);

    //3.
    m["Nasar"] = 1;
    m["Nasar"] = 2; //Overwrites the value to 2

    //Search
    cout<<m["Faiz"]<<endl;
    cout<<m.at("Faiz")<<endl;

    cout<<m["Unknown"]<<endl; //Makes the Entry of "Unknown" with zero
    // cout<<m.at("Unknown2")<<endl; //Does'nt makes the entry of "Unknown2" with zero 

    //Size
    cout<<m.size()<<endl;

    //To check presence
    cout<<m.count("Iqbal")<<endl; // If key is absent it returns 0 or false
    cout<<m.count("Nasar")<<endl; //If key is present in any value it returns 1 or true

    //To erase key 
    m.erase("Unknown");
    cout<<m.size()<<endl;

    //Iteration
    //1.
    for(auto x: m){
        cout<<x.first<<", "<<x.second<<endl;
    }

    unordered_map<string, int> :: iterator it= m.begin();
    while(it != m.end()){
        cout<<it->first<<", "<<it->second<<endl;
        it++;
    }

    //Using unoredered map key value pairs are printed in random order
    //But using ordered map key value pairs are printed in the order in which they are inserted
    //All syntax of ordered and unordered map are same except name