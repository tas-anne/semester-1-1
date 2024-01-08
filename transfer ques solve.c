#include<stdio.h>
#include<stdlib.h>
#define HEAD_KEY -333
struct node
{
    int val;
    struct node *nxt;
};
struct node *head=NULL;
void insert(int val)
{

    struct node *start, *temp;
    start=head;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->val=val;
    temp->nxt=NULL;
    if(head==NULL)
    {
    head=temp;
        return;
    }
    temp->nxt=start;
    head=temp;

}
void transfer(int v)
{
    struct node*start,*prev,*temp;
    start=head;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->val=v;
    while(start!=NULL)
    {
        if(start->val==v)
        {
            prev->nxt=start->nxt;
            free(start);
            start=prev;
        }
        prev=start;
        start=start->nxt;
    }
    temp->nxt=head;
    head=temp;
}
void view()
{
    struct node *start;
    start=head;
    if(start==NULL)
    {
        printf("NO DATA\n");
        return;
    }
    while(start!=NULL)
    {
        printf("%d ",start->val);
        start=start->nxt;
    }

}
int main()
{
    int n,val,v,c;
   insert(2);
   insert(3);
   insert(6);
   insert(3);
   insert(7);
   view();
   scanf("%d",&v);
   transfer(v);
   view();
}

