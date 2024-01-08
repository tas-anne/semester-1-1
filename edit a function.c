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
void edit(struct node*head,int new_node,int key)
{
    while(head->next!=NULL)
    {
        if(head->key==key)
        {
            break;
        }
        head=head->next;
    }
    if(head->next==NULL&&head->key!=key)
    {
        printf("NO such nodes");
        return;
    }
    head->key=new_node;
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
    insert_tail(head,5);
    insert_tail(head,4);
    insert_tail(head,8);
    insert_tail(head,2);
    print(head);
    int new_node,key;
    scanf("%d",&key);
    scanf("%d",&new_node);
    edit(head,new_node,key);
    print(head);

}
