#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct node{
	datatype data;
	struct node *next;
}listnode, *linklist;

linklist list_create()
{
	linklist H, p, r;
	H=(linklist)malloc(sizeof(listnode));
	if(NULL==H)
	{
		perror("malloc");
		exit(-1);
	}
	H->data=0;
	H->next=NULL;
	r=H;

	int value;
	while(1)
	{
		printf("input(-1 exit)");
		scanf("%d", &value);
		if(value==-1)
			break;
		else
		{
			p=(linklist)malloc(sizeof(listnode));
			if(NULL==p)
			{
				perror("malloc");
				exit(-1);
			}
			p->data=value;
			p->next=NULL;
			r->next=p;
			r=p;
		}
	}
	return H;
}

int list_order_insert(linklist H, datatype value)
{
	linklist p, q;

	p=(linklist)malloc(sizeof(listnode));
	if(NULL==p)
	{
		perror("malloc");
		exit(-1);
	}
	p->data=value;

	q=H;
	while(q->next && q->next->data<value)
	{
		q=q->next;
	}
	p->next=q->next;
	q->next=p;

	return 0;
}

void list_sort(linklist H)
{
	linklist p, q, r;

	p=H->next;
	H->next=NULL;

	while(p)
	{
		q=p;
		p=p->next;

		r=H;
		while(r->next && r->next->data<q->data)
		{
			r=r->next;
		}
		q->next=r->next;
		r->next=q;
	}
}

void list_show(linklist H)
{
	while(H->next)
	{
		printf("%d ", H->next->data);
		H=H->next;
	}
	puts("");
}

int main(int argc, const char *argv[])
{
	linklist H;
	H=list_create();
	list_show(H);

	list_sort(H);
	list_show(H);

	list_order_insert(H, 20);
	list_show(H);
	list_order_insert(H, 50);
	list_show(H);

	return 0;
}
