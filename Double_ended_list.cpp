#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void insert_beg(struct Dlist **H,int value);
int delete_beg(struct Dlist **h);
void insert_random(struct Dlist **H,int val,int ele);
int delete_random(struct Dlist **H,int val);
void insert_last(struct Dlist *H,int val);
struct Dlist
{
	int data;
	struct Dlist *prev;
	struct Dlist *next;
};
struct Dlist *createnode()
{
	struct Dlist *n;
	n=(struct Dlist *)malloc(sizeof(struct Dlist));
	return(n);
}
void insert_beg(struct Dlist **H,int value)
{
    struct Dlist *n;
    n=createnode();
    n->data=value;
    n->next=NULL;
    n->prev=NULL;
    if(*H==NULL)
    {
    *H=n;
    }
    else
    {
    n->next=*H;
    (*H)->prev=n;
    *H=n;  	 
    }
}

int delete_beg(struct Dlist **H)
{
	struct Dlist *t;
	int val;
	if(*H==NULL)
	{
	 printf("List is empty\n\n");	
	}
	else
	{
		t=*H;
		val=(*H)->data; 
		if((*H)->next==NULL)
		{
			*H=NULL;
		}
		else
		{
			*H=(*H)->next;
			(*H)->prev=NULL;
		}
		free(t);		
	}
	return(val);	
}
void insert_last(struct Dlist **H,int val)
{
	struct Dlist *t,*node;
	node->data=val;
	node->next=NULL;
	node->prev=NULL;
	if(*H==NULL)
	{
	  *H=node;
	}
	else
	{
	 t=*H;
	 while(t->next!=NULL)
	 {
	 	t=t->next;
	 }
	   t->next=node;
	   node->prev=t;
	}
}
void insert_random(struct Dlist **H,int val,int ele)
{
	 struct Dlist *t,*node;
	 node=(struct Dlist *)malloc(sizeof(struct Dlist));
	 node->data=val;
	 node->next=NULL;
	 node->prev=NULL;
	 if(*H==NULL)
	 {
	 	*H=node;
	 }
	 else
	 {
	 	t=*H;
	 	while(t->data!=ele && t!=NULL)
	 	{
	 	  t=t->next;
		}
		if(t->data==ele)
		{
		node->next=t->next;
		t->next=node;
		node->prev=t;
		(t->next)->prev=node;
	    }
	    else
	    {
	    	printf("Element not found you entered\n");
		}
		
	 }
}
int delete_random(struct Dlist **H,int val)
{
   struct Dlist *t,*n;
   int x=0;
   if(*H==NULL)
   {
  	printf("List is null\n");
   }
   t=*H;
   while(t->next->data!=val)
   {
   	 t=t->next;
   }    
    if(x==val)
    {
    n=t->next;
    x=n->data;
    t->next=n->next;
    (n->next)->prev=t;
    free(n);
   	return(x);
    }
    else
    {
    	printf("Element not found\n");
    	return 0;
	}
}
void display(struct Dlist **H)
{
	struct Dlist *t;
	printf("Elements of the list is:");
	if(*H==NULL)
	{
		printf("List is empty\n\n");
	}
	t=*H;
	while(t!=NULL)
	{
	  printf("%d ",t->data);
	  t=t->next;
	}
	printf("\n\n");
}
int main()
{
	struct Dlist *H=NULL;
	int choice,value,y,ele;
    while(1)
	{
   	  printf("Press 1 to add element at beginning of list\n");
   	  printf("Press 2 to add element at last of list\n");
   	  printf("Press 3 to delete element from beginning of list\n");
	  printf("Press 4 to add element at random position of list\n");
	  printf("Press 5 to delete element from a particulat index of list\n");
	  printf("Press 6 to display the list elements\n");
	  printf("Press 7 to exit from program\n");
	  printf("Enter your choice\n");
	  scanf("%d",&choice);
		switch(choice)
		{
		case 1:
		{
		printf("Enter the value to insert into list\n");
		scanf("%d",&value);
	    insert_beg(&H,value);
		break;
		}
		case 2:
		{
		printf("Enter the element to add\n");
		scanf("%d",&value);
		insert_last(&H,value);
		}
		case 3:
		{
		y=delete_beg(&H);
		printf("Deleted element from rear position is %d\n",y);
		break;
		}
		case 4:
		{
		printf("Enter the value to add into list\n");
		scanf("%d",&value);
		printf("Enter the value after which to add element\n");
		scanf("%d",&ele);
		insert_random(&H,value,ele);			
		break;
     	}
		case 5:
		{
		printf("Enter the element to delete\n");
		scanf("%d",&ele);
		y=delete_random(&H,ele);
		printf("Popped element is %d\n\n",y);
		break;
	    }
		case 6:
		{
		display(&H);
		break;	
		}	
	    case 7:
	   	{
		exit(0);
		}
		default:
		{
		printf("Invalid input\n");
		}
		}
	}
}