//
//  main.cpp
//  17
//
//  Created by 劉翊安 on 2020/4/17.
//  Copyright © 2020 劉翊安. All rights reserved.
//

# include <iostream>
# include <cstdlib>
# include <math.h>
# define N 6
# define window 3
using namespace std;
double A[N][N] = {{}};
double K[window][window] = {{}};
double C[4][4] = {{}};
double M[3][3][3]={{{}}};
void init(){
        for (int i = 0; i < N; i++){
                for (int j = 0; j < N; j++){
                        A[i][j] = i+2*j;
                }
        }
        for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++){
                        K[i][j] = (-1) * ((i+ j)%2 ==1) + 4*((i==j)&(i==1));
                }
        }
}
int  main(){
        init();
    
    for(int m=0; m<4; m++){//設定m跟n，Ａ要乘的列與行就是i+m,j+n，而且m,n會剛剛好等於我們要的答案的列跟行
        for(int n=0; n<4; n++){
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    M[m][n][i]+=A[i+m][j+n]*K[i][j];//把要相乘再相加的九個元素，其中三個加起來存成Ｍ
                }
            }
        }
    }
    
    for(int m=0; m<4; m++){
          for(int n=0; n<4; n++){
              for(int i=0; i<3; i++){
                  C[m][n]+=M[m][n][i];//再把三個相乘再相加的元素相加
               }
          }
    }
    
          for (int m = 0; m < 4; m++){
                      for (int n = 0; n < 4; n++){
                          cout << C[m][n] <<"\t";
                      }
              cout<<endl;
              }
    return 0;
}
