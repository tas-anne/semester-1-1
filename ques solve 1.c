#include<stdio.h>
#include<stdlib.h>
#define HEAD_KEY -333
int i,t=1;
struct node
{
int key;
struct node *next;
};
void insert_after(struct node*head,int key,int n)
{
      struct node *temp;

    temp=(struct node*)malloc(sizeof(struct node));
    temp->key = key;
    temp->next = NULL;
    for(i=0; i<t; i++)
    {
        if(i==n)
        {
            t++;
            temp->next=head->next;
            head->next=temp;
            return;
        }
        head=head->next;
    }
    printf("There is no such node\n");

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
    struct node*head;
    int key,n;
    head=(struct node*)malloc(sizeof(struct node));
    head->key=HEAD_KEY;
    head->next=NULL;
    scanf("%d %d",&key,&n);
    insert_after(head,key,n);
    print(head);

}
