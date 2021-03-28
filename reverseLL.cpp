
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

"O(n)"

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


//----------------------------------------------------------------------
//RECURSIVE - DOUBLE NODE


"O(n)"
	
// Here a node class contains definition for head as well as tail node. !!
// We use an object of pair class to be able to return the head as well as the tail node at once

class Pair{
	public :
	
	Node *head;
	Node *tail;
};

Pair revLL2(Node *head)
{
	if(head == NULL || head -> next == NULL)
	{
		Pair ans;
		
		ans.head = head;
		ans.tail = tail;
		
		return ans;
	}
	else
	{
		Pair smallAns = revLL2(head -> next);
		
		smallAns.tail -> next = head;
		head -> next = NULL;
		
		Pair ans;
		ans.head = smallAns;
		ans.tail = head;
		
		return ans;
	}
}


//----------------------------------------------------------------------
//ITERATIVE METHOD


"O(n)"

Node *reverseLinkedList(Node *head) {
    // Write your code here
    if(head == NULL || head -> next == NULL)
        return head;
    else
    {
        Node *prev = NULL;
        Node *cur = head;
        Node *nxt = NULL;
        
        while(cur != NULL)
        {
            nxt = cur -> next;
            
            cur -> next = prev;
            
            prev = cur;
            cur = nxt;
        }
        
        return prev; 

    }
}


	
