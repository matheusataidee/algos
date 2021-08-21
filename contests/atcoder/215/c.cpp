#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
string s;
set<string> perms;

void solve(int p, string& r) {
	if (p == n) {
		perms.insert(r);
	} else {
		for (int i = p; i < n; i++) {
			swap(s[p], s[i]);
			r += s[p];
			solve(p+1, r);
			r.pop_back();
			swap(s[p], s[i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int k;
	cin >> s >> k;
	n = s.size();
	
	string r = "";
	solve(0, r);
	
	auto it = perms.begin();
	while (k-- > 1) it++;
	cout << *it << endl;
	return 0;
}
