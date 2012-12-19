#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void f210(int N, int* A, int* result);

int main(void){
    FILE* in;
    FILE* out;
    int N, q, result;
    int kol, res;
    int* A=NULL;
    out = fopen("output.txt", "w"); if(out==NULL) return -1;
    in = fopen("input.txt", "r"); if(in==NULL) {fclose(out); return -1;}
    q = fscanf(in, "%d", &N);
    if((q!=1)||(N<=0)) {fclose(in); fclose(out); return -1;}
    A = (int*)malloc(N*sizeof(int));
    if(A==NULL) {fclose(in); fclose(out); return -1;}
    for(int i = 0; i< 2 && i<N; i++) {
        if((q=fscanf(in, "%d", &A[i]))!=1){
            fclose(in); fclose(out); return -1;
        }
    }
    for(int i = 2; i< N; i++) {
        if((q=fscanf(in, "%d", &A[i]))!=1){
            fprintf(out, "-1"); fclose(in); fclose(out); return 0;
        }
    }
    f210(N, A, &result);
    if(result==0){
        fprintf(out, "0");
    }
    else{
        fprintf(out, "1");
    }
    fclose(in); fclose(out); 
    return 0;
}

void f210(int N, int* A, int* result){
    int sum1 = 0;
    int sum2 = 0;
    for(int k =0; k<N; k+=2){
        sum1+=A[k];
    }
    for(int k =1; k<N; k+=2){
        sum2+=A[k];
    }
    if(sum1==sum2){
        *result = 1;
        return;
    }
    *result = 0;        
    return;
}
