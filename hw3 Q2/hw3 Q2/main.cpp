//
//  main.cpp
//  hw3 Q2
//
//  Created by 劉翊安 on 2020/4/30.
//  Copyright © 2020 劉翊安. All rights reserved.
//
# include <iostream>
# include <math.h>
# define N 5
using namespace std;
int index_arr[N] = {0,1,2,3,4};
int value_arr[N] = {0,1,2,3,4};
int value_new[N] = {0,1,2,3,4};
int u[15] = {};

void initial(){
    for (int i=0; i<N; i++){
           value_arr[i] = value_new[i];
    }
}
//identify whether array u and array v are the same
int Identification(int u, int v){
    if(u==v){
        return 1;
    }
    else{
        return 0;
    }
}

void Rotation(){
        for(int i=0; i<4; i++){
           value_arr[i] = index_arr[i+1];//第零到三個位置轉一格會到他們家一的位置
        }
        if(int i=4){
           value_arr[i] = index_arr[0]; //第四格再轉一格會回到第零格
        }
       for (int i=0; i<N; i++){
           index_arr[i] = value_arr[i];//把轉一格的值放到index裡面，藉此做下一個旋轉
       }
}

void Reflection(int reflection_axis){
    int M;
    int H;
    for(int n=-2;n<=2;n++){
        //要鏡射的軸的前一格跟後一格會交換，前兩格跟後兩格會交換。所以利用一個加一個減的方式把前後對調。取得值要從負二到二才可以剛剛好做到這件事。
         M=reflection_axis+n;
         H=reflection_axis-n;
        //假設是第四格的後兩格要跟前兩格交換，4+2會變成六，但其實四的後兩格是1，所以要減五變回正常的值。依此類推。
        if(M<0){
            M=M+5;
        }
        if(M>4){
            M=M-5;
        }
        if(H<0){
            H=H+5;
        }
        if(H>4){
            H=H-5;
        }
        value_arr[M]=value_new[H];//鏡射。
    }
}
int main(){
    cout<<"belows are the reflection"<<endl;
    for (int axis = 0; axis<5; axis++){
        Reflection(axis);
        for(int i =0; i<5; i++){
            cout<<value_arr[i];
        }
        for(int q=0;q<5;q++){
            u[axis]+=value_arr[q]*pow(10,4-q);//把鏡射轉成五位數字存到u的一到五格
        }
        cout<<endl;
        initial();
    }
    cout<<"belows are the rotation"<<endl;
    for (int rotation = 0; rotation<5; rotation++){
        Rotation();
        for(int i =0; i<5; i++){
            cout<<value_arr[i];
        }
        for(int q=0;q<5;q++){
            u[rotation+5]+=value_arr[q]*pow(10,4-q);//把旋轉轉成五位數字存到u的六到十格
        }
        cout<<endl;
        initial();
    }
    cout<<"belows are the reflection with rotation"<<endl;
    
    for (int i = 0; i<5 ; i++){
        initial();
        Reflection(i);
        for (int i = 0; i<5 ; i++){
        index_arr[i] = value_arr[i];
        }
        for(int j=0;j<i+1;j++){
            Rotation();
        }
        for(int i =0; i<5; i++){
            cout<<value_arr[i];
        }
        for(int q=0;q<5;q++){
            u[i+10]+=value_arr[q]*pow(10,4-q);//把鏡射在旋轉轉成五位數字存到u的十一到十五格
        }
        cout<<endl;
        initial();
    }
    cout << "belows are the 不重複\n";
    // 把一樣的那個後面的數變成數值0
    for(int i = 0; i < 15; i++){
        for(int j = 14; j > i; j--){
            if(u[i]==u[j]){
                u[j] = 0;
            }
        }
    }
    //將沒有重複的輸出
    for(int i = 0; i < 15; i++){
        if (u[i]!=0) {
           if (u[i]<10000) cout << "0" << u[i] << endl;  //因為1234沒有0 所以在前面加個0
            else cout << u[i] << endl;
        }
    }
    return 0;
}
