class Node{
  
  public :
  
  int val;
  Node *next = NULL;
  
  Node(int data)
  {
    this -> data = data;
  }
  
}



Node *takeInput()
{
  Node *head = NULL;
  
  int data;
  cin >> data;
  
  while (data != -1)
  {
    Node *newNode = new Node(data);
    if (head == NULL)
    {
      head = newNode;
    }
    else
    {
      Node *temp = head;
      
      while(temp -> next != NULL)
      {
        temp = temp -> next;
      }
      
      temp -> next = newNode;
    }
    
    cin >> data;
  }
  
  return head;
}
