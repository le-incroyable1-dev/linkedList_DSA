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

Node *deleteNode(Node *head, int pos)
{
    //Write your code here
    if (head == NULL)
        return head;
    else
    {
        if (pos < 0)
            return head;
        else if (pos == 0)
        {
            Node *temp = head;
            head = temp -> next;
            delete temp;
            return head;
        }
        else
        {
            Node *temp = head;
            
            for (int i = 0; i < pos-1 ; i++)
            {
                if (temp == NULL)
                    return head;
                else
                {
                    temp = temp -> next;
                }
            }
            
            if (temp -> next == NULL)
                temp = NULL;
            else
            {
            	Node *a = temp -> next;
            	Node *b = temp -> next;
            
            	a = a -> next;
            	temp -> next = a;
            
            	delete b;
            }
            
            return head;
        }
    }
}
