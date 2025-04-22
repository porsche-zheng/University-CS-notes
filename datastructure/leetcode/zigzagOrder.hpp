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

#include<iostream>
#include<vector>
#include<deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        deque<TreeNode*> deq;
        deq.push_back(root);
        int num = 1 ; //本层的元素数,决定for循环次数
        int level = 1; //层数
        while(!deq.empty()){
            int i = 0 , times = num ; // i循环,times循环次数;
            // 改进：deq.size()可直接获得deque长度，无需自行记录每层的元素数
            num = 0 ; //num置0;
            TreeNode* top = nullptr;
            if(level%2){ // 奇数
                for(i=0;i<times;++i){
                    top = deq.front();
                    ans[level-1].push_back(top->val);
                    deq.pop_front();
                    if(top->left){
                        deq.push_back(top->left);
                        ++num;
                    }
                    if(top->right){
                        deq.push_back(top->right);
                        ++num;
                    }
                }
            }
            else{
                for(i=0;i<times;++i){
                    top = deq.back();
                    ans[level-1].push_back(top->val);
                    deq.pop_back();
                    if(top->right){
                        deq.push_front(top->right);
                        ++num;
                    }
                    if(top->left){
                        deq.push_front(top->left);
                        ++num;
                    }
                }
            }
            ++level;
        }
        return ans;
    }
};
