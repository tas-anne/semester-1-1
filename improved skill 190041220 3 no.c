#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define HEAD_KEY -333
int t=1,i;
struct club
{
    int year,revenue;
    char name[100];
    struct club *next;


};
void insert(struct club *head)
{
    char arr[100];
    int a,r,pos;
    struct club *temp;
    temp=(struct club*)malloc(sizeof(struct club));
    printf("Enter name:");
    gets(arr);
    printf("Enter Year of formation:");
    scanf("%d",&a);
    getchar();
    printf("Yearly revenue in million Euros:");
    scanf("%d",&r);
    getchar();
    printf("Enter Position in list:\n");
    scanf("%d",&pos);
    getchar();
    strcpy(temp->name,arr);//as it is string
    temp->year=a;
    temp->revenue=r;
    temp->next=NULL;
    for(i=0; i<t; i++)
    {
        if(i==pos-1)
        {
            t++;
            temp->next=head->next;
            head->next=temp;
            return ;
        }
        head=head->next;
    }

    printf("NO SUCH NODE\n");

}
void delete_node(struct club *head)
{
    char arr[100];
    printf("Enter Name of The club to remove : ");
    gets(arr);
    struct club *prev;

    while(head->next!=NULL)
    {
        if(strcmp(head->name,arr)==0)
            break;

        prev=head;
        head=head->next;
    }
    if(head->next==NULL && strcmp(head->name,arr)!=0)
    {
        printf("No such node is found\n");
        return;
    }
    prev->next=head->next;
    free(head);
    t--;
}
void view(struct club *head)
{
    if(head->next==NULL)
    {
        printf("No clubs to show!\n");
        return;
    }



    printf("Showing Club List:\n");
    while(head->next != NULL)
    {
        head = head->next;
        printf("%s\n",head->name);
        printf("%d\n",head->year);
        printf("%d\n",head->revenue);


    }
}
swap(struct club *head,int pos1,int pos2)
{
    int temp;
    int c1=0, c2=0;
    struct club *club1=head;
    struct club *prev1=NULL;
    struct club *club2=head;
    struct club *prev2=NULL;
    if(head==NULL || head->next==NULL)
    {
        printf("Not found clubs to swap\n");
        return head;
    }
    else if(pos1==pos2)
    {
        printf(" Not necessary to swap\n");
        return head;
    }
    else
    {
        if(pos1>pos2)
        {
            temp=pos1;
            pos1=pos2;
            pos2=temp;
        }
        while(club1!=NULL && c1<pos1)
        {
            prev1=club1;
            club1=club1->next;
            c1++;
        }
        if(club1==NULL)
        {
            printf("Invalid First position\n");
            return head;
        }
        while(club2!=NULL && c2<pos2)
        {
            prev2 = club2;
            club2 = club2->next;
            c2++;
        }
        if(club2 == NULL)
        {
            printf("Invalid Second position\n");
            return head;
        }
        if(prev1==NULL)
        {
            if(club1->next==club2)
            {
                club1->next = club2->next;
                club2->next = club1;
                head=club2;
                return head;
            }
            else
            {
                struct club *next1 = club1->next;
                club1->next = club2->next;
                prev2->next = club1;
                club2->next =  next1;
                head = club2;
                return head;
            }
        }
        else
        {
            if(club1->next==club2)
            {
                club1->next=club2->next;
                club2->next=club1;
                prev1->next=club2;
                return head;
            }
            else
            {
                struct club *next1=club1->next;
                club1->next=club2->next;
                prev2->next=club1;
                club2->next=next1;
                prev1->next=club2;
                return head;
            }
        }
    }
}
int main()
{
    int n,pos1,pos2;
    struct club *head;
    head=(struct club*)malloc(sizeof(struct club));
    head->year=HEAD_KEY;
    head->revenue=HEAD_KEY;
    head->next=NULL;

    printf("La Liga Database Initializing....\n");
    while(1)
    {

        printf("What do you want to do?\n1.Create Club\n2.Delete Club\n3.View club info\n4.Swap\n");
        printf("Choice:\n");
        scanf("%d",&n);
        getchar();
        if(n==1)
        {
            insert(head);
        }
        else  if(n==2)
        {
            delete_node(head);
        }
        else if(n==3)
        {
            view(head);
        }
        else if(n==4)
        {
            struct player *temp=head->next;
            printf("Which two positions do you want to swap?\n");
            scanf("%d %d", &pos1, &pos2);
            swap(head, pos1, pos2);
        }
        else
        {
            printf("La Liga Database Terminating....\n");

            break;
        }
        printf("...................\n");
    }
}


