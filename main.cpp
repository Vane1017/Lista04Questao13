
#include <iostream>

using namespace std;


void criarMatriz(int A[100][100]){
    int ii, jj;
    for(ii=0;ii<2;ii++){
        for(jj=0;jj<2;jj++){
            A[ii][jj] = rand()%101;
        }
    }
}

void printMatriz(int A[100][100]){
    int ii, jj;
    for(ii=0;ii<2;ii++){
        for(jj=0;jj<2;jj++){
            cout << A[ii][jj] << " ";
        }
        cout << endl;
    }
}

void strassen(int A[100][100], int B[100][100], int C[100][100]){
    int m1,m2,m3,m4,m5,m6,m7;
    m1 = (A[0][0]+A[1][1])*(B[0][0]+B[1][1]);
    m2 = (A[1][0]+A[1][1])*(B[0][0]);
    m3 = (A[0][0])*(B[0][1]-B[1][1]);
    m4 = (A[1][1])*(B[1][0]-B[0][0]);
    m5 = (A[0][0]+A[0][1])*(B[1][1]);
    m6 = (A[1][0]-A[0][0])*(B[0][0]+B[0][1]);
    m7 = (A[0][1]-A[1][1])*(B[1][0]+B[1][1]);
    C[0][0] = m1+m4-m5+m7;
    C[0][1] = m3+m5;
    C[1][0] = m2+m4;
    C[1][1] = m1+m3-m2+m6;
}

int main()
{
    int A[100][100] = {0};
    int B[100][100] = {0};
    int C[100][100] = {0};
    criarMatriz(A);
    printMatriz(A);
    cout << endl;
    criarMatriz(B);
    printMatriz(B);
    cout << endl;
    strassen(A,B,C);
    printMatriz(C);
    return 0;
}
