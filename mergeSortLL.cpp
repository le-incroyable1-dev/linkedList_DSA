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


Node *midPoint(Node *head)
{
    
    // Write your code here
    if (head == NULL || head -> next == NULL)
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
                    return slow -> next;
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


// mergeSort function

Node *mergeSort(Node *head)
{
	//Write your code here
    if (head == NULL || head->next == NULL)
        return head;
    else
    {
        
        Node *mid = midPoint(head);
        Node *h = NULL;
        
        while (head != mid)
        {
            h = insertNode(h, 0, head->data);
            head = head -> next ;
        }
        
        Node *n1 = mergeSort(h);
        Node *n2 = mergeSort(mid);
        
        return mergeTwoSortedLinkedLists(n1, n2);
        
    }
}
