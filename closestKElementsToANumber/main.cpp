/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 13, 2020, 1:55 PM
 */

#include <cstdlib>
#include <queue>
#include <iostream>
#include <valarray>


using namespace std;

vector<pair<int,int>> getKClosestElementsToNumber(int arr[], int size, int k, int x){
    vector<pair<int,int>> result;
    priority_queue<pair<int,int>> maxHeap;
    
    //Create the Diff Array
    vector<int> diffArray;
    for( int i=0; i<size; i++){
        diffArray.push_back(abs(arr[i]-x));
    }
    
    //Create the Heap of diff elements
    for(int i=0; i< size;i++){
        maxHeap.push(make_pair(diffArray[i], i));
        if(maxHeap.size()>k){
            maxHeap.pop();
        }
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
    int arr[]={3,1,5,4,7,8,12,9,6};
    vector<pair<int,int>> result = getKClosestElementsToNumber(arr,9,4,10);
    cout <<"4 closest elements to 10 are "<<endl;
    vector<pair<int,int>>::iterator it;
    
    for( it= result.begin();it!= result.end();it++){
        pair<int,int> temp = *it;
        
        cout<< "["<< arr[temp.second]<<"," <<temp.second<<"]"<<"\t";
    }
    
    return 0;
}

