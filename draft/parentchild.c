#include <stdio.h>
typedef struct {
	int x;
	int y;
	void * vd_ptr;
}parent;

typedef struct {
	int k;
	int l;
	parent child_parent;
	parent *child_parent_ptr;
}child;

int main() {
	parent parent_1;
	parent *ptr_parent;
	ptr_parent = &parent_1;

	child child_1;

	(parent_1.vd_ptr) = &child_1;    //pointing coid pointer to child_1
	((child*)(parent_1.vd_ptr))->k = 55;//casting before using

	
	printf("child1.k = %d \n", child_1.k);

	ptr_parent->x = 1;
	printf ("%d \n", parent_1.x);
	
	child_1.child_parent = *ptr_parent;
	child_1.child_parent_ptr = ptr_parent; 

	child_1.child_parent.x = 2;
	child_1.child_parent_ptr->x = 3;

	printf("%d \n", ptr_parent->x);
	printf("%d \n", child_1.child_parent.x);



	return 0;
}