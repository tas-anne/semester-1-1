void search(struct node *head, int key)
{
    while (head != NULL)
    {
        if (head->key == key)
        {
            printf("key found\n");
            return;
        }
        head = head->next;
    }
    printf("Key not found\n");
}
