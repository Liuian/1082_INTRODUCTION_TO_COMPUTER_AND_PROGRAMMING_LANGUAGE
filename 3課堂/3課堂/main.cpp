//
//  main.cpp
//  3課堂
//
//  Created by 劉翊安 on 2020/6/3.
//  Copyright © 2020 劉翊安. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
using namespace std;
int arr[13];

class dice{
public:
    int N;
    dice(){
        N=6;
    }
    dice(int n){
        N=n;
    }
    int cast(){
        
        return rand()%N+1;
    }
};

int main() {
    srand( time(NULL) );
    int K=0;
    dice D1,D2;
    for(int i=0;i<30;i++){
        K=D1.cast()+D2.cast();
        for(int j=2;j<13;j++){
            if(K==j){
                arr[j]++;
            }
        }
    }
    for(int i=2;i<13;i++){
        cout<<i<<"="<<arr[i]<<endl;
    }
    return 0;
}
