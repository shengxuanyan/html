#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node
{
	int num;
	int coff;
	struct node *next;
}ploynomial;
ploynomial *input_()
{
	ploynomial *head,*p1,*p2;
	int a,b,count;
	int i=0;
	printf("请输入你要输入的多项式的项数并按回车键\n");
	scanf("%d",&count);
	if(count<=0)
	{
		printf("Error");
		exit(0);
	}
	head=(ploynomial *)malloc(sizeof(ploynomial));
	p2=head; 
	printf("请输入你要输入的多项式的系数和指数,形式如a,b(a^b）每输完一项按回车键\n");
	printf("ps：输入完成后也按回车键\n");
	scanf("%d,%d",&head->num,&head->coff);
	for(i=1;i<count;i++)
	{	
		p1=(ploynomial *)malloc(sizeof(ploynomial));
		scanf("%d,%d",&a,&b);
		p1->num=a;
	    p1->coff=b;
		p2->next=p1;
		p2=p1;
	}
	p2->next=NULL;
	return head;
}
int print_(ploynomial *head)
{
	ploynomial *q,*y;
	q=head;
	y-head;
	int cou=0;
	for(y=head;y!=NULL;y=y->next)
	{
		cou+=y->num;
	}
	if(cou==0)
	  printf("%d",cou);
	if(q->num>0&&q->num!=1)
	{
		if(q->coff!=0)
		{
			if(q->coff!=1)
			{
			printf("%d",q->num);
	        printf("X^");
	        printf("%d",q->coff);
	        }
	        else
	        {
	        	printf("%d",q->num);
	            printf("X");
			}
		}
		else
		    printf("%d",q->num);
		
    }
    else if(q->num==1)
    {	if(q->coff!=0)
		{
			if(q->coff!=1)
			{
	        printf("X^");
	        printf("%d",q->coff);
	        }
	        else
	        {
	        printf("X");	
			}
		}
		else
		    printf("1");
	}
    else if(q->num<0&&q->num!=-1)
    {
    	if(q->coff!=0)
		{
			if(q->coff!=1)
			{
			printf("%d",q->num);
	        printf("X^");
	        printf("%d",q->coff);
	        }
	        else
	        {
	        printf("%d",q->num);
	        printf("X");	
			}
		}
		else
		    printf("%d",q->num);
	}
	else if(q->num==-1)
	{
		if(q->coff!=0)
		{
			if(q->coff!=1)
			{
	        printf("-X^");
	        printf("%d",q->coff);
	        }
	        else
	        {
	         printf("-X");	
			}
		}
		else
		    printf("-%d",q->num);
	}
	while(1)
	{
		q=q->next;
		if(q == NULL)
		return 0;
		if(q->num>0&&q->num!=1)
	{
		if(q->coff!=0)
		{
			if(q->coff!=1)
			{
			printf("+%d",q->num);
	        printf("X^");
	        printf("%d",q->coff);
	        }
	        else
	        {
	        printf("+%d",q->num);
	        printf("X");	
			}
		}
		else
		    printf("+%d",q->num);
		
    }
    else if(q->num==1)
    {	if(q->coff!=0)
		{
			if(q->coff!=1)
		{
	        printf("+X^");
	        printf("%d",q->coff);
	    }
	    else
	    {
	    	printf("+X");
		}
		}
		else
		    printf("+1");
	}
     else if(q->num<0&&q->num!=-1)
    {
    	if(q->coff!=0)
		{
			if(q->coff!=1)
			{
			printf("%d",q->num);
	        printf("X^");
	        printf("%d",q->coff);
	        }
	        else
	        {
	        printf("%d",q->num);
	        printf("X");	
			}
		}
		else
		    printf("%d",q->num);
	}
	else if(q->num==-1)
	{
		if(q->coff!=0)
		{
			if(q->coff!=1)
			{
	        printf("-X^");
	        printf("%d",q->coff);
	        }
	        else
	        {
	        printf("-X");	
			}
		}
		else
		    printf("-%d",q->num);
	}
	}
	return 0;
}
void addl(ploynomial *head)
{
	ploynomial *p,*p1;
	p = head;
	p1 = head;
	while(1)
	{
		p1=p->next;
		if(p1 == NULL)
		{
			return;
		}
		if(p->coff==p1->coff)
		{
			p->num += p1->num;
			p->next=p1->next;
			if(p->next == NULL)
			{
				return;
			}
			if(p->coff == p->next->coff)
			{
				continue;
			}
		}
		p=p->next;
		if(p==NULL)
			break;
	}
}
ploynomial *pai_(ploynomial *head)
{
	ploynomial *p,*p1,*p2;
	p=p2=head;
	int N;
	int l;
	for(p=head;p!=NULL;p=p->next)
	{
		for(p1=p->next;p1!=NULL;p1=p1->next)
		{
			if(p->coff>p1->coff)
			{
				N=p->coff;
				l=p->num;
				p->coff=p1->coff;
				p->num=p1->num;
				p1->coff=N;
				p1->num=l;
			}
		}
	}
	return p2;
}
int main()
{
	ploynomial *head1,*head2;
	int cc;
	long int d;
	head1 = input_();
	head2=pai_(head1);
	addl(head2);
	printf("你输入的一元多项式为: ");
	print_(head2);

}


