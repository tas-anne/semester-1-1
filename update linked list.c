void update(struct node *head,int val)
{
    int temp;
    while(head->nxt!=NULL)
    {
        head=head->nxt;
        temp=head->key;
        temp=temp+val;
        head->key=temp;
    }
}
