node* reverse_A_LinkedList (node*head)
{
    node *curr = head ;
    node *prev = NULL;

    while (curr)
    {
        node *n = curr -> next ;
        curr ->next = prev ;
        prev = curr ;
        curr = n ;
    }
    return prev;
}