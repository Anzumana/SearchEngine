#include <string.h>
#include <stdio.h>
#include "testhead.h"
int facultyR(int a){

	if(a==0) return 1;
	a = a * facultyR(a-1);
	return a;
}
	
int main(void){
	printf("%d\n",faculty(6));
	printf("%d\n",facultyR(6));
	return;
//recursion test
}
