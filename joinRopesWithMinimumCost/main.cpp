/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 14, 2020, 2:25 PM
 */

#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

int getMinCostOfJoiningRopes(int arr[], int size){
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    int sum=0;
    for(int i=0;i<size;i++){
        minHeap.push(arr[i]);
    }
    
    while(minHeap.size()>=2){
        int r1 = minHeap.top();
        minHeap.pop();
        int r2 = minHeap.top();
        minHeap.pop();
        int temp = r1+ r2;
        sum+= temp;
        minHeap.push(temp);
        
    }
    return sum;
}
/*
 * 
 */
int main(int argc, char** argv) {
    int arr[]={1,2,5,8,10,15,3,4,12};
    int cost = getMinCostOfJoiningRopes(arr,9);
    cout <<"Cost :" <<cost;
    return 0;
}

