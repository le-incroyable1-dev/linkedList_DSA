/*
Bubble Sort (Iterative) LinkedList

Given a singly linked list of integers, sort it using 'Bubble Sort.'

Note :
No need to print the list, it has already been taken care. Only return the new head to the list.

Input format :
The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the elements of the sorted singly linked list.

Output for every test case will be printed in a seperate line.

Constraints :
0 <= M <= 10^3
Where M is the size of the singly linked list.

Time Limit: 1sec

Sample Input 1 :
10 9 8 7 6 5 4 3 -1

Sample Output 1 :
 3 4 5 6 7 8 9 10 
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

Node *bubbleSort(Node *head)
{
    if(head == NULL || head -> next == NULL)
        return head;
    
    int len = 0;
    bool swapped = false;
    Node *originalHead = head;
    //to maintain a reference to the original head node
    
    while(head != NULL)
    {
        len++;
        head = head -> next;
    }
    
    head = originalHead;
    
    for (int i = 0 ; i < (len-1); i++)
    {
        for(int j = 0; j < (len-1- i); j ++)
        {
            if(head -> data > head -> next -> data)
            {
                int temp = head -> data;
                head -> data = head -> next -> data;
                head -> next -> data = temp;
                swapped = true;
            }
            
            head = head -> next;
        }
        
        if(swapped == false)
            break;
        
        head = originalHead;
    }
    
    return originalHead;
}
