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
void delete_node(struct node*head,int pos)
{int j=0;
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
    int p;
    int q;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&p);
       insert_tail(head,p);

    }
    int pos;
    scanf("%d",&pos);
   delete_node(head,pos);
    print(head);
}


