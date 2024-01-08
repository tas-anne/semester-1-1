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





bool areIdentical(struct node *head, struct node *head2)
{
    while (head!= NULL && head2 != NULL)
    {
        if (head->key != head2->key)
            return false;

        /* If we reach here, then head and head2 are not NULL and
           their data is same, so move to next nodes in both
           lists */
        head = head->next;
        head2= head2->next;
    }

    // If linked lists are identical, then 'head' and 'head2' must
    // be NULL at this point.
    return (head== NULL && head2 == NULL);
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
    insert_tail(head,5);
    insert_tail(head,4);
    insert_tail(head,8);
    insert_tail(head,2);
    insert_tail(head2,5);
    insert_tail(head2,4);
    insert_tail(head2,2);
    insert_tail(head2,2);
    print(head);
    print(head2);
    areIdentical(head,head2)? printf("0"):
    printf("1");
    return 0;


}
