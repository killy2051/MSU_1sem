#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void f206sort(int N, int* A);
void f206(int N, int* A, int* res, int* kol);

int main(void){
    FILE* in;
    FILE* out;
    int N, q;
    int kol, res;
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
    
    f206sort(N,A);
    f206(N, A, &res, &kol);
    fprintf(out, "%d %d", res, kol);
    fclose(in); fclose(out); 
    return 0;
}
void f206sort(int N, int* A){
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
void f206(int N, int* A, int* res, int* kol){
    *kol = 1;
    *res = A[0];
    int dl = 1;
    for(int k = 0; k< N-1; k++)
    {
       if(A[k]==A[k+1])
       {
            dl++;
       }
       if(A[k] != A[k+1])
       {
            if(dl>*kol)
            {
                *kol = dl;
                *res = A[k];
            }
            dl = 1;
        
       }
    }
    if(dl>*kol){
                *kol = dl;
                *res = A[N-1];
            }
    return;
}
