#include "MX.h"


int getMax_subArr(vector<int> vec)//返回数组子串最大和
{
	int sum = vec[0];
	int b = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		b += vec[i];
		if (sum < b)
			sum = b;
		if (b < 0)
			b = 0;
	}
	return sum;
}

bool match(char* str, char* pattern)//正则表达式
{
	if (pattern[0] == 0 && str[0] == 0)
	{
		return true;
	}
	if (pattern[0] != 0 && pattern[1] == '*')
	{
		if (match(str, pattern + 2))
			return true;
	}
	if ((pattern[0] == '.' && str[0]) || str[0] == pattern[0])
	{
		if (match(str + 1, pattern + 1))
			return true;
		if (pattern[1] == '*' && match(str + 1, pattern))
		{
			return true;
		}
	}
	return false;
}
string ReverseSentence(string str) {//翻转字符串已空格为划分
	if (str.empty())
		return str;
	string res;
	int r = str.length();
	std::size_t found = str.rfind(' ');
	while(found != std::string::npos)
	{
		res += str.substr(found + 1, r);
		res += " ";
		r = found;
		str = str.substr(0, r);
		found = str.rfind(' ');
	}
	res += str.substr(0, r);
	return res;
}
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {//返回两个链表第一个共同节点
	if (!pHead1 || !pHead2)
		return NULL;
	set<ListNode *> s;
	s.insert(pHead1);
	pHead1 = pHead1->next;
	while (true)
	{
		if (!pHead1 && !pHead2)
			return NULL;
		if (pHead2) {
			if (s.find(pHead2) != s.end())
				return pHead2;
			else
			{
				s.insert(pHead2);
				pHead2 = pHead2->next;
			}
		}
		if (pHead1) {
			if (s.find(pHead1) != s.end())
				return pHead1;
			else
			{
				s.insert(pHead1);
				pHead1 = pHead1->next;
			}
		}
	}
}

int partition(vector<int>& input, int l, int r)
{
	if (l < r)
	{
		int value = input[l];
		while (l < r)
		{
			while (l < r && input[r] >= value)
				r--;
			if (l < r)
				input[l++] = input[r];
			while (l < r && input[l] <= value)
				l++;
			if (l < r)
				input[r--] = input[l];
		}
		input[l] = value;
		return l;
	}
	return l;
}
vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
	int kk = 0;
	int l = 0;
	int r = input.size() - 1;
	while (l <= r)
	{
		kk = partition(input, l, r);
		cout << "kk" << kk << " " << l << " " << r << endl;
		printArr(input);
		if (kk == k - 1)
		{
			vector<int> res(input.begin(), input.begin() + k);
			sort(res.begin(), res.end());
			return res;
		}
		else if (kk < k - 1)
			l = kk + 1;
		else
			r = kk - 1;
	}
	return vector<int>();
}

