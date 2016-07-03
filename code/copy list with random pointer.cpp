/**
1. 对于myHasher; 类型要是Node *const &; 而不是const Node* &; 
pointer本身是const，而不是pointer指向的内容是const;
2. MyHasher需要把（）列为public method; 或者myHasher需要是struct;
3. 在64-bit machine, pointer是8 bytes,;
 in x86, pointer is 4 bytes，此时用reinterpret_cast转换为int会有precision lost.
4. 当hash一个pointer的时候，要判断其是否为nullptr;
5. map里需要提前存一个 NULL --> NULL;
6. unordered_map要实现==和Hasher; map要实现==和<.


 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 struct myHasher{
     size_t operator()(RandomListNode* const&node) const{
         int val = reinterpret_cast<long long>(node);
         if(node != nullptr) 
            val += node->label;
         return val;
     }
 };
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == nullptr) return nullptr;
        unordered_map< RandomListNode*, RandomListNode*, myHasher> map;
        RandomListNode *new_head = new RandomListNode(head->label);
        auto p1 = new_head, p2 = head;
        map[p2] = p1;
        map[nullptr] = nullptr;
        while(p2->next != nullptr){
            p2 = p2->next;
            p1->next = new RandomListNode(p2->label);
            p1 = p1->next;
            map[p2] = p1;
        }
        p1 = new_head; p2 = head;
        while(p2!= nullptr){
            p1->random = map[p2->random];
            p2 = p2->next;
            p1 = p1->next;
        }
        return new_head;
    }
};