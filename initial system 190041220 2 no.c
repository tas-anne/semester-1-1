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
        if(i==pos-1)//oi pos er age boshbe dekhe
        {
            t++;//koyta elements ache ta count korte
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


int main()
{

    struct club *head;
    head=(struct club*)malloc(sizeof(struct club));
    head->year=HEAD_KEY;
    head->revenue=HEAD_KEY;
    head->next=NULL;
    int n;
    printf("La Liga Database Initializing....\n");
    while(1)
    {

        printf("What do you want to do?\n1.Create Club\n2.Delete Club\n3.View club info\n");
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
         else
        {
            printf("La Liga Database Terminating....\n");

            break;
        }
        printf("...................\n");
    }
}