int MoreThanHalfNum_Solution(vector<int> numbers) {//寻找数组中个数超过数组一半长度的数据
	vector<int> temp(numbers.begin(), numbers.end());//记录原数组
	int flag = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == 0)
			continue;
		flag = 0;
		for (int j = i + 1; j < numbers.size(); j++)
		{
			if (numbers[j] == 0)
				continue;
			if (numbers[i] != numbers[j])
			{
				flag++;
				numbers[i] = 0;
				numbers[j] = 0;
				break;
			}
		}
		if (flag == 0)
			break;
	}
	int max_num = 0;
	for (int i = 0; i < numbers.size(); i++)
		if (numbers[i] != 0)
		{
			max_num = numbers[i];
			break;
		}
	if (max_num == 0)
		return 0;
	int count = 0;
	for (int i = 0; i < temp.size(); i++)
		if (temp[i] == max_num)
			count++;
	if (count > temp.size() / 2)
		return max_num;
	else
		return 0;
}
RandomListNode* Clone(RandomListNode* pHead)//复杂链表的copy（包含random指针)
{
	if (!pHead)
		return NULL;
	RandomListNode *head = new RandomListNode(pHead->label);
	head->random = pHead->random;
	map<RandomListNode *, RandomListNode *> mapp;
	mapp.insert(pair<RandomListNode*, RandomListNode*>(pHead, head));
	RandomListNode *p2 = pHead;
	RandomListNode *p1 = head;
	while (p2->next)
	{
		p1->next = new RandomListNode(p2->next->label);
		p1->next->random = p2->next->random;
		mapp.insert(pair<RandomListNode*, RandomListNode*>(p2->next, p1->next));
		p1 = p1->next;
		p2 = p2->next;
	}
	p1->next = NULL;
	p1 = head;
	while (p1)
	{
		if (p1->random)
		{
			auto iter = mapp.find(p1->random);
			p1->random = iter->second;
		}
		p1 = p1->next;
	}
	return head;
}
void GetPath(TreeNode *root, int expectNumber, vector<vector<int> > &res, vector<int> &path)
{
	if (!root->left && !root->right)//如果是叶节点
	{
		if (expectNumber == root->val) {
			path.push_back(root->val);
			res.push_back(path);
			path.erase(path.end() - 1);
		}
	}
	else
	{
		path.push_back(root->val);
		if (root->left)
		{
			GetPath(root->left, expectNumber - root->val, res, path);
		}
		if (root->right)
		{
			GetPath(root->right, expectNumber - root->val, res, path);
		}
		path.erase(path.end() - 1);
	}
}
vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {//遍历一棵树输出所有路径和为expectnumber
	vector<vector<int> > res;
	vector<int> path;
	if (!root)  
		return res;
	GetPath(root, expectNumber, res, path);
	return res;
}
bool VerifySquenceOfBST(vector<int> vec) {//判断该数组是否为某二叉搜索树的后序遍历结果
	if (vec.empty())
		return true;
	int i = 0;
	for (; i < (int)vec.size() - 1; i++)
		if (vec[i] > vec[vec.size() - 1])
			break;
	int i_temp = i;
	for (; i < (int)vec.size() - 1; i++)
		if (vec[i] < vec[vec.size() - 1])
			return false;
	vector<int> vec_left(vec.begin(), vec.begin() + i_temp);
	vector<int> vec_right(vec.begin() + i_temp, vec.end() - 1);
	cout << "##" << endl;
	printArr(vec);
	printArr(vec_left);
	printArr(vec_right);
	return VerifySquenceOfBST(vec_left) & VerifySquenceOfBST(vec_right);
}
vector<int> get_three_number_one_time(vector<int> vec)//返回数组中仅出现一次的三个值
{
	int xor_sum = 0;
	vector<int> res;
	int num1 = 0;
	for (int i = 0; i < (int)vec.size(); i++)
		xor_sum ^= vec[i];
	if (!xor_sum)
		return res;
	int first_not_zero = 1;
	while (xor_sum % 2 == 0)
	{
		first_not_zero++;
		xor_sum >>= 1;
	}
	int flag = 1 << (first_not_zero - 1);
	for (int i = 0; i < (int)vec.size(); i++)
		if(flag & vec[i])
			num1 ^= vec[i];
	vec.push_back(num1);
	res = get_two_number_one_time(vec);
	res.push_back(num1);
	return res;
}
vector<int> get_two_number_one_time(vector<int> vec)//返回数组中仅出现一次的两个值
{
	int xor_sum = 0;
	int num1 = 0;
	for (int i = 0; i < (int)vec.size(); i++)
		xor_sum ^= vec[i];
	int xor_sum_temp = xor_sum;
	int first_not_zero = 1;
	while (xor_sum % 2 == 0)
	{
		first_not_zero++;
		xor_sum >>= 1;
	}
	for (int i = 0; i < (int)vec.size(); i++)
		if ((1 << (first_not_zero - 1)) & vec[i])
			num1 ^= vec[i];
	vector<int> res;
	res.push_back(num1);
	res.push_back(num1 ^ xor_sum_temp);
	return res;
}
int get_one_number_one_time(vector<int> vec)//返回数组中仅出现一次的一个值
{
	int res = 0;
	for (int i = 0; i < (int)vec.size(); i++)
		res ^= vec[i];
	return res;
}
vector<int> get_non_exist_two_num(vector<int> vec)//返回数组中不存在的1~N的两个值
{
	int N = vec.size() + 2;
	int temp = 0;
	int num1 = 0;
	for (int i = 0; i < (int)vec.size(); i++)
	{
		temp ^= vec[i];
		temp ^= i + 1;
	}
	temp ^= N - 1;
	temp ^= N;//temp值即为两个不存在的值得异或
	int xor_sum = temp;
	int first_not_zero = 1;
	while (temp % 2 == 0)
	{
		first_not_zero++;
		temp >>= 1;
	}
	int flag = 1 << (first_not_zero - 1);
	for (int i = 0; i < (int)vec.size(); i++)
		if (vec[i] & flag)
			num1 ^= vec[i];
	for (int i = 1; i <= N; i++)
		if (i & flag)
			num1 ^= i;
	vector<int> res;
	res.push_back(num1);
	res.push_back(xor_sum ^ num1);
	return res;
}
string get_longest_common_substr(string s1, string s2)
{
	int n = s1.length();
	int m = s2.length();
	int max_sub_length = 0;
	int max_i, max_j;
	int i = 0, j = m - 1;
	vector<int> vec(m + 1, 0);
	for (; i < n; i++)
		for(j = m - 1; j >= 0; j--)
		{
			vec[j + 1] = s1[i] == s2[j] ? vec[j] + 1 : 0;
			if (vec[j + 1] > max_sub_length)
			{
				max_sub_length = vec[j + 1];
				max_i = i;
				max_j = j;
			}
		}
	cout << max_sub_length << endl;
	return s1.substr(max_i - max_sub_length + 1, max_sub_length);
}
string get_longest_common_subsequence(string s1, string s2)
{
	int n = s1.length();
	int m = s2.length();
	vector<vector<int>> vec(n + 1, vector<int>(m + 1, 0));
	vector<vector<int>> des(n, vector<int>(m, 0));
	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (s1[i] == s2[j])
			{
				vec[i + 1][j + 1] = vec[i][j] + 1;
				des[i][j] = 2;
			}				
			else
			{
				if (vec[i + 1][j] > vec[i][j + 1])
				{
					vec[i + 1][j + 1] = vec[i + 1][j];
					des[i][j] = 0;
				}
				else
				{
					vec[i + 1][j + 1] = vec[i][j + 1];
					des[i][j] = 1;
				}
			}
		}
	vector<char> sub;
	for (int i = n - 1, j = m - 1; i >= 0 && j >= 0; )
	{
		if (des[i][j] == 2)
		{
			sub.push_back(s1[i]);
			i--;
			j--;
		}
		else if (des[i][j] == 1)
		{
			i--;
		}
		else
		{
			j--;
		}
	}
	string res(sub.size(), ' ');
	for (int i = 0; i < (int)sub.size(); i++)
		res[sub.size() - 1 - i] = sub[i];
	return res;
}
string get_max_symmetry_sub(string s)
{
	int l = 0;
	int max_i = 0;
	int max_length = 1;
	while (l < (int)s.length())
	{
		int i = l, j = l + 1;
		while (i >= 0 && j < (int)s.length() && s[i] == s[j])
		{
			i--;
			j++;
		}
		if (max_length < j - i - 1)
		{
			max_length = j - i - 1;
			max_i = i + 1;
		}
		i = l - 1; 
		j = l + 1;
		while (i >= 0 && j < (int)s.length() && s[i] == s[j])
		{
			i--;
			j++;
		}
		if (max_length < j - i - 1)
		{
			max_length = j - i - 1;
			max_i = i + 1;
		}
		l++;
	}
	//string res(s, max_i - (max_length - 1) / 2, max_length);
	cout << max_i << max_length << endl;
	return s.substr(max_i, max_length);
}
int tree_level(TreeNode *head)
{
	if (!head)
		return 0;
	else
		return max(tree_level(head->left), tree_level(head->right)) + 1;
}
bool is_balance(TreeNode *head)
{
	if (!head)
		return true;
	else
		return is_balance(head->left) &&
		is_balance(head->right) &&
		abs(tree_level(head->left) - tree_level(head->right)) <= 1;
}
int is_balance(TreeNode *head, bool &flag)
{
	if (!head)
		return 0;
	int l = is_balance(head->left, flag);
	if (!flag)
		return 0; 
	int r = is_balance(head->right, flag);
	if (!flag)
		return 0;
	if (abs(l - r) > 1)
		flag = false;
	return max(l, r) + 1;

}
void tree_reverse(TreeNode * head)
{
	if (!head)
		return;
	queue<TreeNode *> que;
	que.push(head);
	while (!que.empty())
	{
		TreeNode *temp = que.front();
		que.pop();
		TreeNode *left = temp->left;
		temp->left = temp->right;
		temp->right = left;
		if (temp->left)
			que.push(temp->left);
		if (temp->right)
			que.push(temp->right);
		//delete temp;
		//delete left;
	}
}
string mul(string s1, string s2)
{
	if ((s1[0] == '+' && s2[0] == '+') ||
		(s1[0] == '-' && s2[0] == '-'))
		return mul__(s1.substr(1), s2.substr(1));
	else if (s1[0] != '+' && s1[0] != '-' && s2[0] != '+' && s2[0] != '-')
		return mul__(s1, s2);
	else if (s1[0] == '+' && s2[0] == '-' || s2[0] == '+' && s1[0] == '-')
		return  "-" + mul__(s1.substr(1), s2.substr(1));
	else if (s1[0] == '+' && s2[0] != '+' && s2[0] != '-')
		return  mul__(s1.substr(1), s2);
	else if (s1[0] == '-' && s2[0] != '+' && s2[0] != '-')
	{
		string res1 = mul__(s1.substr(1), s2);
		if (res1[0] == '0')
			return "0";
		else
			return "-" + res1;
	}

	else if (s2[0] == '-' && s1[0] != '-' && s1[0] != '+')
	{
		string res2 = mul__(s2.substr(1), s1);
		if (res2[0] == '0')
			return  "0";
		else
			return "-" + res2 ;
	}

	else if (s2[0] == '+' && s1[0] != '-' && s1[0] != '+')
		return mul__(s2.substr(1), s1);
}
string mul_(string s, int val, int shift)
{
	int flag = 0;
	int i = s.length() - 1;
	vector<int> vec;
	for (int j = 0; j < shift; j++)
		vec.push_back(0);
	for (; i >= 0; i--)
	{
		int temp = (int)(s[i] - '0')*val + flag;
		flag = temp / 10;
		vec.push_back(temp % 10);
	}
	if (flag)
		vec.push_back(flag);
	string res(vec.size(), ' ');
	for (int i = vec.size() - 1; i >= 0; i--)
		res[i] = char('0' + vec[vec.size() - 1 - i]);
	return res;
}
string mul__(string s1, string s2)
{
	string res = "0";
	for (int i = s2.length() - 1; i >= 0; i--)
	{
		res = add(res, mul_(s1, int(s2[i] - '0'), s2.length() - 1 - i));
	}
	string rres = "";
	int i = 0;
	if (res[0] == '-' || res[0] == '+')
		i = 1;
	for (; i < res.length(); i++)
	{
		while (res[i] == '0')
			i++;
		break;
	}
	if (i == res.length())
		return "0";
	bool flag = false;
	if (res[0] == '-')
	{
		flag = true;
		rres += '-';
	}
	rres += res.substr(i);
	if (flag && rres[1] == '0')
		return "0";
	return rres;

}
string add(string s1, string s2)
{
	int flag = 0;
	int i1 = s1.length() - 1;
	int i2 = s2.length() - 1;
	vector<int> vec;
	for (; i1 >= 0 && i2 >= 0;)
	{
		int temp = int(s1[i1--] - '0' + s2[i2--] - '0') + flag;
		flag = temp / 10;
		vec.push_back(temp % 10);
	}
	if (i1 >= 0)
		for (; i1 >= 0;)
		{
			int temp = int(s1[i1--] - '0') + flag;
			flag = temp / 10;
			vec.push_back(temp % 10);
		}
	else
		for (; i2 >= 0;)
		{
			int temp = int(s2[i2--] - '0') + flag;
			flag = temp / 10;
			vec.push_back(temp % 10);
		}
	if (flag)
		vec.push_back(flag);
	string res(vec.size(), ' ');
	for (int i = vec.size() - 1; i >= 0; i--)
		res[i] = char('0' + vec[vec.size() - 1 - i]);
	return res;
}

