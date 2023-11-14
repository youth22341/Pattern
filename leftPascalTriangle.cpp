//print Left Pascal Triangle
/*
    Ex: 
	  	Input: n = 5 //the height of half pattern
	  	Output: 
			  	*
			   **
			  ***
			 ****
			*****
			 ****
			  ***
			   **
			    *
*/
#include<iostream>
using namespace std;

void printLeftPascalTriangle(int n){
    int i,j;
    //upper
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            if(j >= n-i+1) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }
    
    //lower
    for(i = 2; i <= n; i++){
        for(j = n; j >= 1; j--){
            if(j <= n-i+1) cout << "*";
            else cout << " ";
        }
        if(i < n) cout << endl;
    }
}

int main(){
  printLeftPascalTriangle(5);
  return 0;
}
