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

Q)Delete every N nodes

You have been given a singly linked list of integers along with two integers, 'M,' and 'N.' Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes. Continue the same until the end of the linked list.
To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.
*****************************************************************/

Node *skipMdeleteN(Node *head, int m, int n)
{
	// Write your code here
    if(head == NULL)
        return head;
    else
    {
        Node *h = head;
        
        if(m == 0)
            return NULL;
        else if(n == 0)
            return head;
        else
        {
        while(head != NULL)
        {
        
    
        for(int i = 1; i < m; i++)
        {
            if(head != NULL)
                head = head -> next;
            else
                return h;
        }
        
        if(head == NULL)
            return h;
        
        Node *h1 = head;
        
        head = head -> next;
        for(int i = 0; i < n; i++)
        {
            if(head != NULL)
                head = head -> next;
            else
            {
                h1 -> next = NULL;
                return h;
            }
        }
        
        h1 -> next = head;
        }
    
        return h;
        }
    }
}
