#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "typeDef.h"

extern st_account *root ;



int validID(u8 *x){
	int n=0,i=0;
	while( (x[i])){
		if((x[i]) && ((x[i])-'0') <=9 && ((x[i])-'0') >=0){
			n++;
		}
	i++;
	}
	if(n!=14){
		printf("not validID\n" );
		return 0;
	}
	else{
		return 1;
	}

}
int validBankID(u8 *x){
	int n=0,i=0;
	while( (x[i])){
		if((x[i]) && ((x[i])-'0') <=9 && ((x[i])-'0') >=0){
			n++;
		}
	i++;
	}
	if(n!=10){
		printf("not validID\n" );
		return 0;
	}
	else{
		return 1;
	}

}

void pbaGenerator(st_account *x){
	x->access=1;
	x->balance=0;
	srand(time(NULL));   

	for (int i = 0; i < 4; ++i)
	{
		x->pass[i] = rand()%10; 
	}

		for (int j = 0; j < 10; ++j)
		{
			x->bankID[j]  = rand()%10; 
		}

}


st_account* searchId(u8 *id){
	st_account* temp;
    temp = root;
    if(temp == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        while (temp != NULL){        	

			if(repeatID(temp->bankID , id )){
				return(temp);
			}
			temp = temp->next;
		}
	}
	return(0);
}


int repeatID(u8 *x, u8 *y){

	for (int i = 0; i < 10; ++i)
	{
		if (x[i]!=y[i]-'0')
		{
			return 0;
		}
	}
	return 1;
}

