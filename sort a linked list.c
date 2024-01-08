#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define HEAD_KEY -333
struct node
{
    struct node* next;
    int key;
};
void insert_sort(struct node*head,int k)
{
    struct node*p1=NULL;
    struct node*p2=head->next;
    for( ;p2->key<k;p2=p2->next)
    {
        p1=p2;
        if(p2->next==NULL)
        {
            p2=p2->next;
            break;
        }
    }
    struct node*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->key=k;
    temp->next=p2;
    if(p1==NULL)
    {
        head->next=temp;
    }
    else
    {
        p1->next=temp;
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
int main()
{
    struct node *head;
    head=(struct node*)malloc(sizeof(struct node));
    head->next=NULL;
    head->key=HEAD_KEY;
    int k;
    scanf("%d",&k);
    insert_sort(head,k);
    print(head);
}

