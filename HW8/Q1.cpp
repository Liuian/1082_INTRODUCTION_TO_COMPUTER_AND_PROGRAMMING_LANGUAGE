//
//  main.cpp
//  HW8-1
//
//  Created by 劉翊安 on 2020/6/8.
//  Copyright © 2020 劉翊安. All rights reserved.
//
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
using namespace std;

int A[10000];
int go(){
    if(rand()%2==1){
        return 1;
    }
    else{
        return -1;
    }
}
int main() {
    srand( time(NULL) );
    for(int j=0;j<10000;j++){
        int N=0;
        for(int i=0;i<10000;i++){
            N=N+go();
        }
        A[j]=N;
    }
    for(int i=0;i<10000;i++){
        for(int j=0;j<10000-i-1;j++){
            if(A[j]>A[j+1])
            {
                int k=A[j];
                A[j]=A[j+1];
                A[j+1]=k;
            }
        }
    }
    /*
    for(int i=0;i<10000;i++){
        cout<<A[i]<<endl;
    }
    */
    int F=A[0];
    int L=A[9999];
    int I=0;
    I=(L-F)/5+1;
    int B[I];
    int max=0;
    int position = 0;
    for(int i=0;i<I;i++){
        B[i]=0;
    }
    int k=0;
    for(int i=A[0];i<A[9999];i=i+5){
        for(int j=0;j<10000;j++){
            if(A[j]>=i && A[j]<i+5){
                B[k]=B[k]+1;
            }
        }
        k=k+1;
    }
    for(int j=0;j<I;j++){
        if(max<B[j]){
            max=B[j];
            position=j;
        }
    }
    position=F+position*5;
    cout<<"["<<position-5<<","<<position<<")";
}
//次數最多的區間幾乎都在零附近，我看到的沒有在正負四十以外
