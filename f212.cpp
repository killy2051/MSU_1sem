#include <stdlib.h>
#include <stdio.h>
void f212sort(int N, int* A);

int main(void){
    FILE* in;
    FILE* out;
    int N, q;
    int kol;
    int* A=NULL;
    out = fopen("output.txt", "w"); if(out==NULL) return -1;
    in = fopen("input.txt", "r"); if(in==NULL) {fclose(out); return -1;}
    q = fscanf(in, "%d", &N);
    if(N<=0) {fclose(in); fclose(out); return -1;}
    A = (int*)malloc(N*sizeof(int));
    if(A==NULL) {fclose(in); fclose(out); return -1;}
    for(int i = 0; i< N; i++) {
        if(q=fscanf(in, "%d", &A[i])!=1){
            fclose(in); fclose(out); return -1;
        }
    }
    f212sort(N,A);
    for(int j = 0; j< N; j++){
        fprintf(out, "%d ", A[j]);
    }
    fclose(in); fclose(out); 
    return 0;
}
void f212sort(int N, int* A){
    int tmp;
    for(int i = N-1; i>0; i--){
        for(int j = 0; j<i; j++){
            if(A[j]> A[j+1]){
                tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp;
            }
        }
    }
}
