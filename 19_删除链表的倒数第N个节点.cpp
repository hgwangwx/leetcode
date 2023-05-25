struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x): val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(!head)
        return nullptr;

    // 创建虚拟头结点，以处理要删除的是头结点的情况
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    // 双指针，快指针先向前移动n+1个节点
    ListNode* fast = dummy;
    ListNode* slow = dummy;
    while(n-- && fast!=nullptr){
        fast=fast->next;
    }

    fast=fast->next;
    // 快慢指针同时移动，直到快指针到达尾节点
    while(fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode *temp = slow->next;
    slow->next=slow->next->next;
    delete temp;
    return dummy->next;
}