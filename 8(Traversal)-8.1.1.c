#include<stdio.h>
#include<stdlib.h>
#define HEAD_KEY -333
struct node
{
    struct node* next;
    int key;
};
void insert_node(struct node*head,int key)
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
int main()
{
    struct node *head;
    head=(struct node*)malloc(sizeof(struct node));
    head->next=NULL;
    head->key=HEAD_KEY;
    int n,key;
    char ch;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        scanf("%c",&ch);
        if(ch=='I')
        {
            scanf("%d",&key);
            getchar();
            insert_node(head,key);
        }
        else
        {   getchar();
            print(head);
        }

    }

}








