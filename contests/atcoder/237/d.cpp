#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	string order;
	cin >> order;
	
	vector<int> v(4 * n);
	int l = 2 * n - 1, r = 2 * n + 1;
	
	int last = n;
	v[2 * n] = last;
	reverse(begin(order), end(order));
	for (char c : order) {
		last--;
		if (c == 'L') {
			v[r++] = last;
		} else { // c == 'R'
			v[l--] = last;
		}
	}
	for (int i = l + 1; i < r; i++) {
		if (i > l + 1) cout << " ";
		cout << v[i];
	}
	cout << endl;
	
	return 0;
}
