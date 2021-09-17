//
//  main.cpp
//  HW8-2
//
//  Created by 劉翊安 on 2020/6/9.
//  Copyright © 2020 劉翊安. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

double i=0;

double f1(double x){
    double y=0;
    y=x-sin(x);
    return y;
}
double f2(double x){
    double y=0;
    y=sin(x)/x;
    return y;
}
double f3(double x){
    double y=0;
    y=exp(x)*sin(x);
    return y;
}


int main() {
    //cout<< integrate( 0.02, 0, 1,f1(i));
    double ans=0;
    for(i=0;i<1;i=i+0.02){
        ans+=0.02*f1(i);
    }
    cout<<"x-sin(x) = "<<ans<<endl;
    ans=0;
    for(i=0;i<1;i=i+0.02){
        ans+=0.02*f2(i+0.02); //計算上和避免第一個數分母是零
    }
    cout<<"sin(x)/x = "<<ans<<endl;
    ans=0;
    for(i=0;i<1;i=i+0.02){
        ans+=0.02*f3(i+0.02); //計算上和避免第一個數分母是零
    }
    cout<<"exp(x)*sin(x) = "<<ans<<endl;
}
