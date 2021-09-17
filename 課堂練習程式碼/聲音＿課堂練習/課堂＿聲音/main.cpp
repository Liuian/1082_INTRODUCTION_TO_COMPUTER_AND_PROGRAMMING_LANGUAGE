//
//  main.cpp
//  課堂＿聲音
//
//  Created by 劉翊安 on 2020/5/29.
//  Copyright © 2020 劉翊安. All rights reserved.
//

#include <iostream>
#include"wave_file_s.h"
#include<math.h>
#define pi 3.1415926
int main() {
    long length=44100;
    short s[44100];
    double fre0=200;
    double dt=1./44100,t;
    for(int i=0;i<length;i++){
        t=i*dt;
        s[i]=5000*(sin(2*pi*fre*t))+0.5*sin(2*pi*fre*t)
    }
    wave_file A((char*)"a.wav",s,length);
    return 0;
}
