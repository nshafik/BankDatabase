#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "typeDef.h"
extern st_account *root ;


void append(){
	st_account* temp;
    temp = (st_account*)malloc(sizeof(st_account));
    addAccount(temp);

    temp->next = NULL;
    if(root == NULL) //list is empty
    {
        root=temp;
    }else
    {
    	st_account* p;
        p=root;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}


void addAccount(st_account *x){
	int i=0;
	getInfo(x);
	pbaGenerator(x);
	if((x->age)  <= 21){
		appendAdult(x);
	}
}
void appendAdult(st_account *x){
	st_guardian* temp = malloc(sizeof(st_guardian));
   	underAge(x,temp);
}

void underAge(st_account *x, st_guardian *y){
	x->adult = y;

	do{
		printf("Please enter adult National ID: ");
		scanf(" %s", &(x->adult->natID));	
		
	}while(!validID((x->adult->natID)));
	

	printf("Please enter Adult Name: ");
	scanf("\n %[^\n]c",&(x->adult->name));
	printf("so\n");

}


void getInfo(st_account *x){
	do{

		printf("Please enter National ID: ");
		scanf(" %s", &(x->natID));
	}while(!validID(x->natID));

	printf("Please enter Name: ");
	scanf(" %[^\n]c", &(x->name));

	printf("Please enter Age: ");
	scanf(" %d", &(x->age));
	printf("Please enter Address: ");
	scanf(" %d", &(x->address));

}


void printInfo(){
	st_account* temp;
    temp = root;
    if(temp == NULL)
    {
        printf("List id empty.\n");
    }
    else
    {
        while (temp != NULL){
			printf("Access:%s",temp->access);
			printf("Name:%s",temp->name);
			printf("\nNat ID:");
			for (int j = 0; j < 14; ++j)
			{
				printf("%c",temp->natID[j]);	
			}
			printf("\nAge: %d",temp->age);
			if (temp->age <21)
				{
					printf("\nAdult name: %s ",temp->adult->name );
					printf("\nAdult Nat ID:");
					 for (int j = 0; j < 14; ++j)
					 {
					 	printf("%c",temp->adult->natID[j]);	
					 }
				}	

			printf("\nBank ID: ");
			for (int j = 0; j < 10; ++j)
			{
				printf("%d",temp->bankID[j]);	
			}
		

			printf("\npassword: ");
			for (int j = 0; j < 4; ++j)
			{
				printf("%d",temp->pass[j]);	
			}
			
			printf("\nAddress: %s", temp->address);
			printf("\nBalance: %s", temp->balance);

		temp = temp->next;
		printf("\n\n");

		}		
	}
}

void admin(){
	u8 func;
	st_account *x;
	while(1){
		printf("Please select function\n");
		printf("'e' main menu, 'a' to create new account, 'u' to open an existing user account\n");

		scanf(" %c",&func);
		if (func == 'e')
		{
			break;
		}
		switch(func){
	 		case 'a':
	 			append();
				printInfo();
				break;					

			case 'u':
				x=login();
				adminUser(x);
				break;

			default:
				printf("Not a valid function\n");

		}
				
	}

}

void changeAccess(st_account *account){
	account->access ^=1;
}

void adminUser(st_account *account){
	u8 func,flag=0;
	while(1){
		printf("Please select function\n");
		printf("'e' main menu, 'a' to change access, 'o' for other functions\n");
		scanf(" %c",&func);
		if (func == 'e')
		{
			break;
		}
		switch(func){
			case 'a':
				changeAccess(account);
				flag=1;
				break;
			
			case 'd':
				deleteAccount(account);
				flag=1;
				printInfo();
				break;

			case 'o':
				money(account);
				break;
			default:
				printf("not a valid function \n");
		}
		if (flag==1)
		{
			break;
		}
		
	}
}

void deleteAccount(st_account *account){
	st_account *temp;
    temp = root;
	while ( temp->next !=NULL)
	{
		
		if (temp->next==account)
		{
			temp->next=temp->next->next;

			break;
		}

		temp=temp->next;
		
	}
	
	if (account==temp)
	{
		root=root->next;
	}
}