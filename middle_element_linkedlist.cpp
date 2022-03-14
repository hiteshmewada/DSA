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
        Node *slow = head, *fast = head;
        while (fast != NULL and fast->link != NULL)
        {
            slow = slow->link;
            fast = fast->link->link;
        }
        cout << "Middle Element is " << slow->data;
    }
}
