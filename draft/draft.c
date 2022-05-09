#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "typeDef.h"



int main()
{
	u8 arr[5];
	int n=0;
	printf("input\n");
	scanf("%[^\n]c",&arr);
	for(int i=0;i< (sizeof(arr));i++){
		if(arr[i]){
			n++;
		}
	}
	printf("%d\n",n );
	return 0;
}