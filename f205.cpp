#include <stdlib.h>
#include <stdio.h>
void f205sort(int N, int* A);
void f205(int N, int* A, int* kol);

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
    f205sort(N,A);
    f205(N, A, &kol);
    fprintf(out, "%d", kol);
    fclose(in); fclose(out); 
    return 0;
}
void f205sort(int N, int* A){
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
void f205(int N, int* A, int* kol){
    *kol = 1;
    for(int k = 0; k< N-1; k++){
       if(A[k] != A[k+1]){
        (*kol)++;
        
        }
    }
    
    return 0;
}
