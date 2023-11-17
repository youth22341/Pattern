//print K word with patter "~" and "*"
/*
	Ex:
		Input: n = 5; //height of half letter
		Output:
				~~~~*****
				~~~****
				~~***
				~**
				*
				~**
				~~***
				~~~****
				~~~~*****
*/
#include<stdio.h>

void Print_K_Word(int n){
	int i,j;
	int copy = n;
	for(i = 1; i <= 2*copy-1; i++){
		if(i < copy){
			for(j = 1; j <= 2*n-1; j++){
				if(j <= n-1) printf("~");
				else printf("*");
			}
			printf("\n");
			n--;
		}else if(i == copy){
			printf("*\n");
			n = 1;
		}else{
			for(j = 1; j <= 2*n+1; j++){
				if(j <= n) printf("~");
				else printf("*");
			}
			if(i < 2*copy-1) printf("\n");
			n++;
		}	
	}
}

int main(){
	Print_K_Word(5);
	return 0;
}
