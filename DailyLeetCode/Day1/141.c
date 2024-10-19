#include <stdbool.h>
#include <stdio.h>
struct ListNode
{
    int val;
    struct ListNode* next;
};


bool hasCycle(struct ListNode* head) {
    if (head == NULL)
        return false;
    
    if (head->next == NULL)
        return false;
    
    struct ListNode* slow = head;
    struct ListNode* fast = head;
// Logic: One pointer moves a step at a time, the other moves 2 steps at a time
    // thus if there is a cycle they will eventually meet each other as the linked list doesn't end
    
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        slow = slow->next;
        if (slow == fast) 
            return true;
    }
    return false;
}

// Time-Complexity: O(n)
// Space-Complexity: O(1)