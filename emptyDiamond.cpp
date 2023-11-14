//print Empty Diamond shape
/*
	Ex:
	  	Input: n = 5 //the height of half diamond
	  	Output:
	  	         *
	  	        * *
	  	       *   *
	  	      *     *
	  	     *       *
	  	      *     *
	  	       *   *
	  	        * *
	  	         *
*/
#include<iostream>
using namespace std;

void printEmptyDiamond(int n){
	int i,j;
	for(i = 1; i <= n; i++){
	    for(j = 1; j <= 2*n-1; j++){
	      if(j == n-i+1 || j == n+i-1) cout << "*";
	      else cout << " ";
	    }
	    cout << endl;
   }
    for(i = n-1; i >= 1; i--){
    	for(j = 1; j <= 2*n-1; j++){
      		if(j == n-i+1 || j == n+i-1) cout << "*";
      		else cout << " ";
    	}
    	if(i > 1)cout << endl;
    }
}

int main(){
  printEmptyDiamond(5);
  return 0;
}
