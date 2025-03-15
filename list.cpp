#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* mergeList(std::vector<ListNode*> Lists){
    ListNode* head = new ListNode(0);
    ListNode* p = head;
    while(true){
        int min = INT_MAX;
        int minIndex = -1;
        for(int i = 0; i < Lists.size(); i++){
            if(Lists[i] != nullptr && Lists[i]->val < min){
                min = Lists[i]->val;
                minIndex = i;
            }
        }
        if(minIndex == -1){
            break;
        }
        p->next = new ListNode(min);
        p = p->next;
        Lists[minIndex] = Lists[minIndex]->next;
    }
    return head->next;    
}


// 1 4 5
// 1 3 4
// 2 6

int main(){
    std::vector<ListNode*> Lists;
    ListNode* head1 = new ListNode(1);
    ListNode* p = head1;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(5);
    Lists.push_back(head1);

    ListNode* head2 = new ListNode(1);
    p = head2;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(4);
    Lists.push_back(head2);

    ListNode* head3 = new ListNode(2);
    p = head3;
    p->next = new ListNode(6);
    Lists.push_back(head3);

    ListNode* head = mergeList(Lists);
    while(head != nullptr){
        std::cout << head->val << " ";
        head = head->next;
    }
    return 0;
}