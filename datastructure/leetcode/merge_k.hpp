/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include<iostream>
#include<vector>
using namespace std;

class Solution { // parameter(not necessary):ListNode* , ptr_node
    struct ptr_node{
        ListNode* ptr;
        ptr_node* next;
        ptr_node(ListNode* p=nullptr,ptr_node* n=nullptr):ptr(p),next(n) {}
    };//ptr的node结构体

    class ptr_list{ // 手动构建一个ptr的链表
    private:
        ptr_node* head; //头节点
    public:
        ptr_list(ptr_node* p){ // parameter:ptr_ndoe
            head = new ptr_node(nullptr,p);
        }
        ~ptr_list(){
            ptr_node* del = head;
            while(head){
                del = head;
                head = head->next;
                delete del;
            }
        }
        void insert(ListNode* p){
            ptr_node* find = head->next;
            ptr_node* pre = head; // 双指针
            while(find && find->ptr->val < p->val){
                pre = find;
                find = find->next;
            }
            pre->next = new ptr_node(p,pre->next);
        }
        ListNode* remove(/*int val*/){ // 假设一定能找到
            ptr_node* find = head->next;
            ptr_node* pre = head; // 这道题中永远remove第一个元素,因此无需循环
            // 双指针
            // while(find && find->ptr->val != val){
            //     pre = find;
            //     find = find->next;
            // }
            ListNode* ans = find->ptr;
            pre->next = find->next;
            delete find;
            return ans;
        }
        ListNode* replace(){
            ListNode* minmum = remove();
            if(minmum->next) insert(minmum->next); // 不添加nullptr节点
            return minmum;
        }
        bool isEmpty(){
            return !head->next;
        }
    };
    // ListNode* + ptr_node*(next) -> ptr_node -->> ptr_list;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //预处理
        int i=0;
        while(i<lists.size() && !lists[i]) ++i;
        if(i==lists.size()) return nullptr;
        ptr_node* head = new ptr_node(lists[i]);
        ptr_list* ptrList = new ptr_list(head);
        for(i=i+1;i<lists.size();++i){
            if(!lists[i]) continue; // 不能插入nullptr!
            ptrList->insert(lists[i]); // 插入并排序
        }
        ListNode* res = ptrList->replace();
        ListNode* cur = res;
        while(!ptrList->isEmpty()){
            cur = cur->next = ptrList->replace();
        }
        delete ptrList;
        return res;
    }
};

/*
遇到的错误及问题：
1. alloc-dealloc-mismatch : 'delete []ptr' should be-> 'delete ptr';
2. Undefined Behavior : when lists = [[]] ! think the special case like that;
3. In ~ptr_list() function , while(!head!) ; not while(!del!) it will cause 'Undefined Behavior' error;
*/
