#include <stdio.h>

struct node{
	int data;
	node *next;
};

int main(int argc, const char *argv[])
{
	node *head=new node;
	head->data=0;
	head->next=0;
	node *p=head;

	for(int i=1; i<1000; i++)
	{
		node *tmp=new node;
		tmp->data=i;
		tmp->next=0;
		head->next=tmp;
		head=head->next;
	}
	head->next=p;

	while(p!=p->next)
	{
		p->next->next=p->next->next->next;
		p=p->next->next;
	}
//	cout
	
	return 0;
}
