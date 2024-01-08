
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
void delete_node(struct node*head,int key)
{
    struct node*prev;
    while(head->next!=NULL)
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
int count_node(struct node*head)
{
    int count=0;
    while(head->next!=NULL)
    {
        head=head->next;
        count++;
    }
    printf("%d",count);
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
    //count_node(head);
     int k;
    scanf("%d",&k);
    delete_node(head,k);
    print(head);


}
