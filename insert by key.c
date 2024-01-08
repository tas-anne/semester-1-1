#include<stdio.h>
#include<stdlib.h>
#define HEAD_KEY -333
struct node
{
    struct node *next;
    int key;
};
void insert_tail(struct node*head,int key)
{
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->key=key;
    temp->next=NULL;
    while(head->next!=NULL)
    {
        head=head->next;
    }
    head->next=temp;
}
void insert_atK(struct node*head,int key,int k)
{
    struct node*temp,*prev;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->key=key;
    temp->next=NULL;
    while(head->next!=NULL)
    {
        if(head->key==k)
        {
            break;
        }
        prev=head;
        head=head->next;

    }
    prev->next=temp;
    temp->next=head;


}
void print(struct node*head)
{
    if(head->next==NULL)
    {
        printf("The list is empty");
    }
    while(head->next!=NULL)
    {
        head=head->next;
        printf("%d ",head->key);

    }
    printf("\n");
}
int main()
{
    struct node *head;
    head=(struct node*)malloc(sizeof(struct node));
    head->next=NULL;
    head->key=HEAD_KEY;
    int p,q,k,u;
    scanf("%d",&p);
    while(p--)
    {
        scanf("%d",&q);
        insert_tail(head,q);

    }
    scanf("%d",&u);
    scanf("%d",&k);
    insert_atK(head,u,k);
     print(head);
}
