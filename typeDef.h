#include <stdio.h>
#include <stdlib.h>

typedef unsigned char u8;
typedef signed char s8;

typedef unsigned int u32;
typedef signed int s32;

typedef short int s16;
typedef long int li32;
typedef long long int lli64;

typedef float f32;

typedef long double ld128;

typedef struct st_guardian
{
	u8 natID[14];	
	u8 name[50];

}st_guardian;


typedef struct st_account 
{
	u8 access;
	u8 age;
	u8 pass[4];
	s32 balance;
	u8 bankID[10];
	u8 natID[14];
	u8 name[50];	
	u8 address[100];
	st_guardian *adult;
	struct st_account* next;

}st_account;


/* add account functions*/
void underAge(st_account *x, st_guardian *y);
void appendAdult(st_account *x);
void getInfo(st_account *x);     
void pbaGenerator(st_account *x);
void printInfo();


/* validations*/
int validID(u8 *x);
int validBankID(u8 *x);
int repeatID(u8 *x, u8 *y);


/* user functions */
void append();
void addAccount(st_account *x);
void getCash(st_account *x, u32 amount);
void deposit(st_account *x, u32 amount);
void transaction(st_account *x,st_account *y, u32 amount);
void changePass(st_account *x);
void money();
void admin();
void adminUser(st_account *account);
void changeAccess(st_account *account);
void deleteAccount(st_account *account);

/* search functions*/
st_account* searchId(u8 *id); 
st_account* login();
