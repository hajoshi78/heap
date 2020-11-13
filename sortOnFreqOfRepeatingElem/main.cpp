/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 13, 2020, 7:54 PM
 */

#include <cstdlib>
#include <queue>
#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

vector<pair<int,int>> sortOnFreqOfRptElem(int arr[], int size){
    unordered_map<int,int> freqMap;
    priority_queue<pair<int,int>> maxHeap;
    vector<pair<int,int>> result;
    
    for(int i=0; i< size;i++){
        freqMap[arr[i]]++;
    }
    
     for(auto x: freqMap){
        maxHeap.push(make_pair(x.second, x.first));
    }
    
    while(!maxHeap.empty()){
        result.push_back(maxHeap.top());
        maxHeap.pop();
    }
    return result;
}



/*
 * 
 */
int main(int argc, char** argv) {
    int arr[]={1,1,1,2,2,2,2,3,3,3,3,3,4,4,4,4,4,4,9,9,10,10,10,10,10,8,8,8,8,8,8,8,8,8,8};
    vector<pair<int,int>> result;
    result = sortOnFreqOfRptElem(arr,35);
    
    for( auto x: result){
        cout <<"[" << x.second<<","<<x.first<<"]"<<"\t";
    }
    for( auto x: result){
        //cout <<"[" << x.second<<","<<x.first<<"]"<<"\t";
        for(int i=0; i< x.first; i++){
            cout << x.second<<",";
        }
    }
    return 0;
}

