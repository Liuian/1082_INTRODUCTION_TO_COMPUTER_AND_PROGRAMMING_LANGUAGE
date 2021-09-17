//
//  main.cpp
//  計概期中
//
//  Created by 劉翊安 on 2020/5/7.
//  Copyright © 2020 劉翊安. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <math.h>
int inc(int);
int inc2(int);
int Inc(int &);
using namespace std;
 int main()
{
int a=1;
int b,x;
int c[10] = { 0,1,2 };
b=3*a+2;
printf(" b=%d\n", b);//這裡會印出b=   (1) b=2*b+3*a++;
b=2*b+3*a++;
printf(" a=%d , b=%d\n",a, b);//這裡會印出a=   (2), b= (3)
printf("c[1]=%d, c[5]=%d\n",c[1],c[5]);
a=10;
b = inc(a);
printf(" a=%d , b=%d\n", a, b);//這裡會印出a=   (6), b= (7)
    for( int i=0;i<10;i++)

{
c[i]=i*i; }
    printf(" c[1]=%d , c[5]=%d \n",c[1],c[5]);
a=0;
b=1;
x=2;
int k;
if (a<b && a>x)
k=a;
else
k=b;
printf(" k=%d\n", k);//這裡會印出k=

k=1;
a = inc(k);
      printf("   k=%d\n", k);//
      printf("   a=%d\n", a);//
k=1;
a = Inc(k);
      printf("   k=%d\n", k);//
      printf("   a=%d\n", a);//
k=1;
a = inc2(k);
      printf("   k=%d\n", k);//
      printf("   a=%d\n", a);//
}

int inc(int n)
{
n++;
return n; }
int inc2(int n)
{
    n++;
    if(n<=5)
n = inc2(n);
    return n;
}
int Inc(int& n)
{
return n++; }


