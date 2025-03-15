#include<iostream>


struct binTree{
    int val;
    binTree *left;
    binTree *right;
    binTree(int x) : val(x), left(nullptr), right(nullptr) {}
};


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct Listptr{
    ListNode* head;
    ListNode* tail;
    Listptr(ListNode* h, ListNode* t): head(h), tail(t){}
};



// left ->root ->right

Listptr* converToList(binTree *root){
    if(root == nullptr){
        return nullptr;
    }
    if(root->left == nullptr){
        return 
    }

    Listptr *left = converToList(root->left);
    Listptr *right = converToList(root->right);

    left->tail->next = new ListNode(root->val);
    left->tail->next->next = right->head;
    return left;

}