
bool ispresent (node *head , int data)
{
    node *curr = head ;
    while (curr != NULL)
    {
        if (curr -> data == data)
        {
            return true;
        }
        curr=curr->next;
    }
    return false;
}

bool ispresent_recursev(node *head , int data)
{
    if (head==NULL)return false;
    if (head -> data == data)return true;
    return ispresent_recursev(head->next,data);
}