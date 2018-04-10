#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;
	int tt = 1;
	while (tt <= T)
	{
		vector<vector<bool>> dis(3, vector<bool>(3, false));
		char ch;
		int point = 0;
		for(int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				cin >> ch;
				if (ch == '.')
				{
					dis[i][j] = true;
					point++;
				}
					
			}
		int count_ = 0;
		count_ += point * (point - 1) / 2;//每两个点是一种图形,每一行也处理了
		vector<int> nums(3, 0);//行
		vector<int> cols(3, 0);//列
		for (int i = 0; i < 3; i++)
		{
			if (dis[0][i])
				nums[0] += 1;
			if (dis[i][0])
				cols[0] += 1;
		}
			
		for (int i = 0; i < 3; i++)
		{
			if (dis[i][1])
				cols[1] += 1;
			if (dis[1][i])
				nums[1] += 1;
		}
		for (int i = 0; i < 3; i++)
		{
			if (dis[2][i])
				nums[2] += 1;
			if (dis[2][i])
				nums[2] += 1;//给出每一行的个数
		}
		int three = 0;
		if (dis[0][0] && dis[1][1] && dis[2][2])
			three++;
		if (dis[2][0] && dis[1][1] && dis[0][2])
			three++;
		for (int i = 0; i < 3; i++)
		{
			if (nums[i] == 3)
				three++;
			if (cols[i] == 3)
				three++;
		}
		if (nums[0] >= 2)
			count_ += (nums[0] * (nums[0] - 1) / 2) * (nums[1] + nums[2]);
		if (nums[1] >= 2)
			count_ += (nums[1] * (nums[1] - 1) / 2) * (nums[0] + nums[2]);
		if (nums[2] >= 2)
			count_ += (nums[2] * (nums[2] - 1) / 2) * (nums[1] + nums[0]);
		if (cols[0] >= 2)
			count_ += (cols[0] * (cols[0] - 1) / 2) * (cols[1] + cols[2]);
		if (cols[1] >= 2)
			count_ += (cols[1] * (cols[1] - 1) / 2) * (cols[0] + cols[2]);
		if (cols[2] >= 2)
			count_ += (cols[2] * (cols[2] - 1) / 2) * (cols[1] + cols[0]);
		cout << count_ << "##"<<endl;
		for (int i = 4; i <= point; i++)
		{
			//组成的i图形的个数
			int sum1 = 1;
			int sum2 = 1;
			for (int j = point; j > point - i; j--)
				sum1 *= j;
			for (int j = 1; j <= i; j++)
				sum2 *= j;
			int kinds = sum1 / sum2;
			cout << "kind:" << kinds << endl;
			cout << "three" << three << endl;
			int three_kind = three * (point - 3);
			count_ += three_kind * 2 * 2;
			count_ += (kinds - three_kind) * 4 * 2;
		}
		cout << count_ << endl;
	}







	return 0;
}