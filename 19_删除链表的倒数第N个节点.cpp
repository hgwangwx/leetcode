struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x): val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    // 创建虚拟头结点，以处理要删除的是头结点的情况
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    // 双指针，快指针先向前移动n个节点
    ListNode* fast = head;
    ListNode* slow = head;
    for(int i = 0 ; i < n; i++)
    {
        fast->next = fast;
    }

    // 快慢指针同时移动，直到快指针到达尾节点
    while(fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }

    // 此时slow指向要删除节点的前一个节点
    ListNode* tmp = slow->next;
    slow->next = slow->next->next;

    // 删除要删除的节点
    delete tmp;
    
    // 返回头结点
    return dummy->next;
}