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
vector<int> GetLeastNumbers_Solution(vector<int> input, int k); //ʹ��partition˼��
bool is_balance(TreeNode *head);
int is_balance(TreeNode *head, bool &flag);//ʹ��flag�������ٱ����Ĵ������Ż�����
int tree_level(TreeNode *head);
void tree_reverse(TreeNode * head);
void GetPath(TreeNode *root, int expectNumber, vector<vector<int> > &res, vector<int> &path);
vector<vector<int> > FindPath(TreeNode* root, int expectNumber);//����һ�����������·����Ϊexpectnumber
void print_tree(TreeNode *head);
string get_max_symmetry_sub(string s);
string get_longest_common_substr(string s1, string s2);
string get_longest_common_subsequence(string s1, string s2);
vector<int> get_non_exist_two_num(vector<int> vec);//���������в����ڵ�1~N������ֵ
int get_one_number_one_time(vector<int> vec);//���������н�����һ�ε�һ��ֵ
vector<int> get_two_number_one_time(vector<int> vec);//���������н�����һ�ε�����ֵ
vector<int> get_three_number_one_time(vector<int> vec);//���������н�����һ�ε�����ֵ
bool VerifySquenceOfBST(vector<int> vec);//�жϸ������Ƿ�Ϊĳ�����������ĺ���������
void printArr(vector<int> vec);
RandomListNode* Clone(RandomListNode* pHead);//���������copy������randomָ��)
int MoreThanHalfNum_Solution(vector<int> numbers);//Ѱ�������и�����������һ�볤�ȵ�����
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2);//�������������һ����ͬ�ڵ�
string ReverseSentence(string str); //��ת�ַ����ѿո�Ϊ����
bool match(char* str, char* pattern);//������ʽ
int getMax_subArr(vector<int> vec);//���������Ӵ�����


