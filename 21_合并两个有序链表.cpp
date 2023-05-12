#include <iostream>

using namespace std;

// 定义链表节点结构体
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 打印链表
void printList(ListNode* head) {
    ListNode* cur = head;
    while (cur != NULL) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

// 合并两个有序链表，返回合并后的链表头节点指针
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // 定义一个哨兵节点，便于操作
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;

    while(l1 && l2)
    {
        if(l1->val <= l2->val)
        {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }

    // 将剩余的节点插入到新链表中
    if (l1 != NULL) {
        cur->next = l1;
    }
    if (l2 != NULL) {
        cur->next = l2;
    }
    // 返回新链表的头节点
    return dummy->next;
}