void merge_sort(int *arr, int l, int r)
{
	if (l < r)
	{
		int mid = (l + r) / 2;
		merge_sort(arr, l, mid);
		merge_sort(arr, mid + 1, r);
		merge(arr, l, mid, r);
		
	}
}
void merge(int *arr, int l, int mid, int r)
{
	if (l < r)
	{
		int *temp = new int[r - l + 1];
		int i = l, j = mid + 1, k = 0;
		while (i <= mid && j <= r)
		{
			if (arr[i] < arr[j])
				temp[k++] = arr[i++];
			else
				temp[k++] = arr[j++];
		}
		while (i <= mid)
			temp[k++] = arr[i++];
		while (j <= r)
			temp[k++] = arr[j++];
		for (int i = 0; i < r - l + 1; i++)
			arr[i + l] = temp[i];
		delete[] temp;
	}
	
}
void quick_sort(int *arr, int l, int r)
{
	if (l < r)
	{
		int p = partition(arr, l, r);
		quick_sort(arr, l, p - 1);
		quick_sort(arr, p + 1, r);
	}
}
int partition(int *arr, int l, int r)
{
	if (l < r)
	{
		int value = arr[l];
		while (l < r)
		{
			while (l < r && arr[r] >= value)
				r--;
			if (l < r)
				arr[l++] = arr[r];
			while (l < r && arr[l] <= value)
				l++;
			if (l < r)
				arr[r--] = arr[l];
		}
		arr[l] = value;
		return l;
		
	}
	return 0;
}
void printArr(vector<int> vec)
{
	for (int i = 0; i < (int)vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}