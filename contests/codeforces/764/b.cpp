#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool checkAll(const vector<int>& v) {
	int target = v[1] + (v[1] - v[0]);
	if (v[2] <= target && target % v[2] == 0) return true;
	
	target = (v[2] + v[0]) / 2;
	if ((v[2] + v[0]) % 2 == 0 && v[1] <= target && target % v[1] == 0) return true;
	
	target = v[1] - (v[2] - v[1]);
	if (v[0] <= target && target % v[0] == 0) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		vector<int> v(3);
		cin >> v[0] >> v[1] >> v[2];
		if (v[1] - v[0] == v[2] - v[1] || checkAll(v)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
