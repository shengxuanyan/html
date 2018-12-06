
六．附录：源代码（电子版）
一、

#include<stdio.h>
#include<stdlib.h>
typedef struct link
{
    int code;
    int N;
    struct link *next;
}circle;
circle  *create()
{
    circle *p,*q;
    circle *head;
    int number,i,count,num=1;
    count = 1;
    printf("«Î ‰»Î»À ˝:\n");
    scanf("%d",&number);
    if(number<=0)
    {
        printf("Error");
        exit(0);
    }
    getchar();
    if(number < count)
    {
        printf("Error");
        exit(0);
    }
    head=(circle *)malloc(sizeof(circle));
    head->code=99999;
    p=(circle *)malloc(sizeof(circle));
    head->next=p;
    q=p;
    printf("«Î ‰»Îµ⁄%d∏ˆ»Àµƒ√‹¬Î:",count);
    scanf("%d",&p->code);
    p->N=num;
    for(count=2;count<=number;count++)
    {
        p=(circle *)malloc(sizeof(circle));
        printf("«Î ‰»Îµ⁄%d∏ˆ»Àµƒ√‹¬Î:",count);
        scanf("%d",&p->code);
        num++;
        p->N=num;
        q->next=p;
        q=p;
    }
    q->next=head;
    printf("–≈œ¢“—¥Ê»Î≥…π¶£°\n");
    return head;
}
void reverse(circle *head)
{
    circle *p1,*q1,*flag;
    p1=head->next;
    q1=head->next;
    p1=p1->next;
    flag=p1->next;
    p1->next=head;
    p1=flag;
    while(flag!=head)
    {
        flag=p1->next;
        p1->next=q1->next;
        q1->next=p1;
        p1=flag;
    }
    
}
void print_(circle *head)
{
    circle *q;
    int numbers=0;
    q=head->next;
    printf(" ID      ***Password***\n");
    while(q->next!=head)
    {
        printf(" %d         %d\n",++numbers,q->code);
        q=q->next;
    }
    printf(" %d         %d\n",++numbers,q->code);
}

void delecte_(circle *head,circle *del)
{
    circle *p,*q,*f;
    p=head;
    q=del;
    while(p->next!=q)
    {
        p=p->next;
    }
    f=p;
    f->next=q->next;
}
int out_(circle *head)
{
    int password;
    int count;
    circle *p,*q,*h;
    p=h=head;
    printf("«Î ‰»Î≥ı º√‹¬Î÷µ:");
    scanf("%d",&password);
    while(1)
    {
        for(count=1;count<=password;count++)
        {
            p=p->next;
            q=p;
            if(q->code==99999)
            {
                q=q->next;
                p=q;
            }
        }
        if(p!=p->next)
        {
            password=q->code;
            printf("µ⁄%d∏ˆ»À“—≥ˆ¡–£¨√‹¬Î£®%d)\n",q->N,q->code);
            p=q;
            delecte_(h,q);
        }
        else
            return 0;
    }
    
}

main()
{
    circle *p1;
    int judge;
    p1=create();
    print_(p1);
    printf("«Î ‰»Î ˝◊÷°Æ1°ØÀ≥ ±’Î◊™£ª∑Ò‘Ú ‰»Î°Æ0°ØƒÊ ±’Î◊™: ");
    scanf("%d",&judge);
    if(judge==1)
        out_(p1);
    else
    {
        reverse(p1);
        out_(p1);
    }
    
    return 0;
}

