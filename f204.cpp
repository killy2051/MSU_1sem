#include <stdlib.h>
#include <stdio.h>
void f204(int N, int* A);

int main(void){
    FILE* in;
    FILE* out;
    int N, q;
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
    f204(N, A);
    for(int j = 0; j< N; j++){
        fprintf(out, "%d ", A[j]);
    }
    fclose(in); fclose(out); 
    return 0;
}
void f204(int N, int* A){
    int tmp=A[N-1];
    for(int k=N-1; k> 0; k--){
       A[k] = A[k-1];
    }
    A[0] = tmp;
    return;
}
