//
//  main.cpp
//  HW5
//
//  Created by 劉翊安 on 2020/5/18.
//  Copyright © 2020 劉翊安. All rights reserved.
//

# include <iostream>
# include <cstdlib>
# include <math.h>
using namespace std;

int num_array[100];
int kick_array[99];

int main(){
    for(int i=0;i<100;i++){
        num_array[i]=i+1;
    }
    int i=0;
    
    
    for(int j=0;j<99;j++){
        if(j%2==0){
        i=i+2;
        if(i>99-j){
            while(i>99-j){
                i=i-(99-j);
            }
        }
        else{
            i=i+1;
        }
        i=i-1;
        kick_array[j]=num_array[i];
        for(int k=i;k<99;k++){
            num_array[k]=num_array[k+1];
        }
        num_array[99]=0;
        }
        
        if(j%2==1){
        i=i+4;
        if(i>99-j){
            while(i>99-j){
                i=i-(99-j);
            }
        }
        else{
            i=i+1;
        }
        i=i-1;
        kick_array[j]=num_array[i];
        for(int k=i;k<99;k++){
            num_array[k]=num_array[k+1];
        }
        num_array[99]=0;
        }
    }
    
    cout<<num_array[0]<<endl;
    cout<<"+++++++++++"<<endl;
    for(int i=0;i<99;i++){
        cout<<kick_array[i]<<endl;
    }
    return 0;
}
