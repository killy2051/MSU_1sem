#include <stdlib.h>
#include <stdio.h>
void f201(int N, double* A, double* result);

int main(void){
    FILE* in;
    FILE* out;
    int N, q;
    double* A=NULL;
    double result;
    out = fopen("output.txt", "w"); //if(out==NULL) return -1;
    in = fopen("input.txt", "r"); //if(in==NULL) {fclose(out); return -1;}
    q = fscanf(in, "%d", &N);
    //if(N<=0) {fclose(in); fclose(out); return -1;}
    A = (double*)malloc(N*sizeof(double));
    //if(A==NULL) {fclose(in); fclose(out); return -1;}
    //for(int i = 0; i< N; i++) {
        //if(q=fscanf(in, "%lf", &A[i])!=1){
         //   fclose(in); fclose(out); return -1;
        //}
    //}
    f201(N, A, &result);
    fprintf(out, "%lf", result);
    fclose(in); fclose(out); 
    return 0;
}
void f201(int N, double* A, double* result){
    double sum=0.0;
    int kol=0;
    for(int k=0; k< N; k++){
        sum+=A[k];
        kol++;
    }
    *result = sum/kol;
    return;
}
