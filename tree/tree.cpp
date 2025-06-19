#include <iostream>
using namespace std;

struct ListNode {
    char val;
    ListNode* prev;
    ListNode* next;

    ListNode(char x) : val(x), prev(nullptr), next(nullptr) {}
};


int main() {
    ListNode* head = new ListNode('3'); //root
    head->prev = new ListNode('4'); //child left
    head->next = new ListNode('5'); //child left
    head->prev->prev = new ListNode('1'); //LEAF left
    head->prev->next = new ListNode('2'); //LEAF left

    cout<< "root : "<< head->val << endl;
    cout<< "child 1 (left) : "<< head->prev->val << endl;
    cout<< "child 2 (right) : "<< head->next->val << endl;
    cout<< "leaf kiri 1 : "<< head->prev->prev->val << endl;
    cout<< "child kanan 1 : "<< head->next->prev->val << endl;
    cout<< "leaf kanan 1 : "<< head->next->next->val << endl;
    return 0;
}