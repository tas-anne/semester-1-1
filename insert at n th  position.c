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
void insert_middle(struct node*head,int key,int pos)
{
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->key=key;
    temp->next=NULL;
    int j=1;
    while(head->next!=NULL)
    {
        if(j==pos)
        {
            break;
        }
        head=head->next;
        j++;
    }
    temp->next=head->next;
    head->next=temp;


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
    int p,q,pos,u;
    scanf("%d",&p);
    while(p--)
    {
        scanf("%d",&q);
        insert_tail(head,q);

    }
    scanf("%d",&u);
    scanf("%d",&pos);
    insert_middle(head,u,pos);
     print(head);
}
