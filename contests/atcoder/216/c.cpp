#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	ll num;
	cin >> num;
	stack<char> stk;
	while (num) {
		if (num % 2 == 1) {
			stk.push('A');
		}
		stk.push('B');
		num /= 2;
	}
	while (!stk.empty()) {
		cout << stk.top();
		stk.pop();
	}
	cout << endl;
	return 0;
}
