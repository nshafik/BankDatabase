/*********************
in this section were going to verify the input before saving it in the database
	-natId ==14
	-age > 21
	-age < 21 must have a valid natId of a guardian

**********************/
int validID(st_account *x){
	int n=0;
	for(int i=0;i< 14 ;i++){
		if((x->natId[i]) && ((x->natId[i])-'0') <=9 && ((x->natId[i])-'0') >=0){
			n++;
		}
	}
	if(n){}
	else{
		printf("%s\n", );
	}
	return n;
}