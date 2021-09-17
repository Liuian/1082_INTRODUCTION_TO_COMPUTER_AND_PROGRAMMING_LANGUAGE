//
//  main.cpp
//  HW5 Q1
//
//  Created by 劉翊安 on 2020/5/20.
//  Copyright © 2020 劉翊安. All rights reserved.
//
# include <iostream>
# include <cstdlib>
# include <math.h>
using namespace std;

double A[4][4]= {{0.1,0.2,0.4,0.3}, {0.5,0.2,0.1,0.2},{0.3,0.4,0.2,0.1},{0.15,0.25,0.2,0.4}};
double B[4][4]={{0.1,0.2,0.4,0.3}, {0.5,0.2,0.1,0.2},{0.3,0.4,0.2,0.1},{0.15,0.25,0.2,0.4}};
double C[4][4]={{}};

void matrixMul(){
    for(int j=0;j<4;j++){
        for(int i=0;i<4;i++){
            C[j][i]=0;
            for(int m=0;m<4;m++){
                C[j][i]+=A[j][m]*B[m][i];
            }
        }
    }
}

int main(){
    
    for(int m=0;m<14;m++){
        matrixMul();
            for(int j=0;j<4;j++){
                for(int i=0;i<4;i++){
                    B[i][j]=C[i][j];
                }
            }
    }
     
        
    for(int j=0;j<4;j++){
        for(int i=0;i<4;i++){
            cout <<C[j][i]<<" " ;
        }
        cout<<endl;
    }
}
