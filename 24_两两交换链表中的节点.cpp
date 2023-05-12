#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
    if(!head || !head->next)
        return nullptr;

    ListNode* dummy = head;
    // 指针 p1 指向待交换的第一个节点
    ListNode* p1 = head;
    // 指针 p2 指向待交换的第二个节点
    ListNode* p2 = p1->next;
    // 指针 pre 指向 p1 的前一个节点
    ListNode* pre = nullptr;

    while(p1 && p2)
    {
        p1->next = p2->next;
        p2->next = p1;

        if(p1->next)
        {
            pre = p1->next;
            p1 = p1->next;
        }

        if(p1->next)
        {
            p2 = p1->next;
        }
    }

    return dummy;
}