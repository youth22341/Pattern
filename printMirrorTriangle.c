//print 2 square Triangle that mirror each other by y-axis
/*
  Ex:
        Input: n = 5
        Output: 
     	        *
				**
				* *
				*  *
				*********
				     *  *
				      * *
				       **
				        * 
*/
#include <stdio.h>

void printMirrorTriangle(int n){
    int i,j;
    for(i = 1; i <= 2*n-1; i++){
        //upper
        if(i < n){
            for(j = 1; j <= n; j++){
                if(j == 1 || j == i) printf("*");
                else printf(" ");
            }
            printf("\n");
        //middle
        }else if(i == n){
            for(j = 1; j <= 2*n-1; j++) printf("*");
            printf("\n");
        //lower
        }else{
            for(j = 1; j <= 2*n-1; j++){
                if(j == 2*n-1 || j == i) printf("*");
                else printf(" ");
            }
            if(i < 2*n-1) printf("\n");
        }
    }
}

int main(){
    printMirrorTriangle(5);
    return 0;
}

