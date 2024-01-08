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
void printReverse(struct node*head)
{
    if(head->next==NULL)
    {
        return;
    }
    head=head->next;
    printReverse(head);
    printf("%d ", head->key);

}
int main()
{
    struct node *head;
    head=(struct node*)malloc(sizeof(struct node));
    head->key=HEAD_KEY;
    head->next=NULL;
    int n,m,key;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d",&key);
            insert_tail(head,key);
        }
        printReverse(head);
       head->next=NULL;//eta na dile 2 nd time ager gula soho print kore
    }

}
