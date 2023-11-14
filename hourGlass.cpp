//print hourglass pattern
/*
    Ex:
	  	Input: n = 5 //the height of half pattern
	  	Output:
				*********
				 *******
				  *****
				   ***
				    *
				   ***
				  *****
				 *******
				*********
*/
#include<iostream>
using namespace std;

void printHourGlass(int n){
    int i,j;
    for(i = 1; i <= 2*n-1; i++) cout << "*";
    cout << endl;
    //upper
    for(i = n-1; i >= 1; i--){
        for(j = 1; j <= 2*n-1; j ++){
            if(j >= n-i+1 && j <= n+i-1) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }
    
    //lower
    for(i = 2; i < n; i++){
        for(j = 1; j <= 2*n-1; j ++){
          if(j >= n-i+1 && j <= n+i-1) cout << "*";
          else cout << " ";
        }
        cout << endl;
      }
    for(i = 1; i <= 2*n-1; i++) cout << "*";
    cout << endl;
}

int main(){
  printHourGlass(5);
  return 0;
}
