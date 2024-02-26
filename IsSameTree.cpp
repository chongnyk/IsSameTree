/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool valFlag = true;
        bool lFlag = true;
        bool rFlag = true;
        
        if(p == nullptr && q == nullptr){
            return true;
        }
        else if((p != nullptr) != (q != nullptr)){
            return false;
        }

        if(p->val != q-> val){
            valFlag = false;
        }

        if(!valFlag) return valFlag;

        if(p->left != nullptr && q->left != nullptr){
            lFlag = isSameTree(p->left, q->left);
        }
        else if(p->left != q->left){
            lFlag = false;
        }
        else {
            lFlag = true;
        }

        if(!lFlag) return lFlag;

        if(p->right != nullptr && q->right != nullptr){
            rFlag = isSameTree(p->right, q->right);
        }
        else if(p->right != q->right){
            rFlag = false;
        }
        else {
            rFlag = true;
        }

        return (valFlag && lFlag && rFlag);
    }
};
