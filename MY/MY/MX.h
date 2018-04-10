#pragma once
#include "head.h"

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
struct TreeNode{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int val) :val(val), left(NULL), right(NULL) {};
};
struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {}
};
string add(string s1, string s2);
string mul_(string s, int val, int  shift);
string mul__(string s1, string s2);
string mul(string s1, string s2);
void merge_sort(int *arr, int l, int r);
void merge(int *arr, int l, int mid, int r);
void quick_sort(int *arr, int l, int r);
int partition(int *arr, int l, int r);
int partition(vector<int>& input, int l, int r);
vector<int> GetLeastNumbers_Solution(vector<int> input, int k); //使用partition思想
bool is_balance(TreeNode *head);
int is_balance(TreeNode *head, bool &flag);//使用flag变量减少遍历的次数，优化计算
int tree_level(TreeNode *head);
void tree_reverse(TreeNode * head);
void GetPath(TreeNode *root, int expectNumber, vector<vector<int> > &res, vector<int> &path);
vector<vector<int> > FindPath(TreeNode* root, int expectNumber);//遍历一棵树输出所有路径和为expectnumber
void print_tree(TreeNode *head);
string get_max_symmetry_sub(string s);
string get_longest_common_substr(string s1, string s2);
string get_longest_common_subsequence(string s1, string s2);
vector<int> get_non_exist_two_num(vector<int> vec);//返回数组中不存在的1~N的两个值
int get_one_number_one_time(vector<int> vec);//返回数组中仅出现一次的一个值
vector<int> get_two_number_one_time(vector<int> vec);//返回数组中仅出现一次的两个值
vector<int> get_three_number_one_time(vector<int> vec);//返回数组中仅出现一次的三个值
bool VerifySquenceOfBST(vector<int> vec);//判断该数组是否为某二叉搜索树的后序遍历结果
void printArr(vector<int> vec);
RandomListNode* Clone(RandomListNode* pHead);//复杂链表的copy（包含random指针)
int MoreThanHalfNum_Solution(vector<int> numbers);//寻找数组中个数超过数组一半长度的数据
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2);//返回两个链表第一个共同节点
string ReverseSentence(string str); //翻转字符串已空格为划分
bool match(char* str, char* pattern);//正则表达式
int getMax_subArr(vector<int> vec);//返回数组子串最大和


