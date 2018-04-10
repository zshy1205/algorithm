#include "mystring.h"
#include "MX.h"

int main()
{
	int arr[10] = { -4, 6, 2, 3,-5, 9, 1, 15, -9, -2 };
	vector<int> vec(arr, arr + 10);
	cout << getMax_subArr(vec);
	string s1 = "+3243243";
	string s2 = "-0";
	cout << mul(s1, s2) << endl;
	
	getline(cin,s1);
	getline(cin, s2);
	cout << s1 << s2 << endl;

	/*
	ListNode l1(1);
	ListNode l2(2);
	ListNode l3(3);
	ListNode l4(4);
	ListNode l5(5);
	ListNode l6(6);
	ListNode l7(7);
	l1.next = &l2;
	l2.next = &l6;
	l6.next = &l7;
	l4.next = &l5;
	l5.next = &l6;
	cout << FindFirstCommonNode(&l1, &l4)->val << endl;
	/*
	int array[] = { 1,2,3,2,2,2,5,4,2 };
	vector<int> vec1(array, array + 9);
	cout << MoreThanHalfNum_Solution(vec1) << endl;
	int array2[] = { 4,5,1,6,2,7,3,8 };
	vector<int> vec2(array2, array2 + 8);
	printArr(GetLeastNumbers_Solution(vec2, 8));

	/*
	RandomListNode* p1 = new RandomListNode(1);
	RandomListNode* p2 = new RandomListNode(2);
	RandomListNode* p3 = new RandomListNode(3);
	RandomListNode* p4 = new RandomListNode(4);
	RandomListNode* p5 = new RandomListNode(5);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = NULL;
	p1->random = NULL;
	p2->random = p5;
	p3->random = p4;
	p4->random = p4;
	p5->random = p1;
	RandomListNode* head = Clone(p1);
	cout << head->label << endl;
	cout << head->random->label << endl;
	/*
	TreeNode *head = new TreeNode(5);
	TreeNode *n1 = new TreeNode(6);
	TreeNode *n2 = new TreeNode(8);
	TreeNode *n3 = new TreeNode(7);
	TreeNode *n4 = new TreeNode(9);
	TreeNode *n5 = new TreeNode(7);
	TreeNode *n6 = new TreeNode(9);
	head->left = n1;
	head->right = n2;
	n1->left = n3;
	n1->right = n4;
	n2->left = n5;
	n2->right = n6;
	head = NULL;
	vector<vector<int>> matrix = FindPath(head, 20);
	//printArr(matrix[0]);
	//printArr(matrix[1]);
	cout << "############" << endl;

	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(7);
	vec.push_back(8);
	vec.push_back(10);
	vec.push_back(11);
	printArr(get_non_exist_two_num(vec));
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(7);
	vec.push_back(8);
	vec.push_back(10);
	vec.push_back(11);
	cout << get_one_number_one_time(vec) << endl;
	vec.erase(vec.end() - 1);
	printArr(get_two_number_one_time(vec));
	vec.erase(vec.end() - 2);
	printArr(vec);
	printArr(get_three_number_one_time(vec));
	int array[] = { 2,5,9,16,17,15,13,18,12 };
	vector<int> vec1(array, array + 9);
	cout << "后序遍历结果为：";
	printArr(vec1);
	cout << "是否是二叉搜索树：";
	cout << VerifySquenceOfBST(vec1) << endl;
	/*
	mystring s1("abcdef");
	mystring s2(s1);
	mystring s3 = s2;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	mystring s4;
	//cin >> s4;
	cout << s4 << endl;
	s4 = s2;
	cout << s4 << endl;
	s4 = "2312111";
	cout << s4 << endl;
	mystring s5 = "12345";
	cout << s5 << endl;
	mystring s6;
	s6 = "44444444";
	cout << s6 << endl;
	char cch[] = "sadsad";
	mystring s7(cch, 3);
	cout << s7 << endl;

	string s8 = "sfdsfdsf";
	string s9(s8, 2);
	cout << s9 << endl;
	mystring s10 = "sfdsfdsf";
	mystring s11(s10, 2);
	cout << s11 << endl;

	string s12 = "qweqweqweq";
	string s13(s12, 3,4);
	cout << s13 << endl;
	mystring s14 = "qweqweqweq";
	mystring s15(s14, 3, 4);
	cout << s15 << endl;
	*/
	/*
	string s17 = "ahgshjfdgash";
	cout << s17.substr(2, 6).substr(2)<<endl;
	//mystring s18 = "ahgshjfdgash";
	//cout << s18.substr(2, 6).substr(2) << endl;
	mystring s1 = "232";
	mystring s2 = "233";
	s1 = s2;
	*/
	/*
	string s1 = "1234324355675466";
	string s2 = "24234234326544654523342343";
	cout << s1 << " + " << s2 << " = ";
	cout << add(s1, s2) << endl;
	cout << mul(s1, s2) << endl;
	int arr[10] = { 5, 6, 3, 4, 8, 11, 45, 2, 7, 0 };
	//merge_sort(arr, 0, 9);
	quick_sort(arr, 0, 9);
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";

	cout << "############" << endl;
	TreeNode *head = new TreeNode(5);
	TreeNode *n1 = new TreeNode(6);
	TreeNode *n2 = new TreeNode(8);
	TreeNode *n3 = new TreeNode(7);
	TreeNode *n4 = new TreeNode(9);
	head->left = n1;
	head->right = n2;
	n1->left = n3;
	n1->right = n4;
	cout << tree_level(head) << endl;
	
	cout << is_balance(head) << endl;
	bool flag = true;
	cout << is_balance(head, flag) << endl;
	cout << "flag: " << flag << endl;
	
	flag = true;
	TreeNode *n5 = new TreeNode(10);
	n4->left = n5;
	cout << is_balance(head) << endl;
	cout << is_balance(head, flag) << endl;
	cout << "flag: " << flag << endl;
	tree_reverse(head);
	cout << head->left->val << endl;
	cout << head->right->val << endl;

	cout << "#####" << endl;
	cout << get_max_symmetry_sub("baaccccc");
	cout << "#####" << endl;
	string s1("jkashgjhgajhfgsdasfdhafghabcdefgjhsagdjhgsaj");
	string s2("sfgdhajsgdhafgdabcdefgfajhsdjhgahsd");
	cout << get_longest_common_substr(s1, s2) << endl;
	cout << get_longest_common_subsequence(s1, s2) << endl;
	*/
	
	
	
	return 0;
}