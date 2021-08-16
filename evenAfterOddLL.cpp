
/*
Even after Odd LinkedList

For a given singly linked list of integers, arrange the elements such that all the even numbers are placed after the odd numbers. 
The relative order of the odd and even terms should remain unchanged.

Note :
No need to print the list, it has already been taken care. Only return the new head to the list.

Input format:
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
The first line of each test case or query contains the elements of the singly linked list separated by a single space. 

 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format:
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.

Time Limit: 1sec

Sample Input 1 :
1
1 4 5 2 -1

Sample Output 1 :
1 5 4 2 
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

Node *evenAfterOdd(Node *head)
{
    if(head == NULL)
        return head;
    
    Node *OddHead = NULL;
    Node *OddTail = NULL;
    Node *EvenHead = NULL;
    Node *EvenTail = NULL;
    
    while(head != NULL)
    {
        if(head -> data %2 == 0)
        {
            if(EvenHead == NULL)
            {
                EvenHead = head;
                EvenTail = head;
            }
            else
            {
                EvenTail -> next = head;
                EvenTail = EvenTail -> next;
            }
        }
        else
        {
            if(OddHead == NULL)
            {
                OddHead = head;
                OddTail = head;
            }
            else
            {
                OddTail -> next = head;
                OddTail = OddTail -> next;
            }
        }
        
        head = head -> next;
    }
    
    
    if(OddHead == NULL)
    {
        EvenTail -> next = NULL;
        return EvenHead;
    }
    else
    {
        if(EvenHead)
            OddTail -> next = EvenHead;
        else
            OddTail -> next = NULL;
        
        if(EvenTail)
            EvenTail -> next = NULL;
        
        return OddHead;
    }
}
