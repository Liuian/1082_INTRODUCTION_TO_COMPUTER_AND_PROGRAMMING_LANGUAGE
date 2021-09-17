//
//  main.cpp
//  introduction to computers HW3 Q1
//
//  Created by 劉翊安 on 2020/4/30.
//  Copyright © 2020 劉翊安. All rights reserved.
//
# include <iostream>
# include <stdlib.h>
# include <math.h>
# define COL 3
# define ROW 10
//# define m 3
using namespace std;
double** A;
double* v;
double* u;
void Allocate_Memory(){
    // Allocate memory, if u are interested in it plz refer to malloc
    A = new double*[ROW];
    for (int i=0; i < ROW; i++){
        *(A+i) = new double[COL];
    }
    
    v = (double *)malloc(sizeof(double*) * COL);

    u = (double *)malloc(sizeof(double*) * ROW);
}
void Free_Memory(){
    for( int i=0; i<ROW; i++){
        free(A[i]);
    }
    free (A);
    free (v);
    free (u);
}


void init(double **ptr_A,double *ptr_v){
    //matrix A
    for( int i = 0; i < ROW; i++){
        for ( int j = 0; j < COL; j++){
            
            ptr_A[i][j] = i+j;
        }
    }
    for (int i =0; i<COL; i++){
        ptr_v[i] = 2*i;
    }
}


void Matrix_mul_vector(double **ptr_A, double *ptr_v, double *ptr_u){
    // Please compute A*v = u
    for(int i=0; i<ROW; i++){
        for(int m=0; m<3; m++){
            ptr_u[i]+= ptr_A[i][m]*ptr_v[m];//設一個m讓A的第m行跟向量的第m列相乘。
        }
    }
    
}

int main(){
    
    Allocate_Memory();
    init(A, v);
    Matrix_mul_vector(A, v, u);
    for (int i=0; i<ROW; i++){
        for (int j=0; j<COL; j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"++++++++"<<endl;
    for (int i=0; i<COL; i++){
        cout << v[i] <<" ";
    }
    cout<<endl;
    cout<<"++++++++"<<endl;
    for (int i=0; i<ROW; i++){
        cout << u[i] <<" ";
    }
    Free_Memory();
}
