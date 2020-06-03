/*数据结构
struct ListNode{
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL){}
}*/
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
        /*为什么这样不行呢
        while(node->next){
          node->val = node->next->val;
          node = node->next;
        }
        node = nullptr;*/
    }
};

