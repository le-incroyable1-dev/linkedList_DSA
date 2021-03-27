Q) Code: Merge Two Sorted LL
You have been given two sorted(in ascending order) singly linked lists of integers.
Write a function to merge them in such a way that the resulting singly linked list is also sorted(in ascending order) and return the new head to the list.
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

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    if (head1 == NULL)
        return head2;
    else if(head2 == NULL)
        return head1;
    else
    {
        Node *nh1 = head1 -> next ;
        Node *nh2 = head2 -> next ;
        
        if(head1 ->  data > head2 -> data)
        {
            
            Node *h2 = head2;
            
            while (head2 -> next != NULL && (head2 -> next -> data < head1 -> data))
            {
                head2 = head2 -> next;
                nh2 = nh2 -> next;
            }
            
            head2 -> next = head1;
            Node *nxt = mergeTwoSortedLinkedLists(nh1, nh2);
            head1 -> next = nxt;
            
            return h2;   
        }
        else
        {
            
            Node *h1 = head1;
            
            while (head1 -> next != NULL && (head1 -> next -> data < head2 -> data))
            {
                head1 = head1 -> next;
                nh1 = nh1 -> next;
            }
            
            head1 -> next = head2;
            Node *nxt = mergeTwoSortedLinkedLists(nh1, nh2);
            head2 -> next = nxt;
            
            return h1;   
        }
    }
}
