//print Diamond full with Alpha
/*
	Ex:
		Input: n = 5 //mean the height of half diamond
		Output:
		        A
		       ABC
		      ABCDE
		     ABCDEFG
		    ABCDEFGHI
		     ABCDEFG
		      ABCDE
		       ABC
		        A
*/
#include<iostream>
using namespace std;

void pintAlphaDiamond(int n){
	int i,j;
  	char alpha = 'A'-1;
  	//upper
  	for(i = 1; i <= n; i++){
    	for(j = 1; j <= 2*n-1; j++){
      		if(j >= n-i+1 && j <= n+i-1){
        		alpha ++;
        		if(alpha > 'Z') alpha = 'A';
        		cout << alpha;
      		}else cout << " ";
    	}
    	alpha = 'A'-1;
    	cout << endl;
  	}
  
  	//lower
  	alpha = 'A'-1;
  	for(i = n-1; i >= 1; i--){
    	for(j = 1; j <= 2*n-1; j++){
      		if(j >= n-i+1 && j <= n+i-1){
        		alpha ++;
        		if(alpha > 'Z') alpha = 'A';
        		cout << alpha;
      		}else cout << " ";
    	}
    	alpha = 'A'-1;
    	if(i > 1) cout << endl;
  	}
}

int main(){
  	int n;
  	pintAlphaDiamond(5);
  	return 0;
}
