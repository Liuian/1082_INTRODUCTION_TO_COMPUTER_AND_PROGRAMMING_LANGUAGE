//
//  main.cpp
//  hw 1
//
//  Created by 劉翊安 on 2020/4/16.
//  Copyright © 2020 劉翊安. All rights reserved.
//
# include <iostream>
# include <cstdlib>
using namespace std;

int main()
{
        double a = 0.1;
        double b = 0.2;
        int c=10;
        if ((a*c+b*c)/c == 0.3){
                cout<<"TRUE"<<endl;
        }
        else{
                cout<<"FALSE"<<endl;
        }
        return 0;
}

