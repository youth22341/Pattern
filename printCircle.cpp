//print Circle with center point (a,b) and Radius R
/*
	Ex:
		Input: a = 10, b = 10, R = 8;
		Output:
		
			                    **
			              **************
			          **********************
			        **************************
			        **************************
			      ******************************
			      ******************************
			      ******************************
			    **********************************
			      ******************************
			      ******************************
			      ******************************
			        **************************
			        **************************
			          **********************
			              **************
			                    **
*/
#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.1415926535
#define MAX 20

void printCircle(int a, int b, int R){
	int i,j;
	for(i = 0; i < MAX; i++){
		for(j = 0; j < MAX; j++){
			if((a-i)*(a-i) + (b-j)*(b-j) <= R*R) cout << "**";
			else cout << "  ";
		}
		if(i < MAX-1) cout << endl;
	}
}

int main(){
    printCircle(10,10,8);
    return 0;
}
