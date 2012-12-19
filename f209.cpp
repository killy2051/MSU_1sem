#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void f209sort(int N, int* A);
void f209(int N, int* A, int* result);

int main(void){
    FILE* in;
    FILE* out;
    int N, q, p, t, result;
    int kol, res;
    int* A=NULL;
    out = fopen("output.txt", "w"); if(out==NULL) return -1;
    in = fopen("input.txt", "r"); if(in==NULL) {fclose(out); return -1;}
    q = fscanf(in, "%d", &N);
    if(N<=0) {fclose(in); fclose(out); return -1;}
    A = (int*)malloc(N*sizeof(int));
    if(A==NULL) {fclose(in); fclose(out); return -1;}
    for(int i = 0; i< N; i++) {
        if((q=fscanf(in, "%d", &A[i]))!=1){
            fclose(in); fclose(out); return -1;
        }
    }
    
    f209sort(N,A);
    p= A[0]; t= A[N-1];
    f209(N, A, &result);
    if(result==-1){
        fprintf(out, "-1");
    }
    else{
        fprintf(out, "%d %d", p, t);
    }
    fclose(in); fclose(out); 
    return 0;
}
void f209sort(int N, int* A){
    int tmp;
    for(int i = N-1; i>0; i--){
        for(int j = 0; j<i; j++){
            if(A[j]>A[j+1]){
                tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp;
            }
        }
    }
}
void f209(int N, int* A, int* result){
    
    for(int k =0; k<N-1; k++){
        if((A[k+1]-A[k])>1){
            *result=-1;
            return;
        }
    }
    *result = 0;        
    return;
}
