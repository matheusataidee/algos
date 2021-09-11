#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int q;
	cin >> q;
	vector<int> v;
	priority_queue<int, vector<int>, greater<int>> heap;
	int last = -1;
	for (int i = 0; i < q; i++) {
		int type;
		cin >> type;
		if (type == 1) {
			int val;
			cin >> val;
			v.push_back(val);
		} else if (type == 2) {
			if (heap.empty()) {
				cout << v[++last] << endl;
			} else {
				cout << heap.top() << endl;
				heap.pop();
			}
		} else {
			while (last + 1 < (int)v.size()) {
				heap.push(v[++last]);
			}
		}
	}
	return 0;
}
