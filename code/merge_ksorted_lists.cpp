/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
namespace std{
    template<>
    class less<ListNode*>{
    public:
        bool operator()(ListNode* &n1, ListNode* &n2) const{
            return n1->val > n2->val;
        }
    };
}
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*> q;
        for(ListNode* &li : lists){
            if(li != nullptr)
                q.push(li);
        }
        
        ListNode* head = new ListNode(0), *p = head;
        while(!q.empty()){
            p->next = q.top();
            p = p->next;
            q.pop();
            if(p->next != nullptr) 
                q.push(p->next);
        }
        p->next = nullptr;
        p = head->next;
        delete head;
        return p;
    }
};