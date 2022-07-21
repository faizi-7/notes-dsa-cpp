
#include<bits/stdc++.h>
using namespace std;
//We need to create hashmap such that Insertion, Deletion and Searching takes O(1) time
//Linked list cant be used beacause it takes O(N) time
//map is implemented using BST & unordered_map is implemented using Hashtable
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<unordered_map<char,int>, vector<string>> map;
        vector<vector<string>> ans;
        
        for(string str: strs){
            
            unordered_map<char,int> fmap;
            for(int i = 0; i < str.length(); i++){
                char ch = str[i];
                if(fmap.find(ch) != fmap.end()){
                    int fre = fmap[ch];
                    fmap[ch] = fre + 1;
                }
                else{
                    fmap[ch] = 1;
                }
                
            }
            
            if(map.find(fmap) != map.end()){
                
                vector<string> lst = map[fmap];
                lst.push_back(str);
                
            }
            else{
                
                vector<string> lst;
                lst.push_back(str);
                map[fmap] = lst;
                
            }
            
            
        }
        for(auto x: map){
            ans.push_back(x.second);
        }
        return ans;
        
    }