/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 13, 2020, 2:22 PM
 */

#include <cstdlib>

#include <iostream>
#include <unordered_map>
#include <queue>


using namespace std;

vector<pair<int,int>> getTopKFrequentElements(int arr[], int size, int k){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > minHeap;
    unordered_map<int,int> frequencyMap;
    vector<pair<int,int>> result;
    
    for(int i =0;i< size;i++){
        frequencyMap[arr[i]]++;
    }
    
    for(auto j: frequencyMap){
        minHeap.push(make_pair(j.second, j.first));
        if(minHeap.size()>k){
            minHeap.pop();
        }
    }
    while(!minHeap.empty()){
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    return result;
}
/*
 * 
 */
int main(int argc, char** argv) {
    int arr[]={1,1,1,2,2,2,2,3,3,3,3,3,4,4,4,4,4,4,9,9,10,10,10,10,10,8,8,8,8,8,8,8,8,8,8};
    vector<pair<int,int>> result;
    result = getTopKFrequentElements(arr,35,4);
    for( auto x: result){
        cout <<"[" << x.second<<","<<x.first<<"]"<<"\t";
    }
    return 0;
}

