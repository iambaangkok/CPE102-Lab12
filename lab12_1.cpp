#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double source[],int N,double dest[]){
    dest[0] = dest[1] = dest[3] = 0 ;
    dest[2] = 1;
    dest[4] = -1e9;
    dest[5] = 1e9;
    for(int i = 0 ; i < N;++i){
        dest[0] += source[i];
        dest[1] += pow(source[i],2);
        dest[2] *= source[i];
        dest[3] += 1/source[i];
        if(source[i] > dest[4]){
            dest[4] = source[i];
        }
        if(source[i] < dest[5]){
            dest[5] = source[i];
        }
    }
    dest[0] /= N;
    dest[1] = sqrt(dest[1]/N - pow(dest[0],2));
    dest[2] = pow(dest[2],1.0/N);
    dest[3] = N/dest[3];

    return;
}