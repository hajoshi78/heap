/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 12, 2020, 3:14 PM
 */

#include <cstdlib>
#include <iostream>
#include <queue>
#include <stack>


using namespace std;


pair<int,int> getKthSmallestElementInArray(int arr[], int size, int k){
    priority_queue<pair<int,int>> maxHeap;
    pair<int,int> result;
    result = make_pair(-1,-1);
    for(int i=0;i<size;i++){
        maxHeap.push(make_pair(arr[i],i));
        if(maxHeap.size()>k){
            maxHeap.pop();
        }
    }
    if( !maxHeap.empty()){
        result= maxHeap.top();
    }
    return result;
}
/*
 * 
 */
int main(int argc, char** argv) {
    int arr[]={2,1,5,6,3,4,8,7,9,10,15,20,18};
    pair<int,int> elem;
    elem = getKthSmallestElementInArray(arr,13,1);
    cout <<endl<<"1st smallest element in the array is " << elem.first;
    elem = getKthSmallestElementInArray(arr,13,5);
    cout <<endl<<"5th  smallest element in the array is " << elem.first;
    
    elem = getKthSmallestElementInArray(arr,13,13);
    cout <<endl<<"13th  smallest element in the array is " << elem.first;
    
    elem = getKthSmallestElementInArray(arr,13,7);
    cout <<endl<<"7th smallest element in the array is " << elem.first;
    elem = getKthSmallestElementInArray(arr,13,0);
    cout <<endl<<"0th smallest element in the array is " << elem.first;
    
    return 0;
}

