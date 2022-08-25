#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct Node*next;
} Node;

typedef struct
{
Node *head, *tail;}

LinkedList;

 Node*newNode(int val)
 {
     Node*n=malloc(sizeof(Node));
     n->data=val;
     n->next=NULL;
     return n;

 }
 void initLinkedList(LinkedList*list)
 {
     list->head=NULL;
     list->tail=NULL;
 }
 void addHead(LinkedList*list,int value)
 {
     Node*n=newNode(value);
     n->next=list->head;
     list->head=n;
     if(list->tail==NULL)
        list->tail=n;
 }
 int isEmpty(LinkedList *list)
 {
     if (list->head==NULL)
        return 1;
     else
        return 0;
 }

 void addTail(LinkedList *list,int value)
 {

     Node *n=newNode(value);
     if(list->head==NULL)
        list->head=list->tail=n;
     else{
        Node *OldTail=list->tail;
        list->tail=n;
        OldTail->next=n;
     }
 }
 void deleteHead(LinkedList *list)
 {
     Node *first=list->head;
     if(first!=NULL)
     {
         list->head=first->next;
         free(first);
         if(list->head==NULL)
            list->tail=NULL;
     }
 }
 //Delete data from the end of list.
int deleteTail(LinkedList*list)
{
	Node * temp;
	int i = 0;

	int data = 0;

//special case: if there is no tail...
	if(list->tail == NULL)
	{

		return -1;
	}
	else
	{
		temp = list->head;
		//loop till you find the tail then stop before you access it:

		while(temp->next != list->tail)
		{ temp = temp->next;}

		data = list->tail->data;

		list->tail = temp;
		list->tail->next = NULL;
	}

	return data;
}
 void printList(LinkedList*list)
{
	Node * node;

	if(list->head == NULL)
	{
		printf("\nEmpty List");
		return;
	}

	node = list->head;

	printf("\nList: \n\n\t");
	while(node != NULL)
	{
		printf("| %05d |",node->data);
		node = node->next;

		if(node !=NULL)
			printf("--->");
	}
	printf("\n\n");
}

int main()
{
	Node *lp;

	int data = 0;

	lp = (LinkedList *) malloc(sizeof(LinkedList
                                   ));
    initLinkedList(lp);

	addTail(lp,10);
	addTail(lp,20);
	addHead(lp,30);
	addHead(lp,40);

	printList(lp);

	data = deleteTail(lp);

	if(data >= 0)
		printf("\nDeleted data is : %d",data);
	printList(lp);

		data = deleteHead(lp);

	if(data >= 0)
		printf("\nDeleted data is : %d",data);
	printList(lp);

	return 0;
}

