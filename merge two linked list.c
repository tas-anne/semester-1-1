#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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

void merge(struct node*head,struct node*head2)
{
    while(head->next!=NULL)
    {
        head=head->next;
    }
    head->next=head2->next;
}




int main()
{
    struct node *head,*head2;
    head=(struct node*)malloc(sizeof(struct node));
    head2=(struct node*)malloc(sizeof(struct node));
    head->next=NULL;
    head->key=HEAD_KEY;
    head2->next=NULL;
    head2->key=HEAD_KEY;
    insert_tail(head,1);
    insert_tail(head,2);
    insert_tail(head,3);
    insert_tail(head2,3);
    insert_tail(head2,4);

    print(head);
    print(head2);

merge(head,head2);
print(head);


}

