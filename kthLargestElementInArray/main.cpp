/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 12, 2020, 3:51 PM
 */

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


using namespace std;


pair<int,int> getKthLargestElementInArray(int arr[], int size, int k){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
    pair<int,int> result;
    result = make_pair(-1,-1);
    for(int i=0;i<size;i++){
        minHeap.push(make_pair(arr[i],i));
        if(minHeap.size()>k){
            minHeap.pop();
        }
    }
    if( !minHeap.empty()){
        result= minHeap.top();
    }
    return result;
}


vector<pair<int,int>> getKLargestElementInArray(int arr[], int size, int k){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
    vector<pair<int,int>>  result;
    
    for(int i=0;i<size;i++){
        minHeap.push(make_pair(arr[i],i));
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
    int arr[]={2,1,5,6,3,4,8,7,9,10,15,20,18};
    pair<int,int> elem;
    elem = getKthLargestElementInArray(arr,13,1);
    cout <<endl<<"1st Largest element in the array is " << elem.first;
    elem = getKthLargestElementInArray(arr,13,5);
    cout <<endl<<"5th  Largest element in the array is " << elem.first;
    
    elem = getKthLargestElementInArray(arr,13,13);
    cout <<endl<<"13th  Largest element in the array is " << elem.first;
    
    elem = getKthLargestElementInArray(arr,13,7);
    cout <<endl<<"7th Largest element in the array is " << elem.first;
    elem = getKthLargestElementInArray(arr,13,0);
    cout <<endl<<"0th Largest element in the array is " << elem.first;
    
    vector<pair<int,int>> kLargestElements = getKLargestElementInArray(arr,13,6);
    vector<pair<int,int>>::iterator it;
    
    cout<<endl<<"6 largest elements in the array is ";
    for( it = kLargestElements.begin();it!= kLargestElements.end();it++){
        pair<int,int> data = *it;
        cout << data.first <<"\t";
    }
    
    
    return 0;
}

