#include<stdio.h>
#include<stdlib.h>
#define HEAD_KEY -333
int t=1,i;
struct node
{
    int key;
    struct node* next;


};
void insert_node(struct node*head,int key,int pos)
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
    if(head->next==NULL && j!=pos)
    {
        printf("NO SUCH NODE\n");
    }
    else
    {


        temp->next=head->next;
        head->next=temp;
    }


}
void delete_node(struct node*head,int pos)
{
    int j=0;
    struct node*prev;

    while(head->next!=NULL)
    {
        if(j==pos)

            break;

        prev=head;
        head=head->next;
        j++;
    }
    if(head->next==NULL && j!=pos)
    {
        printf("No such node is found\n");
        return;
    }
    prev->next=head->next;
    free(head);
    t--;
}

void print(struct node*head)
{
    if(head->next==NULL)
    {
        printf("The list is empty\n");
        return;
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
    char ch;
    int n,key,pos;
    struct node *head;
    head=(struct node*)malloc(sizeof(struct node));

    head->key=HEAD_KEY;
    head->next=NULL;


    scanf("%d",&n);
    getchar();
    while(n--)
    {
        scanf("%c",&ch);
        if(ch=='I')
        {
            scanf("%d%d",&pos,&key);
            getchar();
            insert_node(head,key,pos);
        }


        else if(ch=='P')
        {

            print(head);
            getchar();
        }
        else  if(ch=='D')
        {
            scanf("%d",&pos);
            getchar();
            delete_node(head,pos);
        }

    }

}

