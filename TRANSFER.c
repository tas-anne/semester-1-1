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
void transfer(struct node*head,int v)
{
    struct node*start,*prev,*temp;
    start=head;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->key=v;
    while(start!=NULL)
    {
        if(start->key==v)
        {
            prev->next=start->next;
            free(start);
            start=prev;
        }
        prev=start;
        start=start->next;
    }
    temp->next=head->next;
    head=temp;
}
void print(struct node*head)
{
    if(head->next==NULL)
    {
        printf("The list is empty");
    }
    while(head->next!=NULL)
    {

        printf("%d ",head->key);
         head=head->next;



    }
    printf("\n");
}

int main()
{
    struct node *head;
    head=(struct node*)malloc(sizeof(struct node));
    head->next=NULL;
    head->key=HEAD_KEY;
    int p;
    int q,v;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&p);
        insert_tail(head,p);

    }

    print(head);
    scanf("%d",&v);
    transfer(head,v);
    print(head);

}
