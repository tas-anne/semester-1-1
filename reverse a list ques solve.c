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
struct node* rev() //func type struct node
{
    struct node *current, *prev,*nxt;
    prev=NULL;
    current=head;
    while(current!=NULL)
    {
        nxt=current->nxt;
        current->nxt=prev;
        prev=current;
        current=nxt;
    }
    head=prev;

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
   insert(6);
   insert(3);
   insert(7);
   insert(5);
   view();
rev();

}


