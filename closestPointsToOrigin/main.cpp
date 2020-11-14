/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on November 14, 2020, 8:08 AM
 */

#include <cstdlib>
#include <vector>
#include <iostream>
#include <queue>
#include <valarray>
using namespace std;


vector<pair<int,int>> getKClosestPointsToOrigin(vector<pair<int,int>> cords, int k){
    vector<pair<int,int>> result;
    priority_queue<pair<int,pair<int,int>>> maxHeap;
    
    for( auto x: cords){
        maxHeap.push( make_pair(((x.first * x.first) + (x.second * x.second)),x));
        if( maxHeap.size()>k){
            maxHeap.pop();
        }
    }
    while( !maxHeap.empty()){
        result.push_back(maxHeap.top().second);
        maxHeap.pop();
    }
    return result;
}

/*
 * 
 */
int main(int argc, char** argv) {
    vector<pair<int,int>> cords;
    cords.push_back(make_pair(2,2));
    cords.push_back(make_pair(1,1));
    cords.push_back(make_pair(1,2));
    cords.push_back(make_pair(2,1));
    cords.push_back(make_pair(3,1));
    cords.push_back(make_pair(1,3));
    cords.push_back(make_pair(0,1));
    cords.push_back(make_pair(4,2));
    cords.push_back(make_pair(3,2));
    
    vector<pair<int,int>> result = getKClosestPointsToOrigin(cords,3);
    cout <<"Nearest 3 points to the origin are : "<<endl;
    for( auto x: result)
        cout <<"["<<x.first<<","<<x.second <<"]"<<"\t";
    return 0;
}

