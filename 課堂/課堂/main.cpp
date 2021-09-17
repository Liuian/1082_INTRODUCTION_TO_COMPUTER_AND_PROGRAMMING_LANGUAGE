//
//  main.cpp
//  課堂
//
//  Created by 劉翊安 on 2020/5/22.
//  Copyright © 2020 劉翊安. All rights reserved.
//

#include <iostream>


class simple{
public:
    simple(char *n){
        name=n;
    }
    simple(char*n,int k){
        name=n;
        birthyear=k;
    }
char* name;
int birthyear;
int age(){
    return 2020-birthyear;
}
};

int main(){
    simple fst((char*)"first");
    std::cout<<fst.name;
}
