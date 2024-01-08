
#include<stdio.h>
#include<stdlib.h>
#define HEAD_KEY -333
struct node
{
    struct node *next;
    int key;
};




void insert_node(struct node *head, int key)
{
    struct node *temp;
    temp=(struct node*) malloc(sizeof(struct node));
    temp->key = key;
    temp->next = NULL;

    while(head->next!=NULL)
    {
        head=head->next;
    }
    head->next = temp;
}

void print(struct node *head)
{
    while(head->next!=NULL)
    {
        head= head->next;
        printf("%d ", head->key);

    }
    printf("\n");
}
//important
void print_r(struct node *head)
{
    while(head!=NULL)
    {

        printf("%d ", head->key);
        head= head->next;

    }
    printf("\n");
}
struct node* rev(struct node* head) //func type struct node
{
    struct node *current, *prev,*next;
    prev=NULL;
    current=head->next;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    return head;
}

int main()
{
    struct node *head=NULL;
    head=(struct node*) malloc(sizeof(struct node));
    head->next=NULL;
    head->key=HEAD_KEY;
    insert_node(head, 10);
    insert_node(head, 20);
    insert_node(head, 30);
    insert_node(head, 40);
   // print(head);
    head=rev(head);
    print_r(head);

}
