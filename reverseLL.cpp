
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
 
//RECURSIVE ALGORITHM


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
