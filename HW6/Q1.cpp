//
//  main.cpp
//  HW6_1
//
//  Created by 劉翊安 on 2020/5/28.
//  Copyright © 2020 劉翊安. All rights reserved.
//


#include <iostream>
using namespace std;

int f[9]={10,15,-2,0,-1,0,18,0,-1};
int g[9]={0,0,0,0,0,0,0,1,-7};
int Q[9]={0};//商
int R[9]={0};//餘

void valueFind(int a[9],int b[9]){
    if (b[7]==1){
        b[8]=-b[8];//把-7換成7，因為在做除法的時候減負七會變成加七
    }
    Q[0]=a[0];
    //在做第一次除法的時候因為除出來第一個係數是10，且後面會用到除出來的前一個數，所以先把傷的地一個數存成10。
    for(int i=0;i<8;i++){
        Q[i+1]=Q[i]*b[8]+a[i+1];
         //下一位數會根據上一位數倍乘了多少而變動，而因為除數x的係數剛好是一，所以成的數就是除的數的直
        R[8]=Q[8];//Q的最後一項是餘數
    }
 
}



int main() {
 valueFind(f,g);
 
 cout<<"f(x) = ";
 for(int i=0;i<8;i++){
  cout<<" "<<f[i]<<"x"<<"^"<<8-i<<" "<<" + ";
 }
 cout<<" "<<f[8]<<"x^0"<<" "<<endl;
 
 
 cout<<endl<<"g(x) = ";
 for(int i=0;i<8;i++){
  cout<<" "<<g[i]<<"x"<<"^"<<8-i<<" "<<" + ";
 }
 cout<<" "<<g[8]<<"x^0"<<" ";
 
  
 cout<<endl<<endl<<"Q(x) = ";
 for(int i=0;i<7;i++){
  cout<<" "<<Q[i]<<"x"<<"^"<<7-i<<" "<<" + ";
 }
 cout<<" "<<Q[7]<<"x^0"<<" ";
 
 cout<<endl<<endl<<"R(x) = "<<R[8]<<endl;
 return 0;
}
