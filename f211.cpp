#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void f210(int N, int* A, int* k, int* sum, int* result);

int main(void){
    FILE* in;
    FILE* out;
    int N, q, result;
    int kol, res, k, sum;
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
    f210(N, A, &result, &k,&sum);
    if(result==-1){
        fprintf(out, "-1");
    }
    else{
        fprintf(out, "%d %d", k+1, sum);
    }
    fclose(in); fclose(out); 
    return 0;
}

void f210(int N, int* A, int* result, int* k, int* sum){
    int sum1 = 0;
    int sum2 = 0;
    for(int j =0; j<N; j++){
        sum1+=A[j];
    }
    for(int j =0; j<N; j++){
        sum2+=A[j];
        if(sum2==(sum1/2)){
            *sum=sum2;
            *k=j;
            *result=0;
            return;
        }
    }
    *result = -1;   
    return;
}
