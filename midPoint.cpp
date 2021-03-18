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

Node *midPoint(Node *head)
{
    // Write your code here
    if (head == NULL)
        return head;
    else
    {
        Node *slow = head;
        Node *fast = head;
        
        while (fast != NULL)
        {
            if (fast -> next != NULL)
            {
                fast = fast -> next -> next;
                
                if (fast == NULL)
                    return slow;
                else
                    slow = slow -> next;
            }
            else
            {
                return slow;
            }
        }
        
        return slow;
    }
}
