#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node *root = NULL;
int len;


void append(){
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if(root == NULL) //list is empty
    {
        root=temp;
    }else
    {
        struct node* p;
        p=root;
        while(p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
}

void display(){
    struct node* temp;
    temp = root;
    if(temp == NULL)
    {
        printf("List id empty.\n");
    }
    else
    {
        while (temp != NULL){
            printf("%d -> ", temp->data);
            temp = temp->link;
        }
        printf("\n\n");
    }
}
int main()
{
    append();
    display();

    append();
    display();

    append();
    display();
}