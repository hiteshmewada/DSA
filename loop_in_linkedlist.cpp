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
        Node *slow=head,*fast=head;
        while(fast!=NULL and fast->next!=NULL){
            fast=fast->link->link;
            slow=slow->link;
            if(fast==slow){
                cout<<"Found LOOp";
                return;
            }
        }
        cout<<"NO Loop";
    }
}
