//
//  main.cpp
//  HW6-2
//
//  Created by 劉翊安 on 2020/5/29.
//  Copyright © 2020 劉翊安. All rights reserved.
//

# include <iostream>
#include <cmath>
#include <math.h>
# define N 20
using namespace std;

double A[N][N] = {};
double B[N][N] = {};
double C[N][N] = {};
double D[N][N] = {};
double r = 0;

int F[N] = {};
void initial() {
    for (int i = 0; i < N; i++) {
        A[i][i] = -2;
        if ((i + 1) < N) {
            A[i][i + 1] = 1;
            A[i + 1][i] = 1;
        }
        F[i] = (i == 49);
    }
}

void allocate() {
    for (int i = 0; i < N; i++) {
        B[i][i] = 1;
    }
}

void matrixSolver() {
    //goal找Ａ的反矩陣
    //把A變成上三角矩陣
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            r = A[j][i] / A[i][i];//找出下一行除掉前一行的比值
            for (int k = i; k < N; k++) {
                A[j][k] -= A[i][k] * r;//利用前面找出的比值把下一行的第一個數減掉變成零
            }
            for (int a = 0; a < N; a++) {
                B[j][a] -= B[i][a] * r;//b也做同樣的運算
            }
        }
    }
    //把Ａ變成對角矩陣
    for (int i = N - 1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            r = A[j][i] / A[i][i];//找出每一行的第一個非零的樹根該行以前的數的比值
            for (int k = i; k < N; k++) {
                A[j][k] -= A[i][k] * r;//利用比值把該行以前的數都剪掉
            }
            for (int l = 0; l < N; l++) {
                B[j][l] -= B[i][l] * r;//b也做同樣的運算
            }
        }
    }
    //利用矩陣運算把不是零的數都換成1
    for (int i = 0; i < N; i++) {
        r = A[i][i];
        A[i][i] /= r;
        for (int j = 0; j < N; j++) {
            B[i][j] /= r;//B就是Ａ的反矩陣
        }
    }
}

void p() {
    // 計算 C = A*B
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = fabs(round(C[i][j]));
        }
    }

    // 計算 D = B*A
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                D[i][j] += B[i][k] * A[k][j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = fabs(round(C[i][j]));
            D[i][j] = fabs(round(D[i][j]));
        }
    }
}

int main() {
    initial();
    allocate();
    matrixSolver();
    initial();
    p();

    cout << "A =" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "A' =" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "A*A' =" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "A'*A =" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << D[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
