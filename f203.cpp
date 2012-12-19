#include <stdlib.h>
#include <stdio.h>
void f203(int N, double* A);

int main(void){
    FILE* in;
    FILE* out;
    int N, q;
    double* A=NULL;
    out = fopen("output.txt", "w"); if(out==NULL) return -1;
    in = fopen("input.txt", "r"); if(in==NULL) {fclose(out); return -1;}
    q = fscanf(in, "%d", &N);
    if(N<=0) {fclose(in); fclose(out); return -1;}
    A = (double*)malloc(N*sizeof(double));
    if(A==NULL) {fclose(in); fclose(out); return -1;}
    for(int i = 0; i< N; i++) {
        if(q=fscanf(in, "%lf", &A[i])!=1){
            fclose(in); fclose(out); return -1;
        }
    }
    f203(N, A);
    for(int j = 0; j< N; j++){
        fprintf(out, "%lf ", A[j]);
    }
    fclose(in); fclose(out); 
    return 0;
}
void f203(int N, double* A){
    for(int k=1; k< N; k++){
       A[k] = A[k-1] + A[k];
    }
    return;
}