二、一元多项式的输入输出

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
    printf("«Î ‰»Îƒ„“™ ‰»Îµƒ∂‡œÓ ΩµƒœÓ ˝≤¢∞¥ªÿ≥µº¸\n");
    scanf("%d",&count);
    if(count<=0)
    {
        printf("Error");
        exit(0);
    }
    head=(ploynomial *)malloc(sizeof(ploynomial));
    p2=head;
    printf("«Î ‰»Îƒ„“™ ‰»Îµƒ∂‡œÓ Ωµƒœµ ˝∫Õ÷∏ ˝,–Œ Ω»Áa,b(a^b£©√ø ‰ÕÍ“ªœÓ∞¥ªÿ≥µº¸\n");
    printf("ps£∫ ‰»ÎÕÍ≥…∫Û“≤∞¥ªÿ≥µº¸\n");
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
    {    if(q->coff!=0)
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
        {    if(q->coff!=0)
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
    printf("ƒ„ ‰»Îµƒ“ª‘™∂‡œÓ ΩŒ™: ");
    print_(head2);
    
}




三
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int num;
    int coff;
    struct node *next;
}ploynomial;
ploynomial *input_(int N)
{
    ploynomial *head,*p1,*p2;
    int a,b,c,count;
    c=N;
    int number=1;
    printf("«Î ‰»Îƒ„“™ ‰»Îµƒµ⁄%d∏ˆ∂‡œÓ ΩµƒœÓ ˝≤¢∞¥ªÿ≥µº¸\n",c);
    scanf("%d",&count);
    if(count<=0)
    {
        printf("Error");
        exit(0);
    }
    p2=(ploynomial *)malloc(sizeof(ploynomial));
    head=p2;
    printf("«Î ‰»Îƒ„“™ ‰»Îµƒµ⁄%d∏ˆ∂‡œÓ Ωµƒœµ ˝∫Õ÷∏ ˝,–Œ Ω»Áa,b(a^b£©√ø ‰ÕÍ“ªœÓ∞¥ªÿ≥µº¸\n",c);
    printf("ps£∫ ‰»ÎÕÍ≥…∫Û“≤∞¥ªÿ≥µº¸\n",c);
    scanf("%d,%d",&a,&b);
    head->num=a;
    head->coff=b;
    while(1)
    {
        if(count==1)
            break;
        p1=(ploynomial *)malloc(sizeof(ploynomial));
        scanf("%d,%d",&a,&b);
        if(a==0)
        {
            printf("ERROR");
            exit(0);
            
        }
        p1->num=a;
        p1->coff=b;
        number++;
        p2->next=p1;
        p2=p1;
        if(number==count)
            break;
    }
    p2->next=NULL;
    return head;
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
int print_(ploynomial *head)//∏ƒΩ¯∞Ê
{
    ploynomial *q,*y,*p;
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
    {    if(q->coff!=0)
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
        p=q;
        q=q->next;
        if(q == NULL)
            return 0;
        if(q->num>0&&q->num!=1)
        {
            if(q->coff!=0)
            {
                if(q->coff!=1)
                {
                    if(p->num==0)
                    {
                        printf("%d",q->num);
                        printf("X^");
                        printf("%d",q->coff);
                    }
                    else
                    {
                        printf("+%d",q->num);
                        printf("X^");
                        printf("%d",q->coff);
                    }
                }
                else
                {
                    if(p->num==0)
                    {
                        printf("%d",q->num);
                        printf("X");
                    }
                    else
                    {
                        printf("+%d",q->num);
                        printf("X");
                    }
                }
            }
            else
            {
                if(p->num==0)
                {
                    printf("%d",q->num);
                }
                else
                    printf("+%d",q->num);
            }
        }
        else if(q->num==1)
        {    if(q->coff!=0)
        {
            if(q->coff!=1)
            {
                if(p->num==0)
                {
                    printf("X^");
                    printf("%d",q->coff);
                }
                else
                {
                    printf("+X^");
                    printf("%d",q->coff);
                }
            }
            else
            {
                if(p->num==0)
                {
                    printf("X");
                }
                else
                {
                    printf("+X");
                }
            }
        }
        else
        {
            if(p->num==0)
            {
                printf("1");
            }
            else
                printf("+1");
        }
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
ploynomial *add_(ploynomial *head1,ploynomial *head2)//Ω´µ⁄∂˛∏ˆ∂‡œÓ Ωº”‘⁄µ⁄“ª∏ˆ∂‡œÓ Ω∫Û±ﬂ
{
    ploynomial *p1,*p2,*change,*header;
    p1=head1;
    p2=head2;
    header=head1;
    for(p1=head1;p1!=NULL;p1=p1->next)
    {
        change=p1;
    }
    change->next=p2;
    return header;
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
ploynomial *minus_(ploynomial *head1,ploynomial *head2)//Ω´µ⁄∂˛∏ˆ∂‡œÓ Ωœ‡∑¥ ˝º”‘⁄µ⁄“ª∏ˆ∂‡œÓ Ω∫Û±ﬂ
{
    ploynomial *p1,*p2,*p3,*change,*header;
    p1=head1;
    p2=p3=head2;
    header=head1;
    for(p1 = head1;p1 != NULL;p1 = p1->next)
    {
        change = p1;
    }
    for(p3 = head2;p3 != NULL;p3 = p3->next)
    {
        p3->num=-p3->num;
    }
    change->next=p2;
    return header;
}

ploynomial *multi_(ploynomial *head1,ploynomial *head2)
{
    ploynomial *p1,*p2,*p3,*p4,*header,*q;
    p1=head1;
    p2=head2;
    header=p3=(ploynomial *)malloc(sizeof(ploynomial));
    for( p1 = head1;p1!=NULL;p1 = p1->next)
    {
        for( p2 = head2;p2!=NULL;p2 = p2->next)
        {
            p3->num=p1->num*p2->num;
            p3->coff=p1->coff+p2->coff;
            p4=(ploynomial *)malloc(sizeof(ploynomial));
            p3->next=p4;
            p3=p4;
        }
    }
    p3->next=NULL;
    q=header;
    while(q->next->next!=NULL)
    {
        q=q->next;
        
    }
    q->next=NULL;
    return header;
}

char choose()
{
    char s;
    printf("«Î ‰»Îƒ„œÎ“™µ⁄“ª∏ˆ∂‡œÓ Ω∫Õµ⁄∂˛∏ˆ∂‡œÓ ΩΩ¯–– ≤√¥≤Ÿ◊˜£®+£¨-£¨*£©≤¢∞¥ªÿ≥µº¸\n");
    scanf("%c",&s);
    return s;
}
int main()
{
    ploynomial *head1,*head2,*head3,*head4;
    int numbers = 1 ;
    char c;
    head1 = input_(numbers);
    head2 =input_(++numbers);
    fflush(stdin);
    c = choose();
    if(c=='+')
    {
        head3 = add_(head1,head2);
        head4 = pai_(head3);
        addl(head4);
        printf("‘ÀÀ„Ω·π˚Œ™£∫\n");
        print_(head4);
    }
    else if(c=='-')
    {
        head3 = minus_(head1,head2);
        head4 = pai_(head3);
        addl(head4);
        printf("‘ÀÀ„Ω·π˚Œ™£∫\n");
        print_(head4);
    }
    else if(c=='*')
    {
        head3 = multi_(head1,head2);
        head4 = pai_(head3);
        addl(head4);
        fflush(stdin);
        printf("‘ÀÀ„Ω·π˚Œ™£∫\n");
        print_(head4);
    }
    return 0;
}


四、导数
#include<stdio.h>
#include<stdlib.h>
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
    int number=1;
    printf("«Î ‰»Îƒ„“™ ‰»Îµƒ∂‡œÓ ΩµƒœÓ ˝≤¢∞¥ªÿ≥µº¸\n");
    scanf("%d",&count);
    if(count<=0)
    {
        printf("Error");
        exit(0);
    }
    p2=(ploynomial *)malloc(sizeof(ploynomial));
    head=p2;
    printf("«Î ‰»Îƒ„“™ ‰»Îµƒ∂‡œÓ Ωµƒœµ ˝∫Õ÷∏ ˝,–Œ Ω»Áa,b(a^b£©√ø ‰ÕÍ“ªœÓ∞¥ªÿ≥µº¸\n");
    printf("ps£∫ ‰»ÎÕÍ≥…∫Û“≤∞¥ªÿ≥µº¸\n");
    getchar();
    scanf("(%d,%d)",&a,&b);
    head->num=a;
    head->coff=b;
    while(1)
    {
        if(count==1)
            break;
        p1=(ploynomial *)malloc(sizeof(ploynomial));
        scanf("(%d,%d)",&a,&b);
        if(a==0)
        {
            printf("ERROR");
            exit(0);
            
        }
        p1->num=a;
        p1->coff=b;
        number++;
        p2->next=p1;
        p2=p1;
        if(number==count)
            break;
    }
    p2->next=NULL;
    return head;
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
int print_(ploynomial *head)//∏ƒΩ¯∞Ê
{
    ploynomial *q,*y,*p;
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
    {    if(q->coff!=0)
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
        p=q;
        q=q->next;
        if(q == NULL)
            return 0;
        if(q->num>0&&q->num!=1)
        {
            if(q->coff!=0)
            {
                if(q->coff!=1)
                {
                    if(p->num==0)
                    {
                        printf("%d",q->num);
                        printf("X^");
                        printf("%d",q->coff);
                    }
                    else
                    {
                        printf("+%d",q->num);
                        printf("X^");
                        printf("%d",q->coff);
                    }
                }
                else
                {
                    if(p->num==0)
                    {
                        printf("%d",q->num);
                        printf("X");
                    }
                    else
                    {
                        printf("+%d",q->num);
                        printf("X");
                    }
                }
            }
            else
            {
                if(p->num==0)
                {
                    printf("%d",q->num);
                }
                else
                    printf("+%d",q->num);
            }
        }
        else if(q->num==1)
        {    if(q->coff!=0)
        {
            if(q->coff!=1)
            {
                if(p->num==0)
                {
                    printf("X^");
                    printf("%d",q->coff);
                }
                else
                {
                    printf("+X^");
                    printf("%d",q->coff);
                }
            }
            else
            {
                if(p->num==0)
                {
                    printf("X");
                }
                else
                {
                    printf("+X");
                }
            }
        }
        else
        {
            if(p->num==0)
            {
                printf("1");
            }
            else
                printf("+1");
        }
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

void derivative_(ploynomial *head)
{
    ploynomial *p;
    p=head;
    for(p=head;p!=NULL;p=p->next)
    {
        p->num=p->num*p->coff;
        p->coff=p->coff-1;
    }
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
int main()
{
    ploynomial *head1,*head2;
    head1 = input_();
    head2=pai_(head1);
    addl(head2);
    derivative_(head2);
    printf(" ‰»Îµƒ∂‡œÓ Ωµƒµº ˝Œ™: ");
    print_(head2);
}



