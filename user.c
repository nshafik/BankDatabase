#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "typeDef.h"


void changePass(st_account *x){
	printf("Please enter new password: ");
	scanf(" %s", &(x->pass));
}

void getCash(st_account *x, u32 amount){
	(x->balance)-= amount;
	printf("New Balane = %d\n",(x->balance));
}

void deposit(st_account *x, u32 amount){
	(x->balance)+= amount;
	printf("New Balane = %d\n",(x->balance));
}


void transaction(st_account *x,st_account *y, u32 amount){
	getCash(x,amount);
	deposit(y,amount);
}

void money(){
	u8 func;
	u32 amount;
	u8 id[10];
	st_account *x , *y;
	do{
		do{
			printf("Please enter Bank ID: ");
			scanf("%s", &(id)); 
		}while(!validBankID(id));
		x=searchId(id);

		if(!searchId(id))
		{
			printf("Bank ID not found, please try again!\n");
		}
	}while(!searchId(id));

	while(1){
		printf("Please enter function: ");
		printf("'e' main menu, 'p' to change password, 'c' to get cash, 'd' to deposit, 't' to transfer ");

		scanf(" %c", &(func));
		if (func=='e')
		{
			break;
		}

		switch(func){
			case 'p': 
				changePass(x);
				break;

			case 'c':
				printf("Please enter amount: ");
				scanf(" %d", &(amount));
				getCash(x,amount);
				break;

			case 'd':
				printf("Please enter amount: ");
				scanf(" %d", &(amount));
				deposit(x,amount);
				break;

			case 't':
				do{
					printf("Please enter Bank ID: ");
					scanf(" %s", &(id));
				}while(!validBankID(id));
			
				y=searchId(id);
				

				printf("Please enter amount: ");
				scanf(" %d", &(amount));
				transaction(x,y,amount);
				break;


			default:
				printf("Not a valid function\n");

			}

		}

	

}

