#include<stdio.h>
#include<stdlib.h>

// m - number N
// n - parts K

#define Min(x,y) ((x<y)?x:y)

  typedef struct partitionnode 
  {
    int m;
    int numparts;
    int parts[101];
  } partition;

  int Pn[40][40];
  int P[50];
  
void output(partition a)
/*
**  print out the partition a
*/
{
 int i,j;
 printf("%d = ",a.m);
 for(i=1;i<=a.numparts;i=i+1)
 {
    j = a.parts[i];
    printf("%d",j);
    if (i != a.numparts)
      printf("+");
 }

 // print to file
 FILE* out = fopen("out.txt", "w");
    if (out == NULL) {
        perror("Could not open output file");
    }

	fprintf(out, "%d = ",a.m);
 for(i=1;i<=a.numparts;i=i+1)
 {
    j = a.parts[i];
    fprintf(out, "%d",j);
    if (i != a.numparts)
      fprintf(out, "+");
 }

 fclose(out);
}

void EnumPartitions(int m, int n )
/*
**  compute the partition numbers P[i] and P[i,j] for i <= m, j <= n
*/
{
 int i,j;
 Pn[0][0] =  1;
 P[0] = 1;
 for(i=1;i<=m;i=i+1) Pn[n][0]=0;
 for(i=1;i<=m;i=i+1)
 {
   for (j=1;j<=Min(i,m);j=j+1)
   {
       if (i < (2*j)) 
         Pn[i][j] =  Pn[i-1][j-1];
       else 
         Pn[i][j] =  Pn[i-1][j-1] + Pn[i-j][j];
     P[i] = P[i] + Pn[i][j];
   }
   P[i] = 0;
   for(j=1;j<=m;j++) P[i] = P[i] + Pn[i][j];
 }
}

void PartitionLexUnrank(int m, int n, int r, partition *a)
/*
**  find the partition of m into n parts having rank r
*/
{
  int i;
  EnumPartitions(m,n);
  (*a).m = m;
  (*a).numparts = n;
  for(i=1;i<=n;i=i+1)
   (*a).parts[i] = 0;
  while (m > 0)
  {
      if (r < Pn[m-1][n-1])
      {
          (*a).parts[n] = (*a).parts[n]+1;
          m = m-1;
          n = n-1;
      }
      else 
      {
         for (i=1;i<=n;i=i+1)
           (*a).parts[i] = (*a).parts[i] + 1;
         r = r - Pn[m-1][n-1];
         m = m - n;
      }
  }
}

int main()
{ 
  int m,n,r;

  partition a;

  printf("Enter N ");
  scanf("%d", &m);
  printf("Enter K ");
  scanf("%d", &n);

  printf("\nTest with N(m)=%d K(n)=%d \n\n",m,n);
  for(r=0;r<=8;r=r+1)
  {
    PartitionLexUnrank(m,n,r,&a);
    output(a); printf("\n");
  }
  printf("\nEnd of test.\n\n");

  return(0);
}
