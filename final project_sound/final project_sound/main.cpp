//
//  main.cpp
//  final project_sound
//
//  Created by 劉翊安 on 2020/6/30.
//  Copyright © 2020 劉翊安. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#define length 1;
using namespace std;

int main(){
    int c;
    FILE *fp;
    int lines=1;
    fp=fopen("file.txt", "rb");
    if(fp)
    {
        while((c=fgetc(fp)) != EOF)
            if(c=='\n') lines++;
        printf("%d\n",lines);
        fclose(fp);
    }
    
    system("file.txt");
    cout<<endl;
    fstream fin("file.txt",ios::in);
    fstream fout("outcome.txt",ios::out);

    for(int i=0;i<lines;i++){
        double n,l;
        fin>>n;
        fin>>l;
        fout<<n<<"\t";
        fout<<l<<"\t";
        double frequency =440*pow(2,(n-49)/12);
        double tonelength=pow(0.5,l)*length;
        fout<<frequency<<"\t";
        fout<<tonelength<<endl;
    }
    fout.close();
    fin.close();
    system("Pause");
}


