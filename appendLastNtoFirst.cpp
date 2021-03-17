/*
AppendLastNToFirst
Send Feedback
You have been given a singly linked list of integers along with an integer 'N'. 
Write a function to append the last 'N' nodes towards the front of the singly 
linked list and returns the new head to the list.
*/

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


int length(Node *head)
{
    if(head == NULL)
    {
        return 0;
    }
    //Write your code here
    Node *temp = head;
    
    int count = 0; 
    
    while ( temp!=NULL )
    {
        count++;
        temp = temp->next;
    }
    
    return count;
}


Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here
    if (head == NULL)
        return head;
    else
    {
        int len = length(head);
        
        if (n <= 0)
            return head;
        else
        {
            if (n  >= len)
                return head;
            else
            {
                Node *temp = head;
                
                for (int i = 0; i < len-n-1; i++)
                {
                    temp = temp -> next;
                }
                
                Node *temp2 = temp -> next;
                Node *temp3 = temp -> next;
                temp -> next = NULL;
                
                for(int i = 0; i < n-1; i++)
                {
                    temp2 = temp2 -> next;
                }
                
                temp2 -> next = head;
                head = temp3;
                
            }
            
        }
    }
}
