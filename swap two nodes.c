#include<stdio.h>
#include<stdlib.h>
#define HEAD_KEY -333
struct node
{
    struct node* next;
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
void swap(struct node*head,int x,int y)
{
    if(x==y)
    {
        printf("NO need to swap\n");
        return;
    }
    struct node *currx=head;
    struct node *prevx=NULL;
    struct node *curry=head;
    struct node *prevy=NULL;
    while(currx->next!=NULL)
    {
        if(currx->key==x)
        {
            break;
        }
        prevx=currx;
        currx=currx->next;
    }
    while(curry->next!=NULL)
    {
        if(curry->key==y)
        {
            break;
        }
        prevy=curry;
        curry=curry->next;
    }
    if (currx == NULL || curry == NULL)
        return;

    if(prevx!=NULL)
    {
        prevx->next=curry;
    }
    else
    {
        head->next=curry;//head or tail hole
    }
    if(prevy!=NULL)
    {
        prevy->next=currx;
    }
    else
    {
      head->next=currx;//head or tai hole
    }
    struct node *temp = curry->next;//jodi boro tar pore o  nodes tthake
   curry->next = currx->next;
   currx->next  = temp;
}
int main()
{
    struct node *head;
    head=(struct node*)malloc(sizeof(struct node));
    head->next=NULL;
    head->key=HEAD_KEY;
    insert_tail(head,5);
    insert_tail(head,4);
    insert_tail(head,8);
    insert_tail(head,2);
    print(head);
     int x,y;
    scanf("%d %d",&x,&y);
    swap(head,x,y);
    print(head);


}
