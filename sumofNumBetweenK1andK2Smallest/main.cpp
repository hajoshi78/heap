/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 14, 2020, 8:43 AM
 */

#include <cstdlib>
#include <queue>
#include <iostream>

using namespace std;

int getKthSmallestNumber(int arr[], int size, int k){
    priority_queue<int> maxHeap;
    
    for (int i=0;i<size;i++){
        maxHeap.push(arr[i]);
        if(maxHeap.size()>k){
            maxHeap.pop();
        }
    }
    return maxHeap.top();
    
}
int getSumBetweenK1andK2SmallestNumbers(int arr[],int size , int k1, int k2){
    int k1thSmallestElem = getKthSmallestNumber(arr,size,k1);
    int k2thSmallestElem = getKthSmallestNumber(arr,size,k2);
    
    int start=0;
    int end =0;
    int sum =0;
    if( k1>k2){
        end = k1thSmallestElem;
        start = k2thSmallestElem;
    }
    else{
        end = k2thSmallestElem;
        start = k1thSmallestElem;
    }
    for( int i=0;i<size;i++){
        if( arr[i]>start && arr[i]< end){
            sum+= arr[i];
        }
    }
    return sum;
}

/*
 * 
 */
int main(int argc, char** argv) {
    int arr[]={2,5,7,1,67,23,45,12,34,28,56,100,78,83,43};
    cout <<"sum of elements between 3rd and 9th smallest elements is " << getSumBetweenK1andK2SmallestNumbers(arr,15,3,9);
    return 0;
}

