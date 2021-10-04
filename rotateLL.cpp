


/**

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,

return 4->5->1->2->3->NULL.


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* rotateRight(ListNode* A, int B) {

    int l = 0;
    
    ListNode* t1 = A;

    while(t1 -> next != NULL)
    {
        l++;
        t1 = t1 -> next;
    }

    if(B > l)
    {
        B = B%(l+1) ;
    }

    int sp = l - B; //starting point for rotation

    if(sp >= 0 && B > 0)
    {

    ListNode *t2 = A;

    for(int i = 0; i < sp; i++)
    {
        t2 = t2 -> next;
    }

    ListNode *rp = t2 -> next;

    t2 -> next = NULL;
    t1 -> next = A;

    return rp;
    }
    else
    {
        return A;
    }
    

}
