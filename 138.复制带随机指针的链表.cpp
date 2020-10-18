/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (nullptr == head) return nullptr;

        unordered_map<Node*, Node*> m;
        auto pCur = head;
        while (pCur) {
            Node* newNode = new Node(pCur->val);
            m[pCur] = newNode;
            pCur = pCur->next;
        }

        pCur = head;
        while (pCur) {
            m[pCur]->next = m[pCur->next];
            m[pCur]->random = m[pCur->random];
            pCur = pCur->next;
        }

        return m[head];
    }
};
// @lc code=end

