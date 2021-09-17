//
//  main.cpp
//  HW4＿計概
//
//  Created by 劉翊安 on 2020/5/9.
//  Copyright © 2020 劉翊安. All rights reserved.
//
# include <iostream>
# include <cstdlib>
# include <math.h>
using namespace std;

double **triangle_v;
double **triangle_w;

double *v_1, *v_2, *v_3, *w_1, *w_2, *w_3;
double findLength(double  *vector){
    int u=0;
    for(int i=0;i<2;i++){
        u +=vector[i]*vector[i];
    }
    return sqrt(u);;
}
double findAngle(double *vector_1, double *vector_2){
    double theta;
    int u=0;
    int v=0;
    for(int i=0;i<2;i++){
        u +=vector_1[i]*vector_2[i];
        v +=vector_1[i]*vector_1[i]+vector_2[i]*vector_2[i];
    }
    theta=u/sqrt(v);
    return theta;
        //cos(theta) = a。b/|a||b|
}
double findSlideRatio(double *slide_1, double *slide_2){
    double lambda;
    lambda= findLength (slide_1)/findLength (slide_2);
    return lambda;
    /*
    int u=0;
    int v=0;
    for(int i=0;i<2;i++){
        v +=slide_1[i]*slide_1[i];
        u +=slide_1[i]*slide_1[i];
    }
    lambda =sqrt(v)/sqrt(u);
     */
        //a = lambda*b
}
int isAAA(double *v_1, double *v_2, double *v_3, double *w_1, double *w_2, double *w_3){
    if(
    findAngle(v_1,v_2)== findAngle(w_1,w_2)&&
    findAngle(v_2,v_3)== findAngle(w_2,w_3)&&
    findAngle(v_3,v_1)== findAngle(w_3,w_1)
       )
    {
        return 1;
    }
    else {
        return 0;
    }
    // angles should meet
        // if satisfied AAA criteria return 1, else 0
}
int isSSS(double *v_1, double *v_2, double *v_3, double *w_1, double *w_2, double *w_3){
    if
    (
     findLength(v_1)==findLength(w_1)&&
     findLength(v_2)==findLength(w_2)&&
     findLength(v_3)==findLength(w_3)
    )
    {
        return 1;
    }
    else {
        return 0;
    }
        // lambda should be the same
        // if satisfied SSS criteria return 1, else 0
}
int isSAS(double *v_1, double *v_2, double *v_3, double *w_1, double *w_2, double *w_3){
    if(
       findAngle(v_1,v_2)==findAngle(w_1,w_2)&&
       findLength(v_1)==findLength(w_1)&&
       findLength(v_2)==findLength(w_2)
    )
    {
        return 1;
    }
    else{
        return 0;
    }
        // angle between the two slides should be the same, lambda as well
        // if satisfied SAS criteria return 1, else 0
}

void Allocate(){

        triangle_v = new double*[3];
        triangle_w = new double*[3];
        for (int j=0; j<3; j++){
                *(triangle_v+j) = new double[2];
                *(triangle_w+j) = new double[2];
        }
        v_1 = (double *)malloc(sizeof(double *)* 2);
        v_2 = (double *)malloc(sizeof(double *)* 2);
        v_3 = (double *)malloc(sizeof(double *)* 2);

        w_1 = (double *)malloc(sizeof(double *)* 2);
        w_2 = (double *)malloc(sizeof(double *)* 2);
        w_3 = (double *)malloc(sizeof(double *)* 2);
}
void Free(){
        for( int i=0; i<3; i++){
                free(triangle_v[i]);
                free(triangle_w[i]);
        }
        free (triangle_v);
        free (triangle_w);
        free(v_1);
        free(v_2);
        free(v_3);
        free(w_1);
        free(w_2);
        free(w_3);
}
void initTriangles(double **ptr_v, double **ptr_w){
        ptr_v[0][0] = -3;
        ptr_v[0][1] = -3;

        ptr_v[1][0] = -1;
        ptr_v[1][1] = -1;

        ptr_v[2][0] = 0;
        ptr_v[2][1] = -2;
////////////////////////////////////
        ptr_w[0][0] = 7.5;
        ptr_w[0][1] = 6.2;

        ptr_w[1][0] = 9.96;
        ptr_w[1][1] = 8.66;

        ptr_w[2][0] = 11.19;
        ptr_w[2][1] = 7.43;
        /*ptr_w[0][0] = -3;
        ptr_w[0][1] = -3;

        ptr_w[1][0] = -1;
        ptr_w[1][1] = -1;

        ptr_w[2][0] = 0;
        ptr_w[2][1] = -2;*/
}
void initVectors(double **ptr_v, double **ptr_w){
    for(int i=0 ;i<2 ;i++){
        v_1[i]=ptr_v[1][i]-ptr_v[0][i];
        v_2[i]=ptr_v[2][i]-ptr_v[1][i];
        v_3[i]=ptr_v[0][i]-ptr_v[2][i];
        w_1[i]=ptr_w[1][i]-ptr_w[0][i];
        w_2[i]=ptr_w[2][i]-ptr_w[1][i];
        w_3[i]=ptr_w[0][i]-ptr_w[2][i];
    }
        // consider the clockwise direction started at the point ptr_v[0] and ptr_w[0] respectiviely.
}
int main(){


        Allocate();
        initTriangles(triangle_v, triangle_w);
        initVectors(triangle_v, triangle_w);

       

        int isSimiliar = 1;
        if (isAAA(v_1, v_2, v_3, w_1, w_2, w_3) ==  0){
                isSimiliar = 0;
                
        }
        else if (isSSS(v_1, v_2, v_3, w_1, w_2, w_3) == 0){
                isSimiliar = 0;
                
        }
        else if (isSAS(v_1, v_2, v_3, w_1, w_2, w_3) == 0){
                isSimiliar = 0;
        }
        cout<<isSimiliar<<endl;

        Free();
}
