#include<stdio.h>
#include<stdlib.h>

#define HEAD_KEY -333

int t=1,i;
struct node
{
    int key;
    struct node *nxt;

};
void insert_middle(struct node*head,int key,int pos)
{
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->key=key;
    temp->nxt=NULL;
    int j=1;
    while(head->nxt!=NULL)
    {
        if(j==pos+1)
        {
            break;
        }
        head=head->nxt;
        j++;
    }
    temp->nxt=head->nxt;
    head->nxt=temp;


}
//OR
void insert(struct node *head,int key,int pos)
{
    struct node *temp;

    temp=(struct node*)malloc(sizeof(struct node));
    temp->key = key;
    temp->nxt = NULL;
    for(i=0; i<t; i++)
    {
        if(i==pos-1)//JOTO TE DIBO TOTOTE BOSHBE
        {
            t++;
            temp->nxt=head->nxt;
            head->nxt=temp;
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
    free(head);
    t--;
}

void update(struct node *head,int val)
{
    int temp;
    while(head->nxt!=NULL)
    {
        head=head->nxt;
        temp=head->key;
        temp=temp+val;
        head->key=temp;
    }
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

int main()
{
    char ch;
    int n,key,pos,val;
    struct node *head;


    head=(struct node*)malloc(sizeof(struct node));
    head->key=HEAD_KEY;
    head->nxt=NULL;


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
        else if(ch=='U')
        {
            scanf("%d",&val);
            getchar();
            update(head,val);
        }
    }


}

