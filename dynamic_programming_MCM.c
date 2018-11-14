// Matrix_Chain_Multiplication
#include<stdio.h>

int matrix_chain_multiplication(int *a, int n){
	int i=0,j=0,k=0,cost_matrix[n+1][n+1],p_matrix[n+1][n+1],difference=0,cost=0; // total matrices are n=4, therefore there total order required will be n+1=5, so create matrice of order N+1

	for(i=0;i<=n;i++){							// To initalize all matrix multiplication with themselves as 0 and multiply 0th matrix multiplication to 0, as there is no matrix 0, we are taking it as array starts from 0
		cost_matrix[i][i]=0;
		cost_matrix[0][i]=0;
		cost_matrix[i][0]=0;
	}

	for(difference=1;difference<=n-1;difference++){					// loop for calculating total number of rows to be filled by matrix multiplication cost.
		for(i=1;i<=n-difference;i++){								// loop for computing the values for the desired columns in the cost_matrix to be filled by the matrix multiplication cost.
			j=i+difference;
			cost_matrix[i][j]=32767;
			for(k=i;k<=j-1;k++){									// loop for computing the minimum cost from the matrix multiplication and also computing the which value of k gives the minimum cost( which implies till where paranthesis should be marked in matix multiplication) and assign it to the p_matrix.
				cost = cost_matrix[i][k] + cost_matrix[k+1][j] + a[i-1]*a[k]*a[j];
				if(cost < cost_matrix[i][j]){
					cost_matrix[i][j]=cost;
					p_matrix[i][j]=k;
				}
			}
		}
	}
	//printf("%d\n",cost_matrix[1][n] );
	return cost_matrix[1][n];
}

// Main driver Program

int main(int argc, char const *argv[])
{
	int n,i,cost=0;
	
	printf("How many matrices to be multiplied\n");
	scanf("%d",&n);
	int order[n+1];					// as total order required for the matrix multiplication is 1 greator than the total number of matrices, therefore assign order array with n+1 elements.

	for(i=0;i<=n;i++){
		printf("Enter the order %d\n",i );
		scanf("%d",&order[i]);
	}
	cost=matrix_chain_multiplication(order,n);
	printf("Minimum cost for the multiplication of the matrices is = %d \n",cost);
	return 0;
}
