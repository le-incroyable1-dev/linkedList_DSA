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

Node *deleteNodeRec(Node *head, int pos) {
	//Write your code here
    
    if(head == NULL)
        return head;
    else
    {
        if(pos < 0)
            return head;
        else if(pos == 0)
        {
            Node *temp = head;
            head = head -> next;
            delete temp;
            return head;
        }
        else if(pos == 1)
        {
            Node *temp1 = head -> next;
            
            if(temp1 == NULL)
                return head;
            else
            {
                Node *temp2 = temp1 -> next;
                
                if(temp2 == NULL)
                {
                    delete temp1;
                	head -> next = NULL;
                	return head;
                }
                else
                {
            		head -> next = temp2;
            		delete temp1;
            		return head; 
                }
            }
                            
        }
        else
        {
            Node *nxt = head -> next;
            
            if(nxt == NULL)
                return head;
            else
            {
            	Node *tempDo = deleteNodeRec(nxt, pos-1);
            	return head;
            }
        }
    }
}




//ITERATIVE

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
