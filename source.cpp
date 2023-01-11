//https://leetcode.com/problems/same-tree/description/
#include <queue>
using namespace std;

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

class Solution 
{
public:
bool isSameTree(TreeNode* p, TreeNode* q) { 
    bool flag = true;
    /*if(p->val!=q->val)
    {
        return false;
    }*/
    queue<TreeNode*> A;
    queue<TreeNode*> B;
    A.push(p);
    B.push(q);
    TreeNode* tempa;
    TreeNode* tempb;
    while (A.empty() != true)
    {
        tempa = A.front();
        A.pop();
        tempb = B.front();
        B.pop();
        if(tempa==nullptr)//looking for empty nodes
        {
         if(tempb!=nullptr)   
            return false;
        }
        else if(tempb==nullptr)
        {
            if(tempa!=nullptr)   
            return false;
        }
        else
        {
            //either both nodes are nullptr or none
            if(tempa==nullptr &&tempb== nullptr)
            {
                //do nothing
            }
            else 
            {
                if(tempa!=nullptr &&tempb!= nullptr)
                {
                    if(tempa->val!=tempb->val)
                    return false;
                }
            }
        }
        if(tempa!=nullptr)
        {
            if(tempa->left!=nullptr||tempa->right!=nullptr)
            {
                A.push(tempa->left);
                A.push(tempa->right);
            }
            else if(tempa->left==nullptr||tempa->right==nullptr)
                A.push(nullptr);
        }
        if(tempb!=nullptr)
        {
            if(tempb->left!=nullptr||tempb->right!=nullptr)
            {
                B.push(tempb->left);
                B.push(tempb->right);

            }
            else if(tempb->left==nullptr||tempb->right==nullptr)
                B.push(nullptr);
        }
    }
    if(B.empty()!=true)
    {
        return false;
    }
    return flag;
}
    
};
