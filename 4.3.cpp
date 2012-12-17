#include <iostream>

const int MAXN = 45;		/* largest number of dots */
const int MAXK = 10;		/* largest number of dividers */
const int MAXINT = 100000;		/* infinity */


int max(int a, int b)
{
	return( (a > b) ? a : b );
} 

void read_partition(int s[], int *n, int *k)
{
	printf("Enter n and k\n");
	scanf("%d %d",n,k);
	printf("Enter S[]\n");
	for (int i=1; i<=*n; i++)
		scanf("%d",&(s[i]));
}

int print_dots(int s[], int start, int end)
{
	int i;			/* counter */

	printf("\{");
	for (i=start; i<=end; i++) printf(" %d ",s[i]);
	printf("}\n");

	FILE* out = fopen("out.txt", "w");
    if (out == NULL) {
        perror("Could not open output file");
        return (-1);
    }

	for (i=start; i<=end; i++)
			fprintf(out, "%d ",s[i]);
}

void reconstruct_partition(int s[],int d[MAXN+1][MAXK+1], int n, int k)
{
	if (k==1)
		print_dots(s,1,n);
	else {
		reconstruct_partition(s,d,d[n][k],k-1);
		print_dots(s,d[n][k]+1,n);
	}
}

void partition(int s[], int n, int k)
{
	int p[MAXN+1];				/* prefix sums array */
	int m[MAXN+1][MAXK+1];			/* DP table for values */
	int d[MAXN+1][MAXK+1];			/* DP table for dividers */
	int cost;				/* test split cost */
	int i,j,x;				/* counters */

	p[0] = 0;				/* construct prefix sums */
	for (i=1; i<=n; i++) p[i]=p[i-1]+s[i];

	for (i=1; i<=n; i++) m[i][1] = p[i];	/* initialize boundaries */
	for (j=1; j<=k; j++) m[1][j] = s[1];

	for (i=2; i<=n; i++)			/* evaluate main recurrence */
		for (j=2; j<=k; j++) {
			m[i][j] = MAXINT;
			for (x=1; x<=(i-1); x++) {
				cost = max(m[x][j-1], p[i]-p[x]);
				if (m[i][j] > cost) {
					m[i][j] = cost;
					d[i][j] = x;
				}
			}
		}

	reconstruct_partition(s,d,n,k);		/* print dot partition */
}



int main()
{
	int s[MAXN+1];			/* dot thicknesses to partition */
	int n;				/* how many dots? */
	int k;				/* how many partitions? */

	read_partition(s,&n,&k);
	partition(s,n,k);
}


