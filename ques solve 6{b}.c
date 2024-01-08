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
    delete_node(head,v);
    print(head);


}
void delete_node(struct node*head,int key)
{
    struct node*prev;
    while(head->next!=key)
    {
        if(head->key==key)
        {

            break;
        }
        prev=head;
        head=head->next;
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
     insert_tail(head,5);
    insert_tail(head,4);
    insert_tail(head,8);
    insert_tail(head,2);
    print(head);

int v;
scanf("%d",&v);
void transfer(head,v);




}
