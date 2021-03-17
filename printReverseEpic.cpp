//PRINT REVERSE LINKED LIST : MOST EPIC SOLUTION

void printReverse(Node *head)
{
    //Write your code here
    if (head == NULL)
        return;
    else
    {
        Node *nxt = head -> next;
        printReverse(nxt);
        
        cout << head -> data << " ";
    }
}
