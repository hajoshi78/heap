/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 12, 2020, 9:55 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> getSortedArray(int arr[], int size, int k){
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> sortedArray;
    
    for(int i=0; i<size;i++){
        minHeap.push(arr[i]);
        if ( minHeap.size()>k){
            sortedArray.push_back(minHeap.top());
            minHeap.pop();
        }
    }
    while(!minHeap.empty()){
        sortedArray.push_back(minHeap.top());
        minHeap.pop();
    }
    return sortedArray;
}
/*
 * 
 */
int main(int argc, char** argv) {
    int arr[]={6,5,3,2,8,10,13,12,18,15};
    vector<int> resultArr = getSortedArray(arr,10,3);
    vector<int> ::iterator it;
    for( it = resultArr.begin();it!= resultArr.end();it++){
        cout <<*it<<"\t";
    }
    return 0;
}

