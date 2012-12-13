include "testhead.h"
int faculty(int a){
	int result=1;
	if(a==0){
		return 1;
	}
	while(a>0){
		result = result * a;
		a--;
	}
	return result;
}

