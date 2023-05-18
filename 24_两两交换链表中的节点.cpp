#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
    if(!head)
        return nullptr;

    if(!head->next)
        return head;

    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    // 指针 p1 指向待交换的第一个节点
    ListNode* p1 = head;
    // 指针 p2 指向待交换的第二个节点
    ListNode* p2 = p1->next;
    // 指针 pre 指向 p1 的前一个节点
    ListNode* pre = dummy;

    while(p1 && p2)
    {
        pre->next = p2;
        p1->next = p2->next;
        p2->next = p1;

            
        pre = p1;
        p1 = p1->next;
        if(p1)       
            p2 = p1->next;
    }

    return dummy->next;
}