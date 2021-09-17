//
//  main.cpp
//  hw7-1
//
//  Created by 劉翊安 on 2020/6/1.
//  Copyright © 2020 劉翊安. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int k=0;
    for(int x=0;x<=1;x++){
        for(int y=0;y<=6;y++){
            for(int z=0;z<=13;z++){
                for(int i=0;i<=65;i++){
                    int sum=x*50+y*10+z*5+i*1;
                    if(sum==65){
                        k=k+1;
                    }
                }
            }
        }
    }
    cout<<k<<endl;
}
