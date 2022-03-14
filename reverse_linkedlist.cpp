struct Node
{
    /* data */
    int data;
    Node *link;
};
Node *head = NULL;
void showMid()
{
    if (head == NULL)
    {
        cout << "List is empty";
    }
    else
    {
        Node *pre=NULL,*cur=head,*next;
        while (cur!=NULL)
        {
            next=cur->link;
            cur->link=pre;
            pre=cur;
            cur=next;
        }
        head=pre;
    }
}
