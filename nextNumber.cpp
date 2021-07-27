/**********
Next Number

Given a large number represented in the form of a linked list. Write code to increment the number by 1 in-place(i.e. without using extra space).
Note: You don't need to print the elements, just update the elements and return the head of updated LL.

Input Constraints:
1 <= Length of Linked List <=10^6.

Input format :
Line 1 : Linked list elements (separated by space and terminated by -1)

Output Format :
Line 1: Updated linked list elements

Sample Input 1 :
3 9 2 5 -1
Sample Output 1 :
3 9 2 6



 * Following is the Node class that is already written.
 
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
 
*********/
#include <utility>

pair<Node *, int> helper(Node* head)
{
    if(head->next == NULL)
    {
        if(head->data == 9)
        {
            pair<Node *, int> p1;
            head->data = 0;
            p1.first = head;
            p1.second = 1;
            return p1;
        }
        else
        {
            pair<Node *, int> p1;
            head->data += 1;
            p1.first = head;
            p1.second = 0;
            return p1;
        }
    }
    
    pair<Node *, int> p;
    p = helper(head->next);
    
    if(p.second == 1)
    {
        if(head->data == 9)
        {
            head->data = 0;
            p.first = head;
            p.second = 1;
            return p;

        }
        else
        {
            head -> data += 1;
            p.first = head;
            p.second = 0;
            return p;
        }
    }
    else
    {
        p.first = head;
        return p;
    }
    
}


Node* NextLargeNumber(Node *head) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    pair<Node *, int> pp;
    pp = helper(head);
    
    if(pp.second == 1)
    {
        Node *newHead = new Node(1);
        newHead->next = head;
        return newHead;
    }
    else
    {
        return head;
    }
    
    
}



