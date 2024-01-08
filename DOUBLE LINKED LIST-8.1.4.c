#include<stdio.h>
#include<stdlib.h>
#define HEAD_KEY -333
int t=1,i;
struct node
{
    int key;
    struct node *nxt;
    struct node *prv;
};
void insert(struct node *head,int key,int pos)
{
    struct node *temp;
  temp=(struct node*)malloc(sizeof(struct node));
    temp->key = key;
    temp->nxt = NULL;
    for(i=0; i<t; i++)
    {
        if(i==pos-1)
        {
            t++;
            temp->nxt=head->nxt;
            head->nxt=temp;
            temp->prv=head;
            if(temp->nxt!=NULL)
            temp->nxt->prv=temp;
            return;
        }
        head=head->nxt;
    }
    printf("There is no such node\n");

}

void delete_node(struct node *head, int pos)
{
    int j=0;
    struct node *prev;
    while(head->nxt!=NULL)
    {
        if(j==pos)
            break;
        prev=head;
        head=head->nxt;
        j++;
    }
    if(head->nxt==NULL&&j!=pos)
    {
        printf("There is no such node\n");
        return;
    }
    prev->nxt=head->nxt;
    if(head->nxt!=NULL)
        head->nxt->prv=prev;
    free(head);
    t--;
}

void print(struct node *head)
{
    if(head->nxt==NULL)
    {

        printf("The linked list is empty\n");
        return;
    }
    while(head->nxt!=NULL)
    {
        head=head->nxt;
        printf("%d ",head->key);
    }
    printf("\n");


}

void print_reverse(struct node *head)
{
    if(head->nxt==NULL)
    {
      printf("The linked list is empty\n");
      return;
    }
    while(head->nxt!=NULL)
        head=head->nxt;
    while(head->prv!=NULL)
    {
        printf("%d ",head->key);
        head=head->prv;
    }
    printf("\n");

}

void insert_back(struct node *head,int key,int pos)
{
    struct node *temp;

    temp=(struct node*)malloc(sizeof(struct node));
    temp->key = key;
    temp->nxt = NULL;


    while(head->nxt!=NULL)
    head=head->nxt;

    for(i=0; i<t; i++)
    {
        if(i==pos-1)
        {
            t++;
            temp->nxt=head->nxt;
            head->nxt=temp;
            temp->prv=head;
            if(temp->nxt!=NULL)
                temp->nxt->prv=temp;
            return;
        }
        head=head->prv;
    }
    printf("There is no such node\n");

}

void finish(struct node *head, int pos)
{
    int j=1;
    struct node *prev;

    while(head->nxt!=NULL)
     head=head->nxt;
    while(head->prv!=NULL)
    {
        if(j==pos)
        {
        prev=head->prv;
        break;
        }

        head=head->prv;
        j++;
    }
    if(head->nxt==NULL&&j!=pos)
    {
        printf("There is no such node\n");
        return;

    }
    prev->nxt=head->nxt;
    if(head->nxt!=NULL)
    head->nxt->prv=prev;
    free(head);
    t--;
}


int main()
{
    char ch;
    int n,key,pos,val;
    struct node *head;


    head=(struct node*)malloc(sizeof(struct node));
    head->key=HEAD_KEY;
    head->nxt=NULL;
    head->prv=NULL;

    scanf("%d",&n);
    getchar();
    while(n--)
    {
        scanf("%c",&ch);

        if(ch=='I')
        {
            scanf("%d%d",&pos,&key);
            getchar();
            insert(head,key,pos);
        }
        else if(ch=='P')
        {
            print(head);
            getchar();
        }
        else if(ch=='D')
        {
            scanf("%d",&pos);
            getchar();
            delete_node(head,pos);
        }
        else if(ch=='R')
        {
            getchar();
            print_reverse(head);
        }
        else if(ch=='B')
        {
            scanf("%d%d",&pos,&key);
            getchar();
            insert_back(head,key,pos);
        }
        else if(ch='F')
        {
            scanf("%d",&pos);
            getchar();
            finish(head,pos);
        }

    }
}

