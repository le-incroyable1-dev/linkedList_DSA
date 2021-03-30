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


Q) kReverse

Given a singly linked list of integers, reverse the nodes of the linked list 'k' at a time and return its modified list.
'k' is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of 'k,' then left-out nodes, in the end, should 
be reversed as well.
*****************************************************************/



Node *reverseLinkedListRec(Node *head)
{
    //Write your code here
    if(head == NULL || head -> next == NULL)
        return head;
    else
    {
        Node *nxt = head -> next;
        Node *newHead  = reverseLinkedListRec(nxt);
        
        nxt -> next = head;
        head -> next = NULL;
        return newHead;
    }
    
}


Node *kReverse(Node *head, int k)
{
	//Write your code here
    if(head == NULL || head -> next == NULL)
        return head;
    else
    {
        if(k == 0 || k == 1)
            return head;
        else
        {
            int count = 1;
            
            Node *h1= head;
            //de *h2= head;
            while(count < k && head -> next != NULL)
            {
                head = head -> next;
                count++;
            }
            
            Node *nxt = head -> next;
            
            head -> next = NULL;
            Node *rev = reverseLinkedListRec(h1);
            
            h1-> next = kReverse(nxt, k);
            
            return rev;
        }
    }
}
