#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef struct _p {
	int x;
	int y;
	_p(int _x, int _y) : x(_x), y(_y) {}
}PA;

int func(int N, int X, int Y, const vector<PA>& pa) {
	vector<vector<int>> r(X + 1, vector<int>(Y + 1));
	//int r[X + 1][Y + 1];
	for (int x = X; x >= 0; x--) {
		for (int y = Y; y >= 0; y--) {
			r[x][y] = 0;
		}
	}
	r[0][0] = 1000000; // 能力值不会超过该数字，用于初始化x=y=0时一定可以匹配但是状态转移又不能依赖于该值的逻辑
	for (int i = 1; i < N + 1; ++i) {
		// cout << "pa." << i << ": " << pa[i-1].x << " " << pa[i-1].y << endl;
		for (int x = X; x >= 0; x--) {
			for (int y = Y; y >= 0; y--) {
				if (x == 0 && y == 0) {
					r[x][y] = 1000000;
				}
				else if (i < (x + y)) {
					r[x][y] = 0;
				}
				else {
					if (pa[i - 1].x != 0 && x > 0) {
						r[x][y] = max(min(r[x - 1][y], pa[i - 1].x), r[x][y]);
					}
					if (pa[i - 1].y != 0 && y > 0) {
						r[x][y] = max(min(r[x][y - 1], pa[i - 1].y), r[x][y]);
					}
				}
				// cout << "for, " << "x=" << x << ", y=" << y << " : " << r[x][y] << endl;
			}
		}
		// cout << "pass " << i << endl;
		// for (int x = 0; x < X+1; x++) {
		// for (int y = 0; y < Y+1; y++) {
		// cout << r[x][y] << "\t";
		// }
		// cout << endl;
		// }

	}
	return r[X][Y];
}

void test1() {
	int N = 5, X = 2, Y = 2;
	vector<PA> pa;
	pa.push_back(PA(100, 0));
	pa.push_back(PA(0, 99));
	pa.push_back(PA(95, 95));
	pa.push_back(PA(96, 0));
	pa.push_back(PA(0, 97));

	cout << func(N, X, Y, pa) << endl;
}

void test2() {
	int N = 6, X = 1, Y = 3;
	vector<PA> pa;
	pa.push_back(PA(99, 99));
	pa.push_back(PA(100, 0));
	pa.push_back(PA(0, 100));
	pa.push_back(PA(100, 100));
	pa.push_back(PA(100, 0));
	pa.push_back(PA(100, 0));

	cout << func(N, X, Y, pa) << endl;
}

void test3() {
	int N = 4, X = 2, Y = 2;
	vector<PA> pa;
	pa.push_back(PA(100, 0));
	pa.push_back(PA(100, 0));
	pa.push_back(PA(100, 0));
	pa.push_back(PA(0, 100));

	cout << func(N, X, Y, pa) << endl;
}

void online() {
	int TT = 0;
	cin >> TT;
	int N = 0, X = 0, Y = 0;
	int x = 0, y = 0;
	vector<PA> pa;
	for (int i = 0; i < TT; i++) {
		pa.clear();
		cin >> N >> X >> Y;
		for (int j = 0; j < N; j++) {
			cin >> x >> y;
			pa.push_back(PA(x, y));
		}
		cout << func(N, X, Y, pa) << endl;
	}
}
int main() {
	//test1();
	//test2();
	//test3();
	online();
	return 0;
}