#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void f207sort(int N, int* A);
void f207(int N, int* A);

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
    
    f207sort(N,A);
    f207(N, A);
    for(int j = 0; j< N; j++){
        fprintf(out, "%d ",A[j]);
    }
    fclose(in); fclose(out); 
    return 0;
}
void f207sort(int N, int* A){
    int tmp;
    for(int i = N-1; i>0; i--){
        for(int j = 0; j<i; j++){
            if(A[j]<0 && A[j+1]>=0){
                tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp;
            }
        }
    }
}
void f207(int N, int* A){

    for(int k = N; k>0; k--)
    {
        if(A[k-1]<0){
            A[k-1]=0;
        }
    }       
    return;
}
