//
//  main.cpp
//  HW7-2
//
//  Created by 劉翊安 on 2020/6/1.
//  Copyright © 2020 劉翊安. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <cstdlib>
# define N 8
using namespace std;

int A[N][N] = {};
double D[N][N] = {};
double U[N][N] = {};
double L[N][N] = {};
double LU[N][N] = {};
double x[N] = {1,1,1,1,1,1,1,1};
double x1[N] ={};
double xb[N] ={};
double Ax[N] = {};
double Axb[N] = {};
double b[N] = {5,10,12,16,20,24,28,31};


void initial(){
    for (int i=0; i<N; i++){
        A[i][i] = 3;
        if ((i+1) < N){
            A[i][i+1] = 1;
            A[i+1][i] = 1;
        }
    }
}

void newmatrix(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(i==j){
                D[i][j]=A[i][j];
            }
            if(i<j){
                U[i][j]=-A[i][j];
            }
            if(i>j){
                L[i][j]=-A[i][j];
            }
        }
    }
}

void matrixMulVector(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            LU[i][j]=L[i][j]+U[i][j];
        }
    }
    for (int i = 0; i < N; i++){
            x1[i]=0;
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            x1[i]+=LU[i][j]*x[j];
        }
    }
    for (int i = 0; i < N; i++){
        xb[i]=x1[i]+b[i];
    }
    for(int i=0;i<N;i++){
        x[i] = 0;
    }
    for (int i =0; i < N; i++){
        x[i]=0;
    }
    for (int i =0; i < N; i++){
        for (int j = 0; j < N; j++){
            x[i]+=D[i][j]*xb[j];
        }
    }
}

double computeNorm(){
    for(int i=0;i<N;i++){
        Ax[i]=0;
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            Ax[i]+=A[i][j]*x[j];
        }
    }
    for(int i=0;i<N;i++){
        Axb[i]=0;
    }
    for (int i = 0; i < N; i++){
        Axb[i]=Ax[i]-b[i];
    }
    double K=0;
    for(int i=0;i<8;i++){
        K+=pow(Axb[i],2);
    }
    K= pow(K,0.5);
    return K;
}

int main(){
    initial();
    newmatrix();
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if(i==j){
                D[i][j]=pow(D[i][j],-1);
            }
        }
    }
    int n=1;
    for(int i=0;i<n;i++){
        matrixMulVector();
        if(computeNorm()>0.00001){
            n++;
        }
    }
    cout<<endl;
    for(int i=0;i<8;i++){
        cout<<x[i]<<endl;
    }
    cout<<computeNorm();
}
