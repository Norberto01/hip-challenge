/**
 * Definition for singly-linked list.
 */
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *middle = head;
        ListNode *fast = head;

        while(fast && fast->next){
            middle = middle->next;
            fast = fast->next->next;
        }
        return middle;
    }
};