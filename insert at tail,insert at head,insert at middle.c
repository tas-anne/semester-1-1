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
void insert_head(struct node*head,int key)
{
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->key=key;
    temp->next=NULL;
    if(head->next==NULL)
    {
        head->next=temp;
    }
    else
    {

        temp->next=head->next;
        head->next=temp;
    }
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
void max(struct node*head)
{
    int max=-333;
    while(head->next!=NULL)
    {
        if(head->key>max)
        {
            max=head->key;
        }
        head=head->next;
    }
    printf("%d",max);
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
        //insert_head(head,p);
        insert_tail(head,p);

    }
    //insert_tail(head,10);
    print(head);
    max(head);

}
