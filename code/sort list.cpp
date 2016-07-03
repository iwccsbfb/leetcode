/**
random quick sort for list;


 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 * 
 */
 #include <memory>
class Solution {
    void quick_sort(ListNode *head, ListNode *tail, int sz){
        // 因为ri在middle向右一个,le向左一个, so maybe head>tail;
		if (head == tail || head == nullptr || tail == nullptr) return;
        ListNode *le, *ri;
        int sz1, sz2;
        split(head, le, sz1, ri, tail, sz2, sz);
        quick_sort(head, le, sz1);
        quick_sort(ri, tail, sz2);
    }
    // split的时候，le一定要在middle往前一个，ri一定要在middle向后一个；否则，可能
    // 死循环
    void split(ListNode *head, ListNode * &le, int &sz1,
                 ListNode * &ri, ListNode *tail,  int &sz2, int sz){
        // head != tail
        int num = rand()%sz, idx = 0;
        auto p = head;
        while(idx < num){
            p = p->next;
            idx++;
        }
        int pivot = p->val;
        std::swap(p->val, tail->val);
        p = head; sz1 = 0;
        shared_ptr<ListNode> dummy(new ListNode{0, head});
        le = dummy.get();
        while( p != tail){
            if(p->val < pivot){
                std::swap(p->val, le->next->val);
                le = le->next;
                sz1 ++;
            }
            p = p->next;
        }
        sz2 = sz - sz1 - 1;
        std::swap(le->next->val, tail->val);
        if(le->next != tail)
            ri = le->next->next;
        else ri = nullptr;
        
        if(le == dummy.get())
            le = nullptr;
    }
    
public:
    /**
     * @param head: The first node of linked list.
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        if(head == nullptr) return nullptr;
        ListNode *tail = head;
        int sz = 1;
        while(tail->next != nullptr){
            tail = tail->next;
            sz ++;
        }
        quick_sort(head, tail, sz);
        return head;
    }
};



int main(int argc, char *argv[]) {
	ListNode *p1 = new ListNode(0);
	ListNode *p2 = new ListNode(3);
	ListNode *p3 = new ListNode(1);
	ListNode *p4 = new ListNode(-1);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	Solution().sortList(p1);
	return 0;
}
