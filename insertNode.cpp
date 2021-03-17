/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/


//RECURSIVE


Node* insertNode(Node *head, int i, int data) {
	// Write your code here
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        return head;
    }
    else
    {
        if (i < 0)
            return head;
        else if (i == 0)
        {
            Node *newNode = new Node(data);
            newNode -> next = head;
            head = newNode;
            return head;
        }
        else if (i == 1)
        {
            Node *newNode = new Node(data);
            Node *temp = head -> next;
            head -> next = newNode;
            newNode -> next = temp;
            return head;
        }
        else
        {
            Node *nxt = head -> next;
            Node *tempDo = insertNode(nxt, i-1, data);
            return head; 
        }
    }
}



//ITERATIVE

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


