# include <iostream>
# include <cstdlib>
# include <math.h>
# define N 5
using namespace std;
double A[N][N] = {{}};
double B[N][N] = {{}};
double C[N][N] = {{}};

void init(){
        for (int i = 0; i < N; i++)
        {
                for (int j = 0; j < N; j++)
                {
                        A[i][j] = i+j;
                        B[i][j] = 2*i+j;
                }
        }
}

int  main()
{
        init();
   
         for (int i = 0; i < N; i++)
                {
                        for (int j = 0; j < N; j++)
                        {
                             for(int m=0;m<N;m++)
                             {
                                 C[i][j]+=A[i][m]*B[m][j];//設一個變數m，是Ａ的列，Ｎ的行，乘起來剛好就會是我們要的答案
                             }
                        }
                }
        
        for (int i = 0; i < N; i++)
        {
                for (int j = 0; j < N; j++)
                {
                        cout <<C [i][j] << "\t";
                }
            cout<<endl;
        }
    return 0;
}
