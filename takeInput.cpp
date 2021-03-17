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
  Node *tail = NULL;
  
  int data;
  cin >> data;
  
  while (data != -1)
  {
    Node *newNode = new Node(data);
    if (head == NULL)
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      tail -> next = newNode;
      tail = newNode;
    }
    
    cin >> data;
  }
  
  return head;
}
