#include <stdlib.h>
#include <stdio.h>
void f208(int N, double* A);

int main(void){
    FILE* in;
    FILE* out;
    int N, q;
    double* A=NULL;
    double result;
    out = fopen("output.txt", "w"); if(out==NULL) return -1;
    in = fopen("input.txt", "r"); if(in==NULL) {fclose(out); return -1;}
    q = fscanf(in, "%d", &N);
    if(N<=0) {fclose(in); fclose(out); return -1;}
    A = (double*)malloc(N*sizeof(double));
    if(A==NULL) {fclose(in); fclose(out); return -1;}
    for(int i = 0; i< N; i++) {
        if((q=fscanf(in, "%lf", &A[i]))!=1){
            fclose(in); fclose(out); return -1;
        }
    }
    f208(N, A);
    for(int k = 0; k< N; k++){
        fprintf(out, "%lf ", A[k]);
    }
    fclose(in); fclose(out); 
    return 0;
}
void f208(int N, double* A){
    double tek, pred, predposl;
    FILE* fileout;
    fileout = fopen("fileout.txt", "w");
    if(N==1) {A[0] = 0.0; return;}
    predposl = A[N-2];
     fprintf(fileout, "%lf ", predposl);
    pred = A[0];
    A[0]= A[1]/2;
    for(int k=1; k< N-1; k++){
        tek=A[k];
        A[k]= (A[k+1]+pred)/2;
        pred=tek;
    }
    
    A[N-1]= predposl/2;
    return;
}
