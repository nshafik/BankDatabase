#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "typeDef.h"

st_account *root = NULL;

int main()
{
	u8 mode;


	while(1){
		printf("Please select mode \"a\" for admin \"u\" for user\"e\" to exit\n");
		scanf(" %c",&mode);
		if (mode=='e')
		{
			break;
		}

		if (mode=='a')
		{
			printf("admin mode\n");
			admin();

		}
		else if(mode=='u'){
			printf("user mode\n");
			money();
		}
	}



	return 0;
}



