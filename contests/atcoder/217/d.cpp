#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int L, q;

int main() {
	ios::sync_with_stdio(false);
	cin >> L >> q;
	set<int> cuts;
	cuts.insert(L);
	cuts.insert(0);
	for (int i = 0; i < q; i++) {
		int type, x;
		cin >> type >> x;
		if (type == 1) {
			cuts.insert(x);
		} else {
			auto it = cuts.lower_bound(x);
			int c = *it;
			it--;
			cout << (c) - (*(it)) << endl;
		}
	}
	return 0;
}
