#include<stdio.h>
#include<iostream.h>
typedef struct lnode
{
	int id;
	int Egoal;
	int Cgoal;
	int Mgoal;
	int goal;
	struct lnode *next;
}lnode,*linklist;
void creat(linklist &L)
{
	int i,j,N;
	L=new lnode;
	L->next=NULL;
	lnode *p;
	printf("请输入学生数及各科成绩\n");
	cin>>N;
	for(i=0;i<N;i++)
	{
		p=new lnode;
		p->id=i+1;
		cin>>p->Cgoal;
		cin>>p->Mgoal;
		cin>>p->Egoal;
		p->goal=p->Mgoal+p->Cgoal+p->Egoal;
		p->next=L->next;L->next=p;
	}
	lnode *q,*pe,*qe;
	for(i=0;i<N;i++)
	{	
		pe=L;
	for(j=i;j<N-1;j++)
	{
		if((pe->next->goal)<(pe->next->next->goal))
		{
		qe=pe->next;
		pe->next=qe->next;
		qe->next=pe->next->next;
		pe->next->next=qe;
		}
		pe=pe->next;
	}
	}
	for(i=0;i<N;i++)
	{	
		pe=L;
	for(j=0;j<N-1;j++)
	{
	if(((pe->next->goal)==(pe->next->next->goal))&&((pe->next->Cgoal)<(pe->next->next->Cgoal)))
		{
		qe=pe->next;
		pe->next=qe->next;
		qe->next=pe->next->next;
		pe->next->next=qe;
		}
		pe=pe->next;
	}
	}
	for(i=0;i<N;i++)
	{	
		pe=L;
	for(j=i;j<N-1;j++)
	{
		if(((pe->next->goal)==(pe->next->next->goal))&&((pe->next->Cgoal)==(pe->next->next->Cgoal))
			&&((pe->next->id)>(pe->next->next->id)))
		{
		qe=pe->next;
		pe->next=qe->next;
		qe->next=pe->next->next;
		pe->next->next=qe;
		printf("%d",j);
		}
		pe=pe->next;
	}
	}
	printf("前五名学生学号和总分数为：\n");
	q=L->next;
	for(i=0;i<5;i++)
	{
		printf("%d  ",q->id);
		printf("%d\n",q->goal);
		q=q->next;
	}
}
main()
{ 
	linklist L;
	creat(L);
}