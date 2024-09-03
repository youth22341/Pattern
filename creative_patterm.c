/*
	print from 1 to n^2 into matrix with n row and n column with 4 types of patterns:
	Example with n = 5
	
	1/
	   1 2 3 4 5
	   10 9 8 7 6
	   11 12 13 14 15
	   20 19 18 17 16
	   21 22 23 24 25   
	(moving by Z-pattern by row from the left-top)
	
	2/
		25 16 15 6 5
		24 17 14 7 4
		23 18 13 8 3
		22 19 12 9 2	
	        21 20 11 10 1
	(moving by Z-pattern by column from the right-bottom)

	3/
		1 2 3 4 5
		16 17 18 19 6	
		15 24 25 20 7
		14 23 22 21 8
		13 12 11 10 9
	(moving by circle from left to right + top to bottom + right to left + bottom to top)
	
	4/
		1 2 6 7 15
		3 5 8 14 16
		4 9 13 17 22
		10 12 18 21 23
		11 19 20 24 25
   (moving by ziczac-move from left to right + top to bottom (diagonal))
*/

#include<stdio.h>
#include<stdlib.h>

//Declare function with prototype
void print_style(int i, int value);
void print_array(int A[], int n);
void print_matrix(int n, int A[n][n]);
void pattern_1 (int n);
void pattern_2 (int n);
void pattern_3 (int n);
void pattern_4 (int n);

//Writting function
void print_style(int i, int value){
	if(i == 1) printf("%d",value);
	else printf(" %d",value);
}

void print_array(int A[], int n){
	int i,j;
	for(i = 0; i < n; i++){
		if(i == 0) printf("%d",A[i]);
		else printf(" %d",A[i]);	
	}
}

void print_matrix(int n, int A[n][n]){
	int i,j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			print_style(j+1,A[i][j]);
		}
		if(i < n-1) printf("\n");
	}
}

void pattern_1 (int n){
	int i, j;
	int sum = 0;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			if(i%2 == 1){
				sum++;
			}else{
				if(j == 1) sum += n;
				else sum--;
			}
			if(j < n) printf("%d ",sum);
			else{
				printf("%d",sum);
				if(i%2 == 0) sum += (n-1);
			}
		}
		if(i < n) printf("\n");
	}	
}

void pattern_2 (int n){
	int i,j;
	int A[n];
	for(i = 0; i < n; i++){
		if(n%2 == 0){
			if(i == 0) A[0] = n*n-n+1;
			else{
				if(i%2 == 1) A[i] = A[i-1] - 1;
				else A[i] = A[i-1] - (2*n-1);
			}
		}else{
			if(i == 0) A[0] = n*n;
			else{
				if(i%2 == 1) A[i] = A[i-1] - (2*n-1);
				else A[i] = A[i-1] - 1;
			}
		}
	}
	/*
		//Test array A
		print_array(A,n);
		printf("\n");
	*/
	int value;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			if(n%2 == 0){
				if((j-1)%2 == 0) value = A[j-1] + (i-1);
				else value = A[j-1] - (i-1);
			}else{
				if((j-1)%2 == 0) value = A[j-1] - (i-1);
				else value = A[j-1] + (i-1);
			} 
			print_style(j,value);
		}
		if(i < n) printf("\n");
	}
}

void pattern_3 (int n){
	int i,j;
	int sum = 0;		
	int A[n][n];
	int start_i, end_i, start_j, end_j;
	int step = 1;
	int count = 0;
	while (sum < n*n){
		if(step == 1){
			start_i = count;
			start_j = start_i;
			end_j = (n-1) - count; 
			for(i = start_i, j = start_j; j <= end_j; j++){
				sum++;
				A[i][j] = sum;
			}
		}
		if(step == 2){
			start_i = count+1;
			end_i = n-count-1;
			start_j = n-count-1;
			for(i = start_i, j = start_j; i <= end_i; i++){
				sum++;
				A[i][j] = sum;
			}
		}
		if(step == 3){
			start_i = n-count-1;
			start_j = count; 
			end_j = n-count-2;
			for(i = start_i, j = end_j; j >= start_j; j--){
				sum++;
				A[i][j] = sum;
			}
		}
		if(step == 4){
			start_i = count+1;
			end_i = n-count-2;
			start_j = count;
			for(i = end_i, j = start_j; i >= start_i; i--){
				sum++;
				A[i][j] = sum;
			}
	    }
		step++;
		if(step == 5){
			step = 1;
			count++;
		} 
	}
	print_matrix(n,A);
}

void pattern_4 (int n){
	int i,j;
	int sum = 0;		
	int A[n][n];
	int start_i, end_i, start_j, end_j;
	int step = 1;
	int count = 0;
	//left array
	while(sum < (n*n+n)/2){
		if(step == 1){
			start_i = 0;
			start_j = 2*count;                 
			i = start_i; j = start_j;
			sum++;
			A[i][j] = sum;
		}
		if(step == 2){
			start_i = 0;
			end_i = 2*count+1;
			start_j = 0; 
			end_j = 2*count+1;
			for(i = start_i, j = end_j; i <= end_i, j >= start_j; i++, j--){
				sum++;
				A[i][j] = sum;
			}
		}
		if(step == 3){
			start_i = 0;
			end_i = 2*count+2;
			start_j = 0;
			end_j = 2*count+1;
			for(i = end_i, j = start_j; i >= start_i, j <= end_j; i--, j++){
				sum++;
				A[i][j] = sum;
			}
		}
		step++;
		if(step == 4){
			step = 1;
			count++;
		}
	}
	//right array
	step = 1;
	count = 1;
	while(sum < n*n){
		if(step == 1){
			start_i = 2*count-1;
			end_i = n-1;
			start_j = 2*count-1; 
			end_j = n-1;
			if(n%2 == 0){
				for(i = end_i, j = start_j; i >= start_i, j <= end_j; i--, j++){
					sum++;
					A[i][j] = sum;
				}
			}else{
				for(i = start_i, j = end_j; i <= end_i, j >= start_j; i++, j--){
					sum++;
					A[i][j] = sum;
				}				
			}
		}
		if(step == 2){			
			start_i = 2*count;
			end_i = n-1;
			start_j = 2*count; 
			end_j = n-1;
			if(n%2 == 0){
				for(i = start_i, j = end_j; i <= end_i, j >= start_j; i++, j--){
					sum++;
					A[i][j] = sum;
				}						
			}else{
				for(i = end_i, j = start_j; i >= start_i, j <= end_j; i--, j++){
					sum++;
					A[i][j] = sum;
				}		
			}
		}
		step++;
		if(step == 3){
			step = 1;
			count++;
		}
		if(sum == n*n-1){
			A[n-1][n-1] = n*n;
			break;
		}
	}	
	print_matrix(n,A);		
}

//Main
int main(){
	int n = 8;
	printf("Pattern 1:\n");
	pattern_1(n);
	printf("\n\nPattern 2:\n");	
	pattern_2(n);
	printf("\n\nPattern 3:\n");	
	pattern_3(n);
	printf("\n\nPattern 4:\n");		
	pattern_4(n);
	return 0;
}
