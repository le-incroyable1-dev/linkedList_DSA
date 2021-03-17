Node* insertNode (Node *head, int i, int data)
{
  if (head == NULL)
    return head;
  else
  {
    if (i < 0)
      return head;
    else if (i == 0)
    {
      Node *newNode = new Node(data);
      newNode -> next = head;
      head = newNode;
    }
    else
    {
      Node *temp = head;
      Node *newNode = new Node(data);
      
      for(int j = 0; j < i-1; j++)
      {
        temp = temp -> next;
      }
      
      Node *a = temp -> next;
      temp -> next = newNode;
      newNode -> next = a;
    }
    
    return head;
  }

}
