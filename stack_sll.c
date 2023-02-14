#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int info;
	struct node* link;
};
typedef struct node* NODE;
NODE getnode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("MEMORY NOT AVAILABLE\n");
		exit(0);
	}
	return x;
}
NODE insert_front(NODE first,int elem)
{
	NODE temp;
	temp=getnode();
	temp->info=elem;
	temp->link=first;
	return temp;
}
NODE delete_front(NODE first)
{
	NODE next;
	if(first==NULL)
	{
		printf("Deletion not possible\n");
		return NULL;
	}
	if(first->link==NULL)
	{
		printf("The deleted element is %d\n",first->info);
		free(first);
		return NULL;
	}
	next = first->link;
	printf("The deleted element is %d\n",first->info);
	free(first);
	return next;
}
void display(NODE first)
{
	if(first==NULL)
	{
		printf("No elements to display\n");
	}
	else
	{
		printf("Displayig the elements of SLL:\n");
		while(first!=NULL)
		{
			printf("%d\t",first->info);
			first=first->link;
		}
		printf("\n");
	}
}
int main()
{
	int op,elem;
	NODE first;
	first=NULL;
	while(1)
	{
		printf("Enter an option\n");
		printf("1:push\n2:pop\n3:display\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
			printf("Enter an element to be inserted\n");
			scanf("%d",&elem);
			first= insert_front(first,elem);
			break;
			case 2:
			first=delete_front(first);
			break;
			case 3:
			display(first);
			break;
			default :
			printf("invalid option\n");
			return 0;
		}
	}
	return 0;
}

