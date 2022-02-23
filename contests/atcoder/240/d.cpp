#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Ball {
	int num;
	int qnt;
	Ball(int num_, int qnt_) : num(num_), qnt(qnt_) { }
};

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	stack<Ball> stk;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (!stk.empty() && stk.top().num == x) {
			stk.top().qnt++;
		} else {
			stk.push(Ball(x, 1));
		}
		sum++;
		if (stk.top().qnt == stk.top().num) {
			sum -= stk.top().qnt;
			stk.pop();
		}
		cout << sum << endl;
	}
	return 0;
}
